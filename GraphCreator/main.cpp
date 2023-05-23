/*
Nathan Wu
Graph Creator
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:

This program creates a basic directed graph. User can add and delete nodes and edges. Nodes can be labeled and edges can be given a weight. There is also a function that will find the shortest path between two nodes.

 - Nathan's Quick Notes - 
We can implement this in the form of an array of linked lists, with the array storing vertices and the linked lists storing all the edges. Edges store the pointer to the connected vertex or its index in the array. A node stores 3 pieces of information: the vertex, a visit marker, and a head pointer to the connected edges.

* Things to Find Out from Mr. Galbraith *
 - What is the implementation? Do I need separate Node and Vertex classes or can I combine all the info into one Node class?
 - Do I need an Edge class?
 - Still very confused on implementation
 - Do the edges only have one direction, since it's a directed graph? Or is it more similar to our graphs in Java where direction doesn't matter?
 - Do I need nodeList and edgeList? Do I need the adjacency table as an object? If so, what type of implementation? Vectors?

*/

#include <iostream>
#include <cstring>
#include <vector>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

void addVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label);
void addEdge();
int getVertexIndex();
Vertex* getVertex();
bool vertexExists();
//getConnectedEdges function   - What type of return is this?
void deleteVertex();
void deleteEdge();
void printAdj();
void findShortestPath();//this must return something else but I don't know what yet
bool isNumber(char*);

int main() {
  cout << "Welcome to Graph Creator. Your available commands are ADD, DELETE, PRINT, PATH, and QUIT." << endl;

  vector<char*> nodeList;
  //vector<Edge*> edgeList;
  vector<vector<int>> matrix;
  
  while (true) {
    cout << endl << "Expecting new command: ";
    char command[20];
    cin >> command;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(command, "ADD") == 0) {
      cout << "Adding a vertex or an edge (v/e)" << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == 'v') {//add a node
	cout << endl << "Label: ";
	char label[10];
	cin >> label;
	addVertex();
      }
      else if (typeInput == 'e') {//add an edge
	cout << "First Connected Vertex: ";
	char* v1;
	cin >> v1;
	cout << endl << "Second Connected Vertex: ";
	char* v2;
	cin >> v2;
	if (vertexExists() == true && vertexExists() == true) {//if both entered vertices exist, we can create an edge between them.
	  cout << endl << "Weight: ";
	  char* weight[5];
	  cin >> weight;
	  if (isNumber(weight) == true) {
	    addEdge();
	  }
	  else {
	    cout << "Not a valid input. The weight of an edge must be a integer value." << endl;
	  }
	}
	else {
	  cout << "You entered a vertex that doesn't exist. Please try again." << endl;
	}
      }
      else {
	cout << "Not a valid input. Please enter either \"v\" to add a vertex or \"e\" to add an edge." << endl;
      }
    }

    if (strcmp(command, "PRINT") == 0) {
      printAdj();
      cout << endl;
    }

    if (strcmp(command, "PATH") == 0) {
      cout << "Enter two vertices and I will find the shortest path between them, if it exists." << endl;
      cout << "Origin: ";
      char* origin[10];
      cin >> origin;
      cout << endl << "Destination: ";
      char* dest[10];
      cin >> dest;
      if (vertexExists() == true && vertexExists() == true) {
	findShortestPath();
      }
      else {
	cout << "You entered a vertex that doesn't exist. Please try again." << endl;
      }
    }

    if (strcmp(command, "DELETE") == 0) {
      cout << "Deleting a vertex or an edge (v/e)" << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == 'v') {//delete a node
        cout << endl << "Label: ";
        char label[10];
        cin >> label;
        deleteVertex();
      }
      else if (typeInput == 'e') {//delete an edge
	cout << "First Connected Vertex: ";
        char* v1;
        cin >> v1;
        cout << endl << "Second Connected Vertex: ";
        char* v2;
        cin >> v2;
        if (vertexExists() == true && vertexExists() == true) {//if both entered nodes exist and an edge exists between them, we can delete the edge.
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


void addVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label) {
  nodeList.push_back(label);//adds to the nodeList
  
  matrix.push_back(vector<int>());//adds a new empty row to the matrix
  for (int r = 0; r < matrix.size() - 1; r++) {//populates the row we just added with zeros
    matrix[matrix.size()-1].push_back(0);  
  }
  for (int c = 0; c < matrix.size(); c++) {
    matrix[c].push_back(0);
  }  
}

void addEdge() {

}

int getVertexIndex() {

}

Vertex* getVertex() {

}

bool vertexExists() {

}

//getConnectedEdges function

void deleteVertex() {

}

void deleteEdge() {

}

void printAdj() {

}

void findShortestPath() {

}

bool isNumber(char* input) {
  for (int i = 0; i < sizeof(input)/sizeof(char); i++) {
    if (isdigit(input[i]) == false) {
      return false;
    }
  }
  return true;
}
