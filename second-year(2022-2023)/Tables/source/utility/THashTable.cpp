//
// Created by Андрей Юрин on 13.05.2023.
//

#include "../../include/utility/THashTable.h"

THashTable::THashTable(uint32_t primeNumber) : TTable() {
    _primeNumber = primeNumber;
}

uint64_t THashTable::HashFunction(const TKey& key) {
    uint64_t hash = 0;
    uint64_t p_pow = 1;
    for (char sym : key) {
        hash += (sym - 'a' + 1) * p_pow;
        p_pow *= _primeNumber;
    }
    return hash;
}

