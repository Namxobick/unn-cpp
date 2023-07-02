//
// Created by Андрей Юрин on 03.04.2023.
//

#ifndef TABLES_TSCANTABLE_H
#define TABLES_TSCANTABLE_H


#include "utility/TArrayTable.h"

class TScanTable : public TArrayTable{
public:
    explicit TScanTable(size_t size = 50) : TArrayTable(size) {};
    ~TScanTable() override = default;

    std::optional<TDataValue*> Find(TKey key) override;
    bool Insert(TKey key, TDataValue* value) override;
    void Remove(TKey key) override;
};


#endif //TABLES_TSCANTABLE_H
