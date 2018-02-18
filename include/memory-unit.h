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

class MemoryUnit {
 public:

  MemoryUnit(const std::string &program_file_path);

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

  const char COMMENT_DELIMITER = '#';

  bool process_instruction(const std::string instruction);
};

#endif //RAM_SIMULATOR_MEMORY_UNIT_H
