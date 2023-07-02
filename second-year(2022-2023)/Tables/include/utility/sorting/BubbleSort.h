//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_BUBBLESORT_H
#define TABLES_BUBBLESORT_H


#include "ISorting.h"

class BubbleSort : public ISorting{
public:
    ~BubbleSort() override = default;
    uint64_t Sort(TTableRecord** &data, size_t size) override;
};


#endif //TABLES_BUBBLESORT_H
