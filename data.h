#ifndef DATA_H
#define DATA_H

#include "word.h"
#include <iostream>

class Data: public Word
{
  int num;
public:
  Data(int adr);
  const int& get() const;
  int& get();
  Data& operator= (int rhs);
}; //data class

#endif
