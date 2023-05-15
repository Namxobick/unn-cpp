//
// Created by Андрей Юрин on 15.05.2023.
//

#ifndef TABLES_IHASHFUNCTION_H
#define TABLES_IHASHFUNCTION_H


#include <cstdint>

template <class TKey>
class IHashFunction {

public:
    virtual uint64_t Hash(TKey key) = 0;
};


#endif //TABLES_IHASHFUNCTION_H
