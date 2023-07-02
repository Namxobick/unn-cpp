//
// Created by Андрей Юрин on 13.05.2023.
//

#ifndef TABLES_THASHTABLE_H
#define TABLES_THASHTABLE_H


#include "TTable.h"
#include "../../utility/hash-function/StringHashFunction.h"

class THashTable: public TTable{
private:
    StringHashFunction _stringHashFunction;
public:
    explicit THashTable(uint32_t primeNumber = 131);
    ~THashTable() override = default;

protected:
    uint64_t Hash(const TKey& key);
};


#endif //TABLES_THASHTABLE_H
