#include "include/storage-structure/TScanTable.h"
#include "include/utility/Writer.h"
#include "include/utility/perfomance-testing/TestingTScanTable.h"

// voina-i-mir
int main() {
    TScanTable scanTable = TScanTable(100000);

    TestingTScanTable().Test("../test.txt", "ветру", &scanTable);

    Writer().WriteInFile("../test.xls", &scanTable);
}
