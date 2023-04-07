//
// Created by Андрей Юрин on 07.04.2023.
//

#include "../../include/utility/InputHandler.h"

void InputHandler::ProcessInput(const std::string& path, TScanTable* scanTable) {
    std::ifstream inFile(path);

    if (!inFile.is_open())
        throw "The file did not open";

    std::string buffer;
    uint32_t counter = 1;
    BookNumber bookNumber = BookNumber::ONE;
    while (!inFile.eof()){
        Language language = Language::RUSSIAN;
        TypeSymbols typeSymbols = TypeSymbols::WORD;
        char sym;
        inFile.get(sym);
        while (std::find(PUNCTUATION_MARK.begin(), PUNCTUATION_MARK.end(), sym) == PUNCTUATION_MARK.end()) {
            if ('0' <= sym and sym <= '9') {
                typeSymbols = TypeSymbols::NUMBER;
                language = Language::NONE;
            }
            else if (typeSymbols == TypeSymbols::NUMBER){
                AddedWordInTable(scanTable, buffer, bookNumber, typeSymbols, language, counter++);
                language = Language::RUSSIAN;
                typeSymbols = TypeSymbols::WORD;
                buffer.clear();
            }
            if (('A' <= sym and sym <= 'Z') or ('a' <= sym and sym <= 'z'))
                language = Language::FRENCH;

            buffer += sym;
            inFile.get(sym);
        }
        bookNumber = DefineBook(buffer, bookNumber);

        AddedWordInTable(scanTable, buffer, bookNumber, typeSymbols, language, counter++);
        AddedWordInTable(scanTable, std::string(&sym), bookNumber, TypeSymbols::PUNCTUATION_MARK,
                         Language::NONE, counter++);

        buffer.clear();
    }
    inFile.close();
}

void InputHandler::AddedWordInTable(TScanTable *scanTable, const std::string& buffer, BookNumber bookNumber,
                                    TypeSymbols typeSymbols, Language language, uint32_t counter) {
    auto* wordsInWarAndPeace = new TWordsInWarAndPeace(bookNumber, typeSymbols, language,counter);
    if (!scanTable->Insert(buffer, wordsInWarAndPeace)){
        auto value = (TWordsInWarAndPeace*) scanTable->Find(buffer);
        value->AddWord(counter, bookNumber);
        delete wordsInWarAndPeace;
    }
}

BookNumber InputHandler::DefineBook(const std::string& buffer, BookNumber bookNumber) {
    if (buffer == "ВТОРОЙ")
        return BookNumber::TWO;
    else if (buffer == "ТРЕТИЙ")
        return BookNumber::THREE;
    else if (buffer == "ЧЕТВЕРТЫЙ")
        return BookNumber::FOUR;
    else if (buffer == "ЭПИЛОГ")
        return BookNumber::EPILOGUE;
    return bookNumber;
}

