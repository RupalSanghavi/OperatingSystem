#ifndef NODE_H
#define NODE_H


class Node
{
private:
    int PID;
    /*
     * process state
     * process number
     * program counter
     * registers
     * memory limits (segment counters)
     * list of open files
     * burst time
     * priority
     */
    Node * left;
    Node * right;
    int arrivalTime;
    int burstTime;
    int priority;
    int remainBurstTime;
    int cumulativeTime;
    int prevFinTime;
    int totalWait;
    int duration;
    int memReq;
    
    
public:
    Node();
    Node(int PID1, int arrivalTime1, int burstTime1 = 0, int priority1 = 0, int duration1 = 0, int memReq1 = 0);
    void setLeft(Node * obj);
    void setRight(Node* obj);
    void setRemainBurstTime(int remainBurstTime1);
    void setCumulativeTime(int cumulativeTime1);
    int getCumulativeTime();
    int getRemainBurstTime();
    Node *getRight();
    Node *getLeft();
    int getPriority();
    int getPID();
    int getBurstTime();
    int getArrivalTime();
    void display();
    int getMemReq();
};

#endif // NODE_H
