//
// Created by Андрей Юрин on 23.04.2023.
//

#ifndef TABLES_TESTINGCONVERSION_H
#define TABLES_TESTINGCONVERSION_H


#include "../../storage-structure/TScanTable.h"
#include "../sorting/ISorting.h"
#include "../../../include/utility/perfomance-testing/Timer.h"
#include "../../../include/storage-structure/TSortTable.h"
#include "../../storage-structure/TListHashTable.h"

class TestingConversion {
public:
    void TestConversionScanToSortTable(TScanTable* scanTable);

private:
    friend std::ostream& operator<<(std::ostream& ostream, const SortingMethod& sortingMethod);

    void TestSorting(TScanTable* scanTable, SortingMethod sortingMethod);
};


#endif //TABLES_TESTINGCONVERSION_H
