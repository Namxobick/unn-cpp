//
// Created by Андрей Юрин on 10.04.2023.
//

#ifndef TABLES_TESTINGTABLE_H
#define TABLES_TESTINGTABLE_H

#include "../../storage-structure/TScanTable.h"
#include "../../../include/storage-structure/TSortTable.h"
#include "../../storage-structure/TListHashTable.h"
#include "../../../include/utility/perfomance-testing/Timer.h"
#include "../IO/Writer.h"
#include "../../../include/utility/perfomance-testing/TestingConversion.h"

class TestingTable {
private:
    TTable* _table;
public:
    void Test(const std::string& path, const std::string& word, TTable* table);
    void TestAllTables(const std::string& path, const std::string& word);

private:
    void TestOneTable(const std::string& tableName, const std::string& path, const std::string& word, TTable* table);
    void TestOneMethod(const std::function<void(const std::string& word, TTable* table)> &function,
                       const std::string& nameMethod, const std::string& str);

    void HelpTest(const std::function<void(const std::string& word, TTable* table)> &function,
                  const std::string& str);
};


#endif //TABLES_TESTINGTABLE_H
