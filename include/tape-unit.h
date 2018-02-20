//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_TAPE_UNIT_H
#define RAM_SIMULATOR_TAPE_UNIT_H

#include <ostream>
#include "input-tape.h"
#include "output-tape.h"

/**
 * @author Cristian Abrante Dorta
 * @date 18 February 2018
 *
 * @class This class represents the tape unit of the RAM.
 *
 */
class TapeUnit {
 public:
  /**
   * @brief constructor that takes two tapes files.
   *
   * @param in_file_path
   * @param out_file_path
   */
  TapeUnit(std::string in_file_path, std::string out_file_path);

  /**
   * @brief method that reads from input tape.
   *
   * @return data readed.
   */
  double read();

  /**
   * @brief method that writes into the output tape.
   *
   * @param value
   */
  void write(double value);

  /**
   * @brief Friend method that prints the tape unit into a stream.
   *
   * @param os
   * @param unit
   * @return the same stream os.
   */
  friend std::ostream &operator<<(std::ostream &os, const TapeUnit &unit);

 private:
  // output tape of the unit.
  InputTape input_tape_;

  // input tape of the unit.
  OutputTape output_tape_;
};

#endif //RAM_SIMULATOR_TAPE_UNIT_H
