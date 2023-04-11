cmake_minimum_required(VERSION 3.24)
project(Tables)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        Tables
        main.cpp
        source/utility/TDataValue.cpp include/utility/TDataValue.h
        source/utility/TTableRecord.cpp include/utility/TTableRecord.h
        source/utility/TTable.cpp include/utility/TTable.h
        source/utility/TDatCom.cpp include/utility/TDatCom.h source/utility/TArrayTable.cpp include/utility/TArrayTable.h source/storage-structure/TScanTable.cpp include/storage-structure/TScanTable.h source/data-structure/TWordsInWarAndPeace.cpp include/data-structure/TWordsInWarAndPeace.h source/utility/InputHandler.cpp include/utility/InputHandler.h source/utility/perfomance-testing/Timer.cpp include/utility/perfomance-testing/Timer.h source/utility/Writer.cpp include/utility/Writer.h source/utility/perfomance-testing/TestingTScanTable.cpp include/utility/perfomance-testing/TestingTScanTable.h)
