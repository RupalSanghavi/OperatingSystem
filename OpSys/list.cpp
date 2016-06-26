#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;
List::List()
{
  head = nullptr;
  tail = nullptr;
  queueTotalTime = 0;
}
//default, add to back of queue
void List::priorityInsert(int PID1, int arrivalTime1, int burstTime1, int priority1){
    Node * obj = new Node(PID1, arrivalTime1, burstTime1, priority1); //create a node with all the data
    if(head == nullptr){
        head = obj;
        tail = obj;
    }
    else{
        Node * temp = head;
        while(temp->getPriority() < priority1)
        {
            //cout<<temp->getPID();
            if(temp->getRight() == nullptr){ //if node needs to be added at end
                temp->setRight(obj);
                obj->setLeft(temp);
                return;
            }
            
            temp = temp->getRight();
            if(temp == nullptr) //NEED TO FIX
                break;
            
        }
        //to place at beginning
        if(temp== head){
            obj->setRight(head);
            head->setLeft(obj);
            head = obj;
        }
        else{
            //put node before the current one temp is pointing to
            obj->setLeft(temp->getLeft());
            obj->setRight(temp);
            temp->getLeft()->setRight(obj);
            temp->setLeft(obj);
        }
        //cout<<temp->getPID();
        /*temp->setLeft(tail);
        tail->setRight(obj);
        tail = obj;*/
    }
}
void List::addPCB(int pos, int data) //change to data?
{/*
  Node * obj = new Node(data); //create a node with all the data
  Node * temp = head;
  for(int i = 0; i < pos; i++){ //PROB NEED TO CHANGE 0
      temp = temp->getRight();
    }
  temp->setLeft(obj); //insert node to left of current node
  temp->getLeft()->setRight(obj); //attach node to right of previous node*/

}
//default
void List::addPCB(int PID1, int arrivalTime1, int burstTime1, int priority1, int Q){
  //error checks
  Node * obj = new Node(PID1, arrivalTime1, burstTime1, priority1); //create a node with all the data
  obj->setRemainBurstTime(burstTime1 - Q); //for purposes of Round Robin avg. waiting time calc
    //if process needs to requeued
    if(Q < burstTime1){
        queueTotalTime += Q;
        obj->setCumulativeTime(obj->getCumulativeTime()+Q);
        obj->setRemainBurstTime(obj->getRemainBurstTime()-Q);
    }
    //process finished
    else{
        queueTotalTime += burstTime1;
        obj->setCumulativeTime(obj->getCumulativeTime()+burstTime1);
        obj->setRemainBurstTime(0);
    }
    
  if(head == nullptr){
      head = obj;
      tail = obj;
  }
  else{
      obj->setLeft(tail);
      tail->setRight(obj);
      tail = obj;
    }

}
//delete with given PID
int List::deletePCB(int PID){
  Node* temp = head;
  //iterate till you find PCB/node with matching PID
  if(temp == nullptr){
      cout<<"Queue is already empty!";
      return 0;
    }
  while(temp->getPID() != PID){
      temp = temp->getRight();
      if(temp == nullptr){
          cout<<"Queue does not have PCB with PID number "<<PID<<endl;
          return 0;
        }
    }
  temp->getRight()->setLeft(temp->getLeft()); //set right node's left pointer to point to left node
  temp->getLeft()->setRight(temp->getRight()); //and the opposite
  int retPID = temp->getPID();
  delete temp;
  return retPID;
}
//default, delete from head
int List::deletePCB(){
  //if empty queue
  if(head == nullptr){
      cout<<"Queue is already empty!"<<endl<<endl;
      return 0; //? Or should I be returning something else
    }
  else{
      Node * temp = head->getRight();
      int PID1 = head->getPID();
     // head->setRight(nullptr); //avoid dangling pointer
      //int PID = head.PID?
      delete head;
      head = temp; //set head to next node
      return PID1;
    }

}

void List::printVals()
{
  Node * temp = head;
  //iterate to end of list
  while(temp != nullptr){
      temp->display();
      temp = temp->getRight();
    }
}
double List::calcAvgWaitTime(){
    double waitTime = 0.0;
    int totalTime = 0; //for purposes of calculating incremental wait time
    int finalBurst = 0;
    int tot = 0;
    int nodes = 0;
    Node * temp = head;
    //waitTime += temp->getArrivalTime(); //offset subtracting it later since first arrival time doesn't matter
    //iterate to end of list
    while(temp != nullptr){
        nodes++;
        tot += temp->getBurstTime();
        waitTime += tot;
        waitTime -= temp->getArrivalTime();
        /*finalBurst = temp->getBurstTime();
        tot = totalTime + finalBurst ;
        totalTime += tot;
        waitTime += tot;
        waitTime -= temp->getArrivalTime();*/
        //temp->display();
        temp = temp->getRight();
    }
    
    waitTime -= tot; //for last process
    waitTime /= double(nodes);
    //waitTime -= finalBurst;
    return waitTime;
    
}
int List::getQueueTotalTime(){
    return queueTotalTime;
}
void List::insertRoundRobin(int Q){
    //iterate through initial list, while temp != nullptr
    Node * temp = head;
    while(temp!= nullptr){
        cout<<"O";
        //if process unfinished
//        if(Q < temp->getRemainBurstTime()){
//            Node * obj = new Node(temp->getPID(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
//            obj->setRemainBurstTime(temp->getRemainBurstTime() - Q);
//            obj->setCumulativeTime(queueTotalTime + Q);
//            queueTotalTime += Q;
//            obj->setRemainBurstTime(temp->getRemainBurstTime()-Q);
//            //insert node at end
//            obj->setLeft(tail);
//            tail->setRight(obj);
//            tail = obj;
//        }
//        else{
//            temp->setCumulativeTime(temp->getCumulativeTime() + temp->getBurstTime());
//            queueTotalTime += temp->getRemainBurstTime();
//            obj->setRemainBurstTime(0);
//        }
        if(temp->getRemainBurstTime() > 0){
            Node * obj = new Node(temp->getPID(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());
            obj->setRemainBurstTime(temp->getRemainBurstTime() - Q);
            if(Q < temp->getRemainBurstTime()){
                obj->setCumulativeTime(queueTotalTime + Q);
                queueTotalTime += Q;
                obj->setRemainBurstTime(temp->getRemainBurstTime()-Q);
            }
            else{
                obj->setCumulativeTime(queueTotalTime + temp->getRemainBurstTime());
                queueTotalTime += temp->getRemainBurstTime();
                obj->setRemainBurstTime(0);
            }
            //tail->setRight(obj);
            //obj->setLeft(tail);
            obj->setLeft(tail);
            tail->setRight(obj);
            tail = obj;
            //tail =
        }
        //do nothing
        else{}
        temp = temp->getRight();
         

        
    }
    //if temp->getRemainBurstTime() > 0
        //create new node and append to tail
    
    
}
List::~List(){
    if(head!= nullptr)
    {
        int x = 0;
        Node * temp = head;
        while(temp != nullptr)
        {
            x++;
            delete temp;
            temp = temp->getRight();
        }
        cout<<x;
    }
}
//roundRobinAvgWaitTime