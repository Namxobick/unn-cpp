//
// Created by Андрей Юрин on 16.04.2023.
//

#include "../../../include/utility/sorting/MergeSort.h"

uint32_t MergeSort::Sort(TTableRecord **&data, size_t size) {
    auto copyData = CreateCopy(data, size);
    uint64_t efficiencyIndicator = 0;

    Sort(data, copyData, 0, size-1, efficiencyIndicator);

    if (!IsDataSorted(data, size)) {
        delete[] data;
        data = copyData;
    }
    else{
        delete[] copyData;
    }

    return efficiencyIndicator;
}

TTableRecord** MergeSort::Sort(TTableRecord **arrUp, TTableRecord **arrDown, uint32_t indexFirstElement,
                               uint32_t indexLastElement,uint64_t &efficiencyIndicator) {

    if (indexFirstElement == indexLastElement){
        arrDown[indexFirstElement] = arrUp[indexFirstElement];
        return arrDown;
    }

    uint32_t indexMiddleElement = (indexFirstElement + indexLastElement) / 2;

    TTableRecord** l_buff = Sort(arrUp, arrDown, indexFirstElement, indexMiddleElement, efficiencyIndicator);
    TTableRecord** r_buff = Sort(arrUp, arrDown, indexMiddleElement + 1, indexLastElement, efficiencyIndicator);

    TTableRecord** target = l_buff == arrUp ? arrDown : arrUp;

    uint32_t l_cur = indexFirstElement;
    uint32_t r_cur = indexMiddleElement + 1;

    for (uint32_t i = indexFirstElement; i <= indexLastElement; ++i){
        if (l_cur <= indexMiddleElement and r_cur <= indexLastElement){
            if (*l_buff[l_cur] < *r_buff[r_cur]){
                target[i] = l_buff[l_cur];
                l_cur++;
            }
            else{
                target[i] = r_buff[r_cur];
                r_cur++;
            }
        }
        else if (l_cur <= indexMiddleElement){
            target[i] = l_buff[l_cur];
            l_cur++;
        }
        else{
            target[i] = r_buff[r_cur];
            r_cur++;
        }
    }
    return target;
}

TTableRecord **MergeSort::CreateCopy(TTableRecord **data, size_t size) {
    auto copyData = new TTableRecord* [size];

    for (uint32_t i = 0; i < size; ++i) {
        copyData[i] = data[i];
    }
    return copyData;
}

bool MergeSort::IsDataSorted(TTableRecord **data, size_t size) {
    for (uint32_t i = 0; i < size - 1; ++i){
        if (data[i] > data[i + 1]) {
            return false;
        }
    }
    return true;
}

