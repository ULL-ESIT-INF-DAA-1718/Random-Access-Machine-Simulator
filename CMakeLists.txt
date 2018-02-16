cmake_minimum_required(VERSION 3.4)
project(ram_simulator)

set(CMAKE_CXX_STANDARD 11)

# Set global headers and sources
include_directories(include)
file(GLOB SOURCE_FILES "src/*.cc")

# Set data memory test files
set(DATA_MEM_TEST test/test-main/data-main.cc src/data-memory.cc)

add_executable(ram_simulator ${SOURCE_FILES})
add_executable(data-mem-test ${DATA_MEM_TEST})