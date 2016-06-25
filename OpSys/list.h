#ifndef LIST_H
#define LIST_H
#include "node.h"

class List
{
private:
    Node * head;
    Node * tail;
    int queueTotalTime;
public:
    List();
    void addPCB(int PID1, int arrivalTime1, int burstTime1, int priority1, int Q = 0);
    void addPCB(int pos, int data); //change to data?
    void priorityInsert(int PID1, int arrivalTime1, int burstTime1, int priority1);
    double calcAvgWaitTime();
    int deletePCB(int PID); //change to data?
    int deletePCB();
    void printVals();
    int getQueueTotalTime();
    void insertRoundRobin(int Q);
};

#endif // LIST_H
