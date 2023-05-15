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
#include "Node.h"
#include "Edge.h"

using namespace std;

void addNode(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, char* newLabel);
void addEdge(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, vector<Edge*> &edgeList, int newWeight, Node* first, Node* second);
int getNodeIndex(Node* n, vector<Node*> &nodeList);
Node* getNode(vector<Node*> &nodeList, char* label);
bool nodeExists(char* label, vector<Node*> &nodeList);
//getConnectedEdges function
void deleteNode(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, char* label);
void deleteEdge(vector<vector<bool>> &adjacencyT, vector<Edge*> &edgeList, int weight);
void printAdj(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, vector<Edge*> &edgeList);
void findShortestPath(vector<vector<bool>> &adjacencyT, Node* start, Node* end);//this must return something else but I don't know what yet

int main() {
  cout << "Welcome to Graph Creator. Your available commands are ADD, DELETE, PRINT, PATH, and QUIT." << endl;

  vector<Node*> nodeList;
  vector<Edge*> edgeList;
  vector<vector<bool>> adjacencyT;
  
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
	addNode(adjacencyT, nodeList, label);
      }
      else if (typeInput == 'e') {//add an edge
	cout << "First Connected Node: ";
	char* node1;
	cin >> node1;
	cout << endl << "Second Connected Node: ";
	char* node2;
	cin >> node2;
	if (nodeExists(node1, nodeList) == true && nodeExists(node2, nodeList) == true) {//if both entered nodes exist, we can create an edge between them.
	  cout << endl << "Weight: ";
	  int weight[5];
	  cin >> weight;
	  if (weight.isNumber() == true) {
	    addEdge(adjacencyT, nodeList, edgeList, weight, first, second);
	  }
	  else {
	    cout << "Not a valid input. The weight of an edge must be a integer value." << endl;
	  }
	}
	else {
	  cout << "You entered a node that doesn't exist. Please try again." << endl;
	}
      }
      else {
	cout << "Not a valid input." << endl;
      }
      else {
	cout << "Not a valid input. Please enter either \"n\" to add a node or \"e\" to add an edge." << endl;
      }
    }

    if (strcmp(command, "PRINT") == 0) {
      printAdj(adjacencyT, nodeList, edgeList);
      cout << endl;
    }

    if (strcmp(command, "PATH") == 0) {
      cout << "Enter two nodes and I will find the shortest path between them, if it exists." << endl;
      cout << "Origin: ";
      char* origin[10];
      cin >> origin;
      cout << endl << "Destination: ";
      char* dest[10];
      cin >> dest;
      if (nodeExists(origin, nodeList) == true && nodeExists(dest, nodeList) == true) {
	findShortestPath(adjacencyT, blah, blah);
      }
      else {
	cout << "You entered a node that doesn't exist. Please try again." << endl;
      }
    }

    if (strcmp(command, "DELETE") == 0) {
      cout << "Deleting a node or an edge (n/e)" << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == 'n') {//delete a node
        cout << endl << "Label: ";
        char label[10];
        cin >> label;
        deleteNode(adjacencyT, nodeList, label);
      }
      else if (typeInput == 'e') {//delete an edge
	cout << "First Connected Node: ";
        char* node1;
        cin >> node1;
        cout << endl << "Second Connected Node: ";
        char* node2;
        cin >> node2;
        if (nodeExists(node1, nodeList) == true && nodeExists(node2, nodeList) == true) {//if both entered nodes exist and an edge exists between them, we can delete the edge.
	  //check if there is an edge between the two nodes in the above if statement
	}
      }
    }

    if (strcmp(command, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    
  }

  
}


void addNode(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, char* newLabel) {

}

void addEdge(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, vector<Edge*> &edgeList, int newWeight, Node* first, Node* second) {

}

int getNodeIndex(Node* n, vector<Node*> &nodeList) {

}

Node* getNode(vector<Node*> &nodeList, char* label) {

}

bool nodeExists(char* label, vector<Node*> &nodeList) {

}

//getConnectedEdges function

void deleteNode(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, char* label) {

}

void deleteEdge(vector<vector<bool>> &adjacencyT, vector<Edge*> &edgeList, int weight) {

}

void printAdj(vector<vector<bool>> &adjacencyT, vector<Node*> &nodeList, vector<Edge*> &edgeList) {

}

void findShortestPath(vector<vector<bool>> &adjacencyT, Node* start, Node* end) {

}
