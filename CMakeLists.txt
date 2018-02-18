cmake_minimum_required(VERSION 3.4)
project(ram_simulator)

set(CMAKE_CXX_STANDARD 11)

# Set global headers and sources
include_directories(include)
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

# Set data memory test files
set(DATA_MEM_TEST test/test-main/data-main.cpp src/data-memory.cpp include/data-memory.h)
set(OPERAND_TEST test/test-main/operand-main.cpp include/operand.h src/operand.cpp)
set(INSTRUCTION_TEST test/test-main/instruction-main.cpp include/instruction.h src/instruction.cpp include/operand.h src/operand.cpp)
set(PROG_MEM_TEST include/instruction.h src/instruction.cpp include/operand.h src/operand.cpp test/test-main/prog-main.cpp include/program-memory.h src/program-memory.cpp)
set(MEM_UNIT_TEST include/instruction.h src/instruction.cpp include/operand.h src/operand.cpp include/program-memory.h src/program-memory.cpp src/data-memory.cpp include/data-memory.h test/test-main/mem-unit.cpp include/memory-unit.h src/memory-unit.cpp)

add_executable(ram_simulator ${SOURCE_FILES})
add_executable(data-mem-test ${DATA_MEM_TEST})
add_executable(operand_test ${OPERAND_TEST})
add_executable(instruction_test ${INSTRUCTION_TEST})
add_executable(prog_mem_test ${PROG_MEM_TEST})
add_executable(mem_unit_test ${MEM_UNIT_TEST})
