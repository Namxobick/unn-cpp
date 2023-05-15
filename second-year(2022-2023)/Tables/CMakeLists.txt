cmake_minimum_required(VERSION 3.24)
project(Tables)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        Tables
        main.cpp
        source/data-structure/utility/TDataValue.cpp include/data-structure/utility/TDataValue.h
        source/data-structure/utility/TTableRecord.cpp include/data-structure/utility/TTableRecord.h
        source/storage-structure/utility/TTable.cpp include/storage-structure/utility/TTable.h
        source/data-structure/utility/TDatCom.cpp include/data-structure/utility/TDatCom.h
        source/storage-structure/utility/TArrayTable.cpp include/storage-structure/utility/TArrayTable.h
        source/storage-structure/TScanTable.cpp include/storage-structure/TScanTable.h
        source/data-structure/TWordsInWarAndPeace.cpp include/data-structure/TWordsInWarAndPeace.h
        source/utility/IO/InputHandler.cpp include/utility/IO/InputHandler.h
        source/utility/perfomance-testing/Timer.cpp include/utility/perfomance-testing/Timer.h
        source/utility/IO/Writer.cpp include/utility/IO/Writer.h
        source/utility/perfomance-testing/TestingTable.cpp include/utility/perfomance-testing/TestingTable.h
        source/storage-structure/TSortTable.cpp include/storage-structure/TSortTable.h
        source/utility/sorting/BubbleSort.cpp include/utility/sorting/BubbleSort.h
        source/utility/sorting/InsertionSort.cpp include/utility/sorting/InsertionSort.h
        source/utility/sorting/QuickSort.cpp include/utility/sorting/QuickSort.h
        source/utility/sorting/MergeSort.cpp include/utility/sorting/MergeSort.h
        source/utility/sorting/HeapSort.cpp include/utility/sorting/HeapSort.h
        source/utility/perfomance-testing/TestingConversion.cpp include/utility/perfomance-testing/TestingConversion.h
        source/storage-structure/utility/THashTable.cpp include/storage-structure/utility/THashTable.h
        source/storage-structure/TListHashTable.cpp include/storage-structure/TListHashTable.h
        include/utility/hash-function/IHashFunction.h
        source/utility/hash-function/StringHashFunction.cpp include/utility/hash-function/StringHashFunction.h
        include/utility/sorting/ISorting.h
        source/utility/sorting/StdSort.cpp include/utility/sorting/StdSort.h
        source/utility/MyException.cpp include/utility/MyException.h)
