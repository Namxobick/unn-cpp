//
// Created by Андрей Юрин on 10.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTable.h"
#include <set>

TestingTable::TestingTable(size_t size) {
    _testingTableOperation = TestingTableOperations();
    _testingTableConversion = TestingTableConversion();
    _size = size;
}

void TestingTable::TestTables(const std::string &path, const std::string &word) {
    auto scanTable = new TScanTable(_size);
    auto sortTable = new TSortTable(_size);
    auto arrayHashTable = new TArrayHashTable(_size);
    auto listHashTable = new TListHashTable(_size);
    auto treeTable = new TTreeTable();
    auto avlTreeTable = new TAVLTreeTable();


    TestTable("scanTable", path, word, scanTable);

    std::cout << "~~~~~~~Start of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl;
    _testingTableConversion.TestConversionsScanToSortTable(scanTable);
    std::cout << "~~~~~~~End of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl << std::endl;

    TestTable("sortTable", path, word, sortTable);
    TestTable("arrayHashTable", path, word, arrayHashTable); // 0.0068 - 0.008
    TestTable("listHashTable", path, word, listHashTable); // 0.0045 - 0.007
    TestTable("treeTable", path, word, treeTable);
    TestTable("avlTreeTable", path, word, avlTreeTable);

    delete avlTreeTable;
    delete treeTable;
    delete listHashTable;
    delete arrayHashTable;
    delete sortTable;
    delete scanTable;
}

void TestingTable::TestTable(const std::string &tableName, const std::string &path, const std::string &word,
                             TTable *table) {
    std::cout << "~~~~~~~Start of testing " << tableName << "~~~~~~~" << std::endl;
    _testingTableOperation.TestOperations(path, word, table);
//    auto fileName = path.substr(0, path.size() - 4) + "-" + tableName + ".xls";
//    Writer().WriteInFile(fileName, table);
    std::cout << "~~~~~~~End of testing " << tableName << "~~~~~~~" << std::endl << std::endl;
}


