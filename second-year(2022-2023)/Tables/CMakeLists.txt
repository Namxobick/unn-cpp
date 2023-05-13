cmake_minimum_required(VERSION 3.24)
project(Tables)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        Tables
        main.cpp
        source/utility/TDataValue.cpp include/utility/TDataValue.h
        source/utility/TTableRecord.cpp include/utility/TTableRecord.h
        source/utility/TTable.cpp include/utility/TTable.h
        source/utility/TDatCom.cpp include/utility/TDatCom.h
        source/utility/TArrayTable.cpp include/utility/TArrayTable.h
        source/storage-structure/TScanTable.cpp include/storage-structure/TScanTable.h
        source/data-structure/TWordsInWarAndPeace.cpp include/data-structure/TWordsInWarAndPeace.h
        source/utility/IO/InputHandler.cpp include/utility/IO/InputHandler.h
        source/utility/perfomance-testing/Timer.cpp include/utility/perfomance-testing/Timer.h
        source/utility/IO/Writer.cpp include/utility/IO/Writer.h
        source/utility/perfomance-testing/TestingTable.cpp include/utility/perfomance-testing/TestingTable.h
        source/storage-structure/TSortTable.cpp include/storage-structure/TSortTable.h
        source/utility/sorting/Sorting.cpp include/utility/sorting/Sorting.h
        source/utility/sorting/BubbleSort.cpp include/utility/sorting/BubbleSort.h
        source/utility/sorting/InsertionSort.cpp include/utility/sorting/InsertionSort.h
        source/utility/sorting/QuickSort.cpp include/utility/sorting/QuickSort.h
        source/utility/sorting/MergeSort.cpp include/utility/sorting/MergeSort.h
        source/utility/sorting/HeapSort.cpp include/utility/sorting/HeapSort.h
        source/utility/perfomance-testing/TestingConversion.cpp include/utility/perfomance-testing/TestingConversion.h
        source/utility/THashTable.cpp include/utility/THashTable.h
        source/storage-structure/TListHashTable.cpp include/storage-structure/TListHashTable.h
)
