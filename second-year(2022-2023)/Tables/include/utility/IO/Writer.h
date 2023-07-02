//
// Created by Андрей Юрин on 08.04.2023.
//

#ifndef TABLES_WRITER_H
#define TABLES_WRITER_H

#include <iostream>
#include <fstream>
#include "../../storage-structure/TScanTable.h"


class Writer {
public:
    void WriteInFile(const std::string& path, TTable* table);
};


#endif //TABLES_WRITER_H
