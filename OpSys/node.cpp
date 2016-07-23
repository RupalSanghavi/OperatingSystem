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
    prevFinTime = 0;
    totalWait = 0;
    left = nullptr;
    right = nullptr;
}
Node::Node(int PID1, int arrivalTime1, int burstTime1, int priority1, int duration1, int memReq1){
    this->PID = PID1;
    this->arrivalTime = arrivalTime1;
    this->burstTime = burstTime1;
    this->remainBurstTime = burstTime1;
    this->priority = priority1;
    this->left = nullptr; //initialize
    this->right = nullptr;
    cumulativeTime = 0;
    prevFinTime = 0;
    totalWait = 0;
    duration = duration1;
    memReq = memReq1;
}
/*
Node::Node(int PID1, int arrivalTime1, int duration1, int memReq1){
    this->PID = PID1;
    this->arrivalTime = arrivalTime1;
    burstTime = 0;
    remainBurstTime = 0;
    this->priority = arrivalTime1;
    this->left = nullptr; //initialize
    this->right = nullptr;
    duration = duration1;
    memReq = memReq1;
    cumulativeTime = 0;
    prevFinTime = 0;
    totalWait = 0;
}*/
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
    cout<< "PID: "<<this->PID << " Arrival Time: "<< this->arrivalTime<<" Duration: "<<this->duration<<" Memory Req: "<<this->memReq<< endl;
    /*cout<<"PID: "<<this->PID << " Arrival Time: "<< this->arrivalTime<<" Burst Time: "<<this->burstTime << " Priority: " << this->priority;
    if(this->cumulativeTime != 0)
        cout<< " Cumulative Time: "<<this->cumulativeTime<<endl;
    else
        cout<<endl;*/
    
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
int Node::getMemReq(){
    return memReq;
}