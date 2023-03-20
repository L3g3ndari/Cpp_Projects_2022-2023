/*
Nathan Wu
Shunting Yard Algorithm
Binary Search Tree
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:

This program creates a binary search tree of integers between 1 and 999. The user can add and delete from the tree, as well as search it and display it.
*/

#include <iostream>
#include <cstring>
#include "treeNode.h"

using namespace std;

void printTree(treeNode* current, int depth);
void add(treeNode* &current, int subject);
void deleteNode(treeNode* &current, int target);
bool search(treeNode* root, int target);

int main() {
  cout << "Welcome to the Binary Search Tree program. Your available commands are ADD, DELETE, PRINT, SEARCH, and QUIT." << endl;

  treeNode* root = NULL;

  while (true) {
    cout << endl << "Expecting new command: ";
    char command[20];
    cin >> command;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(command, "ADD") == 0) {
      cout << "Manual input, type \"1\", file input, type \"2\"." << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == '1') {//add manually
	cout << endl << "Please input a number." << endl << "Input: ";
	int input;
	cin >> input;
	if (input > 0 && input < 1000) {//if it is a valid input
	  add(root, input);
	}
      }
      else if (typeInput == '2') {//add by file

      }
      else {
	cout << "That is not a valid input type. Please type either 1 or 2." << endl;
      }
    }

    if (strcmp(command, "DELETE") == 0) {
      
    }

    if (strcmp(command, "PRINT") == 0) {
      printTree(root, 0);
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

void printTree(treeNode* current, int depth) {
  if (current -> getRight() != NULL) {//if current's right child has something
    printTree(current -> getRight(), depth+1);
  }
  for (int i = 0; i < depth; i++) {
    cout << '\t';
  }
  cout << current -> getValue() << endl;
  if (current -> getLeft() != NULL) {//if left child has something
    printTree(current -> getLeft(), depth+1);
  }
}

void add(treeNode* &current, int subject) {
  if (current == NULL) {
    current = new treeNode(subject);
    return;
  }
  if (subject < current -> getValue()) {//if subject is less than current
    //keep traversing left
    add(current -> getLeft(), subject);
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    add(current -> getRight(), subject);
  }
}

void deleteNode(treeNode* &current, int target) {}

bool search(treeNode* current, int target) {
  if (current != NULL) {//while we haven't reached the end of a branch
    cout << "not null" << endl;
    if (target == current -> getValue()) {
      cout << "Found it!" << endl;
      return true;
    }
    else if (target < current -> getValue()) {
      cout << "going left" << endl;
      search(current -> getLeft(), target);
    }
    else {
      cout << "going right" << endl;
      search(current -> getRight(), target);
    }
  }
  return false;//need to find better return value to make this work.
}
