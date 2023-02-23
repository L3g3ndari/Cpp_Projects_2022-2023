/*
Nathan Wu
Heap
C++ Programming
Mr. Galbraith
Project Completed: 
Outside Sources Used: 

Description:
*/

#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

void printFunction();
void addFunction(int* heap[101]);
void deleteFunction();

int main() {
  cout << "Welcome to the Heap." << endl;
  cout << "Available Commands: \"PRINT (DISPLAY),\" \"ADD,\" \"DELETE,\" or \"QUIT\"" << endl;

  int* heap[101];
  for (int i = 0; i < 101; i++) {
    heap[i] = NULL;
  }
  
  while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (strcmp(input, "PRINT") == 0 || strcmp(input, "DISPLAY") == 0) {//if the user types in "PRINT" or "DISPLAY the printFunction method will be run
      printFunction();
    }

    if (strcmp(input, "ADD") == 0) {//if the user types in "ADD," the addFunction method will be run
      addFunction(heap);
    }

    if (strcmp(input, "DELETE") == 0) {//if the user types in "DELETE," the deleteFunction method will be run
      
    }

    if (strcmp(input, "QUIT") == 0) {//if the user types in "QUIT," the program will stop running
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction() {
  //start at slot index 1 and find its children, then move to number 2 and find its children, etc.
}

void addFunction(int* heap[101]) {
  int inputType = 0;
  int input;
  cout << "What is the type of input? Type \"1\" for console input or \"2\" for file input." << endl;
  cin >> inputType;
  //clear and ignore
  if (inputType == 1) {//add as console input
    cout << "What number would you like to add?" << endl;
    cin >> input;
    if (input > 0 && input <= 1000) {
      for (int i = 1; i < 101; i++) {//add to the array in the first available slot
	if (heap[i] == NULL) {
	  //THIS IS WHERE YOU LEFT OFF ******************
	}
      }
      //The children of slot x are 2x and 2x+1
      //The parent of x is x/2
      //Check the slot's parent and check if it is larger or smaller, adjust by swapping if smaller
    }
  }
  else if (inputType == 2) {//add from file

  }
  else {//not one of the options
    cout << "That is not a valid input option. Please type either 1 or 2." << endl;
  }
}

void deleteFunction() {

}
