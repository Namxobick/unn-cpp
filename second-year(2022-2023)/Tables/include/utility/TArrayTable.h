//
// Created by Андрей Юрин on 27.03.2023.
//

#ifndef TABLES_TARRAYTABLE_H
#define TABLES_TARRAYTABLE_H

#include "TTable.h"

enum class Position{
    FIRST,
    CURRENT,
    LAST,
};

class TArrayTable: public TTable{
protected:
    TTableRecord** pData;
    size_t size;
    uint32_t curPosition;

public:
    explicit TArrayTable(size_t size = 10);
    ~TArrayTable() override;

    size_t GetSize();

    [[nodiscard]] bool IsFull() const override;

    int Reset() override;
    int Next() override;
    [[nodiscard]] int IsTabEnded() const override;
    virtual int SetCurrentPosition(int position);
    [[nodiscard]] virtual uint32_t GetCurrentPosition() const;
    [[nodiscard]] TKey GetKey() const override;
    [[nodiscard]] virtual TKey GetKey(Position position) const;
    [[nodiscard]] TDataValue *GetValue() const override;
    [[nodiscard]] virtual TDataValue* GetValue(Position position) const;

};


#endif //TABLES_TARRAYTABLE_H
