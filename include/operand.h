//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#ifndef RAM_SIMULATOR_OPERAND_H
#define RAM_SIMULATOR_OPERAND_H

#include <string>
#include <ostream>

/**
 * Enumeration of the different types of operands.
 */
enum OperandType {
  CONSTANT,         // Constant operand.
  DIRECT_ADDR,      // Direct addressing operand.
  INDIRECT_ADDR,    // Indirect addressing operand.
  EMPTY_OPERAND     // Empty operand (default constructor)
};

/**
 * @author Cristian Abrante Dorta
 * @date 17 February 2018
 *
 * @class This class represents an operand of an instruction of
 *        the random access machine.
 *
 */
class Operand {

 public:

  /**
   * @brief Default constructor.
   * @details Operand type will be EMPTY_OPERAND.
   */
  Operand();

  /**
   * @brief Constructor which has the operand definition as string.
   * @details Operand definition should have this format:
   *            =n -> n is a CONSTANT operator.
   *            n  -> n is the address of a register.
   *            *n -> n is the indirect address of a register.
   * @note value n must always start with a number, in case it has
   *       not numerical characters after the number it only takes first number.
   *
   * @example =3.456 -> value=3 // *78ab -> value=78 // a -> ERROR.
   *
   * @param operand_definition
   *
   * @throw std::invalid_argument if operand don't start by a number.
   * @throw std::length_error if operand_definition is empty.
   */
  Operand(std::string operand_definition);

  /**
   * @brief Destructor of the class.
   */
  ~Operand();

  /**
   * @brief gets the numeric value of the operand.
   *
   * @return numeric value of the operand.
   */
  int get_value() const;

  /**
   * @brief gets the type of the operand.
   *
   * @return type of the operand.
   */
  OperandType get_type() const;

  /**
   * @brief tests if operand is default operand.
   *
   * @return true if type is EMPTY_OPERAND, false otherwise.
   */
  bool empty() const;

  /**
   * @brief Friend method that prints the class into a stream.
   *
   * @param os
   * @param dm
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const Operand &operand);

 private:

  // Value of the operand.
  int value_;

  // Type of the operand.
  OperandType type_;
};

#endif //RAM_SIMULATOR_OPERAND_H
