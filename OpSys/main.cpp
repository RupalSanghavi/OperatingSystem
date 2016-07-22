#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "list.h"
#include "node.h"
using namespace std;

void processMgmt(List*& waiting1);
double firstComeFirstServe(ifstream &fin, List*& ready2);
double npPriority(ifstream &fin, List*& ready2);
void readFile(ifstream &fin);
double roundRobin(ifstream &fin, List*& ready2);
void userInput(List*& ready, int option);
void readMemMgmtFile(ifstream &fin, List*& ready2);
void firstFit(ifstream &fin, List*& ready2);
void memoryMgmt();
void bestFit(ifstream &fin, List*& ready2);
void worstFit(ifstream &fin, List*& ready2);

int main(int argc, char *argv[])
{
    bool correct = false;
    string choice ="";
    List * waiting = new List();
    cout << "============================== \n";
    cout << "SIMULATED OPERATING SYSTEM \n";
    cout << "============================== \n";
    
    // main menu runs until user exits it
    while (correct == false)
    {
        // main menu
        cout << "Mode choices(insert number for one of the options):\n"
        << "\t [1] Phase I: Process Management \n"
        << "\t [2] Phase II: Memory Management \n"
        << "\t [0] exit\n" <<  endl;
        cout << "Select: "<< endl;
        cin >> choice;
        cout << endl;
        
        // Conditional to run correct mode for the choice or if wrong choice displays a error message
        if(choice == "1")
            processMgmt(waiting);
        else if(choice == "2")
            memoryMgmt();
        else if(choice == "0")
            correct = true;
        else
            cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
    }
    cout<<endl;
    return 0;
}
void processMgmt(List *&waiting1){
    bool correct = false;
    int choice;
    cout << "============================== \n";
    cout << "PROCESS MANAGEMENT  \n";
    cout << "============================== \n";
    
    // main menu runs until user exits it
    while (correct == false)
    {
        // main menu
        cout << "Choose a Scheduling Algorithm :\n"
        << "\t [1] First-Come-First-Serve Scheduling \n"
        << "\t [2] Non-Preemptive Priority Scheduling \n"
        << "\t [3] Round Robin Scheduling \n"
        << "\t [0] exit\n" <<  endl;
        cout << "Select: "<< endl;
        cin >> choice;
        cout << endl;
        
        // Conditional to run correct mode for the choice or if wrong choice displays a error message
        switch(choice){
            case 1: {
                List * ready = new List();
                List * waiting = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 1); //1 indicates FCFS
                    
                }
                else if(input == "2"){
                    ifstream fin;
                    readFile(fin);
                    avgWait = firstComeFirstServe(fin, ready);
                }
                else{
                    cout<<"Invalid input!"<<endl;
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
                delete ready;
                break;
                
            }
            case 2: {
                List * ready = new List();
                List * waiting = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 2); //1 indicates Priority
                }
                else{
                    ifstream fin;
                    readFile(fin);
                    avgWait = npPriority(fin, ready);
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
                delete ready;
                break;
            }
            case 3: {
                List * ready = new List();
                List * waiting = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 3); //1 indicates Priority
                }
                else{
                    ifstream fin;
                    readFile(fin);
                    avgWait = roundRobin(fin, ready);
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
                delete ready;
                break;
            }
            case 0:{
                correct = true;
                break;
            }
            default: cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
                break;
                
        }
        
    }
    
}
void memoryMgmt(){
    bool correct = false;
    int choice;
    cout << "============================== \n";
    cout << "Memory MANAGEMENT  \n";
    cout << "============================== \n";
    
    // main menu runs until user exits it
    while (correct == false)
    {
        // main menu
        cout << "Choose a Memory Management Algorithm :\n"
        << "\t [1] First-fit \n"
        << "\t [2] Best-fit \n"
        << "\t [3] Worst-fit \n"
        << "\t [0] exit\n" <<  endl;
        cout << "Select: "<< endl;
        cin >> choice;
        cout << endl;
        
        // Conditional to run correct mode for the choice or if wrong choice displays a error message
        switch(choice){
            case 1: {
                List * ready = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 1); //1 indicates FCFS
                    
                }
                else if(input == "2"){
                    ifstream fin;
                    readMemMgmtFile(fin,ready);
                    firstFit(fin, ready);
                }
                else{
                    cout<<"Invalid input!"<<endl;
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                //cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
                delete ready;
                break;
                
            }
            case 2: {
                List * ready = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 2); //1 indicates Priority
                }
                else if(input == "2"){
                    ifstream fin;
                    readMemMgmtFile(fin,ready);
                    bestFit(fin, ready);
                }
                else{
                    cout<< "Invalid Input!"<<endl;
                }
                //                cout<<"Queue contents:"<<endl;
                //                ready->printVals();
                //                cout<<endl<<endl;
                delete ready;
                break;
            }
            case 3: {
                List * ready = new List();
                string input = "";
                double avgWait = 0.0;
                cout << "Choose a Input Method :\n"
                << "\t [1] User Input \n"
                << "\t [2] Text file \n"<<endl;
                cin>>input;
                if(input == "1"){
                    userInput(ready, 2); //1 indicates Priority
                }
                else if(input == "2"){
                    ifstream fin;
                    readMemMgmtFile(fin,ready);
                    worstFit(fin, ready);
                }
                else{
                    cout<< "Invalid Input!"<<endl;
                }
                //                cout<<"Queue contents:"<<endl;
                //                ready->printVals();
                //                cout<<endl<<endl;
                delete ready;
                break;
            }
            case 0:{
                correct = true;
                break;
            }
            default: cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
                break;
                
        }
        
    }
}
double firstComeFirstServe(ifstream &fin, List*& ready2){
    string line = "";
    vector<int> data;
    while(!fin.eof()){
        getline(fin,line,'\n');
        if(line == "")//if eof didn't work
            break;
        stringstream ss(line);
        int x;
        while(ss>>x){
            data.push_back(x);
            if(ss.peek() == ',')
                ss.ignore();
        }
        ready2->addPCB(data[0],data[1],data[2],data[3]); //default tail insertion due to FCFS
        
        line = "";
        data.clear();
    }
    double avgWait = ready2->calcAvgWaitTime();
    cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
    return avgWait;
    
}
void readMemMgmtFile(ifstream &fin, List*& ready2){
    cout<<"Please enter name of text file: ";
    string file;
    //add check to see if actually able to open text file
    cin>>file;
    fin.open(file);
    bool open = false;
    while(open!=true){
        if(fin.is_open()){
            cout<<"File opened successfully. "<<endl<<endl;
            open = true;
        }
        else{
            cout<<"Error opening file. Please retry: ";
            cin>> file;
            fin.open(file);
        }
    }
    string line = "";
    string blah = "";
    int memSize = 0;
    int numSpaces = 0;
    int startAdd = 0;
    int availSpace = 0;
    vector<int> data;
    vector<int> memory;
    vector<int> baseAdds;
    fin>> memSize;
    fin>> numSpaces;
    fin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
    for(int i = 0; i<numSpaces;i++){
        //fin>>line;
        
        //fin>>blah;
        getline(fin,line,'\n');
        //getline(fin,line,',');
        //fin>>blah;
        
        stringstream ss(line);
        int x;
        while(ss>>x){
            data.push_back(x);
            if(ss.peek() == ',')
                ss.ignore();
        }
        baseAdds.push_back(data[0]);
        memory.push_back(data[1]);
       
        data.clear();
    }
    cout<<"yo mama";
    /*
    string line = "";
    vector<int> data;
    while(!fin.eof()){
        getline(fin,line,'\n');
        if(line == "")//if eof didn't work
            break;
        stringstream ss(line);
        int x;
        while(ss>>x){
            data.push_back(x);
            if(ss.peek() == ',')
                ss.ignore();
        }
        //void priorityInsert(int PID1, int arrivalTime1, int burstTime1 = 0, int priority1 = 0, int duration1 = 0, int memReq1= 0);

        ready2->priorityInsert(data[0],data[1],0,data[1],data[2],data[3]); 
        
        line = "";
        data.clear();
    }*/
    
    
}
void firstFit(ifstream &fin, List*& ready2){
    int memAvail = 0;
    vector<int> memPrt = {300,600,350,200,750,125};
    for(int i = 0 ; i < memPrt.size(); i++){
        memAvail += memPrt[i];
    }
    vector<Node *> memFilled(memPrt.size()); //initialize 5 spots to zero
    //vector<int> procs = {115,500,358,200,375};
    bool found = false;
    Node * temp = ready2->getHead();
    while(temp!= nullptr){
        for(int j = 0; j < memPrt.size(); j++){
            if((temp->getMemReq() <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
                memFilled[j] = temp;
                
                found = true;
                if(temp->getMemReq() < memPrt[j]) //size requested doesn't fully take up partition
                    cout<<"Internal fragmentation for process size : "<< temp->getMemReq() <<endl;
                memAvail -= temp->getMemReq(); //CHANGE TO -= memFilled[j]??
                break;
            }
        }
        if(found == false) //no partition available
            cout<< "External fragmentation for process size : "<< temp->getMemReq()<<endl;
        found = false;
        temp = temp->getRight();
    }
//    for(int i = 0; i < procs.size(); i++){//change to iterate through linked list
//        for(int j = 0; j < memPrt.size(); j++){
//            if((procs[i] <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
//                memFilled[j] = procs[i];
//                found = true;
//                if(procs[i] < memPrt[j]) //size requested doesn't fully take up partition
//                    cout<<"Internal fragmentation for process size : "<< procs[i]<<endl;
//                break;
//            }
//        }
//        if(found == false) //no partition available
//            cout<< "External fragmentation for process size : "<< procs[i]<<endl;
//        found = false;
//    }
    
    cout<<endl;
}
void bestFit(ifstream &fin, List*& ready2){
    int smallestDiff = 1000;
    int bestFitIndex = 0;
    int memAvail = 0;
    vector<int> memPrt = {300,600,350,200,750,125};
    for(int i = 0 ; i < memPrt.size(); i++){
        memAvail += memPrt[i];
    }
    //vector<int> memFilled(memPrt.size()); //initialize 5 spots to zero
    vector<Node *> memFilled(memPrt.size());
    //vector<int> procs = {115,500,358,200,375};
    bool found = false;
    Node * temp = ready2->getHead();
    while(temp!= nullptr){
        for(int j = 0; j < memPrt.size(); j++){
            if((temp->getMemReq() <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
                //memFilled[j] = procs[i];
                int diff = memPrt[j] - temp->getMemReq();
                if(diff < smallestDiff){
                    smallestDiff = diff;
                    bestFitIndex = j;
                }
                found = true;
            }
        }

        if(found == false) //no partition available
            cout<< "External fragmentation for process size : "<< temp->getMemReq()<<endl;
        else {
            memFilled[bestFitIndex] = temp;
            memAvail -= temp->getMemReq();
            if(temp->getMemReq() < memPrt[bestFitIndex]) //size requested doesn't fully take up partition
                cout<<"Internal fragmentation for process size : "<< temp->getMemReq()<<endl;
        }
        smallestDiff = 1000;
        bestFitIndex = 0;
        found = false;
        temp = temp->getRight();
    }
//    for(int i = 0; i < procs.size(); i++){//change to iterate through linked list
//        for(int j = 0; j < memPrt.size(); j++){
//            if((procs[i] <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
//                //memFilled[j] = procs[i];
//                int diff = memPrt[j] - procs[i];
//                if(diff < smallestDiff){
//                    smallestDiff = diff;
//                    bestFitIndex = j;
//                }
//                found = true;
//            }
//        }
//        
//        if(found == false) //no partition available
//            cout<< "External fragmentation for process size : "<< procs[i]<<endl;
//        else {
//            memFilled[bestFitIndex] = procs[i];
//            if(procs[i] < memPrt[bestFitIndex]) //size requested doesn't fully take up partition
//                cout<<"Internal fragmentation for process size : "<< procs[i]<<endl;
//        }
//        smallestDiff = 1000;
//        bestFitIndex = 0;
//        found = false;
//    }
    
    cout<<endl;
}
void worstFit(ifstream &fin, List*& ready2){
    int biggestDiff = 0;
    int bestFitIndex = 0;
    int memAvail = 0;
    vector<int> memPrt = {300,600,350,200,750,125};
    for(int i = 0 ; i < memPrt.size(); i++){
        memAvail += memPrt[i];
    }
    vector<int> memFilled(memPrt.size()); //initialize 5 spots to zero
    vector<int> procs = {115,500,358,200,375};
    bool found = false;
    Node * temp = ready2->getHead();
    while(temp!= nullptr){
        for(int j = 0; j < memPrt.size(); j++){
                if((temp->getMemReq() <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
                    //memFilled[j] = procs[i];
                    int diff = memPrt[j] - temp->getMemReq();
                    if(diff > biggestDiff){
                        biggestDiff = diff;
                        bestFitIndex = j;
                    }
                    found = true;
                }
        }
        
        if(found == false) //no partition available
            cout<< "External fragmentation for process size : "<< temp->getMemReq()<<endl;
        else {
            memFilled[bestFitIndex] = temp->getMemReq();
            memAvail -= temp->getMemReq();
            if(temp->getMemReq() < memPrt[bestFitIndex]) //size requested doesn't fully take up partition
                cout<<"Internal fragmentation for process size : "<< temp->getMemReq()<<endl;
        }
        biggestDiff = 0;
        bestFitIndex = 0;
        found = false;
        temp = temp->getRight();
    }

//    for(int i = 0; i < procs.size(); i++){//change to iterate through linked list
//        for(int j = 0; j < memPrt.size(); j++){
//            if((procs[i] <= memPrt[j]) && (memFilled[j] == 0)){//found an open partition
//                //memFilled[j] = procs[i];
//                int diff = memPrt[j] - procs[i];
//                if(diff > biggestDiff){
//                    biggestDiff = diff;
//                    bestFitIndex = j;
//                }
//                found = true;
//            }
//        }
//        
//        if(found == false) //no partition available
//            cout<< "External fragmentation for process size : "<< procs[i]<<endl;
//        else {
//            memFilled[bestFitIndex] = procs[i];
//            memAvail -= temp->getMemReq();
//            if(procs[i] < memPrt[bestFitIndex]) //size requested doesn't fully take up partition
//                cout<<"Internal fragmentation for process size : "<< procs[i]<<endl;
//        }
//        biggestDiff = 0;
//        bestFitIndex = 0;
//        found = false;
//    }
    
    cout<<endl;
}
double npPriority(ifstream &fin, List*& ready2){
    string line = "";
    vector<int> data;
    while(!fin.eof()){
        getline(fin,line,'\n');
        if(line == "")//if eof didn't work
            break;
        stringstream ss(line);
        int x;
        while(ss>>x){
            data.push_back(x);
            if(ss.peek() == ',')
                ss.ignore();
        }
        ready2->priorityInsert(data[0],data[1],data[2],data[3]); //create a PCB with the data and add to tail of queue
        
        line = "";
        data.clear();
    }
    double avgWait = ready2->calcAvgWaitTime();
    cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
    return avgWait;
    
}
double roundRobin(ifstream &fin, List*& ready2){
    string line = "";
    vector<int> data;
    while(!fin.eof()){
        getline(fin,line,'\n');
        if(line == "")//if eof didn't work
            break;
        //fin>>line;
        stringstream ss(line);
        int x;
        while(ss>>x){
            data.push_back(x);
            if(ss.peek() == ',')
                ss.ignore();
        }
        ready2->addPCB(data[0],data[1],data[2],data[3],data[4]); //do this for first round
        line = "";
        data.clear();
    }
    ready2->insertRoundRobin(data[4]);
    double avgWait=ready2->calcRRWaitTime(data[4]);
    cout<<"Average Waiting Time: "<< avgWait <<endl<<endl;
    return avgWait;
    
    
}
void readFile(ifstream &fin){
    cout<<"Please enter name of text file: ";
    string file;
    //add check to see if actually able to open text file
    cin>>file;
    fin.open(file);
    bool open = false;
    while(open!=true){
        if(fin.is_open()){
            cout<<"File opened successfully. "<<endl<<endl;
            open = true;
        }
        else{
            cout<<"Error opening file. Please retry: ";
            cin>> file;
            fin.open(file);
        }
    }
}
void userInput(List*& ready, int option){
    int PID = 0;
    int arr = 0;
    int burst = 0;
    int prior = 0;
    int q = 0;
    bool input = true;
    bool propInput = false;
    string inpChoice;
    while(input == true){
        cin.clear();
        cout<<"Please enter Process PID: ";
        cin>> PID;
        cout<<"Please enter Arrival Time: ";
        cin>> arr;
        cout<<"Please enter Burst Time: ";
        cin>> burst;
        cout<<"Please enter Priority: ";
        cin>> prior;
        cout<<"Please enter Q value: ";
        cin>>q;
        if(option == 1)
            ready->addPCB(PID,arr,burst,prior);
        else if(option ==2)
            ready->priorityInsert(PID,arr,burst,prior);
        else//Round Robin
            ready->addPCB(PID,arr,burst,prior,q);
        while(propInput == false){
            //cin.clear();
            cout<<endl;
            cout<<"Press 1 to input another process \n"
            << "Press 2 to quit \n \n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin>>inpChoice;
            if(inpChoice == "1"){
                propInput = true;
            }
            else if(inpChoice == "2"){
                propInput = true;
                input = false;
            }
            else{
                cout<< "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
            }
        }
        propInput = false; //reset
        
    }
    if(option ==1 || option ==2)
        cout<<"Average Waiting Time: "<< ready->calcAvgWaitTime() <<endl<<endl;
    else//RR
    {
        ready->insertRoundRobin(q);
        cout<<"Average Waiting Time: "<< ready->calcRRWaitTime(q)<<endl<<endl;
    }
}
