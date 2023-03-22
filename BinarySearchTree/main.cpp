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
#include <fstream>
#include "treeNode.h"

using namespace std;

void printTree(treeNode* current, int depth);
void add(treeNode* &current, int subject);
void deleteNode(treeNode* target);
bool search(treeNode* root, int target);
treeNode* searchN(treeNode* root, int target);

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
      else {
	cout << "That is not a valid input type. Please type either 1 or 2." << endl;
      }
    }

    if (strcmp(command, "DELETE") == 0) {
      cout << "What value would you like to delete?" << endl << "Target: ";
      int target;
      cin >> target;
      treeNode* searchResult = searchN(root, target);
      while (searchResult != NULL) {//it exists
        cout << "We are deleting: " << searchResult -> getValue() << endl;
	deleteNode(searchResult);
	//searchResult = searchN(root, target);
	searchResult = NULL;
      }
      cout << "Deleted all occurences of " << target << " in the tree." << endl;
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
    if (current -> getLeft() == NULL) {
      current -> setLeft(new treeNode(subject));
      return;
    }
    add(current -> getLeft(), subject);
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    if (current -> getRight() == NULL) {
      current -> setRight(new treeNode(subject));
      return;
    }
    add(current -> getRight(), subject);
  }
}

void deleteNode(treeNode* target) {
  if (target == NULL) return;
  //Cases
  //No children
  //1 child
  //2 children
  
  int numKids = (target -> getLeft() != NULL) + (target -> getRight() != NULL);
  if (numKids == 2) {//2 children
    cout << "2 child deletion" << endl;
  }
  else if (numKids == 1) {//1 child
    cout << "1 child deletion" << endl;
  }
  else {//0 children
    cout << "no children deletion \n" << flush;
    cout << "Parent: " << target -> getParent() << flush;
    cout << "\nParent value: " << target -> getParent() -> getValue() << flush;
    if (target -> getParent() -> getRight() == target) {//if we know target to be the right child
      cout << "We are the right child." << endl;
      target -> getParent() -> setRight(NULL);
    }
    else {
      cout << "We are the left child." << endl;
      target -> getParent() -> setLeft(NULL);
    }
    cout << "Deleting target..." << endl;
    delete target;
  }
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

treeNode* searchN(treeNode* current, int target) {//same as bool search, but returns the node that matches
  if (current == NULL) {
    return NULL;
  }
  if (target == current -> getValue()) {
    return current;
  }
  treeNode* rightResult = searchN(current -> getRight(), target);
  treeNode* leftResult = searchN(current -> getLeft(), target);
  if (rightResult != NULL) {
    return rightResult;
  }
  return leftResult;
}
