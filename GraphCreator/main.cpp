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
#include <Node.h>

using namespace std;

int main() {
  cout << "Welcome to Graph Creator. Your available commands are ADD, DELETE, PRINT, PATH, and QUIT." << endl;

  vector<Node> nodeList;
  vector<Edge> edgeList;
  vector<vector<bool>> adjacency;
  
  while (true) {
    cout << endl << "Expecting new command: ";
    char command[20];
    cin >> command;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(command, "ADD") == 0) {
      cout << "Adding a node or an edge (n/e)" << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == 'n') {//add a node
	cout << endl << "Label: ";
	char label[10];
	cin >> label;
	//add it
      }
    }

    if (strcmp(command, "PRINT") == 0) {

    }

    if (strcmp(command, "PATH") == 0) {

    }

    if (strcmp(command, "DELETE") == 0) {

    }

    if (strcmp(command, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    
  }

  
}
