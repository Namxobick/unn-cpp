//
// Created by Андрей Юрин on 17.05.2023.
//

#ifndef TABLES_TARRAYHASHTABLE_H
#define TABLES_TARRAYHASHTABLE_H


#include "utility/THashTable.h"
#include "../utility/MyException.h"


class TArrayHashTable : public THashTable {
protected:
    std::vector<TTableRecord*> data;
    TTableRecord* pMark;
    uint32_t hashStep;
    uint32_t curPosition;
    int64_t firstFreePosition;

public:
    explicit TArrayHashTable(size_t size = 50, uint32_t hashStep = 7);
    ~TArrayHashTable() override;

    [[nodiscard]] size_t GetSize() const;
    [[nodiscard]] bool IsFull() const override;

    std::optional<TDataValue*> Find(TKey key) override;
    bool Insert(TKey key, TDataValue* value) override;
    void Remove(TKey key) override;

    int Reset() override;
    int Next() override;
    [[nodiscard]] int IsTabEnded() const override;
    [[nodiscard]] TKey GetKey() const override;
    [[nodiscard]] TDataValue *GetValue() const override;

protected:
    uint32_t GetNextPosition(uint32_t position);
    uint32_t GetPreviousPosition(uint32_t position);
    void HelpRemove();
};


#endif //TABLES_TARRAYHASHTABLE_H
