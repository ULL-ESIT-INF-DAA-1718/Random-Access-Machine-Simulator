cmake_minimum_required(VERSION 3.4)
project(ram_simulator)

set(CMAKE_CXX_STANDARD 11)

# Set global headers and sources
include_directories(include)
file(GLOB HEADER_FILES "include/*.h")
file(GLOB SOURCE_FILES "src/*.cpp")

# Set data memory test files
set(DATA_MEM_TEST src/data-memory.cpp include/data-memory.h)
set(OPERAND_TEST include/operand.h src/operand.cpp)
set(INSTRUCTION_TEST include/instruction.h src/instruction.cpp ${OPERAND_TEST})
set(PROG_MEM_TEST include/program-memory.h src/program-memory.cpp ${INSTRUCTION_TEST})
set(MEM_UNIT_TEST include/memory-unit.h src/memory-unit.cpp ${PROG_MEM_TEST} ${DATA_MEM_TEST})
set(TAPE_UNIT_TEST include/input-tape.h src/input-tape.cpp  include/output-tape.h src/output-tape.cpp include/tape-unit.h src/tape-unit.cpp)
set(ALU_UNIT_TEST include/arithmetical-logical-unit.h src/arithmetical-logical-unit.cpp ${INSTRUCTION_TEST})
set(CU_UNIT_TEST ${ALU_UNIT_TEST} ${MEM_UNIT_TEST} ${TAPE_UNIT_TEST} include/control-unit.h src/control-unit.cpp)
set(RAM_TEST ${CU_UNIT_TEST} include/random-access-machine.h src/random-access-machine.cpp)

add_executable(ram_simulator ${SOURCE_FILES})
add_executable(data-mem-test ${DATA_MEM_TEST}       test/test-main/data-main.cpp)
add_executable(operand_test ${OPERAND_TEST}         test/test-main/operand-main.cpp)
add_executable(instruction_test ${INSTRUCTION_TEST} test/test-main/instruction-main.cpp)
add_executable(prog_mem_test ${PROG_MEM_TEST}       test/test-main/prog-main.cpp)
add_executable(mem_unit_test ${MEM_UNIT_TEST}       test/test-main/mem-unit.cpp)
add_executable(tape_unit_test ${TAPE_UNIT_TEST}     test/test-main/tape-main.cpp)
add_executable(alu_unit_test ${ALU_UNIT_TEST}       test/test-main/alu-main.cpp)
add_executable(cu_unit_test ${CU_UNIT_TEST}         test/test-main/cu-main.cpp)
add_executable(ram_unit_test ${RAM_TEST} test/test-main/ram-main.cpp)
