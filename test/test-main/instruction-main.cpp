//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#include <iostream>
#include <sstream>
#include <vector>

#include "instruction.h"

int main() {
  std::cout << "Instruction tests" << '\n';

  // Instrucción vacía.
  try {
    Instruction i(" \t\t");
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 15: " << e.what() << std::endl;
  }

  // Intrucción de un solo operando que no sea halt.
  try {
    Instruction i("  \tPEPE");
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 24: " << e.what() << std::endl;
  }

  // Instrucción con dos partes, una es etiqueta y la segunda no válida.
  std::string inst_tag;
  try {
    Instruction i("tag: PEPE", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << inst_tag << '\n';
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  // Instrucción con dos partes, una no es etiqueta y la segunda no válida.
  try {
    Instruction i("tag PEPE", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << inst_tag << '\n';
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  // Instrucción HALT no puede tener argumentos.
  try {
    Instruction i("HALT arg1", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  // Instrucción con 3 partes, una no es etiqueta y la segunda no válida.
  try {
    Instruction i("tag PEPE 2", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  // Instrucción con 3 partes, una si es etiqueta y la segunda no válida.
  try {
    Instruction i("tag: PEPE 45", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  // Instrucción con 3 partes, error en el operando.
  try {
    Instruction i("tag: READ =abc", &inst_tag);
  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error on line 31: " << e.what() << std::endl;
  }

  Instruction i0("fin: JUMP fin");

  std::cout << i0.get_opcode() << '\n';
  std::cout << i0.get_operand() << '\n';
  std::cout << i0.get_category() << '\n';
  std::cout << i0.get_tag() << '\n';
  std::cout << i0 << '\n';
}