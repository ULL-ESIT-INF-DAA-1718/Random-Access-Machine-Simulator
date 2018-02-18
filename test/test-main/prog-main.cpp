//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>

#include "program-memory.h"

int main(void) {

  std::cout << "Program Memory Tests" << std::endl;

  Instruction i0("READ -4");
  Instruction i1("MUL 5");
  Instruction i2("LOAD =4");

  ProgramMemory pr;

  pr.insert_instruction(i0);
  pr.insert_instruction(i1);
  pr.insert_instruction(i2);

  std::cout << pr << '\n';
  std::cout << pr.read(0) << '\n';
  std::cout << pr.read(2) << '\n';
  std::cout << pr.read(48) << '\n';

  try {
    std::cout << pr.read(-6) << '\n';
  }
  catch (std::domain_error &de) {
    std::cerr << "Error at line 29: " << de.what() << std::endl;
  }
}