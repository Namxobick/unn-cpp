//
// Created by Андрей Юрин on 20.03.2023.
//

#ifndef TABLES_TDATAVALUE_H
#define TABLES_TDATAVALUE_H


#include <iostream>

class TDataValue {
protected:
    virtual void Print(std::ostream& ostream) const = 0;

public:
    virtual TDataValue* GetCopy() = 0;
    friend std::ostream& operator<<(std::ostream& ostream, const TDataValue& datValue);
};


#endif //TABLES_TDATAVALUE_H
