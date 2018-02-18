//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_TAPE_UNIT_H
#define RAM_SIMULATOR_TAPE_UNIT_H

#include <ostream>
#include "input-tape.h"
#include "output-tape.h"

class TapeUnit {
 public:

  TapeUnit(std::string in_file_path, std::string out_file_path);

  int read();

  void write(int value);

  friend std::ostream &operator<<(std::ostream &os, const TapeUnit &unit);

 private:
  // output tape of the unit.
  InputTape input_tape_;

  // input tape of the unit.
  OutputTape output_tape_;
};

#endif //RAM_SIMULATOR_TAPE_UNIT_H
