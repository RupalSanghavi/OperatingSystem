#include "node.h"

Node::Node()
{
  PID = 0;
  left = nullptr;
  right = nullptr;
}
Node::Node(int PID){
  this->PID = PID;
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
Node * Node::getLeft(){
  return this->left;
}

int Node::getPID(){
  return PID;
}
