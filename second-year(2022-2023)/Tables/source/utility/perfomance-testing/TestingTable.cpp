//
// Created by Андрей Юрин on 10.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTable.h"


void TestingTable::TestAllTables(const std::string &path, const std::string &word) {
    auto scanTable = new TScanTable(100000);
    auto sortTable = new TSortTable(100000);
    auto listHashTable = new TListHashTable(100000);

    std::cout << "~~~~~~~Start of testing ScanTable~~~~~~~" << std::endl;
    TestingTable().Test(path, word, scanTable);
    Writer().WriteInFile(path.substr(0, path.size() - 4) + "-scanTable.xls", scanTable);
    std::cout << "~~~~~~~End of testing ScanTable~~~~~~~" <<std::endl << std::endl;

    std::cout << "~~~~~~~Start of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl;
    TestingConversion().TestConversionScanToSortTable(scanTable);
    std::cout << "~~~~~~~End of testing conversion ScanTable to SortTable~~~~~~~" <<std::endl << std::endl;

    std::cout << "~~~~~~~Start of testing SortTable~~~~~~~" <<std::endl;
    TestingTable().Test(path, word, sortTable);
    Writer().WriteInFile(path.substr(0, path.size() - 4) + "-sortTable.xls", sortTable);
    std::cout << "~~~~~~~End of testing SortTable~~~~~~~" <<std::endl << std::endl;

    std::cout << "~~~~~~~Start of testing ListHashTable~~~~~~~" <<std::endl;
    TestingTable().Test(path, word, listHashTable);
    Writer().WriteInFile(path.substr(0, path.size() - 4) + "-listHashTable.xls", listHashTable);
    std::cout << "~~~~~~~End of testing ListHashTable~~~~~~~" <<std::endl << std::endl;

    delete scanTable;
    delete sortTable;
    delete listHashTable;
}

void TestingTable::Test(const std::string& path, const std::string& word, TTable* table) {
    _table = table;
    TestOneMethod([](const std::string& path, TTable* table){InputHandler().ProcessInput(path, table);},
                  "filling", path);

    TestOneMethod([](const std::string& word, TTable* table){table->Find(word);},
                  "search", word);

    TestOneMethod([](const std::string& word, TTable* table){table->Remove(word);},
                  "deletion", word);

    TestOneMethod([](const std::string& word, TTable* table){table->Insert(word, new TWordsInWarAndPeace());},
                  "insertion", word);
}

void TestingTable::TestOneMethod(const std::function<void(const std::string &, TTable *)> &function,
                                 const std::string& nameMethod, const std::string& str) {
    std::cout << "------Start of " << nameMethod << "------" << std::endl;
    HelpTest(function, str);
    std::cout << "------End of " << nameMethod << "------" << std::endl << std::endl;
}

void TestingTable::HelpTest(const std::function<void(const std::string&, TTable* )> &function,
                            const std::string& str) {
    double time_spent = Timer().MarkTime(function, str, _table);
    std::cout << "Number of records " << _table->GetNumberOfEntries() << std::endl;
    std::cout << "The elapsed time is " << time_spent << " seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << _table->GetEfficiencyIndicator() << std::endl;
    _table->ResetEfficiencyIndicator();
}
