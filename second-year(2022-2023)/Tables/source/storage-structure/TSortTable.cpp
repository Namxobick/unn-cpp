//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../include/storage-structure/TSortTable.h"

TSortTable::TSortTable(size_t size, SortingMethod sortingMet) : TScanTable(size) {
    sortingMethod = sortingMet;
}

TSortTable::TSortTable(const TScanTable &scanTable, SortingMethod sortingMet) {
    sortingMethod = sortingMet;
    *this = scanTable;
}

TSortTable &TSortTable::operator=(const TScanTable &scanTable) {
    if (pData != nullptr){
        for (int i = 0; i < TArrayTable::size; ++i) {
            delete pData[i];
        }
        delete[] pData;
        pData = nullptr;
    }
    TArrayTable::size = scanTable.GetSize();
    TTable::size = scanTable.GetNumberOfEntries();
    pData = new TTableRecord * [TArrayTable::size];
    for (uint32_t i = 0; i < TTable::size; ++i) {
        pData[i] = (TTableRecord*) scanTable.pData[i]->GetCopy();
    }
    for (uint32_t i = TTable::size; i < TArrayTable::size; ++i){
        pData[i] = nullptr;
    }
    efficiencyIndicator = scanTable.GetEfficiencyIndicator();
    Sort();
    curPosition = 0;
    return *this;
}

void TSortTable::Sort() {
    if (sortingMethod == SortingMethod::QuickSort)
        efficiencyIndicator += sorting.Sort(sortingMethod, pData, TTable::size,
                                            [](uint32_t indexFirstElement, uint32_t indexLastElement){
                                                return (indexFirstElement + indexLastElement) / 2; });
    else
        efficiencyIndicator += sorting.Sort(sortingMethod, pData, TTable::size);
}

SortingMethod TSortTable::GetSortingMethod() const {
    return sortingMethod;
}

void TSortTable::SetSortingMethod(SortingMethod sortingMethod) {
    this->sortingMethod = sortingMethod;
}

TDataValue *TSortTable::Find(TKey key) {
    SetRetCode(TAB_OK);
    int64_t indexRightElement = BinarySearch(pData, key);
    if (GetRetCode() != TAB_NO_RECORD)
        return pData[curPosition]->GetValue();

    curPosition = indexRightElement;

    return nullptr;
}

bool TSortTable::Insert(TKey key, TDataValue *value) {
    if (IsFull()){
        SetRetCode(TAB_FULL);
        return false;
    }

    if (Find(key), GetRetCode() != TAB_NO_RECORD) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }

    for (auto i = (int64_t)TTable::size; i > curPosition; --i) {
        pData[i] = pData[i - 1];
        efficiencyIndicator++;
    }

    pData[curPosition] = new TTableRecord(key, value);
    TTable::size++;
    SetRetCode(TAB_OK);

    efficiencyIndicator++;

    return true;
}

void TSortTable::Remove(TKey key) {
    if (Find(key), GetRetCode() != TAB_NO_RECORD){
        SetRetCode(TAB_OK);
        delete pData[curPosition];
        for (uint32_t i = curPosition; i < TTable::size - 1; i++) {
            pData[i] = pData[i + 1];
            efficiencyIndicator++;
        }
        pData[--TTable::size] = nullptr;
        efficiencyIndicator++;
    }
}

int64_t TSortTable::BinarySearch(TTableRecord **pData, const TKey& key) {
    int64_t indexLeftElement = 0, indexRightElement = (int64_t) TTable::size - 1, indexMiddleElement = 0;

    while (indexLeftElement <= indexRightElement){
        indexMiddleElement = (indexLeftElement + indexRightElement) >> 1;
        TKey middleElement = pData[indexMiddleElement]->GetKey();

        if (middleElement > key)
            indexRightElement = indexMiddleElement - 1;
        else if (middleElement < key)
            indexLeftElement = indexMiddleElement + 1;
        else
            return curPosition = indexMiddleElement;
        efficiencyIndicator++;
    }

    SetRetCode(TAB_NO_RECORD);
    return ++indexRightElement;
}
