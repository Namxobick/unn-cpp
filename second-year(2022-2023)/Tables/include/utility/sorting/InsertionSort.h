//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_INSERTIONSORT_H
#define TABLES_INSERTIONSORT_H


#include "../TTableRecord.h"

class InsertionSort{
public:
    uint64_t Sort(TTableRecord** data, size_t size);
};


#endif //TABLES_INSERTIONSORT_H
