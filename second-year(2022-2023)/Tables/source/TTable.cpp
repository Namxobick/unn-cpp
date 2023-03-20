//
// Created by Андрей Юрин on 20.03.2023.
//

#include "../include/TTable.h"

TTable::TTable() {
    _size = 0;
    _efficiencyIndicator = 0;
}

uint TTable::GetEfficiencyIndicator() const {
    return _efficiencyIndicator;
}

size_t TTable::GetSize() const {
    return _size;
}

bool TTable::IsEmpty() const {
    return _size == 0;
}
