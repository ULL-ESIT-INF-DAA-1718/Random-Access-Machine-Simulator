//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "tape-unit.h"

TapeUnit::TapeUnit(std::string in_file_path, std::string out_file_path) :
input_tape_(in_file_path),
output_tape_(out_file_path) {}

double TapeUnit::read() {
  return input_tape_.read();
}

void TapeUnit::write(double value) {
  output_tape_.write(value);
}

std::ostream &operator<<(std::ostream &os, const TapeUnit &unit) {

  os << '\t' << "TAPE UNIT" << '\n';
  os << std::setfill('=') << std::setw(20) << '\n';

  os << "• " << "input tape" << '\n';
  os << unit.input_tape_;

  os << "• " << "output tape" << '\n';
  os << unit.output_tape_;
  return os;
}
