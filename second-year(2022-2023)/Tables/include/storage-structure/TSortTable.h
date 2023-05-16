//
// Created by Андрей Юрин on 14.04.2023.
//

#ifndef TABLES_TSORTTABLE_H
#define TABLES_TSORTTABLE_H

#include "TScanTable.h"
#include "../utility/sorting/ISorting.h"
#include "../../include/utility/sorting/BubbleSort.h"
#include "../../include/utility/sorting/HeapSort.h"
#include "../../include/utility/sorting/InsertionSort.h"
#include "../../include/utility/sorting/MergeSort.h"
#include "../../include/utility/sorting/QuickSort.h"
#include "../../include/utility/sorting/StdSort.h"


class TSortTable : public TScanTable{
protected:
    SortingMethod sortingMethod;
    ISorting* sorting;
protected:
    void Sort();

public:
    explicit TSortTable(size_t size = 50, SortingMethod sortingMet = SortingMethod::StdSort);
    explicit TSortTable(const TScanTable& scanTable, SortingMethod sortingMet = SortingMethod::StdSort);

    TSortTable& operator=(const TScanTable& scanTable);
    [[nodiscard]] SortingMethod GetSortingMethod() const;
    void SetSortingMethod(SortingMethod sortingMethod);

    std::optional<TDataValue*> Find(TKey key) override;
    bool Insert(TKey key, TDataValue* value) override;
    void Remove(TKey key) override;

private:
    void ChangeSorting();
    int64_t BinarySearch(TTableRecord** pData, const TKey& key);
};


#endif //TABLES_TSORTTABLE_H
