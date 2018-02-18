//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_INPUT_TAPE_H
#define RAM_SIMULATOR_INPUT_TAPE_H

#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>

// Default tape value
const int DEFAULT_TAPE_VALUE = 0;

/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents the input tape
 *        of the tape unit at the random access machine.
 *
 */

class InputTape {

 public:

  /**
   * @brief constructor of the class.
   * @details constructor will catch up ints until any not int character apears.
   *
   * @param input_tape_file_path file where the tape data is stored.
   *
   * @throw std::invalid_argument if tape file is not correct.
   */
  InputTape(std::string input_tape_file_path);

  /**
   * @brief Destructor of the class.
   */
  virtual ~InputTape();

  /**
   * @brief read int data from the tape.
   */
  int read();

  /**
   * @brief Friend method that prints the input tape into a stream.
   *        Only used registers are printed.
   *
   * @param os
   * @param dm
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const InputTape &tape);

 private:
  // current position at tape.
  unsigned head_;

  // data of the tape file
  std::vector<int> input_data_;
};

#endif //RAM_SIMULATOR_INPUT_TAPE_H
