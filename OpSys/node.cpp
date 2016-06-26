#include "node.h"
#include <iostream>
using namespace std;

Node::Node()
{
  PID = 0;
  arrivalTime = 0;
  burstTime = 0;
  priority = 0;
  remainBurstTime = 0;
  cumulativeTime = 0;
  left = nullptr;
  right = nullptr;
}
Node::Node(int PID1, int arrivalTime1, int burstTime1, int priority1){
  this->PID = PID1;
  this->arrivalTime = arrivalTime1;
  this->burstTime = burstTime1;
  this->remainBurstTime = burstTime1;
  this->priority = priority1;
  this->left = nullptr; //initialize
  this->right = nullptr;
  cumulativeTime = 0;
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
    cout<<this->PID << " "<< this->arrivalTime<<" Burst Time: "<<this->burstTime << " Priority: " << this->priority<< " Remaining Burst Time: "<<this->remainBurstTime<< " Cumulative Time: "<<this->cumulativeTime<<endl;
    
}
int Node::getPriority(){
    return priority;
}
int Node::getBurstTime(){
    return burstTime;
}
void Node::setRemainBurstTime(int remainBurstTime1){
     this->remainBurstTime = remainBurstTime1;
}

void Node::setCumulativeTime(int cumulativeTime1){
     this->cumulativeTime = cumulativeTime1;
}

int Node::getCumulativeTime(){
    return cumulativeTime;
}
int Node::getRemainBurstTime(){
    return remainBurstTime;
}
int Node::getArrivalTime(){
    return arrivalTime;
}