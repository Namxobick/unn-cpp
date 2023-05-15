//
// Created by Андрей Юрин on 15.05.2023.
//

#ifndef TABLES_ISORTING_H
#define TABLES_ISORTING_H

#include "../../data-structure/utility/TTableRecord.h"

enum class SortingMethod{
    BubbleSort,
    InsertingSort,
    QuickSort,
    MergeSort,
    HeapSort,
    StdSort,
};

class ISorting {
public:
    ISorting() = default;
    virtual ~ISorting() = default;
    virtual uint64_t Sort(TTableRecord** &data, size_t size) = 0;
};


#endif //TABLES_ISORTING_H
