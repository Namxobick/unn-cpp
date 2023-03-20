cmake_minimum_required(VERSION 3.24)
project(Tables)

set(CMAKE_CXX_STANDARD 23)

add_executable(Tables main.cpp source/TDataValue.cpp include/TDataValue.h source/TTableRecord.cpp include/TTableRecord.h source/TTable.cpp include/TTable.h)
