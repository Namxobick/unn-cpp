//
// Created by Андрей Юрин on 07.04.2023.
//

#ifndef TABLES_TIMER_H
#define TABLES_TIMER_H

#include <iostream>
#include <utility>
#include "../../storage-structure/TScanTable.h"
#include "../IO/InputHandler.h"
#include "../sorting/Sorting.h"

class Timer {
public:
    double MarkTime(const std::function<void(const std::string& word, TTable* table)>& function,
                    const std::string& word, TTable* table);

    std::pair<double, int64_t> MarkTime(const std::function<int64_t (TScanTable *scanTable, SortingMethod sortingMethod)>& function,
                                        TScanTable *scanTable, SortingMethod sortingMethod);
};


#endif //TABLES_TIMER_H
