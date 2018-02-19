//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_MEMORY_UNIT_H
#define RAM_SIMULATOR_MEMORY_UNIT_H

#include <fstream>
#include <ostream>
#include <iomanip>

#include "data-memory.h"
#include "program-memory.h"

// position of ACC
const int ACC = 0;

/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents the memory unit of
 *        the random access machine.
 *
 */
class MemoryUnit {
 public:
  /**
   * @brief Constructor of the class.
   * @details file that contains program must be specified.
   *
   * @param program_file_path
   *
   * @throw std::invalid_argument if an error happen
   *        creating and storing instructions. (Well specified at std::cerr).
   *
   * @throw std::invalid_argument if an error happen opening the program file.
   */
  MemoryUnit(const std::string &program_file_path);

  /**
   * @brief destructor of the class.
   */
  virtual ~MemoryUnit();

  /**
   * @brief read data from data memory at position.
   *
   * @param position
   * @return data stored at position
   *
   * @throw std::domain_error if position < 0.
   */
  int read_data(int position) const;

  /**
   * @brief write data at data memory at position.
   *
   * @param position
   * @param value
   *
   * @throw std::domain_error if position < 0.
   */
  void write_data(int position, int value);

  /**
   * @brief read instruction at a specified position.
   *
   * @param position
   * @return instruction read at position.
   *
   * @throw std::domain_error if position < 0.
   */
  Instruction read_instruction(int position) const;

  /**
   * @brief return the program memory position given a tag.
   *
   * @param tag
   * @return
   *
   * @throw std::invalid_argument if tag is never used at program.
   */
  unsigned get_program_pos(std::string tag) const;

  /**
   * @brief return the original program line, given a program memory position.
   *
   * @param memory_program_line
   * @return
   *
   * @throw std::invalid_argument if memory_program_line is not a line of program.
   */
  unsigned get_original_program_line(int memory_program_line) const;

  /**
   * @brief Friend method that prints the memory unit into a stream.
   *        Only used registers are printed.
   *
   * @param os
   * @param dm
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const MemoryUnit &unit);

 private:
  // Data memory of the unit.
  DataMemory data_memory_;

  // Program memory of the unit.
  ProgramMemory program_memory_;

  // Hash map used to store the equivalence between tags and positions
  // at program memory.
  std::map<std::string, unsigned int> tag_dictionary_;

  // Hash map used to store the equivalence between
  // program memory lines and original file lines.
  std::map<unsigned int, unsigned int> program_lines_dictionary_;

  // Comments delimiter.
  const char COMMENT_DELIMITER = '#';

  // process the instruction to determine if it is a comment or not.
  bool process_instruction(const std::string instruction);
};

#endif //RAM_SIMULATOR_MEMORY_UNIT_H
