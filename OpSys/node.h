#ifndef NODE_H
#define NODE_H


class Node
{
private:
  int PID;
  Node * left;
  Node * right;
public:
  Node();
  Node(int PID);
  void setLeft(Node * obj);
  void setRight(Node* obj);
  Node *getRight();
  int getPID();
};

#endif // NODE_H
