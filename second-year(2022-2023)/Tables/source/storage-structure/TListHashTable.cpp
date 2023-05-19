//
// Created by Андрей Юрин on 13.05.2023.
//

#include "../../include/storage-structure/TListHashTable.h"

TListHashTable::TListHashTable(size_t size) {
    if (size == 0)
        throw(MyException("The size can't be zero"));

    this->size = size;
    this->data.resize(size);
    this->curList = 0;
    this->curIter = data[curList].begin();
}

TListHashTable::~TListHashTable() {
    for(auto & vecIter : data) {
        for (auto & listIter: vecIter)
            delete listIter;
        vecIter.clear();
    }
    data.clear();
}

size_t TListHashTable::GetSize() const {
    return size;
}

bool TListHashTable::IsFull() const {
    return false;
}

std::optional<TDataValue*> TListHashTable::Find(TKey key) {
    SetRetCode(TAB_OK);
    curList = Hash(key) % size;

    for (auto iter = data[curList].begin(); iter != data[curList].end(); ++iter) {
        efficiencyIndicator++;
        auto record = *iter;
        if (record->key == key) {
            curIter = iter;
            return record->value;
        }
    }

    SetRetCode(TAB_NO_RECORD);
    return {};
}

bool TListHashTable::Insert(TKey key, TDataValue *value) {
    if (Find(key).has_value()) {
        SetRetCode(TAB_REC_DOUBLE);
        return false;
    }
    data[curList].push_back(new TTableRecord(key, value));
    efficiencyIndicator++;
    TTable::size++;
    SetRetCode(TAB_OK);
    return true;
}

void TListHashTable::Remove(TKey key) {
    if (Find(key).has_value()){
        SetRetCode(TAB_OK);
        data[curList].erase(curIter);
        --TTable::size;
        Reset();
        efficiencyIndicator++;
    }

}

int TListHashTable::Reset() {
    this->curList = 0;
    while (data[curList].empty() and !IsTabEnded()) curList++;
    this->curIter = data[curList].begin();
    return IsTabEnded();
}

int TListHashTable::Next() {
    if (!IsListEnded())
        this->curIter++;
    else if (!IsTabEnded()) {
        while (data[++curList].empty() and !IsTabEnded());
        this->curIter = data[curList].begin();
    }
    return IsTabEnded();
}

int TListHashTable::IsListEnded() const {
    auto tempIter = curIter;
    return ++tempIter == data[curList].end();
}

int TListHashTable::IsTabEnded() const {
    return curList >= size;
}

TKey TListHashTable::GetKey() const {
    auto record = *curIter;
    return record->key;
}

TDataValue *TListHashTable::GetValue() const {
    auto record = *curIter;
    return record->value;
}

