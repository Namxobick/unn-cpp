#include <iostream>
#include "include/storage-structure/TScanTable.h"
#include "include/utility/Timer.h"

int main() {
    TScanTable scanTable = TScanTable(100000);
    double time_spent = Timer().MarkTime("../voina-i-mir.txt", &scanTable);

    std::cout << "Number of records " << scanTable.GetSize() << std::endl;
    std::cout << "The elapsed time is " << time_spent << "seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << scanTable.GetEfficiencyIndicator() << std::endl;

    std::cout << *scanTable.Find("холодным");
}
