//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../../include/utility/sorting/Sorting.h"

Sorting &Sorting::operator=(const Sorting &sort) {
    return *this;
}

uint64_t Sorting::Sort(SortingMethod sortingMethod, TTableRecord** &data, size_t size) {
    uint64_t efficiencyIndicator = 0;

    switch (sortingMethod) {
        case SortingMethod::BubbleSort:
            efficiencyIndicator = BubbleSort().Sort(data, size);
            break;
        case SortingMethod::InsertingSort:
            efficiencyIndicator = InsertionSort().Sort(data, size);
            break;
        case SortingMethod::MergeSort:
            efficiencyIndicator = MergeSort().Sort(data, size);
            break;
        case SortingMethod::HeapSort:
            efficiencyIndicator = HeapSort().Sort(data, size);
            break;
        case SortingMethod::StdSort:
            std::sort(data, data + size,
                      [](TTableRecord* first, TTableRecord* second){return *first < *second;});
            efficiencyIndicator = size * (uint64_t) log(size);
            break;
        default:
            throw ERROR_MESSAGE;
    }
    return efficiencyIndicator;
}

uint64_t Sorting::Sort(SortingMethod sortingMethod, TTableRecord **data, size_t size,
                       const std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> &calculateIndexSupportElement) {
    uint64_t efficiencyIndicator = 0;
    switch (sortingMethod) {
        case SortingMethod::QuickSort:
            efficiencyIndicator = QuickSort().Sort(data, size, calculateIndexSupportElement);
            break;
        default:
            throw ERROR_MESSAGE;
    }
    return efficiencyIndicator;
}
