//
// Created by Cristian Abrante Dorta on 19/2/18.
//

#include <iostream>
#include "random-access-machine.h"

int main(void) {
  std::cout << "RAM Test" << std::endl;

  Instruction i("45: JUMP 123");

  std::string pf = "../test/tests_ram/test1.ram";
  std::string it = "../test/tape_test/test1.tape";
  std::string ot = "../test/tape_test/otest1.tape";

  RandomAccessMachine ram(pf, it, ot);
  ram.run(false);

  std::string pf2 = "../test/tests_ram/test2.ram";
  std::string it2 = "../test/tape_test/test2.tape";
  std::string ot2 = "../test/tape_test/otest2.tape";

  RandomAccessMachine ram2(pf2, it2, ot2);
  ram2.run(false);

  /*
  std::string pf3 = "../test/tests_ram/test3.ram";
  std::string it3 = "../test/tape_test/test1.tape";
  std::string ot3 = "../test/tape_test/otest3.tape";

  RandomAccessMachine ram3(pf3, it3, ot3);
  ram3.run(false);
  */

  std::string pf4 = "../test/tests_ram/test4.ram";
  std::string it4 = "../test/tape_test/test4.tape";
  std::string ot4 = "../test/tape_test/otest4.tape";

  RandomAccessMachine ram4(pf4, it4, ot4);
  ram4.run(false);

  std::string pf5 = "../test/tests_ram/test5.ram";
  std::string it5 = "../test/tape_test/test4.tape";
  std::string ot5 = "../test/tape_test/otest5.tape";

  RandomAccessMachine ram5(pf5, it5, ot5);
  ram5.run(false);

  /*
  std::string pf6 = "../test/tests_ram/test6.ram";
  std::string it6 = "../test/tape_test/test1.tape";
  std::string ot6 = "../test/tape_test/otest6.tape";

  RandomAccessMachine ram6(pf6, it6, ot6);
  ram6.run(true);
  */

  std::string pf7 = "../test/tests_ram/test7.ram";
  std::string it7 = "../test/tape_test/test4.tape";
  std::string ot7 = "../test/tape_test/otest7.tape";

  RandomAccessMachine ram7(pf7, it7, ot7);
  ram7.run(false);

}