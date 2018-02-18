//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "arithmetical-logical-unit.h"

int ArithmeticalLogicalUnit::perform_aritmetical_operation(int first_op, int second_op, Opcode operation) {
  switch (operation) {
    case ADD:return first_op + second_op;
    case SUB:return first_op - second_op;
    case MUL:return first_op * second_op;
    case DIV:
      if (second_op == 0) {
        throw std::domain_error("denominator of division can't be zero.");
      } else {
        return first_op / second_op;
      }
    default:
      throw std::invalid_argument(Instruction::opcode_to_string(operation) + " is not a valid arithmetical operation.");
  }
}

int ArithmeticalLogicalUnit::perform_logical_operation(int acc, Opcode operation) {
  switch (operation) {
    case JUMP: return true;
    case JZERO:return acc == 0;
    case JGTZ: return acc > 0;
    default:
      throw std::invalid_argument(Instruction::opcode_to_string(operation) + " is not a valid arithmetical operation.");
  }
}
