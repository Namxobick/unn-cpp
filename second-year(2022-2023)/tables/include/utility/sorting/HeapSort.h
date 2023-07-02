//
// Created by Андрей Юрин on 17.04.2023.
//

#ifndef TABLES_HEAPSORT_H
#define TABLES_HEAPSORT_H


#include "ISorting.h"

class HeapSort : public ISorting{
public:
    ~HeapSort() override = default;
    uint64_t Sort(TTableRecord** &data, size_t size) override;

private:
    void Heapify(TTableRecord** data, size_t size, uint32_t index, uint64_t& efficiencyIndicator);
};


#endif //TABLES_HEAPSORT_H
