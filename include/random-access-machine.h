//
// Created by Cristian Abrante Dorta on 19/2/18.
//

#ifndef RAM_SIMULATOR_RANDOM_ACCESS_MACHINE_H
#define RAM_SIMULATOR_RANDOM_ACCESS_MACHINE_H

#include <ostream>
#include "control-unit.h"

class RandomAccessMachine {

 public:

  RandomAccessMachine(std::string &program_file_path,
                        std::string &in_tape_file_path,
                        std::string &out_tape_file_path);

  void run(bool debug = false);

  friend std::ostream &operator<<(std::ostream &os, const RandomAccessMachine &machine);

 private:

  // Control unit of the RAM
  ControlUnit control_unit_;

  // Memory unit of the RAM
  MemoryUnit memory_unit_;

  // Tape unit of the RAM
  TapeUnit  tape_unit_;

  // instruction pointer of the RAM.
  unsigned instruction_pointer_;

  // program file used to show errors.
  std::string program_file_path_;
};

#endif //RAM_SIMULATOR_RANDOM_ACCESS_MACHINE_H
