//
// Created by Андрей Юрин on 07.04.2023.
//

#include "../../../include/utility/IO/InputHandler.h"

void InputHandler::ProcessInput(const std::string& path, TTable* table) {
    _table = table;

    std::ifstream inFile(path);

    if (!inFile.is_open())
        throw MyException("The file didn't open");

    std::string buffer;
    uint32_t counter = 1;
    BookNumber bookNumber = BookNumber::ONE;
    TypeSymbols typeSymbols = TypeSymbols::WORD;
    Language language = Language::RUSSIAN;

    while (!inFile.eof()){
        char sym;
        language = Language::RUSSIAN;
        typeSymbols = TypeSymbols::WORD;

        inFile.get(sym);

        while (std::find(PUNCTUATION_MARK.begin(), PUNCTUATION_MARK.end(), sym) == PUNCTUATION_MARK.end()) {
            ProcessNumber(sym, buffer, bookNumber, typeSymbols, language, counter);
            if (('A' <= sym and sym <= 'Z') or ('a' <= sym and sym <= 'z'))
                language = Language::FRENCH;

            buffer += sym;
            inFile.get(sym);

            if (inFile.eof())
                break;
        }

        bookNumber = DefineBook(buffer, bookNumber);
        if (buffer.size() > 1 or buffer == "—")
            AddedWordInTable(buffer, bookNumber, typeSymbols, language, counter++);
        if (!(std::find(PUNCTUATION_MARK.begin(), PUNCTUATION_MARK.end(), sym) == PUNCTUATION_MARK.end()))
            AddedWordInTable(std::string(1, sym), bookNumber, TypeSymbols::PUNCTUATION_MARK,
                            Language::NONE, counter++);

        buffer.clear();
    }

    inFile.close();
}

void InputHandler::ProcessNumber(char sym, std::string& buffer, BookNumber bookNumber, TypeSymbols& typeSymbols,
                                 Language& language, uint32_t& counter) {
    if ('0' <= sym and sym <= '9') {
        typeSymbols = TypeSymbols::NUMBER;
        language = Language::NONE;
    }
    else if (typeSymbols == TypeSymbols::NUMBER and sym != '/'){
        AddedWordInTable(buffer, bookNumber, typeSymbols, language, counter++);
        language = Language::RUSSIAN;
        typeSymbols = TypeSymbols::WORD;
        buffer.clear();
    }
}

void InputHandler::AddedWordInTable(const std::string& buffer, BookNumber bookNumber, TypeSymbols typeSymbols,
                                    Language language, uint32_t counter) {
    auto* wordsInWarAndPeace = new TWordsInWarAndPeace(bookNumber, typeSymbols, language,counter);
    bool result = _table->Insert(buffer, wordsInWarAndPeace);
    if (!result and _table->GetRetCode() == TAB_REC_DOUBLE){
        auto value = (TWordsInWarAndPeace*) _table->GetValue();
        value->AddWord(counter, bookNumber);
        delete wordsInWarAndPeace;
    }
}

BookNumber InputHandler::DefineBook(const std::string& buffer, BookNumber bookNumber) {
    if (buffer == "ВТОРОЙ")
        bookNumber = BookNumber::TWO;
    else if (buffer == "ТРЕТИЙ")
        bookNumber = BookNumber::THREE;
    else if (buffer == "ЧЕТВЕРТЫЙ")
        bookNumber = BookNumber::FOUR;
    else if (buffer == "ЭПИЛОГ")
        bookNumber = BookNumber::EPILOGUE;

    return bookNumber;
}


