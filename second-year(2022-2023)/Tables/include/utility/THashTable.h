//
// Created by Андрей Юрин on 13.05.2023.
//

#ifndef TABLES_THASHTABLE_H
#define TABLES_THASHTABLE_H


#include "TTable.h"

class THashTable: public TTable{
private:
    uint32_t _primeNumber; // A prime number approximately equal to the number of characters in the input alphabet.

public:
    explicit THashTable(uint32_t primeNumber = 131);

protected:
    virtual uint64_t HashFunction(const TKey& key);
};


#endif //TABLES_THASHTABLE_H
