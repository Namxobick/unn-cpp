//
// Created by Андрей Юрин on 07.04.2023.
//

#include "../../../include/utility/perfomance-testing/Timer.h"

double Timer::MarkTime(const std::function<void(const std::string& word, TTable* table)> &function,
                                     const std::string& str, TTable* table) {
    double time_spent = 0.0;
    clock_t begin = clock();

    function(str, table);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}

std::pair<double, int64_t> Timer::MarkTimeAndEfficiency(const std::function<int64_t (TScanTable *scanTable, SortingMethod sortingMethod)> &function,
                                                        TScanTable *scanTable, SortingMethod sortingMethod) {
    double time_spent = 0.0;
    clock_t begin = clock();

    int64_t efficiencyIndicator = function(scanTable, sortingMethod);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return {time_spent, efficiencyIndicator};
}
