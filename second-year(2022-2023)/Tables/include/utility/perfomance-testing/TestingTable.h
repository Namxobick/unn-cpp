//
// Created by Андрей Юрин on 10.04.2023.
//

#ifndef TABLES_TESTINGTABLE_H
#define TABLES_TESTINGTABLE_H

#include "../../storage-structure/TScanTable.h"
#include "../../storage-structure/TSortTable.h"
#include "../../storage-structure/TArrayHashTable.h"
#include "../../storage-structure/TListHashTable.h"
#include "../../storage-structure/TTreeTable.h"
#include "../../storage-structure/TAVLTreeTable.h"
#include "../../utility/perfomance-testing/TestingTableConversion.h"
#include "../../utility/perfomance-testing/TestingTableOperations.h"


class TestingTable {
private:
    TestingTableOperations _testingTableOperation;
    TestingTableConversion _testingTableConversion;
    size_t _size;

public:
    TestingTable(size_t size = 100000);
    void TestTables(const std::string& path, const std::string& word);
    void TestTable(const std::string& tableName, const std::string& path, const std::string& word, TTable* table);
};


#endif //TABLES_TESTINGTABLE_H
