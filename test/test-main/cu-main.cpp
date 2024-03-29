//
// Created by Cristian Abrante Dorta on 18/2/18.
//

#include <iostream>
#include "control-unit.h"

int main(void) {
  //std::cout << "Control Unit test" << std::endl;

  /*
  int line_counter = 28;
  Instruction ins("LOAD -3");
  try {
    ControlUnit cu(&mem, &tape, &ip);
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 1"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =-5"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 2"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =8"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD =2"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE 4"));
    std::cout << mem;

    cu.execute_instruction(Instruction("LOAD *4"));
    std::cout << mem;

    cu.execute_instruction(Instruction("STORE *3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("SUB =3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("MUL *3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("ADD 8"));
    std::cout << mem;

    cu.execute_instruction(Instruction("DIV *3"));
    std::cout << mem;

    cu.execute_instruction(Instruction("READ *3"));
    std::cout << mem;
    std::cout << tape;

    cu.execute_instruction(Instruction("READ 3"));
    std::cout << mem;
    std::cout << tape;

    cu.execute_instruction(Instruction("WRITE =38"));
    std::cout << mem;
    std::cout << tape;

    cu.execute_instruction(Instruction("WRITE 3"));
    std::cout << mem;
    std::cout << tape;

    cu.execute_instruction(Instruction("WRITE *4"));
    std::cout << mem;
    std::cout << tape;

    cu.execute_instruction(Instruction("JUMP FIN"));
    std::cout << "ip: " << ip << std::endl;

    ip = 2;
    cu.execute_instruction(Instruction("JZERO FIN"));
    std::cout << "ip: " << ip << std::endl;

    ip = 2;
    cu.execute_instruction(Instruction("LOAD =0"));
    cu.execute_instruction(Instruction("JZERO FIN"));
    std::cout << "ip: " << ip << std::endl;

    ip = 0;
    cu.execute_instruction(Instruction("JGTZ FIN"));
    std::cout << "ip: " << ip << std::endl;

    ip = 2;
    cu.execute_instruction(Instruction("LOAD =8"));
    cu.execute_instruction(Instruction("JGTZ FIN"));
    std::cout << "ip: " << ip << std::endl;
  }
  catch(std::domain_error &de) {
    std::cerr << "Error at line " << line_counter << ": ";
    std::cerr << de.what() << std::endl;
    std::cerr << '|' << line_counter << " >> ";
    std::cerr << ins << '\n' << '\n';
  }
  catch (std::logic_error &le) {

  }
   */

  try {
    MemoryUnit mem("../test/tests_ram/test1.ram");
    TapeUnit tape("../test/tape_test/test1.tape", "../test/tape_test/otest.tape");
    unsigned ip = 0;

    ControlUnit cu(&mem, &tape, &ip);

    /* ERROR EN LOAD.
    cu.execute_instruction(Instruction("LOAD =-1"));
    cu.execute_instruction(Instruction("STORE 2"));
    cu.execute_instruction(Instruction("lOAD *2"));
    std::cout << mem << std::endl;
    */


    //cu.execute_instruction(Instruction("STORE =-1"));
    //std::cout << mem << std::endl;
    //cu.execute_instruction(Instruction("STORE -1"));
    //std::cout << mem << std::endl;
    /*cu.execute_instruction(Instruction("LOAD =-1 #load into R0"));
    cu.execute_instruction(Instruction("STORE 2"));
    cu.execute_instruction(Instruction("StorE *2"));
    std::cout << mem << std::endl;*/

    /*
    cu.execute_instruction(Instruction("LOAD =-1 #load into R0"));
    cu.execute_instruction(Instruction("STORE 2"));
    cu.execute_instruction(Instruction("ADD *2"));
    std::cout << mem << std::endl;*/
    /*
    cu.execute_instruction(Instruction("DIV 2"));
    std::cout << mem << std::endl;
    */

    /*
    cu.execute_instruction(Instruction("READ 0"));
    std::cout << mem << std::endl;
    cu.execute_instruction(Instruction("READ *2"));
    std::cout << mem << std::endl;
    */


    //cu.execute_instruction(Instruction("WRITE 0"));
    //std::cout << mem << std::endl;
    //cu.execute_instruction(Instruction("READ *2"));
    //std::cout << mem << std::endl;

    cu.execute_instruction(Instruction("JUMP FIN"));
    std::cout << mem << std::endl;
    std::cout << ip << std::endl;
  }
  catch (std::invalid_argument &ia) {
    std::cerr << "Error line 117: " << ia.what() << '\n';
  }
  catch (std::domain_error &de) {
    std::cerr << "Error line 119: " << de.what() << '\n';
  }
}