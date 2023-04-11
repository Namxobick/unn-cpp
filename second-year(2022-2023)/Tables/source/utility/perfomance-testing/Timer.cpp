//
// Created by Андрей Юрин on 07.04.2023.
//

#include "../../../include/utility/perfomance-testing/Timer.h"

double Timer::MarkTime(const std::function<void(const std::string& word, TScanTable* scanTable)> &function,
                                     const std::string& str, TScanTable* scanTable) {
    double time_spent = 0.0;
    clock_t begin = clock();

    function(str, scanTable);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}
