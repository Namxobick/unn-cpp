//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../../include/utility/sorting/InsertionSort.h"

uint64_t InsertionSort::Sort(TTableRecord **data, size_t size) {
    uint64_t efficiencyIndicator = 0;

    for (uint32_t i = 1; i < size; ++i) {
        auto record = data[i];
        int64_t location = i - 1;

        while (location >= 0 and *data[location] > *record){
            data[location + 1] = data[location];
            location--;
            efficiencyIndicator++;
        }
        data[location + 1] = record;
    }
    return efficiencyIndicator;
}
