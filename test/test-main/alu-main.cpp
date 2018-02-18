//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "arithmetical-logical-unit.h"

int main(void) {
  std::cout << "Test ALU" << std::endl;

  std::cout << "Suma: ";
  std::cout << ArithmeticalLogicalUnit::perform_aritmetical_operation(2,3, ADD) << '\n';
  std::cout << "Resta: ";
  std::cout << ArithmeticalLogicalUnit::perform_aritmetical_operation(2, -9, SUB) << '\n';
  std::cout << "Mult: ";
  std::cout << ArithmeticalLogicalUnit::perform_aritmetical_operation(-52, 3, MUL) << '\n';
  std::cout << "Div: ";
  std::cout << ArithmeticalLogicalUnit::perform_aritmetical_operation(20, 3, DIV) << '\n';

  try {
    ArithmeticalLogicalUnit::perform_aritmetical_operation(2, 0, DIV) << '\n';
  }
  catch (std::domain_error &de) {
    std::cerr << de.what() << '\n';
  }

  try {
    ArithmeticalLogicalUnit::perform_aritmetical_operation(2, 0, HALT)<< '\n';
  }
  catch (std::invalid_argument &ia) {
    std::cerr << ia.what() << '\n';
  }

  std::cout << "jump: ";
  std::cout << ArithmeticalLogicalUnit::perform_logical_operation(0, JUMP) << '\n';
  std::cout << "jzero: ";
  std::cout << ArithmeticalLogicalUnit::perform_logical_operation(4, JZERO) << '\n';
  std::cout << "jzero: ";
  std::cout << ArithmeticalLogicalUnit::perform_logical_operation(0, JZERO) << '\n';
  std::cout << "jgtz: ";
  std::cout << ArithmeticalLogicalUnit::perform_logical_operation(0, JGTZ) << '\n';
  std::cout << "jgtz: ";
  std::cout << ArithmeticalLogicalUnit::perform_logical_operation(89, JGTZ) << '\n';

  try {
    ArithmeticalLogicalUnit::perform_logical_operation(2, DIV) << '\n';
  }
  catch (std::invalid_argument &de) {
    std::cerr << de.what();
  }
}