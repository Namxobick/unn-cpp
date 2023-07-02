//
// Created by Андрей Юрин on 07.04.2023.
//

#ifndef TABLES_INPUTHANDLER_H
#define TABLES_INPUTHANDLER_H

#include <iostream>
#include <fstream>
#include "../../storage-structure/TScanTable.h"
#include "../../data-structure/TWordsInWarAndPeace.h"
#include "../../../include/utility/IO/Writer.h"
#include "../exception/MyException.h"

class InputHandler {
private:
    const std::vector<char> PUNCTUATION_MARK = {'\n', '\t', ' ', '.', ',', '!', '?', ':', ';', '"', '(', ')', '-',
                                                '_', '[', ']', '*'};
    TTable* _table;
public:
    void ProcessInput(const std::string& path, TTable* table);

private:
    void ProcessNumber(char sym, std::string& buffer, BookNumber bookNumber, TypeSymbols& typeSymbols,
                       Language& language, uint32_t& counter);
    void AddedWordInTable(const std::string& buffer, BookNumber bookNumber, TypeSymbols typeSymbols,
                          Language language, uint32_t counter);
    BookNumber DefineBook(const std::string& buffer, BookNumber bookNumber);

};


#endif //TABLES_INPUTHANDLER_H
