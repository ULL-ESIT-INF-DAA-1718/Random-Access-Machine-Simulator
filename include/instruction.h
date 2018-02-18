//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#ifndef RAM_SIMULATOR_INSTRUCTION_H
#define RAM_SIMULATOR_INSTRUCTION_H

#include <ostream>
#include <string>
#include <vector>

#include "operand.h"

// Number of aviable operations.
const int NUMBER_OF_OPERATIONS = 12;

/**
 * Enumeration of the diferent opcodes of the instruction.
 */
enum Opcode {
  LOAD,
  STORE,
  ADD,
  SUB,
  MUL,
  DIV,
  READ,
  WRITE,
  JUMP,
  JZERO,
  JGTZ,
  HALT,
  ERROR_OPCODE
};

/**
 * Enumeration of the different categories of operations.
 */
enum Category {
  MEMORY_OP,
  ARITHMETICAL_OP,
  TAPE_OP,
  JUMP_OP,
  HALT_OP,
  ERROR_OP
};

/**
 * @author Cristian Abrante Dorta
 * @date 17 February 2018
 *
 * @class This class represents an instruction of
 *        the random access machine.
 *
 */
class Instruction {
 public:

  /**
   * @brief Constructor of the class.
   *
   * @param instruction_definition string defining the operation (with tag and arguments).
   * @param instruction_tag pointer to a string,
   *                        if the instruction have got a tag, it will point to this tag.
   *
   * @throw std::invalid_argument if happens some problem with the instruction definition.
   *                              Exception message is very descriptive.
   */
  Instruction(const std::string &instruction_definition,
              std::string *instruction_tag = nullptr);

  /**
   * @brief getter of the opcode of the instruction.
   *
   * @return opcode of the instrucction.
   */
  Opcode get_opcode() const;

  /**
   * @brief getter of the category of the instruction.
   *
   * @return category of the instruction.
   */
  Category get_category() const;

  /**
   * @brief getter of the operand of the instruction.
   *
   * @return operand of the instruction.
   *         if instruction don't have operand
   *         empty operand will be returned.
   */
  const Operand &get_operand() const;

  /**
   * @brief getter of the operand tag of the instruction.
   *
   * @return operand tag of the instruction.
   *         if instruction don't have operand tag
   *         empty operand tag will be returned.
   */
  const std::string &get_tag() const;

  /**
   * @brief Friend method that prints the class into a stream.
   *
   * @param os
   * @param instruction
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const Instruction &instruction);

  /**
   * @brief static method used to convert string to Opcode enum.
   *
   * @param opcode
   * @return opcode if string has the correct format.
   *         ERROR_OPCODE otherwise.
   */
  static Opcode string_to_opcode(std::string opcode);

  /**
   * @brief static method used to convert Opcode enum string.
   *
   * @param opcode
   * @return string with opcode or empty string otherwise.
   */
  static std::string opcode_to_string(Opcode op);

  /**
   * @brief static method used to get opcode category.
   *
   * @param op
   * @return category of the operand.
   *         ERROR_OP if op was not valid.
   */
  static Category opcode_category(Opcode op);

 private:
  // Opcode of the instruction.
  Opcode opcode_;

  // Category of the instruction.
  Category category_;

  // Operand of the instruction (if category has).
  Operand operand_;

  // Tag of the instruction (if category has).
  std::string tag_;

  /**
   * @brief Method used to split instruction into its parts.
   * @details It also uppercase its parts so the instruction set could be case insensible.
   *
   * @param instruction_definition
   * @return vector of string splitted.
   */
  std::vector<std::string> split_definition(const std::string &instruction_definition) const;

  /**
   * @brief This method returns the string but uppercased.
   *
   * @param str
   * @return str uppercased.
   */
  std::string uppercase_string(const std::string &str) const;

  // Method that process the instruction tag.
  bool process_instruction_tag(std::string &tag,
                               std::string *instruction_tag,
                               std::vector<std::string> &instruction_parts) const;

  // Method that process 1 operands instructions.
  void process_1_operand_instruction(std::vector<std::string> instruction_parts);

  // Method that process 2 operands instructions.
  void process_2_operands_instruction(std::vector<std::string> instruction_parts);
};

#endif //RAM_SIMULATOR_INSTRUCTION_H
