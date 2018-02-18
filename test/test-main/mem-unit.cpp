//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "memory-unit.h"

int main() {
  //std::cout << "Memory Unit tests" << std::endl;

  try {

    MemoryUnit a0("../test/tests_ram/test1.ram");
    std::cout << a0 << '\n';

    MemoryUnit a1("../test/tests_ram/test2.ram");
    std::cout << a1 << '\n';

    MemoryUnit a2("../test/tests_ram/test3.ram");
    std::cout << a2 << '\n';

    MemoryUnit a3("../test/tests_ram/test4.ram");
    std::cout << a3 << '\n';

    MemoryUnit a4("../test/tests_ram/test5.ram");
    std::cout << a4 << '\n';

    MemoryUnit a5("../test/tests_ram/test6.ram");
    std::cout << a5 << '\n';

    MemoryUnit a6("../test/tests_ram/test7.ram");
    std::cout << a6 << '\n';


    // ERRORES en la inicialización de la memoria.

    // Fichero erróneo.
    try {
      MemoryUnit err("no_existe.ram");
      std::cout << err << '\n';
    }
    catch (std::invalid_argument &ia) {
      std::cerr << "Error at main line n: ";
      std::cerr << ia.what() << '\n';
    }
    std::cerr << std::endl;
    try {
      MemoryUnit err("../test/error_test_ram/error_test1.ram");
      std::cout << err << '\n';
    }
    catch (std::invalid_argument &ia) {
      std::cerr << "Error at main line n: ";
      std::cerr << ia.what() << '\n';
    }

    std::cerr << std::endl;
    try {
      MemoryUnit err("../test/error_test_ram/error_test2.ram");
      std::cout << err << '\n';
    }
    catch (std::invalid_argument &ia) {
      std::cerr << "Error at main line n: ";
      std::cerr << ia.what() << '\n';
    }
    std::cerr << std::endl;
    try {
      MemoryUnit err("../test/error_test_ram/error_test3.ram");
      std::cout << err << '\n';
    }
    catch (std::invalid_argument &ia) {
      std::cerr << "Error at main line n: ";
      std::cerr << ia.what() << '\n';
    }
    std::cerr << std::endl;
    try {
      MemoryUnit err("../test/error_test_ram/error_test4.ram");
      std::cout << err << '\n';
    }
    catch (std::invalid_argument &ia) {
      std::cerr << "Error at main line n: ";
      std::cerr << ia.what() << '\n';
    }
  }
  catch (std::invalid_argument &ia) {
    std::cerr << "Error at main line n: ";
    std::cerr << ia.what() << '\n';
  }

}