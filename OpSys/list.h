#ifndef LIST_H
#define LIST_H
#include "node.h";

class list
{
private:
  Node head;
  Node tail;
public:
  list();
  addPCB();
  addPCB(int pos); //change to data?
  deletePCB(int PID); //change to data?
  printVals();
};

#endif // LIST_H
