//
// Created by Андрей Юрин on 07.04.2023.
//

#ifndef TABLES_TIMER_H
#define TABLES_TIMER_H

#include <iostream>
#include <utility>
#include "../../storage-structure/TScanTable.h"
#include "../InputHandler.h"

class Timer {
public:
    double MarkTime(const std::function<void(const std::string& word, TScanTable* scanTable)>& function,
                    const std::string& word, TScanTable* scanTable);
};


#endif //TABLES_TIMER_H
