//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#ifndef RAM_SIMULATOR_OUTPUT_TAPE_H
#define RAM_SIMULATOR_OUTPUT_TAPE_H

#include <vector>
#include <fstream>
#include <ostream>
#include <iomanip>

class OutputTape {
 public:

  /**
   * @brief constructor of the class.
   *
   * @param out_file_path file where the output tape was going to be stored.
   */
  OutputTape(std::string out_file_path);

  /**
   * @brief destrcutor of the class. Writes te content into output file.
   */
  virtual ~OutputTape();

  /**
   * @brief method that writes a specified value into output tape.
   *
   * @param value
   */
  void write(int value);

  friend std::ostream &operator<<(std::ostream &os, const OutputTape &tape);
 private:
  // Output data of the tape.
  std::vector<int> output_data_;

  // output stream.
  std::ofstream output_file_;
};

#endif //RAM_SIMULATOR_OUTPUT_TAPE_H
