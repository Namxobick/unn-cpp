//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../../include/utility/sorting/QuickSort.h"


QuickSort::QuickSort(std::function<uint32_t(uint32_t, uint32_t)> &calculateIndexSupportElement) {
    _calculateIndexSupportElement = calculateIndexSupportElement;
}

uint64_t QuickSort::Sort(TTableRecord **&data, size_t size) {
    if (size == 0)
        return 0;

    uint64_t efficiencyIndicator = 0;
    Sort(data, 0, size-1, _calculateIndexSupportElement, efficiencyIndicator);
    return efficiencyIndicator;
}

void QuickSort::Sort(TTableRecord **data, uint32_t indexFirstElement, uint32_t indexLastElement,
                         const std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> &calculateIndexSupportElement,
                         uint64_t& efficiencyIndicator) {
    if (indexFirstElement < indexLastElement){
        uint32_t indexLeftElement = indexFirstElement;
        uint32_t indexRightElement = indexLastElement;
        TTableRecord *supportElement = data[calculateIndexSupportElement(indexLeftElement, indexRightElement)];

        do{
            while (*data[indexLeftElement] < *supportElement) indexLeftElement++;
            while (*data[indexRightElement] > *supportElement) indexRightElement--;

            if (indexLeftElement <= indexRightElement){
                std::swap(data[indexLeftElement], data[indexRightElement]);
                efficiencyIndicator++;
                indexLeftElement++;
                indexRightElement--;
            }
        } while (indexLeftElement <= indexRightElement);
        Sort(data, indexFirstElement, indexRightElement, calculateIndexSupportElement, efficiencyIndicator);
        Sort(data, indexLeftElement, indexLastElement, calculateIndexSupportElement, efficiencyIndicator);
    }
}
