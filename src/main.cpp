
/**
 * @brief main program of ram_simultor
 *
 * @author Cristian Abrante Dorta
 * @date 19/02/2018
 */

#include <iostream>
#include "random-access-machine.h"

int main(int argc, char *argv[]) {

  bool debug = false;

  std::string program_file;
  std::string in_tape_file;
  std::string out_tape_file;

  switch (argc) {
    case 5:
      if (std::string(argv[4]) == "debug") {
        debug = true;
      } else {
        std::cerr << "Incorrect argument " << argv[4] << std::endl;
        return 1;
      }
    case 4:
      program_file = argv[1];
      in_tape_file = argv[2];
      out_tape_file = argv[3];
      break;
    default:
      if (argc < 4) {
        std::cerr << "Too few arguments, 3 expected." << std::endl;
        return 1;
      } else {
        std::cerr << "Too many arguments, 3 expected." << std::endl;
        return 1;
      }
  }

  // Errors during initialization
  try {

    RandomAccessMachine ram(program_file,
                            in_tape_file,
                            out_tape_file);

    // Runtime errors.
    try {
      ram.run(debug);
    }
    catch (std::runtime_error &rte) {
      std::cerr << rte.what() << std::endl;
      return 1;
    }
  }
  catch (std::invalid_argument &ia) {
    std::cerr << ia.what() << std::endl;
    return 1;
  }

  return 0;
}