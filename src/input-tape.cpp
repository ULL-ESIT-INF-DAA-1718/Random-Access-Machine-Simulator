//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include "input-tape.h"

InputTape::InputTape(std::string input_tape_file_path) {
  head_ = 0;
  std::ifstream ifs(input_tape_file_path);

  if (ifs.is_open()) {
    int tape_unit;
    while (ifs >> tape_unit) {
      input_data_.push_back(tape_unit);
    }
  } else {
    throw std::invalid_argument("Error opening program file " + input_tape_file_path);
  }
}

InputTape::~InputTape() {}

int InputTape::read() {
  unsigned tmp = head_;
  head_++;

  if (tmp < input_data_.size()) {
    return input_data_[tmp];
  } else {
    return DEFAULT_TAPE_VALUE;
  }
}

std::ostream &operator<<(std::ostream &os, const InputTape &tape) {

  const int width = 4;

  size_t size = tape.input_data_.size();
  if (tape.head_ >= size) {
    int tmp = tape.head_ - size + 1;
    size = size + tmp;
  }

  os << std::setfill('-') << std::setw(width * size + 1) << '\n';
  for (int i = 0; i < size; i++) {
    if (i < tape.input_data_.size()) {
      os << std::setfill(' ') << std::setw(width) << tape.input_data_[i];
    } else {
      os << std::setfill(' ') << std::setw(width) << DEFAULT_TAPE_VALUE;
    }
  }
  os << '\n';
  os << std::setfill('-') << std::setw(width * size + 1) << '\n';

  os << std::setfill(' ') << std::setw(width * (tape.head_ + 1) + 2) << "↑" << '\n';

  return os;
}
