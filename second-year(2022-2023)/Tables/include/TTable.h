//
// Created by Андрей Юрин on 20.03.2023.
//

#ifndef TABLES_TTABLE_H
#define TABLES_TTABLE_H

#include <iostream>

class TTable {
protected:
    size_t _size;
    uint _efficiencyIndicator;

public:
    TTable();
    [[nodiscard]] size_t GetSize() const;
    [[nodiscard]] uint GetEfficiencyIndicator() const;
    [[nodiscard]] bool IsEmpty() const;

    [[nodiscard]] virtual bool IsFull() const = 0;

};


#endif //TABLES_TTABLE_H
