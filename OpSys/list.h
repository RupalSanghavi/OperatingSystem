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
  void addPCB(int PID1, int arrivalTime1, int burstTime1, int priority1);
  void addPCB(int pos, int data); //change to data?
  void priorityInsert(int PID1, int arrivalTime1, int burstTime1, int priority1);
  int calcAvgWaitTime();
  int deletePCB(int PID); //change to data?
  int deletePCB();
  void printVals();
};

#endif // LIST_H
