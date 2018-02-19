//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_CONTROL_UNIT_H
#define RAM_SIMULATOR_CONTROL_UNIT_H

#include "memory-unit.h"
#include "tape-unit.h"
#include "arithmetical-logical-unit.h"

/**
 * @author Cristian Abrante Dorta
 * @date 18/02/2018
 *
 * @class this class represent the control unit of the random access machine.
 */

class ControlUnit {

 public:

  /**
   * @brief Constructor of the class
   *
   * @param memory_unit
   * @param tape_unit
   * @param instruction_pointer
   *
   * @throw std::invalid_argument if any argument is nulptr.
   */
  ControlUnit(MemoryUnit *memory_unit, TapeUnit *tape_unit, unsigned *instruction_pointer);

  /**
   * @brief Execute given instruction.
   *
   * @param instruction
   *
   * @throw std::invalid_argument if there is any logic error or with addressing errors.
   * @throw std::domain_error if there is any arithmetical operation which takes parameters out of domain.
   */
  void execute_instruction(const Instruction &instruction);

 private:
  // pointer to the memory unit.
  MemoryUnit *memory_unit_;

  // pointer to the tape unit.
  TapeUnit *tape_unit_;

  // pointer to the ip.
  unsigned *instruction_pointer_;

  // read from memory depending on the addressing of operand.
  int read_with_addressing(const Instruction &instruction) const;

  // write at memory depending on the addressing of operand.
  void write_with_addressing(const Instruction &instruction, int value);

  // execute a MEMORY_OP operation.
  void perform_memory_operation(const Instruction &instruction);

  // execute a ARITHMETICAL_OP operation.
  void perform_arithmetical_operation(const Instruction &instruction);

  // execute a TAPE_OP operation.
  void perform_tape_operation(const Instruction &instruction);

  // execute a JUMP_OP operation.
  void perform_jump_operation(const Instruction &instruction);
};

#endif //RAM_SIMULATOR_CONTROL_UNIT_H
