#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "list.h"
#include "node.h"
using namespace std;

void processMgmt(List*& ready1, List*& waiting1);
void firstComeFirstServe(ifstream &fin, List*& ready2);
void npPriority(ifstream &fin, List*& ready2);
void readFile(ifstream &fin);
void roundRobin(ifstream &fin, List*& ready2);

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    bool correct = false;
    string choice ="";
    List * ready = new List();
    List * waiting = new List();
    cout << "============================== \n";
    cout << "SIMULATED OPERATING SYSTEM \n";
    cout << "============================== \n";
    
    // main menu runs until user exits it
    while (correct == false)
    {
        // main menu
        cout << "Mode choices(insert number for one of the options):\n"
        << "\t [1] Process Management \n"
        << "\t [2] Memory Management \n"
        << "\t [0] exit\n" <<  endl;
        cout << "Select: "<< endl;
        cin >> choice;
        cout << endl;
        
        // Conditional to run correct mode for the choice or if wrong choice displays a error message
        if(choice == "1")
            processMgmt(ready, waiting);
        else if(choice == "2"){}
        //
        else if(choice == "0")
            correct = true;
        else
            cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
    }
    ready->printVals();
    cout<<endl;
    cout<<ready->getQueueTotalTime();
    return 0;
}
void processMgmt(List *&ready1, List *&waiting1){
    bool correct = false;
    int choice;
    cout << "============================== \n";
    cout << "PROCESS MANAGEMENT  \n";
    cout << "============================== \n";
    
    // main menu runs until user exits it
    while (correct == false)
    {
        // main menu
        cout << "Process Information Input Choices (insert number for one of the options):\n"
        << "\t [1] Manually Add a PCB to a Given Position in the Queue \n"
        << "\t [2] Default Addition (Add PCB to tail of queue) \n"
        << "\t [3] Delete a PCB with a given PID \n"
        << "\t [4] Default Deletion (given a certain PID) \n"
        << "\t [5] First-Come-First-Serve Scheduling \n"
        << "\t [6] Non-Preemptive Priority Scheduling \n"
        << "\t [7] Round Robin Scheduling \n"
        << "\t [0] exit\n" <<  endl;
        cout << "Select: "<< endl;
        cin >> choice;
        cout << endl;
        
        // Conditional to run correct mode for the choice or if wrong choice displays a error message
        switch(choice){
            case 1: {
                cout<< "Enter Position: ";
                int pos;
                cin>> pos;
                cout<<"Enter data"<<endl;
                int randData;
                cin>> randData;
                ready1->addPCB(pos,randData);
                break;
            }
            case 2: {
                /*cout<<"Enter data"<<endl;
                 int randData;
                 cin>> randData;
                 ready1->addPCB(randData);*/
                break;
            }
            case 3: {
                cout<<"What is the PID of the PCB you wish to delete?";
                int PID;
                cin>>PID;
                int delPID = ready1->deletePCB(PID);
                if(delPID != 0)
                    cout<<"The PID of PCB removed is: "<< PID <<endl<<endl;
                else{}
                break;
            }
            case 4: {
                cout<< "Deleting PCB at beginning of queue "<<endl;
                int PID = ready1->deletePCB();
                if(PID != 0)
                    cout<<"The PID of PCB removed is: "<< PID <<endl<<endl;
                else{}
                break;
            }
            case 5: {
                ifstream fin;
                readFile(fin);
                firstComeFirstServe(fin, ready1);
                break;
                
            }
            case 6: {
                ifstream fin;
                readFile(fin);
                npPriority(fin, ready1);
                break;
            }
            case 7: {
                ifstream fin;
                readFile(fin);
                roundRobin(fin,ready1);
            }
            case 0:{
                correct = true;
                break;
            }
            default: cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
                break;
                
        }
        
        /*if(choice == "1"){
         cout<< "Enter Position: ";
         int pos;
         cin>> pos;
         ready1->addPCB(pos);
         }
         else if()
         
         else if(choice == "2"){
         cout<< "Deleting PCB at beginning of queue "<<endl;
         int PID = ready1->deletePCB();
         if(PID != 0)
         cout<<"The PID of PCB removed is: "<< PID <<endl<<endl;
         else{}
         }
         //
         else if(choice == "0")
         correct = true;
         else
         cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;*/
    }
    
}
void firstComeFirstServe(ifstream &fin, List*& ready2){
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
        ready2->addPCB(data[0],data[1],data[2],data[3]); //default tail insertion due to FCFS
        //for (int i=0; i< data.size(); i++)
        //std::cout << data.at(i)<<std::endl;
        line = "";
        data.clear();
    }
    cout<<"Average Waiting Time: "<<ready2->calcAvgWaitTime()<<endl<<endl;
    
}
void npPriority(ifstream &fin, List*& ready2){
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
        ready2->priorityInsert(data[0],data[1],data[2],data[3]); //create a PCB with the data and add to tail of queue
        //for (int i=0; i< data.size(); i++)
        //std::cout << data.at(i)<<std::endl;
        line = "";
        data.clear();
    }
    //waitTime -= finBurst; //subtract last burst time to calculate waitTime
    cout<<"Average Waiting Time: "<< ready2->calcAvgWaitTime() <<endl<<endl;
    
}
void roundRobin(ifstream &fin, List*& ready2){
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
        ready2->addPCB(data[0],data[1],data[2],data[3],10); //do this for first round
        //for (int i=0; i< data.size(); i++)
        //std::cout << data.at(i)<<std::endl;
        line = "";
        data.clear();
    }
    ready2->insertRoundRobin(10); //NEED TO UNHARDCODE ***

   // cout<<"Average Waiting Time: "<<ready2->calcAvgWaitTime()<<endl<<endl;
    
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
            cout<<"File opened successfully. "<<endl;
            open = true;
        }
        else{
            cout<<"Error opening file. Please retry: ";
            cin>> file;
            fin.open(file);
        }
    }
}

