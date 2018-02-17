
#ifndef INCLUDE_DATA_MEMORY_H_
#define INCLUDE_DATA_MEMORY_H_

#include <iostream>
#include <vector>
#include <map>

// Default value that the data registers are going to store.
const int DEFAULT_VALUE = 0;

/**
 * @author Cristian Abrante Dorta
 * @date 17 February 2018
 *
 * @class This class represents the data memory
 *        of the memory unit at the random access machine.
 *
 */

class DataMemory {

 public:

  /**
   * @brief Default constructor of the class.
   *        The infinite registers of the memory are set to DEFAULT_VALUE.
   */
  DataMemory();

  /**
   * @brief Destructor of the class.
   */
  ~DataMemory();

  /**
   * @brief Read form memory at specified position.
   *
   * @param position
   * @return value stored at position.
   *
   * @throw std::domain_error if position < 0;
   */
  int read(int position) const;

  /**
   * @brief Write value at specified memory position.
   *
   * @param position
   * @param value that we want to store at position.
   *
   * @throw std::domain_error if position < 0;
   */
  void write(int position, int value);

  /**
   * @brief Friend method that prints the memory into a stream.
   *        Only used registers are printed.
   *
   * @param os
   * @param dm
   * @return the same stream os.
   */
  friend std::ostream& operator<<(std::ostream& os, const DataMemory& dm);

 private:

  // vector of registers.
  std::vector<int> registers_;

  // Hash map used to simulate infinite registers.
  std::map<unsigned, unsigned> dictionary_;
};

#endif /* INCLUDE_DATA_MEMORY_H_ */
