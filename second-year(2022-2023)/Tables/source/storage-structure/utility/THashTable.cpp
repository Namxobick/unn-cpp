//
// Created by Андрей Юрин on 13.05.2023.
//

#include "../../../include/storage-structure/utility/THashTable.h"

THashTable::THashTable(uint32_t primeNumber) : TTable() {
    _stringHashFunction = StringHashFunction(primeNumber);
}

uint64_t THashTable::Hash(const TKey& key) {
    return _stringHashFunction.Hash(key);
}

