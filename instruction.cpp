// Author: Sean Davis
#include "instruction.h"
#include <iostream>
#include <cstring>
#include <iostream>
using namespace std;

Instruction::Instruction(int adr) : Word(adr), info(NULL)
{
}  // Instruction()


Instruction::~Instruction()
{
  if(info)
    delete [] info;
}  // ~Instruction
  

const char* Instruction::getInfo() const
{
  return info;
} // get()


void Instruction::operator= (const char* information)
{
  info = new char[strlen(information) + 1];
  strcpy(info, information);
} // setInfo()


ostream& operator<< (ostream &os, const Instruction &instruction)
{
  cout << instruction.getInfo();
  return os;
} // overload operator <<
