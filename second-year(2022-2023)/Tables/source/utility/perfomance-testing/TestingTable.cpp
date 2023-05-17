//
// Created by Андрей Юрин on 10.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTable.h"


TestingTable::TestingTable() {
    _testingTableOperation = TestingTableOperations();
    _testingTableConversion = TestingTableConversion();
}

void TestingTable::TestAllTables(const std::string &path, const std::string &word) {
    auto scanTable = new TScanTable(100000);
    auto sortTable = new TSortTable(100000);
    auto listHashTable = new TListHashTable(100000);

    TestTable("scanTable", path, word, scanTable);

    std::cout << "~~~~~~~Start of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl;
    _testingTableConversion.TestConversionsScanToSortTable(scanTable);
    std::cout << "~~~~~~~End of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl << std::endl;

    TestTable("sortTable", path, word, sortTable);

    TestTable("listHashTable", path, word, listHashTable);


    delete scanTable;
    delete sortTable;
    delete listHashTable;
}

void TestingTable::TestTable(const std::string &tableName, const std::string &path, const std::string &word,
                             TTable *table) {
    std::cout << "~~~~~~~Start of testing " << tableName << "~~~~~~~" << std::endl;
    _testingTableOperation.TestOperations(path, word, table);
    auto fileName = path.substr(0, path.size() - 4) + "-" + tableName + ".xls";
    Writer().WriteInFile(fileName, table);
    std::cout << "~~~~~~~End of testing " << tableName << "~~~~~~~" << std::endl << std::endl;
}


