//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#include "instruction.h"
Instruction::Instruction(const std::string &instruction_definition, std::string *instruction_tag) {

  std::vector<std::string> instruction_parts = split_definition(instruction_definition);

  switch (instruction_parts.size()) {
    case 0:
      throw std::invalid_argument("empty line don't describe an instruction.");
    case 1:
      process_1_operand_instruction(instruction_parts);
      break;
    case 2:

      if (process_instruction_tag(instruction_parts[0],
                                  instruction_tag,
                                  instruction_parts)) {
        process_1_operand_instruction(instruction_parts);
      } else {
        process_2_operands_instruction(instruction_parts);
      }

      break;
    case 3:

      // Instruction tags must finish with :
      if (process_instruction_tag(instruction_parts[0],
                                  instruction_tag,
                                  instruction_parts)) {
        process_2_operands_instruction(instruction_parts);
      } else {
        throw std::invalid_argument(instruction_parts[0] + " is not a valid tag name (must end with ':').");
      }

      // Tag deleted
      instruction_parts.erase(instruction_parts.begin());

      break;
    default:
      throw std::invalid_argument("instructions can't have more than 3 fields.");
  }
}

Opcode Instruction::get_opcode() const {
  return opcode_;
}

Category Instruction::get_category() const {
  return category_;
}

const Operand &Instruction::get_operand() const {
  return operand_;
}

const std::string &Instruction::get_tag() const {
  return tag_;
}

std::ostream &operator<<(std::ostream &os, const Instruction &instruction) {

  os << Instruction::opcode_to_string(instruction.opcode_) << ' ';

  switch (instruction.category_) {
    case MEMORY_OP:
    case ARITHMETICAL_OP:
    case TAPE_OP:
      os << instruction.operand_;
      break;
    case JUMP_OP:
      os << instruction.tag_;
      break;
    case HALT_OP:
      break;
    case ERROR_OP:break;
  }

  return os;
}

// PRIVATE METHODS

std::vector<std::string> Instruction::split_definition(const std::string &instruction_definition) const {

  std::string buffer = "";
  std::vector<std::string> instr_parts;

  for (auto instr_chr: instruction_definition) {
    if (instr_chr != ' ' && instr_chr != '\t' && instr_chr != '\r' && instr_chr != '#') {
      if (instr_chr != '#') {
        buffer += instr_chr;
      }
    } else {
      if (!buffer.empty()) {
        instr_parts.push_back(uppercase_string(buffer));
        buffer.clear();
      }
      if (instr_chr == '#')
        break;
    }
  }

  if (!buffer.empty()) {
    instr_parts.push_back(uppercase_string(buffer));
  }

  return instr_parts;
}

std::string Instruction::uppercase_string(const std::string &str) const {
  std::locale loc;
  std::string upper_str;

  for (int i = 0; i < str.size(); i++) {
    upper_str.push_back(std::toupper(str[i],loc));
  }
  return upper_str;
}

bool Instruction::process_instruction_tag(std::string &tag,
                                          std::string *instruction_tag,
                                          std::vector<std::string> &instruction_parts) const {
  if (tag.back() == ':') {
    tag.pop_back();

    if (instruction_tag != nullptr)
      *instruction_tag = instruction_parts[0];

    // Tag deleted
    instruction_parts.erase(instruction_parts.begin());
    return true;
  } else {
    return false;
  }
}

void Instruction::process_1_operand_instruction(std::vector<std::string> instruction_parts) {
  if (instruction_parts[0] == "HALT") {
    opcode_ = HALT;
    category_ = HALT_OP;
  } else {
    throw std::invalid_argument(instruction_parts[0] + " with no arguments is not a correct instruction.");
  }
}

void Instruction::process_2_operands_instruction(std::vector<std::string> instruction_parts) {

  opcode_ = Instruction::string_to_opcode(instruction_parts[0]);
  if (opcode_ == ERROR_OPCODE) {
    throw std::invalid_argument(instruction_parts[0] + " with 1 argument is not a correct instruction.");
  }

  category_ = opcode_category(opcode_);

  switch (category_) {
    case MEMORY_OP:
    case ARITHMETICAL_OP:
    case TAPE_OP:
      operand_ = Operand(instruction_parts[1]);
      break;
    case JUMP_OP:
      tag_ = instruction_parts[1];
      break;
    case HALT_OP:
      throw std::invalid_argument("instruction HALT can't have arguments.");
    case ERROR_OP:
      throw std::invalid_argument("something extrange happened.");
      break;
  }

}

// STATIC METHODS

Opcode Instruction::string_to_opcode(std::string opcode) {
  for (int opd = 0; opd < NUMBER_OF_OPERATIONS; opd++) {
    if (opcode == opcode_to_string((Opcode) opd))
      return (Opcode) opd;
  }
  return ERROR_OPCODE;
}

std::string Instruction::opcode_to_string(Opcode op) {
  switch (op) {
    case LOAD:  return "LOAD";
    case STORE: return "STORE";
    case ADD:   return "ADD";
    case SUB:   return "SUB";
    case MUL:   return "MUL";
    case DIV:   return "DIV";
    case READ:  return "READ";
    case WRITE: return "WRITE";
    case JUMP:  return "JUMP";
    case JZERO: return "JZERO";
    case JGTZ:  return "JGTZ";
    case HALT:  return "HALT";

    // in case operand is casted over the limits of Opcode.
    default:
      return "";
  }
}

Category Instruction::opcode_category(Opcode op) {
  switch (op) {
    case LOAD:
    case STORE:
      return MEMORY_OP;

    case ADD:
    case SUB:
    case MUL:
    case DIV:
      return ARITHMETICAL_OP;

    case READ:
    case WRITE:
      return TAPE_OP;

    case JUMP:
    case JZERO:
    case JGTZ:
      return JUMP_OP;

    case HALT:
      return HALT_OP;

    case ERROR_OPCODE:
      return ERROR_OP;
  }
}
