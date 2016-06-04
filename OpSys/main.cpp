#include <iostream>
#include "list.h";
#include "node.h";
void processMgmt(List*& ready1, List*& waiting1);
using namespace std;

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
  return 0;
}
void processMgmt(List *&ready1, List *&waiting1){
     bool correct = false;
     string choice ="";
     cout << "============================== \n";
     cout << "PROCESS MANAGEMENT  \n";
     cout << "============================== \n";

     // main menu runs until user exits it
     while (correct == false)
     {
         // main menu
         cout << "Process Information Input Choices (insert number for one of the options):\n"
              << "\t [1] Manual Input \n"
              << "\t [2] Text File Input \n"
              << "\t [0] exit\n" <<  endl;
         cout << "Select: "<< endl;
         cin >> choice;
         cout << endl;

         // Conditional to run correct mode for the choice or if wrong choice displays a error message
         if(choice == "1"){
             cout<< "Enter Process Information: ";
             int process;
             cin>> process;
             ready1->addPCB(process);
           }

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
             cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
     }

}
