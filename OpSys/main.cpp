#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include "list.h"
#include "node.h"
using namespace std;

//void processMgmt(List*& ready1, List*& waiting1);
void processMgmt(List*& waiting1);
void firstComeFirstServe(ifstream &fin, List*& ready2);
void npPriority(ifstream &fin, List*& ready2);
void readFile(ifstream &fin);
void roundRobin(ifstream &fin, List*& ready2);
void userInput(List*& ready, int option);


int main(int argc, char *argv[])
{
    bool correct = false;
    string choice ="";
    //List * ready = new List();
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
        else if(choice == "2"){}
        //
        else if(choice == "0")
            correct = true;
        else
            cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
    }
    //ready->printVals();
    cout<<endl;
    //cout<<ready->getQueueTotalTime();
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
                string input = "";
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
                    firstComeFirstServe(fin, ready);
                }
                else{
                    cout<<"Invalid input!"<<endl;
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                delete ready;
                break;
                
            }
            case 2: {
                List * ready = new List();
                string input = "";
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
                    npPriority(fin, ready);
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
                delete ready;
                break;
            }
            case 3: {
                List * ready = new List();
                string input = "";
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
                    roundRobin(fin, ready);
                }
                cout<<"Queue contents:"<<endl;
                ready->printVals();
                cout<<endl<<endl;
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
        ready2->addPCB(data[0],data[1],data[2],data[3],data[4]); //do this for first round
        line = "";
        data.clear();
    }
    ready2->insertRoundRobin(data[4]);
    
    cout<<"Average Waiting Time: "<< ready2->calcRRWaitTime(data[4]) <<endl<<endl;

    
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
            //cout<<endl;
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
