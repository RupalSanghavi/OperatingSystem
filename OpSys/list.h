#ifndef LIST_H
#define LIST_H
#include "node.h";

class List
{
private:
  Node * head;
  Node * tail;
public:
  List();
  void addPCB();
  void addPCB(int pos); //change to data?
  int deletePCB(int PID); //change to data?
  int deletePCB();
  void printVals();
};

#endif // LIST_H
