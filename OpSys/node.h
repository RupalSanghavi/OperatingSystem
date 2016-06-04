#ifndef NODE_H
#define NODE_H


class Node
{
private:
  int PCB;
  Node * left;
  Node * right;
public:
  Node();
  void setLeft(Node * obj);
  void setRight(Node* obj);
  Node *getRight();
};

#endif // NODE_H
