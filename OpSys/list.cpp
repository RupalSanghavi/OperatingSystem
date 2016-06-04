#include "list.h"
#include "node.h"
using namespace std;
list::list()
{
  head = nullptr;
  tail = nullptr;
}
//default, add to back of queue
list::addPCB() //change to data?
{
  //error checks
  Node obj = new Node(); //create a node with all the data
  if(head == nullptr){
      head = obj;
      tail = obj;
  }
  else{
      obj->left = tail;
      tail->right = obj;
      tail = obj;
    }

}
//if position given
list::addPCB(int pos){

}

list::deletePCB(int PID) //change to data?
{

}

list::printVals()
{

}
