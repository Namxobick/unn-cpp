//
// Created by Андрей Юрин on 27.03.2023.
//

#include "../../include/utility/TArrayTable.h"

TArrayTable::TArrayTable(size_t size) {
    this->size = size;
    this->curPosition = 0;
    this->pData = new TTableRecord* [size];
    for (int i = 0; i < size; i++){
        this->pData[i] = nullptr;
    }
}

TArrayTable::~TArrayTable() {
    for (int i = 0; i < size; i++)
        delete pData[i];
    delete[] pData;
}

size_t TArrayTable::GetSize() {
    return TTable::size;
}

bool TArrayTable::IsFull() const {
    return TTable::size > this->size;
}

int TArrayTable::Reset() {
    this->curPosition = 0;
    return IsTabEnded();
}

int TArrayTable::Next() {
    if (!IsTabEnded())
        curPosition++;
    return IsTabEnded();
}

int TArrayTable::IsTabEnded() const {
    return curPosition >= TTable::size;
}

int TArrayTable::SetCurrentPosition(int position) {
    if (position < 0 or position >= TTable::size)
        Reset();
    else
        curPosition = position;
    return IsTabEnded();
}

uint32_t TArrayTable::GetCurrentPosition() const {
    return curPosition;
}

TKey TArrayTable::GetKey() const {
    return GetKey(Position::CURRENT);
}

TKey TArrayTable::GetKey(Position position) const {
    if (IsEmpty())
        return "";

    uint32_t index;
    switch (position) {
        case Position::FIRST:
            index = 0;
            break;
        case Position::LAST:
            index = TTable::size - 1;
            break;
        default:
            index = curPosition;
            break;
        }

    return pData[index]->key;
}

TDataValue *TArrayTable::GetValue() const {
    return GetValue(Position::CURRENT);
}

TDataValue *TArrayTable::GetValue(Position position) const {
    if (IsEmpty())
        return nullptr;

    uint32_t index;
    switch (position) {
        case Position::FIRST:
            index = 0;
            break;
        case Position::LAST:
            index = TTable::size - 1;
            break;
        default:
            index = curPosition;
            break;
    }

    return pData[index]->value;
}
