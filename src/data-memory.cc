/*
 * data-memory.cc
 *
 *  Created on: 15 feb. 2018
 *      Author: cristian
 */

#include "data-memory.h"

DataMemory::DataMemory() : registers_(1, 0) {
	dictionary_[ACC] = ACC;
}

DataMemory::~DataMemory() {
	registers_.clear();
	dictionary_.clear();
}

int DataMemory::read(int position) const {
	try {
		if (position < 0) {
			throw std::invalid_argument("could not access to a negative memory position.");
		}

		int pos_to_read = dictionary_.at(position);
		return registers_[pos_to_read];
	}
	// position was not a key on the dictionaty_
	// so this position was never accessed.
	catch (const std::out_of_range& oor) {
		return DEFAULT_VALUE;
	}
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
		return 0;
	}
}

void DataMemory::write(int position, int value) {
	try {
		if (position < 0) {
			throw std::invalid_argument("could not access to a negative memory position.");
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
	catch (const std::invalid_argument& ia) {
		std::cerr << "Invalid argument: " << ia.what() << '\n';
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

