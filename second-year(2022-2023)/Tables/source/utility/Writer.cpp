//
// Created by Андрей Юрин on 08.04.2023.
//

#include "../../include/utility/Writer.h"

void Writer::WriteInFile(const std::string& path, TTable *table) {
    std::ofstream outFile;
    outFile.open(path);
    outFile << "Key\tBook One\tBook Two\tBook Three\tBook Four\tEpilogue\tType Symbols\tLanguage" << std::endl;
    std::string key;
    for (table->Reset(); !table->IsTabEnded(); table->Next()){
        if (table->GetKey() == "\"" or (int) table->GetKey()[0] == 34)
            key = "'";
        else if (table->GetKey() == "—")
            key = "-";
        else if (table->GetKey() == "\n")
            key = "\\n";
        else if (table->GetKey() == "\t")
            key = "\\t";
        else
            key = table->GetKey();
        outFile << key << '\t' << *table->GetValue() << std::endl;
    }
    outFile.close();
}
