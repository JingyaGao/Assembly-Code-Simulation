#ifndef INSTRUCTION_H
#define	INSTRUCTION_H
#include "word.h"
#include <iostream>
using namespace std;

class Instruction: public Word
{
  char *info;
public:
  Instruction(int adr);
  ~Instruction();
  const char* getInfo() const;
  void operator=(const char* information);
  friend ostream& operator<< (ostream &os, const Instruction &instruction);

}; //class Instruction

#endif	// INSTRUCTION_H 

