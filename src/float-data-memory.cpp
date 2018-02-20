//
// Created by cristian on 20/02/18.
//

#include "float-data-memory.h"

FloatDataMemory::FloatDataMemory() : registers_(1, F_DEFAULT_VALUE) {
  dictionary_[0] = 0;
}

FloatDataMemory::~FloatDataMemory() {
  registers_.clear();
  dictionary_.clear();
}

int FloatDataMemory::read(int position) const {
  try {
    if (position < 0) {
      throw std::domain_error("could not read at a negative memory position.");
    }

    int pos_to_read = dictionary_.at(position);
    return registers_[pos_to_read];
  }
    // position was not a key on the dictionary_
    // so this position was never accessed.
  catch (const std::out_of_range& oor) {
    return F_DEFAULT_VALUE;
  }
}

void FloatDataMemory::write(int position, double value) {
  try {
    if (position < 0) {
      throw std::domain_error("could not write in a negative memory position.");
    }

    int pos_to_read = dictionary_.at(position);
    registers_[pos_to_read] = value;
  }
    // position was not a key on the dictionary_
    // so this position was never accessed.
  catch (const std::out_of_range& oor) {
    if (value != F_DEFAULT_VALUE) {
      registers_.push_back(value);
      dictionary_[position] = registers_.size() - 1;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const FloatDataMemory& dm) {

  std::map<unsigned,unsigned>::const_iterator it = dm.dictionary_.begin();
  os << "ACC = " << dm.registers_[0] << '\n';
  ++it;

  for (; it != dm.dictionary_.end(); ++it) {
    os << "F[" << it->first << "] = " << dm.registers_[it->second] << '\n';
  }

  return os;
}


