//
// Created by Андрей Юрин on 17.05.2023.
//

#include "../../include/storage-structure/TArrayHashTable.h"

TArrayHashTable::TArrayHashTable(size_t size, uint32_t hashStep) {
    if (size == 0)
        throw(MyException("The size can't be zero"));
    if (hashStep > size)
        throw(MyException("The hashStep must be smaller than the size"));

    this->hashStep = hashStep;
    this->curPosition = 0;
    this->data.resize(size);
    this->pMark = new TTableRecord("", nullptr);
    this->firstFreePosition = -1;
}

TArrayHashTable::~TArrayHashTable() {
    for(auto & iter : data)
        delete iter;
    data.clear();
    delete pMark;
}

size_t TArrayHashTable::GetSize() const {
    return data.size();
}

bool TArrayHashTable::IsFull() const {
    return TTable::size >= data.size();
}

std::optional<TDataValue *> TArrayHashTable::Find(TKey key) {
    SetRetCode(TAB_OK);
    firstFreePosition = -1;
    curPosition = Hash(key) % data.size();

    uint32_t numberViewedRecords = 0;
    while (data[curPosition] != nullptr and numberViewedRecords++ < data.size()){
        efficiencyIndicator++;
        if (data[curPosition] == pMark and firstFreePosition == -1)
            firstFreePosition = curPosition;
        if (data[curPosition]->GetKey() == key)
            return data[curPosition]->GetValue();
        curPosition = GetNextPosition(curPosition);
    }
    SetRetCode(TAB_NO_RECORD);
    return {};
}

bool TArrayHashTable::Insert(TKey key, TDataValue *value) {
    if (IsFull()){
        SetRetCode(TAB_FULL);
        return false;
    }

    if (Find(key).has_value()) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }

    if (firstFreePosition != -1)
        curPosition = firstFreePosition;

    data[curPosition] = new TTableRecord(key, value);
    TTable::size++;
    SetRetCode(TAB_OK);

    efficiencyIndicator++;

    return true;
}

void TArrayHashTable::Remove(TKey key) {
    if (!Find(key).has_value()){
        SetRetCode(TAB_NO_RECORD);
        return;
    }
    SetRetCode(TAB_OK);
    delete data[curPosition];
    data[curPosition] = pMark;
    HelpRemove();
    TTable::size--;
    efficiencyIndicator++;
}

int TArrayHashTable::Reset() {
    curPosition = 0;
    while (curPosition < data.size()) {
        if (data[curPosition] != nullptr and data[curPosition] != pMark) break;
        curPosition++;
    }
    return IsTabEnded();
}

int TArrayHashTable::Next() {
    while (!IsTabEnded()) {
        curPosition++;
        if (data[curPosition] != nullptr and data[curPosition] != pMark) break;
    }
    return IsTabEnded();
}

int TArrayHashTable::IsTabEnded() const {
    return curPosition >= data.size();
}

TKey TArrayHashTable::GetKey() const {
    return data[curPosition]->GetKey();
}

TDataValue *TArrayHashTable::GetValue() const {
    return data[curPosition]->GetValue();
}

uint32_t TArrayHashTable::GetNextPosition(uint32_t position) {
    return (position + hashStep) % data.size();
}

uint32_t TArrayHashTable::GetPreviousPosition(uint32_t position) {
    auto newPosition = (int64_t) position - hashStep;
    if (newPosition < 0)
        newPosition = (int64_t) data.size() + newPosition;
    return newPosition;
}

void TArrayHashTable::HelpRemove() {
    if (data[GetNextPosition(curPosition)] != nullptr)
        return;
    while (data[curPosition] == pMark){
        data[curPosition] = nullptr;
        curPosition = GetPreviousPosition(curPosition);
        efficiencyIndicator++;
    }
}
