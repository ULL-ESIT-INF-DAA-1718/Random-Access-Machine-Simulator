//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#include "operand.h"

Operand::Operand() {
  value_ = NULL;
  type_ = EMPTY_OPERAND;
}

Operand::Operand(std::string operand_definition) {
  try {

    if (operand_definition.empty()) {
      throw std::length_error("operand definition can't be empty");
    }

    switch (operand_definition[0]) {
      case '=':
        type_ = CONSTANT;
        operand_definition.erase(operand_definition.begin());
        value_ = std::stod(operand_definition);
        break;
      case '*':
        type_ = INDIRECT_ADDR;
        operand_definition.erase(operand_definition.begin());
        value_ = std::stoi(operand_definition);
        break;
      default:
        type_ = DIRECT_ADDR;
        value_ = std::stoi(operand_definition);
    }
  }
  catch (std::invalid_argument &e) {
    throw std::invalid_argument("operand must start with a number");
  }

  if (value_ < 0) {
    if (type_ == DIRECT_ADDR) {
      throw std::invalid_argument("direct addressing don't allow negative memory positions.");
    }
    if (type_ == INDIRECT_ADDR) {
      throw std::invalid_argument("indirect addressing don't allow negative memory positions.");
    }
  }
}

Operand::~Operand() {
  type_ = CONSTANT;
  value_ = 0;
}

double Operand::get_value() const {
  return value_;
}

OperandType Operand::get_type() const {
  return type_;
}

bool Operand::empty() const {
  return type_ == EMPTY_OPERAND;
}

std::ostream &operator<<(std::ostream &os, const Operand &operand) {
  switch (operand.type_) {
    case CONSTANT:
      os << '=';
      break;
    case INDIRECT_ADDR:
      os << '*';
  }
  os << operand.value_;
  return os;
}


