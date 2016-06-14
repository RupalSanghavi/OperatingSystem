#include "node.h"
#include <iostream>
using namespace std;

Node::Node()
{
  PID = 0;
  arrivalTime = 0;
  burstTime = 0;
  priority = 0;
  left = nullptr;
  right = nullptr;
}
Node::Node(int PID1, int arrivalTime1, int burstTime1, int priority1){
  this->PID = PID1;
  this->arrivalTime = arrivalTime1;
  this->burstTime = burstTime1;
  this->priority = priority1;
  this->left = nullptr; //initialize
  this->right = nullptr;
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
void Node::display(){
    cout<<this->PID << " "<< this->arrivalTime<<" "<<this->burstTime << " " << this->priority<<endl;
    
}
int Node::getPriority(){
    return priority;
}
