//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "output-tape.h"

OutputTape::OutputTape(std::string out_file_path) :
output_file_(out_file_path) {
  if (!output_file_.is_open()) {
    throw std::invalid_argument("Error opening program file " + out_file_path);
  }
}

OutputTape::~OutputTape() {
  for (auto out_data: output_data_) {
    output_file_ << out_data << '\n';
  }
  output_data_.clear();
  output_file_.close();
}

void OutputTape::write(int value) {
  output_data_.push_back(value);
}

std::ostream &operator<<(std::ostream &os, const OutputTape &tape) {

  const int width = 4;
  const size_t size =  width * tape.output_data_.size() + 1;

  os << std::setfill('-') << std::setw(size) << '\n';
  for (auto out_data: tape.output_data_) {
    os << std::setfill(' ') << std::setw(width) << out_data;
  }
  os << '\n';
  os << std::setfill('-') << std::setw(size) << '\n';

  os << std::setfill(' ') << std::setw(size + 1) << "↑" << '\n';

  return os;
}
