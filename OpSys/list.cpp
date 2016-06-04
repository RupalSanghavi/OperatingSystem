#include "list.h"
#include "node.h"
using namespace std;
list::list()
{
  head = nullptr;
  tail = nullptr;
}
//default, add to back of queue
void list::addPCB() //change to data?
{
  //error checks
  Node * obj = new Node(); //create a node with all the data
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
//if position given
void list::addPCB(int pos){

}

int list::deletePCB(int PID){//change to data?

}
int list::deletePCB(){
  //if empty queue
  if(head == nullptr){
      return 0; //? Or should I be returning something else
    }
  else{
      Node * temp = head->getRight();
      head->setRight(nullptr); //avoid dangling pointer
      //int PID = head.PID?
      delete head;
      head = temp; //set head to next node
      //return PID;
    }

}

void list::printVals()
{
  Node * temp = head;
  //iterate to end of list
  while(temp != nullptr){
      //cout<< temp.data
      temp = temp->getRight();
    }
}
