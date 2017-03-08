#include "memory.h"
#include "cstdlib"
#include <cstring>
#include "registers.h"
#include <iostream>
using namespace std;

ListNode::ListNode(Word* wor, ListNode* nex)
{
  word = wor;
  next = nex;
} //constructor

ListNode::~ListNode()
{
  delete word;
} //destructor for listnode

Memory::Memory()
{
  head = NULL;
} // constructor for memory

Memory::~Memory()
{
  ListNode *ptr;
  for(ptr = head; ptr; ptr = head)
  {
    head = ptr-> next;
    delete ptr;
  } //loops thru list
} //clears memory

const Word& Memory::operator[] (int adr) const
{
  ListNode* ptr;
  Word checkWord(adr);

  for(ptr = head; ptr; ptr = ptr->next)
  {
    if(!(checkWord < *(ptr->word)) && !(*(ptr->word) < checkWord))
    {
      return *(ptr->word);  
    } //if neither is smlr than the other
  } //loops through all operator elements
  cout << "Seg fault at address: " << adr << endl;
  exit(1);
} //overloaded [] operator for memory

Word& Memory::operator[] (int adr)
{
  ListNode* ptr;
  Word checkWord(adr);
//cout << "[]start" << endl;
  for(ptr = head; ptr; ptr = ptr->next)
  {
    if(!(checkWord < *(ptr->word)) && !(*(ptr->word) < checkWord))
    {
      return *(ptr->word);
    } //if neither is smlr than the other
  } //loops through all operator elements
//cout << "before end []" << endl;
  Data *newData = new Data(adr);
  return(insert(newData)); 
} //[] able to insert stuff

Word& Memory::insert(Word* tbi)
{
  ListNode *ptr, *prev = NULL;

  for(ptr = head; ptr && *(ptr->word) < *tbi; ptr = ptr->next)
    prev = ptr;

  ListNode* nLN = new ListNode(tbi, ptr);  

  if(prev)
  {
    prev->next = nLN;
  } // if prev is not NULL
  else // if prev is null
    head = nLN;

  return *(nLN->word);
} //adds element to linked list

const Instruction& Memory::fetch(Registers *registers) const
{
  const Word& temp = (*this)[registers->get(Registers::eip)];
  registers->set(Registers::eip, registers->get(Registers::eip) + 4);
  return dynamic_cast<const Instruction&>(temp);  
} //fetch

istream& operator>> (istream& is, Memory& memory)
{
  char line[256], *ptr; 
  int address = 100;
  
  while(is.getline(line, 256))
  {
    for(ptr = strchr(line, '\t'); ptr; ptr = strchr(line, '\t'))
      *ptr = ' '; // switches tabs with space
    
    for(ptr = line; *ptr == ' '; ptr++); //eats spaces

    //if(*ptr != '.' && *ptr != '_' && !strstr(line, "main:"))
    if(*ptr != '.' && line[strlen(line) - 1] != ':')
    {
      Instruction* newIns = new Instruction(address);
      *newIns = ptr;
      memory.insert(newIns);
      address += 4;
      //cout << "ins: " << newIns->getInfo() << endl;
    } //adds instructions memory 
  } //loops thru all lines
  return is;    
} // overloaded >>

