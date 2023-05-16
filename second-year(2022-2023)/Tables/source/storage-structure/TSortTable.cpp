//
// Created by Андрей Юрин on 14.04.2023.
//

#include "../../include/storage-structure/TSortTable.h"

TSortTable::TSortTable(size_t size, SortingMethod sortingMet) : TScanTable(size) {
    sortingMethod = sortingMet;
    sorting = nullptr;
    ChangeSorting();
}

TSortTable::TSortTable(const TScanTable &scanTable, SortingMethod sortingMet) {
    sortingMethod = sortingMet;
    sorting = nullptr;
    ChangeSorting();
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
    efficiencyIndicator += sorting->Sort(pData, TTable::size);
}

SortingMethod TSortTable::GetSortingMethod() const {
    return sortingMethod;
}

void TSortTable::SetSortingMethod(SortingMethod sortingMethod) {
    this->sortingMethod = sortingMethod;
    ChangeSorting();
}

std::optional<TDataValue*> TSortTable::Find(TKey key) {
    SetRetCode(TAB_OK);
    int64_t indexRightElement = BinarySearch(pData, key);
    if (GetRetCode() != TAB_NO_RECORD)
        return pData[curPosition]->GetValue();

    curPosition = indexRightElement;

    return {};
}

bool TSortTable::Insert(TKey key, TDataValue *value) {
    if (IsFull()){
        SetRetCode(TAB_FULL);
        return false;
    }

    if (Find(key).has_value()) {
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
    if (Find(key).has_value()){
        SetRetCode(TAB_OK);
        delete pData[curPosition];
        for (uint32_t i = curPosition; i < TTable::size - 1; i++) {
            pData[i] = pData[i + 1];
            efficiencyIndicator++;
        }
        pData[--TTable::size] = nullptr;
        TArrayTable::Reset();
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

void TSortTable::ChangeSorting() {
    delete sorting;
    switch (sortingMethod) {
        case SortingMethod::BubbleSort:
            sorting = new BubbleSort();
            break;
        case SortingMethod::InsertingSort:
            sorting = new InsertionSort();
            break;
        case SortingMethod::MergeSort:
            sorting = new MergeSort();
            break;
        case SortingMethod::HeapSort:
            sorting = new HeapSort();
            break;
        case SortingMethod::StdSort:
            sorting = new StdSort();
            break;
        case SortingMethod::QuickSort:
            std::function<uint32_t(uint32_t indexFirstElement, uint32_t indexLastElement)> func = [](uint32_t indexFirstElement, uint32_t indexLastElement) {
                return (indexFirstElement + indexLastElement) / 2;
            };
            sorting = new QuickSort(func);
            break;
    }
}