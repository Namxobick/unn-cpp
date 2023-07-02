//
// Created by Андрей Юрин on 03.04.2023.
//

#include <utility>

#include "../../include/data-structure/TWordsInWarAndPeace.h"

TWordsInWarAndPeace::TWordsInWarAndPeace(){
    _wordCount = {0, 0, 0, 0, 0};
    ChangeWordCount(BookNumber::DEFAULT, 1);
    _typeSymbols = TypeSymbols::DEFAULT;
    _language = Language::DEFAULT;
    _sequentialNumbers.push_back(0);
}

TWordsInWarAndPeace::TWordsInWarAndPeace(BookNumber bookNumber, TypeSymbols typeSymbols, Language language,
                                         uint32_t sequentialNumber) {
    _wordCount = {0, 0, 0, 0, 0};
    ChangeWordCount(bookNumber, 1);
    _typeSymbols = typeSymbols;
    _language = language;
    _sequentialNumbers.push_back(sequentialNumber);
}

TWordsInWarAndPeace::TWordsInWarAndPeace(WordCount wordCount, TypeSymbols typeSymbols, Language language,
                                         std::vector<uint32_t> sequentialNumbers) {
    _wordCount = wordCount;
    _typeSymbols = typeSymbols;
    _language = language;
    _sequentialNumbers = std::move(sequentialNumbers);
}

void TWordsInWarAndPeace::AddWord(uint32_t sequentialNumber, BookNumber bookNumber) {
    ChangeWordCount(bookNumber, 1);
    _sequentialNumbers.push_back(sequentialNumber);
}

void TWordsInWarAndPeace::RemoveWord(uint32_t sequentialNumber, BookNumber bookNumber) {
    if (_wordCount.Sum() == 0)
        throw std::out_of_range("Sum of wordCount == 0");
    ChangeWordCount(bookNumber, -1);
    auto it = _sequentialNumbers.begin();
    for (; it != _sequentialNumbers.end(); ++it) {
        if (*it == sequentialNumber) {
            _sequentialNumbers.erase(it);
            break;
        }
    }
}

void TWordsInWarAndPeace::ChangeWordCount(BookNumber bookNumber, uint32_t delta) {
    switch (bookNumber) {
        case BookNumber::ONE:
            _wordCount.bookOne += delta;
            break;
        case BookNumber::TWO:
            _wordCount.bookTwo += delta;
            break;
        case BookNumber::THREE:
            _wordCount.bookThree += delta;
            break;
        case BookNumber::FOUR:
            _wordCount.bookFour += delta;
            break;
        case BookNumber::EPILOGUE:
            _wordCount.epilogue += delta;
            break;
    }
}

void TWordsInWarAndPeace::Print(std::ostream &os) const {
    os << _wordCount << '\t';

    switch(_typeSymbols){
        case TypeSymbols::WORD:
            os << "Word" << '\t';
            break;
        case TypeSymbols::NUMBER:
            os << "Number" << '\t';
            break;
        case TypeSymbols::PUNCTUATION_MARK:
            os << "Punctuation marks" << '\t';
            break;
        default:
            os << "Default" << '\t';
            break;
    }

    switch (_language) {
        case Language::RUSSIAN:
            os << "Russian" << '\t';
            break;
        case Language::FRENCH:
            os << "French" << '\t';
            break;
        case Language::NONE:
            os << "None" << '\t';
            break;
        default:
            os << "Default" << '\t';
            break;
    }

    os << "[" << *_sequentialNumbers.begin() << ", ..., " << *(_sequentialNumbers.end() - 1) << "]";
//    os << "[";
//    for (auto sequentialNumber : _sequentialNumbers) {
//        os << sequentialNumber << ", ";
//    }
//    os << "]";
}

TDataValue *TWordsInWarAndPeace::GetCopy() {
    return new TWordsInWarAndPeace(_wordCount, _typeSymbols, _language, _sequentialNumbers);
}



