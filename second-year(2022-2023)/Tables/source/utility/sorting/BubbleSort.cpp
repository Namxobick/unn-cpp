//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../../include/utility/sorting/BubbleSort.h"

uint64_t BubbleSort::Sort(TTableRecord **data, size_t size) {
    uint64_t efficiencyIndicator = 0;
    for (uint32_t i = 0; i < size; ++i){
        bool isSorted = true;
        for (uint32_t j = 0; j < size - i - 1; ++j){
            if (*data[j] > *data[j + 1]){
                std::swap(data[j], data[j + 1]);
                isSorted = false;
                efficiencyIndicator++;
            }
        }
        if (isSorted)
            break;
    }
    return efficiencyIndicator;
}
