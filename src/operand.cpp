//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#include "operand.h"

Operand::Operand(std::string operand_definition) {
  try {
    switch (operand_definition[0]) {
      case '=':
        type_ = CONSTANT;
        operand_definition.erase(operand_definition.begin());
        break;
      case '*':
        type_ = INDIRECT_ADDR;
        operand_definition.erase(operand_definition.begin());
        break;
      default:
        type_ = DIRECT_ADDR;
    }
    value_ = std::stoi(operand_definition);
  }
  catch (std::invalid_argument &e) {
    throw std::invalid_argument("operand must start with a number");
  }
}


Operand::~Operand() {
  type_ = CONSTANT;
  value_ = 0;
}

int Operand::get_value() const {
  return value_;
}

OperandType Operand::get_type() const {
  return type_;
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


