//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "program-memory.h"

ProgramMemory::ProgramMemory() {}

ProgramMemory::~ProgramMemory() {
  instructions_.clear();
}

Instruction ProgramMemory::read(int position) const {
  try {
    if (position < 0) {
      throw std::domain_error("could not read at a negative memory position.");
    }

    return instructions_.at(position);
  }
  // position is bigger than instructions size, so its a Halt instruction.
  catch (const std::out_of_range& oor) {
    return Instruction("HALT");
  }
}

void ProgramMemory::insert_instruction(const Instruction &instr) {
  instructions_.push_back(instr);
}

int ProgramMemory::size() const {
  return instructions_.size();
}

std::ostream &operator<<(std::ostream &os, const ProgramMemory &memory) {
  int i = 0;
  for (auto instruction: memory.instructions_) {
    os << "P[" << i << "] = " << instruction << '\n';
    ++i;
  }

  return os;
}
