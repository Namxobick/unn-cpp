//
// Created by Андрей Юрин on 20.03.2023.
//

#ifndef TABLES_TTABLERECORD_H
#define TABLES_TTABLERECORD_H

#include <iostream>
#include "TDataValue.h"

typedef std::string TKey;

class TTableRecord: public TDataValue{
protected:
    TKey _key;
    TDataValue* _value;

protected:
    void Print(std::ostream& ostream) const override;
    void SetKey(const TKey& key);
    void SetValue(TDataValue* value);

public:
    explicit TTableRecord(TKey  key = "", TDataValue* value = nullptr);
    TDataValue* GetCopy() override;
    TDataValue* GetValue();

    TTableRecord& operator=(const TTableRecord& other);
    bool operator==(const TTableRecord& other);
    bool operator<(const TTableRecord& other);
    bool operator>(const TTableRecord& other);

    friend class TScanTable;
    friend class TArrayTable;
};


#endif //TABLES_TTABLERECORD_H
