//
// Created by Андрей Юрин on 15.05.2023.
//

#ifndef TABLES_STRINGHASHFUNCTION_H
#define TABLES_STRINGHASHFUNCTION_H


#include <string>
#include "IHashFunction.h"

class StringHashFunction : IHashFunction<std::string> {
private:
    uint32_t _primeNumber; // A prime number approximately equal to the number of characters in the input alphabet.

public:
    explicit StringHashFunction(uint32_t primeNumber = 131);

    uint64_t Hash(std::string key) override;
};


#endif //TABLES_STRINGHASHFUNCTION_H
