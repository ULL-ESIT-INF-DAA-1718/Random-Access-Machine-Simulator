//
// Created by Cristian Abrante Dorta on 19/2/18.
//

#ifndef RAM_SIMULATOR_RANDOM_ACCESS_MACHINE_H
#define RAM_SIMULATOR_RANDOM_ACCESS_MACHINE_H

#include <ostream>
#include "control-unit.h"

/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents a random access machine.
 *
 */
class RandomAccessMachine {

 public:
  /**
   * @brief constructor that initializes all components of RAM.
   *
   * @param program_file_path
   * @param in_tape_file_path
   * @param out_tape_file_path
   *
   * @throw std::invalid_argument if happens any problem during initialization.
   */
  RandomAccessMachine(std::string &program_file_path,
                        std::string &in_tape_file_path,
                        std::string &out_tape_file_path);

  /**
   * @brief execute program of program memory.
   *
   * @param debug interactive version flag.
   */
  void run(bool debug = false);

  /**
   * @brief Friend method that prints the RAM into a stream.
   *
   * @param os
   * @param machine
   * @return the same stream os.
   */
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
