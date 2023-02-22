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
void addFunction();
void deleteFunction();

int main() {
  cout << "Welcome to the Heap." << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" or \"QUIT\"" << endl;

  int* heap[101];
  for (int i = 0; i < 101; i++) {
    heap[i] = NULL;
  }
  
  while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (strcmp(input, "PRINT") == 0) {//if the user types in "PRINT," the printFunction method will be run
      printFunction();
    }

    if (strcmp(input, "ADD") == 0) {//if the user types in "ADD," the addFunction method will be run
      addFunction();
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

}

void addFunction(int* &heap[101]) {
  int inputType = 0;
  int input;
  cout << "What number would you like to add?" << endl;
  cin.getline(input, 64);
  //add to the array in the first available slot
  //The children of slot x are 2x and 2x+1
  //The parent of x is x/2
  //Check the slot's parent and check if it is larger or smaller, adjust by swapping if smaller
}

void deleteFunction() {

}
