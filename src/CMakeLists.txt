cmake_minimum_required(VERSION 3.20)
project(SchoolTable)

set(CMAKE_CXX_STANDARD 23)

add_executable(SchoolTable SchoolTableMain.cpp ../Input.h)
find_library(LIB_PATH libMOS
        PATHS
        ../cmake-build-debug/)

target_include_directories(SchoolTable PRIVATE ../)

TARGET_LINK_LIBRARIES( SchoolTable ${LIB_PATH} )