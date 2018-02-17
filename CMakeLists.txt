cmake_minimum_required(VERSION 3.4)
project(ram_simulator)

set(CMAKE_CXX_STANDARD 11)

# Set global headers and sources
include_directories(include)
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

# Set data memory test files
set(DATA_MEM_TEST test/test-main/data-main.cpp src/data-memory.cpp include/data-memory.h)
set(RAM_TEST)
set(ALU_TEST)

add_executable(ram_simulator ${SOURCE_FILES})
add_executable(data-mem-test ${DATA_MEM_TEST})
