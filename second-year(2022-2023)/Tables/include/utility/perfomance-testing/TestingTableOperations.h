//
// Created by Андрей Юрин on 17.05.2023.
//

#ifndef TABLES_TESTINGTABLEOPERATIONS_H
#define TABLES_TESTINGTABLEOPERATIONS_H

#include "../../../include/storage-structure/utility/TTable.h"
#include "../../../include/utility/perfomance-testing/Timer.h"

class TestingTableOperations {
private:
    TTable* _table;

public:
    void TestOperations(const std::string& path, const std::string& word, TTable* table);

private:
    void TestOperation(const std::function<void(const std::string& word, TTable* table)> &function,
                       const std::string& nameMethod, const std::string& str);

    void HelpTest(const std::function<void(const std::string& word, TTable* table)> &function,
                  const std::string& str);
};


#endif //TABLES_TESTINGTABLEOPERATIONS_H
