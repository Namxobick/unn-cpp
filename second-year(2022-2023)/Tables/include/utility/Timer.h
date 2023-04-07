//
// Created by Андрей Юрин on 07.04.2023.
//

#ifndef TABLES_TIMER_H
#define TABLES_TIMER_H

#include <iostream>
#include "../storage-structure/TScanTable.h"
#include "InputHandler.h"

class Timer {
public:
    double MarkTime(std::string, TScanTable*);
};


#endif //TABLES_TIMER_H
