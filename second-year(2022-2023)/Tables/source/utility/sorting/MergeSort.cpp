//
// Created by Андрей Юрин on 16.04.2023.
//

#include "../../../include/utility/sorting/MergeSort.h"

uint64_t MergeSort::Sort(TTableRecord **&data, size_t size) {
    if (size == 0)
        return 0;

    auto copyData = CreateCopy(data, size);
    uint64_t efficiencyIndicator = 0;
    Sort(data, copyData, 0, size-1, efficiencyIndicator);

    if (!IsDataSorted(data, size))
        std::copy(copyData, copyData + size, data);

    delete[] copyData;

    return efficiencyIndicator;
}

TTableRecord** MergeSort::Sort(TTableRecord **arrUp, TTableRecord **arrDown, uint32_t indexFirstElement,
                               uint32_t indexLastElement,uint64_t &efficiencyIndicator) {

    if (indexFirstElement == indexLastElement){
        arrDown[indexFirstElement] = arrUp[indexFirstElement];
        return arrDown;
    }

    uint32_t indexMiddleElement = (indexFirstElement + indexLastElement) / 2;

    TTableRecord** leftBuffer = Sort(arrUp, arrDown, indexFirstElement, indexMiddleElement, efficiencyIndicator);
    TTableRecord** rightBuffer = Sort(arrUp, arrDown, indexMiddleElement + 1, indexLastElement, efficiencyIndicator);

    TTableRecord** target = leftBuffer == arrUp ? arrDown : arrUp;

    uint32_t leftCur = indexFirstElement;
    uint32_t rightCur = indexMiddleElement + 1;

    for (uint32_t i = indexFirstElement; i <= indexLastElement; ++i){
        if (leftCur <= indexMiddleElement and rightCur <= indexLastElement){
            if (*leftBuffer[leftCur] < *rightBuffer[rightCur]){
                target[i] = leftBuffer[leftCur];
                leftCur++;
            }
            else{
                target[i] = rightBuffer[rightCur];
                rightCur++;
            }
        }
        else if (leftCur <= indexMiddleElement){
            target[i] = leftBuffer[leftCur];
            leftCur++;
        }
        else{
            target[i] = rightBuffer[rightCur];
            rightCur++;
        }
        efficiencyIndicator++;
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
        if (data[i]->GetKey() > data[i + 1]->GetKey()) {
            return false;
        }
    }
    return true;
}
