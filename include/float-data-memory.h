//
// Created by cristian on 20/02/18.
//

#ifndef RAM_SIMULATOR_FLOAT_DATA_MEMORY_H
#define RAM_SIMULATOR_FLOAT_DATA_MEMORY_H

#include <iostream>
#include <vector>
#include <map>

const double F_DEFAULT_VALUE = 0.0;

class FloatDataMemory {

 public:

  FloatDataMemory();

  ~FloatDataMemory();

  int read(int position) const;

  void write(int position, double value);

  friend std::ostream& operator<<(std::ostream& os, const FloatDataMemory& dm);

 private:

  std::vector<double> registers_;

  // Hash map used to simulate infinite registers.
  std::map<unsigned, unsigned> dictionary_;
};

#endif //RAM_SIMULATOR_FLOAT_DATA_MEMORY_H
