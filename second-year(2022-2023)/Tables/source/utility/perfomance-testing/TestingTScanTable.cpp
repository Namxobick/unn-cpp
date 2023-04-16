//
// Created by Андрей Юрин on 10.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTScanTable.h"
#include "../../../include/utility/perfomance-testing/Timer.h"

void TestingTScanTable::Test(const std::string& path, const std::string& word, TScanTable* scanTable) {
    _scanTable = scanTable;
    TestOneMethod([](const std::string& path, TScanTable* scanTable){InputHandler().ProcessInput(path, scanTable);},
                  "filling", path);

    TestOneMethod([](const std::string& word, TScanTable* scanTable){scanTable->Find(word);},
                  "search", word);

    TestOneMethod([](const std::string& word, TScanTable* scanTable){scanTable->Remove(word);},
                  "deletion", word);

    TestOneMethod([](const std::string& word, TScanTable* scanTable){scanTable->Insert(word, new TWordsInWarAndPeace());},
                  "insertion", word);
}

void TestingTScanTable::TestOneMethod(const std::function<void(const std::string &, TScanTable *)> &function,
                                      const std::string& nameMethod, const std::string& str) {
    std::cout << "------Start of " << nameMethod << "------" << std::endl;
    HelpTest(function, str);
    std::cout << "------End of " << nameMethod << "------" << std::endl << std::endl;
}

void TestingTScanTable::HelpTest(const std::function<void(const std::string& word, TScanTable* scanTable)> &function,
                                 const std::string& str) {
    double time_spent = Timer().MarkTime(function, str, _scanTable);
    std::cout << "Number of records " << _scanTable->GetNumberOfEntries() << std::endl;
    std::cout << "The elapsed time is " << time_spent << " seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << _scanTable->GetEfficiencyIndicator() << std::endl;
    _scanTable->ResetEfficiencyIndicator();
}

