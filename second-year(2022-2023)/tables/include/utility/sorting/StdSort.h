//
// Created by Андрей Юрин on 15.05.2023.
//

#ifndef TABLES_STDSORT_H
#define TABLES_STDSORT_H


#include "ISorting.h"

class StdSort : public ISorting{
public:
    uint64_t Sort(TTableRecord** &data, size_t size) override;
    ~StdSort() override = default;
};


#endif //TABLES_STDSORT_H
