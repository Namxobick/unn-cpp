//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_SORTING_H
#define TABLES_SORTING_H

#include "../TTableRecord.h"
#include "../../../include/utility/sorting/BubbleSort.h"
#include "../../../include/utility/sorting/InsertionSort.h"

enum class SortingMethod{
    BubbleSort,
    InsertingSort,
    QuickSort,
    MergeSort,
    HeapSort,
    CalculationSort,
    StdSort,
};

class Sorting {
private:
    const std::string ERROR_MESSAGE = "The sorting method does not match the number of parameters";
public:
    uint64_t Sort(SortingMethod sortingMethod, TTableRecord** &data, size_t size);
    uint64_t Sort(SortingMethod sortingMethod, TTableRecord** data, size_t size,
                  const std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> &calculateIndexSupportElement);

};


#endif //TABLES_SORTING_H
