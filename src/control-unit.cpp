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
    // TODO: handle null pointer error.
  }
  if (tape_unit_ == nullptr) {
    // TODO: handle null pointer error.
  }
  if (instruction_pointer_ == nullptr) {
    // TODO: handle null pointer error.
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
    // TODO: HANDLE WITH error instruction.
  }
}

// PRIVATE METHODS

// TODO: std::domain_error en el direccionamiento directo. pos < 0
// TODO: std::domain_error en el direccionamiento indirecto. pos < 0
int ControlUnit::read_with_addressing(Operand operand) const {
  switch (operand.get_type()) {

    case CONSTANT: return operand.get_value();

    case DIRECT_ADDR: {
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

      return memory_unit_->read_data(effective_position);
    }
  }
}

// TODO: error en la constante.
// TODO: std::domain_error en el direccionamiento directo. pos < 0
// TODO: std::domain_error en el direccionamiento indirecto. pos < 0
void ControlUnit::write_with_addressing(Operand operand, int value) {
  switch (operand.get_type()) {

    case CONSTANT: break;
        // TODO: Handling write on constant error.

    case DIRECT_ADDR: {
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
      memory_unit_->write_data(effective_position, value);
      break;
    }
  }
}

// CATEGORY OPERATIONS.

void ControlUnit::perform_memory_operation(const Instruction &instruction) {
  switch (instruction.get_opcode()) {
    case LOAD: {
      int value_to_store = read_with_addressing(instruction.get_operand());
      memory_unit_->write_data(ACC, value_to_store);
    }
    case STORE: {
      int value_to_store = memory_unit_->read_data(ACC);
      write_with_addressing(instruction.get_operand(), value_to_store);
    }
    default:
      // TODO: Incorrect category error.
      break;
  }
}

// TODO: error al leer operando. pos < 0
// TODO: error al dividir por 0.
// TODO: operación no aritmética.
void ControlUnit::perform_arithmetical_operation(const Instruction &instruction) {
  int acc_value = memory_unit_->read_data(ACC);
  int operand_value = read_with_addressing(instruction.get_operand());

  int result = ArithmeticalLogicalUnit::perform_aritmetical_operation(acc_value,
                                                                      operand_value,
                                                                      instruction.get_opcode());
  memory_unit_->write_data(ACC, result);
}

void ControlUnit::perform_tape_operation(const Instruction &instruction) {
  switch (instruction.get_opcode()) {
    case READ: {
      int tape_value = tape_unit_->read();
      write_with_addressing(instruction.get_operand(), tape_value);
      break;
    }
    case WRITE: {
      // TODO: handling error with indirect addressing.
      int value_to_write = read_with_addressing(instruction.get_operand());
      tape_unit_->write(value_to_write);
    }
    default:break;
      // TODO: handling error with incorrect operand.
  }
}

// TODO: Error with unused tags.
void ControlUnit::perform_jump_operation(const Instruction &instruction) {
  int acc_value = memory_unit_->read_data(ACC);
  if (ArithmeticalLogicalUnit::perform_logical_operation(acc_value,
                                                         instruction.get_opcode())) {
    *instruction_pointer_ = memory_unit_->get_program_pos(instruction.get_tag());
  }
}


