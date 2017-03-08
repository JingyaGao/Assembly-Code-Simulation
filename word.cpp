#include "word.h"
using namespace std;

Word::Word(int adr) : address(adr)
{
} //constructori

Word::~Word()
{
} //empty destructor

bool Word::operator< (const Word &other) const
{
  return address < other.address;
} //compares address fields of other word

//int Word::peekAdr()
//{
//  return address;
//} //for debugging
