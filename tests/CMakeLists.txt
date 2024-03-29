cmake_minimum_required(VERSION 3.20)
project(MOS_Tests)

set(CMAKE_CXX_STANDARD 23)
include(FetchContent)
FetchContent_Declare(
        googletest
        # Specify the commit you depend on and update it regularly.
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
add_executable(MOS_Tests Creature_Tests.cpp Skill_Tests.cpp Landscape_Tests.cpp)
target_link_libraries(MOS_Tests gtest_main)
find_library(LIB_PATH libMOS
        PATHS
        ../cmake-build-debug/)

target_include_directories(MOS_Tests PRIVATE ../)

TARGET_LINK_LIBRARIES( MOS_Tests ${LIB_PATH} )