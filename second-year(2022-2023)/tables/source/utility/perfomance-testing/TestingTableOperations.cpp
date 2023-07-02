//
// Created by Андрей Юрин on 17.05.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTableOperations.h"

void TestingTableOperations::TestOperations(const std::string &path, const std::string &word, TTable *table) {
    _table = table;
    TestOperation([](const std::string& path, TTable* table){InputHandler().ProcessInput(path, table);},
                  "filling", path);

    TestOperation([](const std::string& word, TTable* table){table->Find(word);},
                  "search", word);

    TestOperation([](const std::string& word, TTable* table){table->Remove(word);},
                  "deletion", word);

    TestOperation([](const std::string& word, TTable* table){table->Insert(word, new TWordsInWarAndPeace());},
                  "insertion", word);
}

void TestingTableOperations::TestOperation(const std::function<void(const std::string &, TTable *)> &function,
                                 const std::string& nameMethod, const std::string& str) {
    std::cout << "------Start of " << nameMethod << "------" << std::endl;
    HelpTest(function, str);
    std::cout << "------End of " << nameMethod << "------" << std::endl << std::endl;
}

void TestingTableOperations::HelpTest(const std::function<void(const std::string&, TTable* )> &function,
                            const std::string& str) {
    double time_spent = Timer().MarkTime(function, str, _table);
    std::cout << "Number of records " << _table->GetNumberOfEntries() << std::endl;
    std::cout << "The elapsed time is " << time_spent << " seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << _table->GetEfficiencyIndicator() << std::endl;
    _table->ResetEfficiencyIndicator();
}