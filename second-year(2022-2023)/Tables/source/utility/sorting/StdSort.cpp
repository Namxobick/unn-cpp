//
// Created by Андрей Юрин on 15.05.2023.
//

#include "../../../include/utility/sorting/StdSort.h"

uint64_t StdSort::Sort(TTableRecord **&data, size_t size) {
    if (size == 0)
        return 0;

    std::sort(data, data + size,
              [](TTableRecord* first, TTableRecord* second){return *first < *second;});
    return size * (uint64_t) log(size);
}
