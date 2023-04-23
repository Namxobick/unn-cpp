//
// Created by Андрей Юрин on 17.04.2023.
//

#ifndef TABLES_HEAPSORT_H
#define TABLES_HEAPSORT_H


#include "../TTableRecord.h"

class HeapSort {
public:
    uint64_t Sort(TTableRecord** data, size_t size);

private:
    void Heapify(TTableRecord** data, size_t size, uint32_t index, uint64_t& efficiencyIndicator);
};


#endif //TABLES_HEAPSORT_H
