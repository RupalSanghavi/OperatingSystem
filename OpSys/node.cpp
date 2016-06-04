#include "node.h"

Node::Node()
{
  PCB = 0;
  left = nullptr;
  right = nullptr;
}
void Node::setLeft(Node * obj){
  this->left = obj;
}

void Node::setRight(Node* obj){
  this->right = obj;
}
Node * Node::getRight(){
  return this->right;
}
