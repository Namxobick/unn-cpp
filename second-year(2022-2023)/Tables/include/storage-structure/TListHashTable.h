//
// Created by Андрей Юрин on 13.05.2023.
//

#ifndef TABLES_TLISTHASHTABLE_H
#define TABLES_TLISTHASHTABLE_H

#include <list>
#include "utility/THashTable.h"
#include "../utility/exception/MyException.h"

class TListHashTable : public THashTable{
protected:
    std::vector<std::list<TTableRecord*>> data;
    size_t size;
    uint32_t curList;
    std::list<TTableRecord*>::iterator curIter;
public:
    explicit TListHashTable(size_t size = 50);
    ~TListHashTable() override;

    [[nodiscard]] size_t GetSize() const;
    [[nodiscard]] bool IsFull() const override;

    std::optional<TDataValue*> Find(TKey key) override;
    bool Insert(TKey key, TDataValue* value) override;
    void Remove(TKey key) override;

    int Reset() override;
    int Next() override;
    [[nodiscard]] int IsListEnded() const;
    [[nodiscard]] int IsTabEnded() const override;
    [[nodiscard]] TKey GetKey() const override;
    [[nodiscard]] TDataValue *GetValue() const override;
};


#endif //TABLES_TLISTHASHTABLE_H
