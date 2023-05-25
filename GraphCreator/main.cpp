/*
Nathan Wu
Graph Creator
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:
 - https://www.programiz.com/dsa/dijkstra-algorithm
 - https://www.algotree.org/algorithms/single_source_shortest_path/dijkstras_shortest_path_c++/

This program creates a basic directed graph. User can add and delete nodes and edges. Nodes can be labeled and edges can be given a weight. There is also a function that will find the shortest path between two nodes.

 - Nathan's Quick Notes 5/23/2023 - 
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
#include <limits.h>
#include <unordered_map>
//#include "Vertex.h"
//#include "Edge.h"

using namespace std;

void addVertex(vector<vector<int>> &matrix, vector<char*> &nodeList, char* inputLabel);
void addEdge(vector<vector<int>> &matrix, vector<char*> &nodeList, int weight, char* label1, char* label2);
int getVertexIndex(vector<char*> &nodeList, char* label);
bool vertexExists(vector<char*> nodeList, char* label);
//getConnectedEdges function   - What type of return is this?
void deleteVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label);
void deleteEdge(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label1, char* label2);
void printAdj(vector<vector<int>> matrix, vector<char*> nodeList);
void findShortestPath(vector<vector<int>> matrix, vector<char*> nodeList, char* origin, char* dest);
bool isNumber(char*);
void printNodeList(vector<char*> nodeList);

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
	addVertex(matrix, nodeList, label);
      }
      else if (typeInput == 'e') {//add an edge
	cout << endl << "First Connected Vertex: ";
	char v1[10];
	cin >> v1;
	cout << endl << "Second Connected Vertex: ";
	char v2[10];
	cin >> v2;
	if (vertexExists(nodeList, v1) == true && vertexExists(nodeList, v2) == true) {//if both entered vertices exist, we can create an edge between them.
	  cout << endl << "Weight: ";
	  char weight[5];
	  cin >> weight;
	  if (atoi(weight) != 0) {
	    int weightNum = atoi(weight);
	    addEdge(matrix, nodeList, weightNum, v1, v2);
	  }
	  else {
	    cout << endl << "Not a valid input. The weight of an edge must be a integer value." << endl;
	  }
	}
	else {
	  cout << endl << "You entered a vertex that doesn't exist. Please try again." << endl;
	}
      }
      else {
	cout << endl << "Not a valid input. Please enter either \"v\" to add a vertex or \"e\" to add an edge." << endl;
      }
    }

    if (strcmp(command, "PRINT") == 0) {
      printAdj(matrix, nodeList);
    }

    if (strcmp(command, "PN") == 0) {
      printNodeList(nodeList);
    }

    if (strcmp(command, "PATH") == 0) {
      cout << "Enter two vertices and I will find the shortest path between them, if it exists." << endl;
      cout << endl << "Origin: ";
      char origin[10];
      cin >> origin;
      cout << endl << "Destination: ";
      char dest[10];
      cin >> dest;
      if (vertexExists(nodeList, origin) == true && vertexExists(nodeList, dest) == true) {
	findShortestPath(matrix, nodeList, origin, dest);
      }
      else {
	cout << endl << "You entered a vertex that doesn't exist. Please try again." << endl;
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
	if (vertexExists(nodeList, label) == true) {
	  deleteVertex(matrix, nodeList, label);
	}
      }
      else if (typeInput == 'e') {//delete an edge
	cout << "First Connected Vertex: ";
        char v1[10];
        cin >> v1;
        cout << endl << "Second Connected Vertex: ";
        char v2[10];
        cin >> v2;
        if (vertexExists(nodeList, v1) == true && vertexExists(nodeList, v2) == true) {//if both entered nodes exist and an edge exists between them, we can delete the edge.
	  //check if there is an edge between the two nodes in the above if statement
	  deleteEdge(matrix, nodeList, v1, v2);
	}
      }
    }

    if (strcmp(command, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    
  }

  
}


void addVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* inputLabel) {
  char* label = new char[10];
  strcpy(label, inputLabel);
  nodeList.push_back(label);//adds to the nodeList
  matrix.push_back(vector<int>());//adds a new empty row to the matrix
  for (int r = 0; r < matrix.size() - 1; r++) {//populates the row we just added with zeros
    matrix[matrix.size()-1].push_back(0);  
  }
  for (int c = 0; c < matrix.size(); c++) {
    matrix[c].push_back(0);
  }
  cout << endl << "Added Vertex " << label << endl;
}

void addEdge(vector<vector<int>>& matrix, vector<char*>& nodeList, int weight, char* label1, char* label2) {
  int firstIndex = getVertexIndex(nodeList, label1);
  int secondIndex = getVertexIndex(nodeList, label2);
  if (firstIndex == secondIndex) {
    cout << endl << "Please specify two different vertices when adding an edge." << endl;
    return;
      }
  matrix[firstIndex][secondIndex] = weight;
  cout << endl << "Edge of weight " << weight << " was added between nodes " << label1 << " and " << label2 << endl;
}

int getVertexIndex(vector<char*>& nodeList, char* label) {//assumes that the vertex being passed in exists
  //cout << "Getting index of vertice " << label << endl;
  for (int i = 0; i < nodeList.size(); i++) {
    if (strcmp(label, nodeList[i]) == 0) return i;
  }
  cout << "Used getVertexIndex but didn't find the specified vertex (it probably doesn't exist)." << endl;
  return -1;
}

bool vertexExists(vector<char*> nodeList, char* label) {
  for (int i = 0; i < nodeList.size(); i++) {
    if (strcmp(label, nodeList[i]) == 0) return true;
  }
  return false;
}

bool edgeExists(vector<vector<int>> matrix, vector<char*> nodeList, char* v1, char* v2) {
  if (matrix[getVertexIndex(nodeList, v1)][getVertexIndex(nodeList, v2)] != 0) {
    return true;
  }
  return false;
}

//getConnectedEdges function

void deleteVertex(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label) {
  if (vertexExists(nodeList, label) == false) {
    cout << "The vertex you are trying to delete doesn't exist." << endl;
    return;
  }
  int targetIndex = getVertexIndex(nodeList, label);
  matrix.erase(matrix.begin() + targetIndex);
  for (int i = 0; i < matrix.size(); i++) {
    matrix[i].erase(matrix[i].begin() + targetIndex);
  }
  delete nodeList[targetIndex];
  nodeList.erase(nodeList.begin() + targetIndex);
}

void deleteEdge(vector<vector<int>>& matrix, vector<char*>& nodeList, char* label1, char* label2) {
  int firstIndex = getVertexIndex(nodeList, label1);
  int secondIndex = getVertexIndex(nodeList, label2);
  if (firstIndex == secondIndex) return;
  matrix[firstIndex][secondIndex] = 0;
  cout << endl << "Edge was removed from between nodes " << label1 << " and " << label2 << endl;
}

void printAdj(vector<vector<int>> matrix, vector<char*> nodeList) {
  //print labels in a row
  cout << "  ";
  for (int i = 0; i < matrix.size(); i++) {
    cout << nodeList[i] << " ";
  }
  cout << endl;
  for (int a = 0; a < matrix.size(); a++) {
    cout << nodeList[a] << " ";
    for (int b = 0; b < matrix[0].size(); b++) {
      cout << matrix[a][b] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void printNodeList(vector<char*> nodeList) {
  cout << "Here are all the existing nodes: ";
  for (int i = 0; i < nodeList.size(); i++) {
    cout << nodeList[i] << " ";
  }
  cout << endl;
}

void findShortestPath(vector<vector<int>> matrix, vector<char*> nodeList, char* origin, char* dest) {
  vector<char*> unvisitedNodes;
  vector<int> costs;
  unordered_map<char*, char*> previous;
  int originIndex = getVertexIndex(nodeList, origin);
  int destIndex = getVertexIndex(nodeList, dest);
  for (int i = 0; i < nodeList.size(); i++) {
    unvisitedNodes.push_back(nodeList[i]);//populate vector of visited nodes with the nodes from nodeList
    costs.push_back(INT_MAX);//initializing all the costs to "infinity"
    previous[nodeList[i]] = NULL;//initializes the hash table
  }
  costs[originIndex] = 0;//set the cost of the origin to zero
  
  //Visit the unvisited vertex with the smallest known distance from the origin.
  //For the current vertex, examine its unvisted neighbors
  //For the current vertex, calculate the distance of each neighbor from the origin.
  //If the calculated distance of a vertex is less than the known distance (usually infinity), update the costs with the shorter distance
  //Add the neighbors to the hashtable, with each neighbor being a key and the value being the current vertex
  //Add the current vertex to the visitedNodes vector
  
  //Repeat, visiting the unvisited vertex with the smallest known distance from the start vertex.

  int current = getVertexIndex(nodeList, origin);
  while (visitedNodes.size() != nodeList.size()) {
    //visit unvisited vertex with the smallest known distance from origin.
    for (auto node : nodeList) {//traverses the vertices in the nodeList
      if (node
    }
  }
}

bool isNumber(char* input) {
  for (int i = 0; i < sizeof(input)/sizeof(char); i++) {
    if (isdigit(input[i]) == false) {
      return false;
    }
  }
  return true;
}
