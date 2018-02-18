//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "memory-unit.h"

MemoryUnit::MemoryUnit(const std::string &program_file_path) {

  std::ifstream ifs(program_file_path);

  if (ifs.is_open()) {

    // used to store program line.
    int current_file_line = 1;
    std::string instruction;

    while (std::getline(ifs, instruction)) {

      std::size_t pos = instruction.find_first_not_of(" \t\n\r");

      if (pos != std::string::npos) {

        instruction.erase(0, pos);
        try {
          if (process_instruction(instruction)) {
            program_lines_dictionary_[program_memory_.size() - 1] = current_file_line;
          }
        }
        catch (std::invalid_argument &ia) {
          std::cerr << "Error at program file: " << program_file_path << '\n';
          std::cerr << "Line " << current_file_line << ": ";
          std::cerr << ia.what() << '\n' << '\n';
          std::cerr << '|' << current_file_line << " >> ";
          std::cerr << instruction << '\n' << '\n';

          throw std::invalid_argument("error initializing program memory.");
        }
      }

      current_file_line++;
    }
  } else {
    std::cerr << "Error opening program file " + program_file_path << std::endl;
    throw std::invalid_argument("error initializing program memory.");
  }
}

bool MemoryUnit::process_instruction(const std::string instruction) {
  if (instruction[0] != COMMENT_DELIMITER) {
    std::string instruction_tag;
    Instruction ins(instruction, &instruction_tag);

    program_memory_.insert_instruction(ins);

    if (!instruction_tag.empty()) {
      if (tag_dictionary_.find(instruction_tag) == tag_dictionary_.end()) {
        tag_dictionary_[instruction_tag] = program_memory_.size() - 1;
      } else {
        throw std::invalid_argument("program can't have duplicated tags.");
      }
    }

    return true;
  } else {
    return false;
  }
}

std::ostream &operator<<(std::ostream &os, const MemoryUnit &unit) {

  os << '\t' << "MEMORY UNIT" << '\n';
  os << std::setfill('-') << std::setw(20) << '\n';

  os << "➞ " << "data memory" << '\n';
  os << unit.data_memory_;
  os << std::setfill('-') << std::setw(20) << '\n';

  os << "➞ " << "program memory" << '\n';
  os << unit.program_memory_;
  os << std::setfill('-') << std::setw(20) << '\n';

  /*
  os << "➞ " << "tag equivalence" << '\n';
  os << '{';
  for (auto it = unit.tag_dictionary_.begin(); it != unit.tag_dictionary_.end(); it++) {
    os << it->first << " -> " << it->second << ", ";
  }
  os << '}' << '\n';
  os << "➞ " << "tag equivalence" << '\n';
  os << '{';
  for (auto it = unit.program_lines_dictionary_.begin(); it != unit.program_lines_dictionary_.end(); it++) {
    os << it->first << " -> " << it->second << ", ";
  }
  os << '}' << '\n';
  os << std::setfill('-') << std::setw(20) << '\n';
  */

  return os;
}
