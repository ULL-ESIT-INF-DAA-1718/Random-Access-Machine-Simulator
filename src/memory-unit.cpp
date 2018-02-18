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

MemoryUnit::~MemoryUnit() {}

int MemoryUnit::read_data(int position) const {
  return data_memory_.read(position);
}

void MemoryUnit::write_data(int position, int value) {
  data_memory_.write(position, value);
}

Instruction MemoryUnit::read_instruction(int position) const {
  return program_memory_.read(position);
}

unsigned MemoryUnit::get_program_pos(std::string tag) const {
  try {
    return tag_dictionary_.at(tag);
  }
  catch (std::out_of_range &oor) {
    throw std::invalid_argument(tag + " is not an specified tag.");
  }
}

unsigned MemoryUnit::get_original_program_line(int memory_program_line) const {
  try {
    return program_lines_dictionary_.at(memory_program_line);
  }
  catch (std::out_of_range &oor) {
    throw std::invalid_argument(std::to_string(memory_program_line) + " is not a valid position on program memory.");
  }
}

std::ostream &operator<<(std::ostream &os, const MemoryUnit &unit) {

  os << '\t' << "MEMORY UNIT" << '\n';
  os << std::setfill('=') << std::setw(20) << '\n';

  os << "• " << "data memory" << '\n';
  os << unit.data_memory_;
  os << std::setfill('-') << std::setw(20) << '\n';

  os << "• " << "program memory" << '\n';
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

// PRIVATE METHODS

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
