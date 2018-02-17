//
// Created by Cristian Abrante Dorta on 17/2/18.
//

#include <iostream>
#include "operand.h"

int main(void) {

  std::cout << "Operand Test" << '\n';

  try {

    // Constant operand.
    Operand cop("=45");
    std::cout << cop << '\n';
    std::cout << "value: " << cop.get_value() << '\n';
    std::cout << "type: " << (cop.get_type() == CONSTANT) << '\n';

    // direct operand.
    Operand dop("346");
    std::cout << dop << '\n';
    std::cout << "value: " << dop.get_value() << '\n';
    std::cout << "type: " << (dop.get_type() == DIRECT_ADDR) << '\n';

    // indirect operand.
    Operand iop("*45");
    std::cout << iop << '\n';
    std::cout << "value: " << iop.get_value() << '\n';
    std::cout << "type: " << (iop.get_type() == INDIRECT_ADDR) << '\n';

  }
  catch (std::invalid_argument &e) {
    std::cerr << "Error en la línea " << e.what() << std::endl;
  }

}