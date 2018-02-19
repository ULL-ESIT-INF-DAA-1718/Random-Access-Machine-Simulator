//
// Created by Cristian Abrante Dorta on 19/2/18.
//

#ifndef RAM_SIMULATOR_CUSTOM_EXCEPTIONS_H
#define RAM_SIMULATOR_CUSTOM_EXCEPTIONS_H

#include <stdexcept>
#include <string>

class OperandError: public std::runtime_error
{
 public:

  OperandError(char const* const message) throw() :
      std::runtime_error(message),
      what_message_(message) {}

  virtual char const* what() const throw() {
    return what_message_.c_str();
  }

 private:
  std::string what_message_;
};

#endif //RAM_SIMULATOR_CUSTOM_EXCEPTIONS_H
