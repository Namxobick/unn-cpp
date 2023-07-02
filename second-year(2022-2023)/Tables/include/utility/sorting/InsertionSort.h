//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_INSERTIONSORT_H
#define TABLES_INSERTIONSORT_H


#include "ISorting.h"

class InsertionSort: public ISorting{
public:
    ~InsertionSort() override = default;
    uint64_t Sort(TTableRecord** &data, size_t size) override;
};


#endif //TABLES_INSERTIONSORT_H
