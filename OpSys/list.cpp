#include "list.h"
#include "node.h"
#include <iostream>
#include <unordered_map>
#include <vector>
#include <list>
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

    }
}

//default
void List::addPCB(int PID1, int arrivalTime1, int burstTime1, int priority1, int Q){
  //error checks
  Node * obj = new Node(PID1, arrivalTime1, burstTime1, priority1); //create a node with all the data
    //if process needs to requeued
    if(Q < burstTime1){
        //queueTotalTime += Q;
        obj->setCumulativeTime(obj->getCumulativeTime()+Q);
        obj->setRemainBurstTime(obj->getRemainBurstTime()-Q);
    }
    //process finished
    else{
        //queueTotalTime += burstTime1;
        obj->setCumulativeTime(obj->getCumulativeTime()+burstTime1);
        obj->setRemainBurstTime(obj->getRemainBurstTime()-Q);//***
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

    //iterate to end of list
    while(temp != nullptr){
        nodes++;
        tot += temp->getBurstTime();
        waitTime += tot;
        waitTime -= temp->getArrivalTime();
        temp = temp->getRight();
    }
    
    waitTime -= tot; //for last process
    waitTime /= double(nodes);
    return waitTime;
    
}
double List::calcRRWaitTime(int Q){
    Node * temp = head;
    unordered_map<int, vector<int> > nodes;// = unordered_map<int,vector<int,int>>();
    vector<int> pids;
    int prev = 0;
    int totArrTime = 0;
    while(temp!= nullptr){
        totArrTime += temp->getArrivalTime();
        if(nodes.find(temp->getPID()) == nodes.end()) //not in map yet
        {
            pids.push_back(temp->getPID());
            int tmp = prev;
            prev = temp->getCumulativeTime();
            nodes[temp->getPID()].push_back(prev);
            nodes[temp->getPID()].push_back(tmp);
        }
        else{
            nodes[temp->getPID()][1] += (prev - nodes[temp->getPID()][0]);
            prev = temp->getCumulativeTime();
            nodes[temp->getPID()][0] = prev;
        }
        temp = temp->getRight();
    }
    double total = 0.0;
    for(int i = 0; i<pids.size();i++){
        total += nodes[pids[i]][1]; //add individual process' total waiting time
    }
    total -= totArrTime;
    total /= double(pids.size());
    return total;
}
int List::getQueueTotalTime(){
    return queueTotalTime;
}
void List::insertRoundRobin(int Q){
    //iterate through initial list, while temp != nullptr
    Node * temp = head;
    while(temp!= nullptr){
        if(temp->getRemainBurstTime() > 0){
            Node * obj = new Node(temp->getPID(), temp->getArrivalTime(), temp->getBurstTime(), temp->getPriority());

            if((temp->getRemainBurstTime() + Q) > Q){
                queueTotalTime += Q;
                temp->setCumulativeTime(queueTotalTime);
                obj->setRemainBurstTime(temp->getRemainBurstTime()-Q);
            }


            else{
                queueTotalTime += (temp->getRemainBurstTime() + Q);
                temp->setCumulativeTime(queueTotalTime);
                obj->setRemainBurstTime(temp->getRemainBurstTime()-Q); //******
            }

            obj->setLeft(tail);
            tail->setRight(obj);
            tail = obj;
        }
        //do nothing
        else{
            if((temp->getRemainBurstTime() + Q) > Q){
                queueTotalTime += Q;
                temp->setCumulativeTime(queueTotalTime);
            }
            else{
                queueTotalTime += (temp->getRemainBurstTime() + Q);
                temp->setCumulativeTime(queueTotalTime);
            }
        }
        temp = temp->getRight();
         

        
    }

    
    
}
void List::calcTotalTime(int Q){
    Node * temp = head;
    while(temp!= nullptr){
        if(temp->getRemainBurstTime() > 0){
          
            if(Q < temp->getRemainBurstTime()){
                queueTotalTime += Q;
            }
            else{
                queueTotalTime += temp->getRemainBurstTime();
            }
 
        }
        //do nothing
        else{
            queueTotalTime += temp->getBurstTime();
        }
        temp = temp->getRight();
        
        
        
    }

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
    }
}
