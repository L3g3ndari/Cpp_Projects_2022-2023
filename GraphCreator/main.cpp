/*
Nathan Wu
Graph Creator
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:

This program creates a basic directed graph. User can add and delete nodes and edges. Nodes can be labeled and edges can be given a weight. There is also a function that will find the shortest path between two nodes.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  cout << "Welcome to Graph Creator. Your available commands are ADD, DELETE, PRINT, FSP, and QUIT." << endl;

  while (true) {
    cout << endl << "Expecting new command: ";
    char command[20];
    cin >> command;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(command, "ADD") == 0) {
      cout << "Adding a node or anb edge (n/e)" << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == 'n') {//add a node
	cout << endl << "Label: ";
	char label[10];
	cin >> label;
	//Add it
	}
      }

  
}
