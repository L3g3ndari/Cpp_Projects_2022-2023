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

void printTree(treeNode* &root);
void add(treeNode* &root, treeNode* subject);
void deleteNode(treeNode* &root, int target);
bool search(int target);

int main() {
  cout << "Welcome to the Binary Search Tree program. Your available commands are ADD, DELETE, PRINT, SEARCH, and QUIT." << endl;

  treeNode* root = NULL;

  while (true) {
    cout << endl << "Expecting new command: ";
    char input[20];
    cin >> input;
    cin.clear();
    cin.ignore(20, '\n');
    cout << endl;

    if (strcmp(input, "ADD") == 0) {
      cout << "Manual input, type \"1\", file input, type \"2\"." << endl;
      char typeInput;
      cin >> typeInput;
      cin.clear();
      cin.ignore(1, '\n');
      if (typeInput == '1') {//add manually
	cout << "Please type a sequence of numbers. Please separate by using space." << endl << "Input Sequence: ";
	char inputSeq[50];
	cin.getline(inputSeq, 50);
	//find out how to parse so that we get integers
      }
      else if (typeInput == '2') {//add by file

      }
      else {
	cout << "That is not a valid input type. Please type either 1 or 2." << endl;
      }
    }

    if (strcmp(input, "DELETE") == 0) {
      
    }

    if (strcmp(input, "PRINT") == 0) {
      
    }

    if (strcmp(input, "SEARCH") == 0) {
      
    }

    if (strcmp(input, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
    
  }
  
}

void printTree(treeNode* &root) {}
void add(treeNode* &root, treeNode* subject) {}
void deleteNode(treeNode* &root, int target) {}
bool search(int target) {
  return true;
}
