/*
Nathan Wu
Red Black Tree
C++ Programming
Mr. Galbraith
Project Completed:
Outside Sources Used:
 - https://www.geeksforgeeks.org/insertion-in-red-black-tree/

*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "treeNode.h"

using namespace std;

void add(treeNode* &current, int subject, treeNode* &root);
void printTree(treeNode* current, int depth);
void deleteNode(treeNode* target);
bool search(treeNode* root, int target);
treeNode* searchN(treeNode* root, int target);
void addFix(treeNode* subject, treeNode* root);


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
	add(root, input, root);
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
	    add(root, num, root);
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

void add(treeNode* &current, int subject, treeNode* &root) {
  if (current == NULL) {//adding to the root
    current = new treeNode(subject, 'R');
    addFix(current, root);
    return;
  }
  if (subject < current -> getValue()) {//if subject is less than current
    //keep traversing left
    if (current -> getLeft() == NULL) {
      current -> setLeft(new treeNode(subject, 'R'));
      //fix if neccessary (rebalance)
      addFix(current -> getLeft(), root);
      return;
    }
    add(current -> getLeft(), subject, root);
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    if (current -> getRight() == NULL) {
      current -> setRight(new treeNode(subject, 'R'));
      //fix if neccessary (rebalance)
      addFix(current -> getRight(), root);
      return;
    }
    add(current -> getRight(), subject, root);
  }
}

void addFix(treeNode* &subject, treeNode* &root) {
  if (subject == root) {//if subject is root, then we need to make it black
    subject -> makeBlack(subject);
    return;
  }
  if (subject -> getParent() == NULL || subject -> getParent() -> getColor() == 'B' || subject -> getColor() == 'B') {//we don't have to do any recoloring in these cases
    return;
  }
  //From now on, we assume that the node we just added is not the root. We also assume that the node is red.
  if (subject -> getParent() -> getColor() != 'B') {//if the parent is not black (it is red) a rbt property has been violated and we must fix
    if (subject -> getUnc(subject) != subject && subject -> getUnc(subject) -> getColor() == 'R') {//checking if uncle is red. If so, only recoloring is required. If getUnc() returns itself, then it doesn't exist and we're looking at a null leaf, which is black.
      //parent and uncle become black, grandparent becomes red
      subject -> getParent() -> setBlack(subject -> getParent());//make parent black
      subject -> getUnc(subject) -> setBlack(subject -> getUnc(subject));//make uncle black
      if (subject -> getGrand(subject) != subject) {//if grandparent exists
	subject -> getGrand(subject) -> setRed(subject -> getGrand(subject));//make grandparent red
      }
      //call recursively on subject's grandparent
      if (subject -> getGrand(subject) != subject) {//if grandparent exists
	addFix(subject -> getGrand(subject));
      }
      else {//we are on height=2 and we just need to check our parent (which should be the root)
	addFix(subject -> getParent());
      }
    }
    else if (subject -> getUnc(subject) != subject && subject -> getUnc(subject) -> getColor() == 'B') {//if uncle is black, we need to do rotations
      //check for the 4 cases: Left Left (LL), Left Right (LR), etc. (RR), (RL).
      //Should probably TEST at this point
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
  cout << current -> getColor() << current -> getValue() << endl;
  if (current -> getLeft() != NULL) {//if left child has something
    printTree(current -> getLeft(), depth+1);
  }
}

void deleteNode(treeNode* target) {

}

bool search(treeNode* current, int target) {//same search function as BST
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
