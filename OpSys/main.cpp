#include <iostream>
void processMgmt();
using namespace std;

int main(int argc, char *argv[])
{
  cout << "Hello World!" << endl;
  bool correct = false;
  string choice ="";
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
             processMgmt();
         else if(choice == "2"){}
             //
         else if(choice == "0")
             correct = true;
         else
             cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
     }

  return 0;
}
void processMgmt(){
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
         if(choice == "1"){}

         else if(choice == "2"){}
             //
         else if(choice == "0")
             correct = true;
         else
             cout << "Incorrect option please enter a correct number corresponding to the menu!"<< endl << endl << endl;
     }

}
