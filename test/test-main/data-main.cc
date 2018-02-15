/*
 * data-main.cc
 *
 *  Created on: 15 feb. 2018
 *      Author: cristian
 */

#include <iostream>
#include "data-memory.h"

int main(void) {

	DataMemory a;

	std::cout << a.read(1) << '\n';

	a.write(3, 4);
	std::cout << a.read(3) << '\n';

	a.write(3, 0);
	std::cout << a.read(3) << '\n';

	a.write(3, 7);
	std::cout << a.read(3) << '\n';

	a.write(345, 0);
	std::cout << a.read(378) << '\n';
	std::cout << a;
}



