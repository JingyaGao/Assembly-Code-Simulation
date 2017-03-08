#ifndef WORD_H
#define WORD_H
#include <iostream>

class Word
{
  int address;
public:
  Word(int adr);
  virtual ~Word();
  bool operator< (const Word &other) const;
}; //word class

#endif
