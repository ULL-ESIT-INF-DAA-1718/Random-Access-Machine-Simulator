//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#ifndef RAM_SIMULATOR_OPERAND_H
#define RAM_SIMULATOR_OPERAND_H

#include <string>
#include <ostream>

enum OperandType {
  CONSTANT,
  DIRECT_ADDR,
  INDIRECT_ADDR
};

class Operand {

 public:

  Operand(std::string operand_definition);

  ~Operand();

  int get_value() const;

  OperandType get_type() const;

  friend std::ostream &operator<<(std::ostream &os, const Operand &operand);

 private:

  // Value of the operand.
  int value_;

  // Type of the operand.
  OperandType type_;
};

#endif //RAM_SIMULATOR_OPERAND_H
