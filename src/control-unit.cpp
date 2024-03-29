//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "control-unit.h"

ControlUnit::ControlUnit(MemoryUnit *memory_unit,
                         TapeUnit *tape_unit,
                         unsigned *instruction_pointer) :

memory_unit_(memory_unit),
tape_unit_(tape_unit),
instruction_pointer_(instruction_pointer) {
  if (memory_unit_ == nullptr) {
    std::cerr <<"Memory unit pointer can't be null." << '\n';
    throw std::invalid_argument("error initializing control unit.");
  }
  if (tape_unit_ == nullptr) {
    std::cerr << "Tape unit pointer can't be null." << '\n';
    throw std::invalid_argument("error initializing control unit.");
  }
  if (instruction_pointer_ == nullptr) {
    std::cerr << "Instruction pointer can't be null." << '\n';
    throw std::invalid_argument("error initializing control unit.");
  }
}

void ControlUnit::execute_instruction(const Instruction &instruction) {
  switch (instruction.get_category()) {
    case MEMORY_OP:
      perform_memory_operation(instruction);
      break;
    case ARITHMETICAL_OP:
      perform_arithmetical_operation(instruction);
      break;
    case TAPE_OP:
      perform_tape_operation(instruction);
      break;
    case JUMP_OP:
      perform_jump_operation(instruction);
      break;
    default:
      break;
  }
}

// PRIVATE METHODS

int ControlUnit::read_with_addressing(const Instruction &instruction) const {
  Operand operand = instruction.get_operand();
  switch (operand.get_type()) {
    case CONSTANT: return operand.get_value();

    case DIRECT_ADDR: {

      if (instruction.get_opcode() == WRITE && operand.get_value() == ACC) {
        throw std::domain_error("WRITE could not use the ACC as destiny register.");
      }

      return memory_unit_->read_data(operand.get_value());
    }

    case INDIRECT_ADDR: {
      int effective_position = memory_unit_->read_data(operand.get_value());
      if (effective_position < 0) {
        std::cerr << "Indirect addressing produced error: ";
        std::cerr << "R[" << operand.get_value()<< "] = ";
        std::cerr << memory_unit_->read_data(operand.get_value()) << std::endl;
        throw std::domain_error("could not read at a negative memory position.");
      }

      if (instruction.get_opcode() == WRITE && effective_position == ACC) {
        std::cerr << "Indirect addressing produced error: ";
        std::cerr << "R[" << operand.get_value()<< "] = ";
        std::cerr << memory_unit_->read_data(operand.get_value()) << std::endl;
        throw std::domain_error("WRITE could not use the ACC as destiny register.");
      }

      return memory_unit_->read_data(effective_position);
    }
    default:break;
  }
}

void ControlUnit::write_with_addressing(const Instruction &instruction, int value) {
  Operand operand = instruction.get_operand();
  switch (operand.get_type()) {
    case CONSTANT:
      throw std::invalid_argument("could not write into a constant value.");

    case DIRECT_ADDR: {

      if (instruction.get_opcode() == READ && operand.get_value() == ACC) {
        throw std::domain_error("READ could not use the ACC as destiny resgiter.");
      }

      memory_unit_->write_data(operand.get_value(), value);
      break;
    }

    case INDIRECT_ADDR: {
      int effective_position = memory_unit_->read_data(operand.get_value());

      if (effective_position < 0) {
        std::cerr << "Indirect addressing produced error: ";
        std::cerr << "R[" << operand.get_value()<< "] = ";
        std::cerr << memory_unit_->read_data(operand.get_value()) << std::endl;
        throw std::domain_error("could not write at a negative memory position.");
      }

      if (instruction.get_opcode() == READ && effective_position == ACC) {
        std::cerr << "Indirect addressing produced error: ";
        std::cerr << "R[" << operand.get_value()<< "] = ";
        std::cerr << memory_unit_->read_data(operand.get_value()) << std::endl;
        throw std::domain_error("READ could not use the ACC as destiny resgiter.");
      }

      memory_unit_->write_data(effective_position, value);
      break;
    }
    default:break;
  }
}

// CATEGORY OPERATIONS.

void ControlUnit::perform_memory_operation(const Instruction &instruction) {
  switch (instruction.get_opcode()) {
    case LOAD: {
      int value_to_store = read_with_addressing(instruction);
      memory_unit_->write_data(ACC, value_to_store);
      break;
    }
    case STORE: {
      int value_to_store = memory_unit_->read_data(ACC);
      write_with_addressing(instruction, value_to_store);
      break;
    }
    default:
      break;
  }
}

void ControlUnit::perform_arithmetical_operation(const Instruction &instruction) {
  int acc_value = memory_unit_->read_data(ACC);
  int operand_value = read_with_addressing(instruction);
  int result = ArithmeticalLogicalUnit::perform_aritmetical_operation(acc_value,
                                                                      operand_value,
                                                                      instruction.get_opcode());
  memory_unit_->write_data(ACC, result);
}

void ControlUnit::perform_tape_operation(const Instruction &instruction) {
  switch (instruction.get_opcode()) {
    case READ: {
      int tape_value = tape_unit_->read();
      write_with_addressing(instruction, tape_value);
      break;
    }
    case WRITE: {
      int value_to_write = read_with_addressing(instruction);
      tape_unit_->write(value_to_write);
      break;
    }
    default:break;
  }
}

void ControlUnit::perform_jump_operation(const Instruction &instruction) {
  int acc_value = memory_unit_->read_data(ACC);
  if (ArithmeticalLogicalUnit::perform_logical_operation(acc_value, instruction.get_opcode())) {
    try {
      *instruction_pointer_ = memory_unit_->get_program_pos(instruction.get_tag());
    }
    catch (std::invalid_argument &ia) {
      std::cerr << instruction.get_tag() << " is undefined." << '\n';
      throw std::invalid_argument("trying to jump to an undefined tag.");
    }
  } else {
    *instruction_pointer_ = *instruction_pointer_ + 1;
  }
}


