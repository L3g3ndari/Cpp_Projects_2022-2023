/*
Nathan Wu
Red Black Tree
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:

*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "treeNode.h"

using namespace std;

void add(treeNode* &current, int subject);


int main() {
  cout << "Welcome to the Red-Black Tree program. Your available commands are ADD, READ, DELETE, PRINT, SEARCH, and QUIT." << endl;

  treeNode* root = NULL;

  while (true) {
    cout << endl << "Expecting new command: ";
    char command[20];
    cin >> command;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(command, "ADD") == 0) {
      cout << endl << "Please input a number." << endl << "Input: ";
      int input;
      cin >> input;
      if (input > 0 && input < 1000) {//if it is a valid input
	add(root, input);
      }
    }

    if (strcmp(command, "READ") == 0) {
      cout << "File Name: ";
      char fileName[20];
      cin.getline(fileName, 20);
      cin.clear();
      int num;
      ifstream File (fileName);
      if (File.is_open()) {
	while (File >> num) {
	  if (num > 0 && num < 1000) {
	    add(root, num);
	  }
	}
	cout << endl << "Adding from file is completed." << endl;
      }
    }
    
    if (strcmp(command, "PRINT") == 0) {

    }

    if (strcmp(command, "DELETE") == 0) {

    }

    if (strcmp(command, "SEARCH") == 0) {

    }
    
  }
}

void add(treeNode* &current, int subject) {

}
