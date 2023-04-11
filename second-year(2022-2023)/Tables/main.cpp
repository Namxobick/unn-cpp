#include "include/storage-structure/TScanTable.h"
#include "include/utility/Writer.h"
#include "include/utility/perfomance-testing/TestingTScanTable.h"

int main() {
    TScanTable scanTable = TScanTable(100000);

    TestingTScanTable().Test("../voina-i-mir.txt", "ветру", &scanTable);

    Writer().WriteInFile("../voina-i-mir.xls", &scanTable);
}
