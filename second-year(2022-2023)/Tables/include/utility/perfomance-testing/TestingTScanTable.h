//
// Created by Андрей Юрин on 10.04.2023.
//

#ifndef TABLES_TESTINGTSCANTABLE_H
#define TABLES_TESTINGTSCANTABLE_H

#include "../../storage-structure/TScanTable.h"

class TestingTScanTable {
private:
    TScanTable* _scanTable;
public:
    void Test(const std::string& path, const std::string& word, TScanTable* table);

private:
    void TestOneMethod(const std::function<void(const std::string& word, TScanTable* scanTable)> &function,
                       const std::string& nameMethod, const std::string& str);

    void HelpTest(const std::function<void(const std::string& word, TScanTable* scanTable)> &function,
                  const std::string& str);
};


#endif //TABLES_TESTINGTSCANTABLE_H
