//
// Created by Андрей Юрин on 20.03.2023.
//

#include "../../include/utility/TTable.h"

TTable::TTable() {
    size = 0;
    efficiencyIndicator = 0;
}

uint TTable::GetEfficiencyIndicator() const {
    return efficiencyIndicator;
}

size_t TTable::GetSize() const {
    return size;
}

bool TTable::IsEmpty() const {
    return size == 0;
}

std::ostream &operator<<(std::ostream &out, TTable &table) {
    for(table.Reset(); !table.IsTabEnded(); table.Next())
        out << "Key: " << table.GetKey() << " Value: " << table.GetValue() << std::endl;

    return out;
}
