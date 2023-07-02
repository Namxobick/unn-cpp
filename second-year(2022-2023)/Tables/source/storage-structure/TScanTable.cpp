//
// Created by Андрей Юрин on 03.04.2023.
//

#include "../../include/storage-structure/TScanTable.h"

std::optional<TDataValue*> TScanTable::Find(TKey key) {
    int index = 0;
    SetRetCode(TAB_OK);
    for (; index < TTable::size; index++)
        if (pData[index]->key == key)
            break;

    efficiencyIndicator += (index + 1);

    if (index < TTable::size)
    {
        curPosition = index;
        return pData[curPosition]->value;
    }
    SetRetCode(TAB_NO_RECORD);
    return {};
}

bool TScanTable::Insert(TKey key, TDataValue *value) {
    if (IsFull()){
        SetRetCode(TAB_FULL);
        return false;
    }

    if (Find(key).has_value()) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }

    pData[TTable::size] = new TTableRecord(key, value);
    TTable::size++;
    SetRetCode(TAB_OK);

    efficiencyIndicator++;

    return true;
}

void TScanTable::Remove(TKey key) {
    if (Find(key).has_value()){
        SetRetCode(TAB_OK);
        delete pData[curPosition];
        pData[curPosition] = pData[TTable::size - 1];
        pData[--TTable::size] = nullptr;
        TArrayTable::Reset();
        efficiencyIndicator++;
    }
}
