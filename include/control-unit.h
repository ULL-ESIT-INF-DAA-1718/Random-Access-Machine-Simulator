//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_CONTROL_UNIT_H
#define RAM_SIMULATOR_CONTROL_UNIT_H

#include "memory-unit.h"
#include "tape-unit.h"
#include "arithmetical-logical-unit.h"

class ControlUnit {

 public:

  ControlUnit(MemoryUnit *memory_unit, TapeUnit *tape_unit, unsigned *instruction_pointer);

  void execute_instruction(const Instruction &instruction);

 private:

  MemoryUnit *memory_unit_;
  TapeUnit *tape_unit_;
  unsigned *instruction_pointer_;

  int read_with_addressing(Operand operand) const;

  void write_with_addressing(Operand operand, int value);

  void perform_memory_operation(const Instruction &instruction);

  void perform_arithmetical_operation(const Instruction &instruction);
};

#endif //RAM_SIMULATOR_CONTROL_UNIT_H
