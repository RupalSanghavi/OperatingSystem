#include "list.h"
#include "node.h"
#include <iostream>
using namespace std;
List::List()
{
  head = nullptr;
  tail = nullptr;
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
void List::addPCB(int PID1, int arrivalTime1, int burstTime1, int priority1){
  //error checks
  Node * obj = new Node(PID1, arrivalTime1, burstTime1, priority1); //create a node with all the data
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
int List::calcAvgWaitTime(){
    int waitTime = 0;
    int finalBurst = 0;
    Node * temp = head;
    //iterate to end of list
    while(temp != nullptr){
        finalBurst = temp->getBurstTime();
        waitTime += finalBurst;
        //temp->display();
        temp = temp->getRight();
    }
    waitTime -= finalBurst;
    return waitTime;
    
}
