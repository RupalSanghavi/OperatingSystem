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
void List::addPCB() //change to data?
{

}
//if position given
void List::addPCB(int pos){
  //error checks
  Node * obj = new Node(pos); //create a node with all the data
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

int List::deletePCB(int PID){//change to data?

}
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
      cout<< temp->getPID();
      temp = temp->getRight();
    }
}
