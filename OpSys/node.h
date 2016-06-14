#ifndef NODE_H
#define NODE_H


class Node
{
private:
  int PID;
  /*
   * process state
   * process number
   * program counter
   * registers
   * memory limits (segment counters)
   * list of open files
   * burst time
   * priority
  */
  Node * left;
  Node * right;
  int arrivalTime;
  int burstTime;
  int priority;
    
public:
  Node();
  Node(int PID1, int arrivalTime1, int burstTime1, int priority1);
  void setLeft(Node * obj);
  void setRight(Node* obj);
  Node *getRight();
  Node *getLeft();
  int getPriority();
  int getPID();
  void display();
};

#endif // NODE_H
