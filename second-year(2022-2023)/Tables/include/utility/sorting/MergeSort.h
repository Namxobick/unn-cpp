//
// Created by Андрей Юрин on 16.04.2023.
//

#ifndef TABLES_MERGESORT_H
#define TABLES_MERGESORT_H

#include "ISorting.h"

class MergeSort: public ISorting {
public:
    ~MergeSort() override = default;
    uint64_t Sort(TTableRecord** &data, size_t size) override;

private:
    TTableRecord** Sort(TTableRecord** arrUp, TTableRecord** arrDown, uint32_t indexFirstElement, uint32_t indexLastElement,
                        uint64_t& efficiencyIndicator);

    TTableRecord** CreateCopy(TTableRecord** data, size_t size);
    bool IsDataSorted(TTableRecord** data, size_t size);
};


#endif //TABLES_MERGESORT_H
