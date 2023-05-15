//
// Created by Андрей Юрин on 03.04.2023.
//

#ifndef TABLES_TWORDSINWARANDPEACE_H
#define TABLES_TWORDSINWARANDPEACE_H


#include <vector>
#include <experimental/iterator>
#include "utility/TDataValue.h"

enum class BookNumber{
    DEFAULT,
    ONE,
    TWO,
    THREE,
    FOUR,
    EPILOGUE,
};

enum class TypeSymbols{
    DEFAULT,
    WORD,
    NUMBER,
    PUNCTUATION_MARK,
};

enum class Language{
    DEFAULT,
    RUSSIAN,
    FRENCH,
    NONE,
};

struct WordCount{
    uint32_t bookOne;
    uint32_t bookTwo;
    uint32_t bookThree;
    uint32_t bookFour;
    uint32_t epilogue;

    [[nodiscard]] uint64_t Sum() const{
        return bookOne + bookTwo + bookThree + bookFour + epilogue;
    }

    friend std::ostream& operator<<(std::ostream& ostream, const WordCount& wordCount){
        ostream << wordCount.bookOne << '\t' << wordCount.bookTwo << '\t' << wordCount.bookThree
        << '\t' << wordCount.bookFour << '\t' << wordCount.epilogue;
        return ostream;
    }
};

class TWordsInWarAndPeace: public TDataValue{
private:
    WordCount _wordCount{};
    TypeSymbols _typeSymbols;
    Language _language;
    std::vector<uint32_t> _sequentialNumbers;

public:
    TWordsInWarAndPeace();
    TWordsInWarAndPeace(BookNumber bookNumber, TypeSymbols typeSymbols, Language language, uint32_t sequentialNumber);
    TWordsInWarAndPeace(WordCount wordCount, TypeSymbols typeSymbols, Language language, std::vector<uint32_t> sequentialNumbers);
    void AddWord(uint32_t sequentialNumber, BookNumber bookNumber);
    void RemoveWord(uint32_t sequentialNumber, BookNumber bookNumber);
    void Print(std::ostream& os) const override;
    TDataValue* GetCopy() override;

private:
    void ChangeWordCount(BookNumber bookNumber, uint32_t delta);
};


#endif //TABLES_TWORDSINWARANDPEACE_H
