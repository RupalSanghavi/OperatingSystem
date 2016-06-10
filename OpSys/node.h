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
public:
  Node();
  Node(int PID);
  void setLeft(Node * obj);
  void setRight(Node* obj);
  Node *getRight();
  Node *getLeft();
  int getPID();
};

#endif // NODE_H
