#ifndef MEMORY_H
#define MEMORY_H
#include <iostream>
#include "instruction.h"
#include "word.h"
#include "data.h"
using namespace std;

class Memory;
class Registers;

class ListNode
{
  Word* word;
  ListNode* next;
  friend Memory;
public:
  ListNode(Word* wor, ListNode* nex);
  ~ListNode();
 }; //class of llist nodei

class Memory
{
  ListNode* head;
public:
  Memory();
  ~Memory();
  const Word& operator[] (int adr) const;
  Word& operator[] (int adr);
  Word& insert(Word* tbi);
  const Instruction& fetch(Registers *registers) const;
  friend istream& operator>> (istream &is, Memory& memory);
}; //memory class 

#endif
