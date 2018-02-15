/*
 * data-memory.h
 *
 *  Created on: 15 feb. 2018
 *      Author: cristian
 */

#ifndef INCLUDE_DATA_MEMORY_H_
#define INCLUDE_DATA_MEMORY_H_

#include <iostream>
#include <vector>
#include <map>

const int DEFAULT_VALUE = 0;
const int ACC = 0;

class DataMemory {

public:

	DataMemory();
	~DataMemory();

	int read(int position) const;
	void write(int position, int value);

	friend std::ostream& operator<<(std::ostream& os, const DataMemory& dm);

private:

	std::vector<int> registers_;
	std::map<unsigned, unsigned> dictionary_;
};

#endif /* INCLUDE_DATA_MEMORY_H_ */
