//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_PROGRAM_MEMORY_H
#define RAM_SIMULATOR_PROGRAM_MEMORY_H

#include <ostream>

#include "instruction.h"


/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents the program memory
 *        of the memory unit at the random access machine.
 *
 */
class ProgramMemory {

 public:

  /**
   * @brief Default constructor of the class.
   *        The infinite registers of the memory are set to HALT instruction.
   */
  ProgramMemory();

  /**
   * @brief Destructor of the class.
   */
  virtual ~ProgramMemory();

  /**
   * @brief Read form memory at specified position.
   *
   * @param position
   * @return instruction stored at position.
   *
   * @throw std::domain_error if position < 0;
   */
  Instruction read(int position) const;

  /**
   * @brief Insert instruction at next register.
   *
   * @param instr
   */
  void insert_instruction(const Instruction &instr);

  /**
   * @brief Friend method that prints the memory into a stream.
   *        Only used registers are printed.
   *
   * @param os
   * @param dm
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const ProgramMemory &memory);

 private:

  // vector that contains the instructions of the program.
  std::vector<Instruction> instructions_;
};

#endif //RAM_SIMULATOR_PROGRAM_MEMORY_H
