//
// Created by Андрей Юрин on 20.03.2023.
//

#include "../../include/utility/TTableRecord.h"

void TTableRecord::Print(std::ostream &ostream) const {
    ostream << key << " " << *value;
}

void TTableRecord::SetKey(const TKey &key) {
    this->key = key;
}

void TTableRecord::SetValue(TDataValue *value) {
    this->value = value;
}

TTableRecord::TTableRecord(TKey key, TDataValue *value) : key(std::move(key)), value(value){}

TTableRecord::~TTableRecord() {
    delete value;
}

TDataValue * TTableRecord::GetCopy() {
    return new TTableRecord(key, value->GetCopy());
}

TKey TTableRecord::GetKey() {
    return key;
}

TDataValue *TTableRecord::GetValue() {
    return value;
}

TTableRecord &TTableRecord::operator=(const TTableRecord &other) {
    if (this != &other) {
        key = other.key;
        value = other.value;
    }
    return *this;
}

bool TTableRecord::operator==(const TTableRecord &other) {
    return key == other.key;
}

bool TTableRecord::operator<(const TTableRecord &other) {
    return key < other.key;
}

bool TTableRecord::operator>(const TTableRecord &other) {
    return key > other.key;
}



