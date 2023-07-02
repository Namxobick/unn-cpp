//
// Created by Андрей Юрин on 23.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingTableConversion.h"

void TestingTableConversion::TestConversionsScanToSortTable(TScanTable *scanTable) {
    scanTable->ResetEfficiencyIndicator();
    TestConversion(scanTable, SortingMethod::BubbleSort);
    TestConversion(scanTable, SortingMethod::InsertingSort);
    TestConversion(scanTable, SortingMethod::MergeSort);
    TestConversion(scanTable, SortingMethod::HeapSort);
    TestConversion(scanTable, SortingMethod::QuickSort);
    TestConversion(scanTable, SortingMethod::StdSort);
}

std::ostream &operator<<(std::ostream &ostream, const SortingMethod &sortingMethod) {
    switch (sortingMethod) {
        case SortingMethod::BubbleSort:
            ostream << "BubbleSort";
            break;
        case SortingMethod::InsertingSort:
            ostream << "InsertingSort";
            break;
        case SortingMethod::QuickSort:
            ostream << "QuickSort";
            break;
        case SortingMethod::MergeSort:
            ostream << "MergeSort";
            break;
        case SortingMethod::HeapSort:
            ostream << "HeapSort";
            break;
        case SortingMethod::StdSort:
            ostream << "StdSort";
            break;
    }
    return ostream;
}

void TestingTableConversion::TestConversion(TScanTable *scanTable, SortingMethod sortingMethod) {
    std::cout << "------Start sorting: " << sortingMethod << "------" << std::endl;

    auto efficiency = Timer().MarkTimeAndEfficiency([](TScanTable *scanTable, SortingMethod sortingMethod) {
                                                        return TSortTable(*scanTable, sortingMethod).GetEfficiencyIndicator();
                                                    },
                                                    scanTable, sortingMethod);
    std::cout << "Number of records " << scanTable->GetNumberOfEntries() << std::endl;
    std::cout << "The elapsed time is " << efficiency.first << " seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << efficiency.second << std::endl;

    std::cout << "------End sorting" << "------" << std::endl << std::endl;
}

