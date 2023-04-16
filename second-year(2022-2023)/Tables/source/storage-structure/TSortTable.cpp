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
        for (int i = 0; i < TTable::size; ++i) {
            delete pData[i];
        }
        delete[] pData;
        pData = nullptr;
    }
    TArrayTable::size = scanTable.GetSize();
    TTable::size = scanTable.GetNumberOfEntries();
    pData = new TTableRecord * [TArrayTable::size];
    for (int i = 0; i < TTable::size; ++i) {
        pData[i] = (TTableRecord*) scanTable.pData[i]->GetCopy();
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
    return nullptr;
}

bool TSortTable::Insert(TKey key, TDataValue *value) {
    return false;
}

void TSortTable::Remove(TKey key) {

}
