//
// Created by Андрей Юрин on 20.03.2023.
//

#ifndef TABLES_TTABLE_H
#define TABLES_TTABLE_H

#define TAB_OK 0
#define TAB_EMPTY (-101)
#define TAB_FULL (-102)
#define TAB_NO_RECORD (-103)
#define TAB_REC_DOUBLE (-104)
#define TAB_NO_MEM (-105)

#include <iostream>
#include "TDatCom.h"
#include "TDataValue.h"
#include "TTableRecord.h"

class TTable: public TDatCom {
protected:
    size_t size;
    uint64_t efficiencyIndicator;

public:
    TTable();
    ~TTable() override = default;
    [[nodiscard]] size_t GetSize() const;
    [[nodiscard]] uint64_t GetEfficiencyIndicator() const;
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] virtual bool IsFull() const = 0;
    virtual TDataValue* Find(TKey key) = 0;
    virtual bool Insert(TKey key, TDataValue* value) = 0;
    virtual void Remove(TKey key) = 0;

    // iterator
    virtual int Reset() = 0;
    virtual int Next() = 0;
    [[nodiscard]] virtual int IsTabEnded() const = 0;
    [[nodiscard]] virtual TKey GetKey() const = 0;
    [[nodiscard]] virtual TDataValue* GetValue() const = 0;

    friend std::ostream& operator<<(std::ostream& out, TTable& table);
};


#endif //TABLES_TTABLE_H
