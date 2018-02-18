//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "input-tape.h"

int main(void) {

  std::cout << "Tape unit tests" << std::endl;

  InputTape t("../test/tape_test/test1.tape");

  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

  std::cout << t.read() << '\n';
  std::cout << t;

}