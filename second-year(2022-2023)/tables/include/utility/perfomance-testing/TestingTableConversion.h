//
// Created by Андрей Юрин on 23.04.2023.
//

#ifndef TABLES_TESTINGTABLECONVERSION_H
#define TABLES_TESTINGTABLECONVERSION_H


#include "../../storage-structure/TScanTable.h"
#include "../../../include/storage-structure/TSortTable.h"
#include "../sorting/ISorting.h"
#include "../../../include/utility/perfomance-testing/Timer.h"

class TestingTableConversion {
public:
    void TestConversionsScanToSortTable(TScanTable* scanTable);

private:
    friend std::ostream& operator<<(std::ostream& ostream, const SortingMethod& sortingMethod);

    void TestConversion(TScanTable* scanTable, SortingMethod sortingMethod);
};


#endif //TABLES_TESTINGTABLECONVERSION_H
