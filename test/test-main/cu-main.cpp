//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "control-unit.h"

int main(void) {
  std::cout << "Control Unit test" << std::endl;

  MemoryUnit mem("../test/tests_ram/test1.ram");
  TapeUnit tape("../test/tape_test/test1.tape", "../test/tape_test/otest.tape");
  int ip = 0;

  int line_counter = 28;
  Instruction ins("LOAD -3");
  try {
    ControlUnit cu(&mem, &tape, nullptr);
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 1"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =-5"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 2"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =8"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =2"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 4"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD *4"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE *3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("SUB =3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("MUL *3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("ADD 8"));
    std::cout << mem;

    cu.execute_instruction(Instruction("DIV *3"));
    std::cout << mem;
  }
  catch(std::domain_error &de) {
    std::cerr << "Error at line " << line_counter << ": ";
    std::cerr << de.what() << std::endl;
    std::cerr << '|' << line_counter << " >> ";
    std::cerr << ins << '\n' << '\n';
  }
  catch (std::logic_error &le) {

  }
}