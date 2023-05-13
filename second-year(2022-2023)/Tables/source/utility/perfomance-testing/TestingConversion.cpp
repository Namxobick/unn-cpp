//
// Created by Андрей Юрин on 23.04.2023.
//

#include "../../../include/utility/perfomance-testing/TestingConversion.h"

void TestingConversion::TestConversionScanToSortTable(TScanTable *scanTable) {
    scanTable->ResetEfficiencyIndicator();
    TestSorting(scanTable, SortingMethod::BubbleSort);
    TestSorting(scanTable, SortingMethod::InsertingSort);
    TestSorting(scanTable, SortingMethod::MergeSort);
    TestSorting(scanTable, SortingMethod::HeapSort);
    TestSorting(scanTable, SortingMethod::QuickSort);
    TestSorting(scanTable, SortingMethod::StdSort);
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

void TestingConversion::TestSorting(TScanTable *scanTable, SortingMethod sortingMethod) {
    std::cout << "------Start sorting: " << sortingMethod << "------" << std::endl;

    auto efficiency = Timer().MarkTime([](TScanTable *scanTable, SortingMethod sortingMethod){return TSortTable(*scanTable, sortingMethod).GetEfficiencyIndicator();},
                                       scanTable, sortingMethod);

    std::cout << "Number of records " << scanTable->GetNumberOfEntries() << std::endl;
    std::cout << "The elapsed time is " << efficiency.first << " seconds" << std::endl;
    std::cout << "The number of operations spent is equal to " << efficiency.second << std::endl;

    std::cout << "------End sorting" << "------" << std::endl << std::endl;
}

