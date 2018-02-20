//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "tape-unit.h"

int main(void) {

  std::cout << "Tape unit tests" << std::endl;

  //InputTape t("../test/tape_test/test1.tape");

  //std::cout << t << std::endl;

  //OutputTape ot("../test/tape_test/otest1.tape");

  //std::cout << ot << std::endl;

  //ot.write(45.98);
  //std::cout << ot << std::endl;

  //ot.write(48);
  //std::cout << ot << std::endl;

  TapeUnit tu("../test/tape_test/test1.tape", "../test/tape_test/otest1.tape");

  /*
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
  */

  /*
  OutputTape ot("../test/tape_test/otest1.tape");

  for (int i = 0; i < 30; ++i) {
    ot.write(i);
  }

  std::cout << ot;

  TapeUnit tu("../test/tape_test/test1.tape", "../test/tape_test/otest1.tape");
  for (int i = 0; i < 5; ++i) {
    tu.write(56.8);
    tu.write(i);
  }

  for (int i = 0; i < 10; ++i) {
    tu.read();
  }

  std::cout << tu;
  */
}