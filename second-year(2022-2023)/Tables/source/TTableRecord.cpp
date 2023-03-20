//
// Created by Андрей Юрин on 20.03.2023.
//

#include <utility>

#include "../include/TTableRecord.h"

void TTableRecord::Print(std::ostream &ostream) const {
    ostream << _key << " " << *_value;
}

void TTableRecord::SetKey(const TKey &key) {
    _key = key;
}

void TTableRecord::SetValue(TDataValue *value) {
    _value = value;
}

TTableRecord::TTableRecord(TKey key, TDataValue *value) : _key(std::move(key)), _value(value){}

TDataValue *TTableRecord::GetCopy() {
    return new TTableRecord(_key, _value);
}

TDataValue *TTableRecord::GetValue() {
    return _value;
}

TTableRecord &TTableRecord::operator=(const TTableRecord &other) {
    if (this != &other) {
        _key = other._key;
        _value = other._value;
    }
    return *this;
}

bool TTableRecord::operator==(const TTableRecord &other) {
    return _key == other._key;
}

bool TTableRecord::operator<(const TTableRecord &other) {
    return _key < other._key;
}

bool TTableRecord::operator>(const TTableRecord &other) {
    return _key > other._key;
}

