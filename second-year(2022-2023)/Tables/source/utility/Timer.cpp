//
// Created by Андрей Юрин on 07.04.2023.
//

#include "../../include/utility/Timer.h"

#include <utility>


double Timer::MarkTime(std::string path, TScanTable* scanTable) {
    double time_spent = 0.0;
    clock_t begin = clock();

    InputHandler().ProcessInput(std::move(path), scanTable);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    return time_spent;
}
