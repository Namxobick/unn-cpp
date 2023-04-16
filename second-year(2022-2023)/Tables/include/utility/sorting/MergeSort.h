//
// Created by Андрей Юрин on 16.04.2023.
//

#ifndef TABLES_MERGESORT_H
#define TABLES_MERGESORT_H

#include "../TTableRecord.h"

class MergeSort {
public:
    uint32_t Sort(TTableRecord** &data, size_t size);

private:
    TTableRecord** Sort(TTableRecord** arrUp, TTableRecord** arrDown, uint32_t indexFirstElement, uint32_t indexLastElement,
                        uint64_t& efficiencyIndicator);

    TTableRecord** CreateCopy(TTableRecord** data, size_t size);
    bool IsDataSorted(TTableRecord** data, size_t size);
    void MakeDataSorted(TTableRecord** data, TTableRecord** copyData, size_t size);
    void FreeUpMemory(TTableRecord** data, size_t size);

};


#endif //TABLES_MERGESORT_H
