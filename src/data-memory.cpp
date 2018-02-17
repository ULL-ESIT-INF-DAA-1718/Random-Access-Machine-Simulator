
#include "data-memory.h"

DataMemory::DataMemory() : registers_(1, 0) {
  dictionary_[0] = 0;
}

DataMemory::~DataMemory() {
  registers_.clear();
  dictionary_.clear();
}

int DataMemory::read(int position) const {
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
    return DEFAULT_VALUE;
  }
}

void DataMemory::write(int position, int value) {
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
    if (value != DEFAULT_VALUE) {
      registers_.push_back(value);
      dictionary_[position] = registers_.size() - 1;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const DataMemory& dm) {

  std::map<unsigned,unsigned>::const_iterator it = dm.dictionary_.begin();
  os << "ACC = " << dm.registers_[0] << '\n';
  ++it;

  for (; it != dm.dictionary_.end(); ++it) {
    os << "R[" << it->first << "] = " << dm.registers_[it->second] << '\n';
  }

  return os;
}

