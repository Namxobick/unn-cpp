//
// Created by Андрей Юрин on 17.04.2023.
//

#include "../../../include/utility/sorting/HeapSort.h"

uint64_t HeapSort::Sort(TTableRecord **&data, size_t size) {
    if (size == 0)
        return 0;

    uint64_t efficiencyIndicator = 0;

    for (auto i = (int64_t) size / 2 - 1; i >= 0; --i) {
        Heapify(data, size, i, efficiencyIndicator);
    }

    for (auto i = (int64_t) size - 1; i >= 0; --i)
    {
        std::swap(data[0], data[i]);
        efficiencyIndicator++;
        Heapify(data, i, 0, efficiencyIndicator);
    }
    return efficiencyIndicator;
}

void HeapSort::Heapify(TTableRecord **data, size_t size, uint32_t index, uint64_t& efficiencyIndicator) {
    uint32_t indexLargestElement = index;

    uint32_t indexLeftElement = 2 * index + 1;
    uint32_t indexRightElement = 2 * index + 2;

    if (indexLeftElement < size && *data[indexLeftElement] > *data[indexLargestElement])
        indexLargestElement = indexLeftElement;

    if (indexRightElement < size && *data[indexRightElement] > *data[indexLargestElement])
        indexLargestElement = indexRightElement;

    if (indexLargestElement != index)
    {
        std::swap(data[index], data[indexLargestElement]);
        efficiencyIndicator++;
        Heapify(data, size, indexLargestElement, efficiencyIndicator);
    }
}
