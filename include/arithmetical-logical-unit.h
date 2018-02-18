//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_ARITHMETICAL_LOGICAL_UNIT_H
#define RAM_SIMULATOR_ARITHMETICAL_LOGICAL_UNIT_H

#include "instruction.h"

/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents the operation of an ALU
 *        unit at random Access Machine.
 */

class ArithmeticalLogicalUnit {
 public:

  /**
   * @brief perform an arithmetical operation.
   *
   * @param first_op
   * @param second_op
   * @param operation could be ADD, SUB, MUL, DIV
   * @return the result of the operation.
   *
   * @throw std::domain_error if operation is DIV and second_op is zero.
   * @throw std::invalid_argument if operation is not arithmetical.
   */
  static int perform_aritmetical_operation(int first_op, int second_op, Opcode operation);

  /**
   * @brief perform a logical operation.
   *
   * @param acc
   * @param operation could be JUMP, JZERO, JGTZ
   * @return the result of the operation.
   *
   * @throw std::invalid_argument if operation is not logical.
   */
  static int perform_logical_operation(int acc, Opcode operation);
};

#endif //RAM_SIMULATOR_ARITHMETICAL_LOGICAL_UNIT_H
