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
void printTree(treeNode* current, int depth);
void deleteNode(treeNode* target);
bool search(treeNode* root, int target);
treeNode* searchN(treeNode* root, int target);


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
      printTree(root, 0);
    }

    if (strcmp(command, "DELETE") == 0) {
      cout << "What value would you like to delete?" << endl << "Target: ";
      int target;
      cin >> target;
      while (searchN(root, target) != NULL) {//it exists
	treeNode* searchResult = searchN(root, target);
	//cout << "We are deleting: " << searchResult -> getValue() << endl;
	deleteNode(searchResult);
	//searchResult = searchN(root, target);
	searchResult = NULL;
      }
      cout << "Deleted all occurences of " << target << " in the tree." << endl;
    }

    if (strcmp(command, "SEARCH") == 0) {
      cout << endl << "What value would you like to search for?" << endl << "Search: ";
      int searchTerm;
      cin >> searchTerm;
      if (search(root, searchTerm) == true) {//we found it!
	cout << searchTerm << " exists in the tree." << endl;
      }
      else {
	cout << "Could not find " << searchTerm << " in the tree." << endl;
      }
    }

    if (strcmp(command, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
  }
}

void add(treeNode* &current, int subject) {
  if (current == NULL) {//adding to the root
    current = new treeNode(subject, 'B');
    return;
  }
  if (subject < current -> getValue()) {//if subject is less than current
    //keep traversing left
    if (current -> getLeft() == NULL) {
      current -> setLeft(new treeNode(subject, 'R'));
      return;
    }
    add(current -> getLeft(), subject);
    //complete checks
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    if (current -> getRight() == NULL) {
      current -> setRight(new treeNode(subject, 'R'));
      return;
    }
    add(current -> getRight(), subject);
    //complete checks
  }
}

void printTree(treeNode* current, int depth) {
  if (current -> getRight() != NULL) {//if current's right child has something
    printTree(current -> getRight(), depth+1);
  }
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << current -> getColor() << current -> getValue() << endl;
  if (current -> getLeft() != NULL) {//if left child has something
    printTree(current -> getLeft(), depth+1);
  }
}

void deleteNode(treeNode* target) {

}

bool search(treeNode* current, int target) {
  if (current == NULL) {
    return 0;
  }
  if (target == current -> getValue()) {
    return 1;
  }
  return search(current -> getRight(), target) + search(current -> getLeft(), target);
}

treeNode* searchN(treeNode* root, int target) {
  return NULL;
}
