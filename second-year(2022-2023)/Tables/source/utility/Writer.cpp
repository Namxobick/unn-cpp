//
// Created by Андрей Юрин on 08.04.2023.
//

#include "../../include/utility/Writer.h"
#include "../../include/storage-structure/TSortTable.h"

void Writer::WriteInFile(const std::string& path, TScanTable *scanTable) {
    std::ofstream outFile;
    outFile.open(path);
    outFile << "Key\tBook One\tBook Two\tBook Three\tBook Four\tEpilogue\tType Symbols\tLanguage" << std::endl;
    std::string key;
    for (auto it = (scanTable->Reset(), scanTable->GetCurrentPosition()); it == scanTable->IsTabEnded(); scanTable->Next()){
        auto temp = scanTable->GetKey();

        if (scanTable->GetKey() == "\""  or (int) scanTable->GetKey()[0] == 34)
            key = "'";
        else if (scanTable->GetKey() == "—")
            key = "-";
        else if (scanTable->GetKey() == "\n")
            key = "\\n";
        else if (scanTable->GetKey() == "\t")
            key = "\\t";
        else
            key = scanTable->GetKey();

        outFile << key << '\t' << *scanTable->GetValue() << std::endl;
    }
    outFile.close();
}
