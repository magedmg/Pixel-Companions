cmake_minimum_required(VERSION 3.14)
project(game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

# Set default build type to Debug if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Compiler flags for build types
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Fetch raylib if not found
find_package(raylib QUIET)
if (NOT raylib_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib GIT_REPOSITORY https://github.com/raysan5/raylib.git GIT_TAG 5.0)
    FetchContent_MakeAvailable(raylib)
endif()

# Fetch raylib-cpp if not found
find_package(raylib_cpp QUIET)
if (NOT raylib_cpp_FOUND)
    include(FetchContent)
    FetchContent_Declare(raylib_cpp GIT_REPOSITORY https://github.com/RobLoach/raylib-cpp.git GIT_TAG v5.0.1)
    FetchContent_MakeAvailable(raylib_cpp)
endif()

# Project files
file(GLOB_RECURSE SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

# Build game executable
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/src/unit-testing/TestFile.cpp)
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} raylib raylib_cpp)

# Build test executable
list(REMOVE_ITEM SOURCES ${CMAKE_SOURCE_DIR}/src/main.cpp)
add_executable(test ${CMAKE_SOURCE_DIR}/src/unit-testing/TestFile.cpp ${SOURCES})
target_link_libraries(test raylib raylib_cpp)
target_compile_definitions(test PRIVATE BUILD_TEST_RUNNER)