//
// Created by Cristian Abrante Dorta on 19/2/18.
//

#include "random-access-machine.h"

RandomAccessMachine::RandomAccessMachine(std::string &program_file_path,
                                         std::string &in_tape_file_path,
                                         std::string &out_tape_file_path) :
instruction_pointer_(0),
memory_unit_(program_file_path),
tape_unit_(in_tape_file_path, out_tape_file_path),
control_unit_(&memory_unit_, &tape_unit_, &instruction_pointer_),
program_file_path_(program_file_path) {}

void RandomAccessMachine::run(bool debug) {

  unsigned program_memory_line = 0;
  Instruction instruction =
      memory_unit_.read_instruction(instruction_pointer_);

  while (instruction.get_category() != HALT_OP) {
    try {

      if (debug) {
        system("clear");
        std::cout << *this;
        std::cout << std::setfill('=') << std::setw(26) << '\n';
        std::cout << "• " << "executed instructions: " << program_memory_line << '\n';
        std::cout << std::endl;
        std::cout << "Press enter to continue > ";
        std::cin.get();
        std::cout << std::setfill('=') << std::setw(26) << '\n';
      }

      control_unit_.execute_instruction(instruction);

      if (instruction.get_category() != JUMP_OP) {
        instruction_pointer_++;
      }

      instruction = memory_unit_.read_instruction(instruction_pointer_);

      program_memory_line++;

    }
    catch (std::invalid_argument &ia) {
      unsigned current_file_line = memory_unit_.get_original_program_line(program_memory_line);

      if (debug)
        system("clear");

      std::cerr << "Error at program file: " << program_file_path_ << '\n';
      std::cerr << "Line " << current_file_line << " : " << ia.what();

      std::cerr << '\n' << '\n';
      std::cerr << '|' << current_file_line << " >> "<< instruction;
      std::cerr << '\n' << '\n';

      throw std::invalid_argument("error running RAM machine.");
    }
    catch (std::domain_error &de) {
      unsigned current_file_line = memory_unit_.get_original_program_line(program_memory_line);

      if (debug)
        system("clear");

      std::cerr << "Error at program file: " << program_file_path_ << '\n';
      std::cerr << "Line " << current_file_line << " : " << de.what();

      std::cerr << '\n' << '\n';
      std::cerr << '|' << current_file_line << " >> "<< instruction;
      std::cerr << '\n' << '\n';

      throw std::invalid_argument("error running RAM machine.");
    }
  }

  std::cout << "Total executed instructions: " << program_memory_line;
  std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const RandomAccessMachine &machine) {

  os << std::setfill('*') << std::setw(23) << '\n';
  os << "RANDOM ACCESS MACHINE" << '\n';
  os << std::setfill('*') << std::setw(23) << '\n';

  os << machine.memory_unit_ << '\n';
  os << machine.tape_unit_ << '\n';

  os << std::setfill('=') << std::setw(26) << '\n';
  os << "• " << "INSTRUCTION POINTER = " << machine.instruction_pointer_ << '\n';

  return os;
}
