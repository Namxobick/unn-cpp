//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_QUICKSORT_H
#define TABLES_QUICKSORT_H

#include "../TTableRecord.h"

class QuickSort{
public:
    uint64_t Sort(TTableRecord** data, size_t size,
                  const std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> &calculateIndexSupportElement);

private:
    void Sort(TTableRecord** data, uint32_t indexFirstElement, uint32_t indexLastElement,
                  const std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> &calculateIndexSupportElement,
                  uint64_t& efficiencyIndicator);
};


#endif //TABLES_QUICKSORT_H
