#include "data.h"

Data::Data(int adr):Word(adr)
{
} //constructor

const int& Data::get() const
{
  return num;
} //returns const int ptr

int& Data::get()
{
  return num;
} //returns int ptr

Data& Data::operator= (int rhs)
{
  num = rhs;
  return *this;
} //overloaded assignment
