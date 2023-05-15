//
// Created by Андрей Юрин on 15.05.2023.
//

#include "../../../include/utility/hash-function/StringHashFunction.h"

StringHashFunction::StringHashFunction(uint32_t primeNumber) {
    _primeNumber = primeNumber;
}

uint64_t StringHashFunction::Hash(std::string key) {
    uint64_t hash = 0;
    uint64_t primeNumberPow = 1;
    for (char sym : key) {
        hash += (sym - 'a' + 1) * primeNumberPow;
        primeNumberPow *= _primeNumber;
    }
    return hash;
}
