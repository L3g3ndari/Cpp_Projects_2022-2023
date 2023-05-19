/*
Nathan Wu
Red Black Tree
C++ Programming
Mr. Galbraith
Project Completed: 4/19/2023
Outside Sources Used:
 - https://www.geeksforgeeks.org/insertion-in-red-black-tree/   for logic.
 - https://algorithmtutor.com/Data-Structures/Tree/Red-Black-Trees/   another perspective on logic.
 - https://www.codesdope.com/course/data-structures-red-black-trees-insertion/   for logic, specifically for rotations. Used pseudocode to build my rotation code.
 - https://www.cs.usfca.edu/~galles/visualization/RedBlack.html   for visualization of RBT concepts and for checking my work.

This project emulates a Red-Black Tree, which is a binary search tree that can (roughly) rebalance itself. So far, the tree can be built, either manually or by file input, printed, and searched.
 
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "treeNode.h"

using namespace std;

void add(treeNode* &root, int subject);
void add(treeNode* current, int subject, treeNode* &root);
void printTree(treeNode* current, int depth);
void printFromRoot(treeNode* current);
void deleteNode(treeNode* target, treeNode* &root);
void deleteRoot(treeNode* &root);
bool search(treeNode* root, int target);
treeNode* searchN(treeNode* root, treeNode* current, int target);
void addFix(treeNode* subject, treeNode* &root);
treeNode* FindInOrderSuc(treeNode* current);
void deleteFix(treeNode* subject, treeNode* &root);
void rRotation(treeNode* subject, treeNode* &root);
void lRotation(treeNode* subject, treeNode* &root);
char getColor(treeNode* subject);
treeNode* FindInorderSuc(treeNode* current);
treeNode* FindInorderPre(treeNode* current);


int main() {//took a lot of code from my BST project to build the skeleton of this one. The READ command is essentially the same. The ADD and DELETE commands are the same, but with the added algorithms of the RBT. PRINT and SEARCH are also the same as my BST.
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
      if (root != NULL) {
	printTree(root, 0);
      }
      else cout << "The tree does not exist" << endl;
    }

    if (strcmp(command, "DELETE") == 0) {
      cout << "What value would you like to delete?" << endl << "Target: ";
      int target;
      cin >> target;
      while (searchN(root, root, target) != NULL) {//it exists
	treeNode* searchResult = searchN(root, root, target);
	//cout << "We are deleting: " << searchResult -> getValue() << endl;
	if (root -> getValue() == target) {
	  deleteRoot(root);
	}
	else {
	  deleteNode(searchResult, root);
	}
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
	cout << searchTerm << " does not exist in the tree." << endl;
      }
    }

    if (strcmp(command, "QUIT") == 0) {
      cout << "Goodbye." << endl;
      exit(0);
    }
  }
}

void add(treeNode* &root, int subject) {//adding at the root
if (root == NULL) {//adding to the root
    root = new treeNode(subject, 'R');
    addFix(root, root);
    return;
  }
  if (subject < root -> getValue()) {//if subject is less than current
    //keep traversing left
    if (root -> getLeft() == NULL) {//when at the end of a branch,
      root -> setLeft(new treeNode(subject, 'R'));//add in the node
      //fix if neccessary (rebalance)
      addFix(root -> getLeft(), root);
      return;
    }
    add(root -> getLeft(), subject, root);
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    if (root -> getRight() == NULL) {//when at the end of a branch,
      root -> setRight(new treeNode(subject, 'R'));//add in the node
      //fix if neccessary (rebalance)
      addFix(root -> getRight(), root);
      return;
    }
    add(root -> getRight(), subject, root);//gets called recursively for transversal
  }
}

void add(treeNode* current, int subject, treeNode* &root) {//adding nodes
  /*
  if (current == NULL) {//adding to the root
    current = new treeNode(subject, 'R');
    addFix(current, root);
    return;
  }
  */
  if (subject < current -> getValue()) {//if subject is less than current
    //keep traversing left
    if (current -> getLeft() == NULL) {//when at the end of a branch,
      current -> setLeft(new treeNode(subject, 'R'));//add in the node
      //fix if neccessary (rebalance)
      addFix(current -> getLeft(), root);
      return;
    }
    add(current -> getLeft(), subject, root);
  }
  else {//if subject is greater than or equal to current
    //keep traversing right
    if (current -> getRight() == NULL) {//when at the end of a branch,
      current -> setRight(new treeNode(subject, 'R'));//add in the node
      //fix if neccessary (rebalance)
      addFix(current -> getRight(), root);
      return;
    }
    add(current -> getRight(), subject, root);//gets called recursively for transversal
  }
}

//Code for rotations was written from pseudocode and logic found on codesdope.com
void rRotation(treeNode* subject, treeNode* &root) {//the subject in the rotation functions is the grandparent of the subject in addFix()
  cout << "Performing Right Rotation on " << subject -> getValue() << endl;
  treeNode* x = subject;//grandparent of the node we just added
  treeNode* y = x -> getLeft();//x's left child
  x -> setLeft(y -> getRight());//y's right child becomes x's left child
  //Fix parent pointers
  if (y -> getRight() != NULL) {
    y -> getRight() -> setParent(x);
  }
  y -> setParent(x -> getParent());
  //make checks for where x is now
  if (x -> getParent() == NULL) {//x is the root
    root = y;
  }
  else if (x -> childType(x) == 1) {//x is right child
    x -> getParent() -> setRight(y);
  }
  else {//x is left child
    x -> getParent() -> setLeft(y);
  }
  y -> setRight(x);//x becomes the right child of y
  x -> setParent(y);//don't forget to fix the parent pointer!
}

void lRotation(treeNode* subject, treeNode* &root) {
  cout << "Performing Left Rotation on " << subject -> getValue() << endl;
  treeNode* x = subject;//grandparent of the node we just added
  treeNode* y = x -> getRight();//x's right child
  x -> setRight(y -> getLeft());//y's left child becoes x's right child
  //Fix parent pointers
  if (y -> getLeft() != NULL) {
    y -> getLeft() -> setParent(x);
  }
  y -> setParent(x -> getParent());
  //make checks for where x is now
  if (x -> getParent() == NULL) {//x is the root
    root = y;
  }
  else if (x -> childType(x) == 2) {//x is left child
    x -> getParent() -> setLeft(y);
  }
  else {//x is right child
    x -> getParent() -> setRight(y);
  }
  y -> setLeft(x);//x becomes the left child of y
  x -> setParent(y);//don't forget to fix the parent pointer!
}

void addFix(treeNode* subject, treeNode* &root) {//this is the complicated part of this project, the algorithms that keep the tree balanced.
  //recoloring always comes first, then restructuring and rotations if recoloring can't fix things.
  if (subject == root) {//if subject is root, then we need to make it black
    subject -> setBlack();
    return;
  }
  if (subject -> getParent() == NULL || subject -> getParent() -> getColor() == 'B' || subject -> getColor() == 'B') {//we don't have to do any recoloring in these cases
    /*Used to test if childType function works (I think it works now)
    if (subject -> childType(subject) == 2) {//subject is a left child
        cout << "I am left child" << endl;
      }
      else cout << "I am not left child" << endl;
    */
    return;
  }
  
  //From now on, we assume that the node we just added is not the root. We also need to remember that the node we are adding is red by default.
  if (subject -> getParent() -> getColor() != 'B') {//if the parent is not black (it is red) a rbt property has been violated and we must fix
    if (subject -> getUnc(subject) != subject && subject -> getUnc(subject) -> getColor() == 'R') {//checking if uncle is red. If so, only recoloring is required. If getUnc() returns itself, then it doesn't exist and we're looking at a null leaf, which is black.
      //parent and uncle become black, grandparent becomes red
      subject -> getParent() -> setBlack();//make parent black
      subject -> getUnc(subject) -> setBlack();//make uncle black
      if (subject -> getGrand(subject) != subject) {//if grandparent exists
	subject -> getGrand(subject) -> setRed();//make grandparent red
      }
      //call recursively on subject's grandparent
      if (subject -> getGrand(subject) != subject) {//if grandparent exists
	addFix(subject -> getGrand(subject), root);
      }
      else {//we are on height=2 and we just need to check our parent (which should be the root)
	addFix(subject -> getParent(), root);
      }
    }//beyond this point, we need to restructure the tree to fix things
    else if (subject -> getUnc(subject) != subject && subject -> getUnc(subject) -> getColor() == 'B' || subject -> getUnc(subject) == NULL) {//if uncle is black or null, we need to do rotations
      if (subject -> getParent() != root) {//if parent is not the root, we proceed with rotations normally
	//after this point, we assume that the tree is not rotating through the root, but make sure to still check if grandparent is root and adjust the head pointer correctly

	//check for the 4 cases: Left Left (LL), Left Right (LR), etc. (RR), (RL).
	if (subject -> childType(subject) == 2) {//subject is a left child
	  cout << "I am left child" << endl;
	  if (subject -> getParent() -> childType(subject -> getParent()) == 2) {
	    cout << "Left Left Case" << endl;
	    //perform right rotation on grandparent
	    treeNode* a = subject -> getGrand(subject);
	    rRotation(a, root);
	    //Recolor a to red and parent of a to black
	    a -> setRed();
	    a -> getParent() -> setBlack();
	  }
	  else if (subject -> getParent() -> childType(subject -> getParent()) == 1) {
	    cout << "Right Left Case" << endl;
	    //perform right rotation at parent
	    treeNode* b = subject -> getParent();
	    rRotation(b, root);
	    //This now becomes an RR case.
	    b = b -> getGrand(b);
	    lRotation(b, root);
            b -> setRed();
            b -> getParent() -> setBlack();
	  }
	  else {//parent is root
	    //what happens???
	    cout << "Parent is root. Didn't know how to proceed from here. This might not even be possible." << endl;
	  }
	}
	else if (subject -> childType(subject) == 1) {//subject is a right child
	  cout << "I am right child" << endl;
	  if (subject -> getParent() -> childType(subject -> getParent()) == 2) {
	    cout << "Left Right Case" << endl;
	    //perform left rotation at parent
	    treeNode* c = subject -> getParent();
	    lRotation(c, root);
	    //This now becomes a LL case.
	    c = c -> getGrand(c);
	    rRotation(c, root);
            //Recolor a to red and parent of a to black
            c -> setRed();
            c -> getParent() -> setBlack();
	  }
	  else if (subject -> getParent() -> childType(subject -> getParent()) == 1) {
	    cout << "Right Right Case" << endl;
	    //perform left rotation at grandparent
	    treeNode* d = subject -> getGrand(subject);
	    lRotation(d, root);
	    //Recolor d to red and parent of d to black
	    d -> setRed();
	    d -> getParent() -> setBlack();
	  }
	  else {//parent is root
	    //what happens???
	    cout << "Parent is root. Didn't know how to proceed from here. This might not even be possible." << endl;
	  }
	}
	else {//subject is the root
	  //what happens?
	  cout << "Checking for 4 cases and we are at the root." << endl;
	}
      }
      else {//parent is the root and we have special rotation cases
	cout << "Parent is the root (special cases?)" << endl;
      }
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

void printFromRoot(treeNode* current) {
  if (current == NULL) return;
  cout << current -> getColor() << current -> getValue() << ": ";
  printFromRoot(current -> getLeft());
  cout << ", ";
  printFromRoot(current -> getRight());
}

treeNode* FindInorderSuc(treeNode* current) {
  current = current -> getRight();
  while (current != NULL && current -> getLeft() != NULL) {
    current = current -> getLeft();
  }
  //cout << "Inorder successor (value): " << current -> getValue() << endl;
  return current;
}

treeNode* FindInorderPre(treeNode* current) {
  current = current -> getLeft();
  while (current != NULL && current -> getRight() != NULL) {
    current = current -> getRight();
  }
  //cout << "Inorder predecessor (value): " << current -> getValue() << endl;
  return current;
}

char getColor(treeNode* subject) {
  if (subject == NULL) return 'B';
  return subject -> getColor();
}

void deleteNode(treeNode* target, treeNode* &root) {
  if (target == NULL) return;
  int numKids = (target -> getLeft() != NULL) + (target -> getRight() != NULL);
  cout << "# of children: " << numKids << "\n" << flush;
  cout << "Target = " << target -> getValue() << "\n" << flush;

  if (numKids == 2) {//2 children
    //cout << "2 child deletion" << endl;
    //find inorder successor
    treeNode* inorderSuc = FindInorderSuc(target);
    treeNode* inorderPre = FindInorderPre(target);
    //replace target's value with inorder successor's value
    target -> setValue(inorderPre -> getValue());
    deleteNode(inorderPre, root);//2-child case has now been converted to a one-child case
    return;
  }
  else if (numKids == 0) {
    cout << "The node we want to delete has zero literal children.\n" << flush;
    if (target -> isBlack() == true) {//we have a double black situation and we need to call cases
      cout << "about to run deleteFix on no child" << endl;
      deleteFix(target, root);
      cout << "finished deleteFix on no child" << endl;
      if (target -> childType(target) == 1) {
        target -> getParent() -> setRight(NULL);
      }
      else target -> getParent() -> setLeft(NULL);
      cout << target -> getParent() -> getLeft() << endl;
      cout << target -> getParent() -> getRight() << endl;
      delete target;
      printFromRoot(root);
      return;
    }
    else {
      //cout << "Parent: " << target -> getParent() << flush;
      //cout << "\nParent value: " << target -> getParent() -> getValue() << flush;
      if (target -> getParent() -> getRight() == target) {//if we know target to be the right child
	//cout << "We are the right child." << endl;
	target -> getParent() -> setRight(NULL);
      }
      else {
	//cout << "We are the left child." << endl;
	target -> getParent() -> setLeft(NULL);
      }
      //cout << "Deleting target..." << endl;
      printFromRoot(root);
      delete target;
      //cout << "deleteNode succeeded\n" << flush;
      return;
    }
  }
  else {//target has 1 child, so we have to call cases
    cout << "The node we want to delete has one child\n" << flush;
    treeNode* the1Child = target -> getRight() == NULL? target -> getLeft() : target -> getRight();//gives the existing child. hmm.
  
    //SWAP target and its one child
    if (target -> childType(target) == 1) {//if target is a right child
      target -> getParent() -> setRight(the1Child);
      the1Child -> setParent(target -> getParent());
    }
    else if (target -> childType(target) == 2) {//if target is a left child
      target -> getParent() -> setLeft(the1Child);
      the1Child -> setParent(target -> getParent());
    }
    else {//target is the root, meaning the swap will make the1Child the root
      root = the1Child;
    }
    the1Child -> setLeft(NULL);
    the1Child -> setRight(NULL);
  
    //Target and its child have been swapped and we can now delete the target (target is now out side the tree).

    //First check if we need to switch the1Child's color

    if (target -> getColor() == 'R') {//if target is red, do nothing

    } 
    else if (the1Child -> getColor() == 'R') {//if target has a red child (the target must be black), and we make the child black
      the1Child -> setBlack();
    }
    else {//both target and its child are black
      //THE CASES BEGIN
      cout << "about to run deleteFix on 1 child" << endl;
      deleteFix(the1Child, root);
      cout << "finished deleteFix on 1 child" << endl;
    }
    delete target;
    return;
  }
}

void deleteFix(treeNode* subject, treeNode* &root) {//target has one child
  cout << "deleteFix initiated\n" << flush; //in the first iteration, subject is the1Child, which replaced target
  while (subject != root && getColor(subject) == 'B') {
    if (subject -> childType(subject) == 2) {//if subject is left child
      treeNode* sib = subject -> getSibling(subject);
      if (getColor(sib) == 'R') {//CASE 1
	cout << "CASE 1: sibling is red" << endl;
	sib -> setBlack();
	subject -> getParent() -> setRed();
	lRotation(sib -> getParent(), root);//used to be sib
	sib = subject -> getSibling(subject);
	//printTree(root, 0);
      }
      if (!sib) {//CASE 2
	cout << "CASE 2: sibling doesn't exist." << endl;
	break;
	//subject = root;
	//continue;
      }
      if (getColor(sib -> getLeft()) == 'B' && getColor(sib -> getRight()) == 'B') {//CASE 3
	cout << "CASE 3: both sibling's children are black." << endl;
	sib -> setRed();
	subject = subject -> getParent();
	continue;
      }
      else {
	if (getColor(sib -> getRight()) == 'B') {//CASE 4
	  cout << "CASE 4: sibling's right child is black, sibling's left child is red" << endl;
	  sib -> getLeft() -> setBlack();
	  sib -> setRed();
	  rRotation(sib, root);//used to be sib -> getLeft()
	  sib = subject -> getSibling(subject);
	}
	if (getColor(subject -> getParent()) == 'R') {//CASE 5
	  cout << "CASE 5: parent is red so we want to switch sibling's color to red" << endl;
	  sib -> setRed();
	}
	else {
	  cout << "CASE 5: parent is black so we want to switch sibling's color to black" << endl;
	  sib -> setBlack();
	}
	subject -> getParent() -> setBlack();
	sib -> getRight() -> setBlack();
	lRotation(sib -> getParent(), root);//used to be sib
	subject = root;
      }
    }
    else if (subject -> childType(subject) == 1) {//if subject is right child
      treeNode* sib = subject -> getSibling(subject);
      if (getColor(sib) == 'R') {
	cout << "CASE 1: sibling is red" << endl;
	sib -> setBlack();
        subject -> getParent() -> setRed();
        rRotation(sib -> getParent(), root);//used to be sib
        sib = subject -> getSibling(subject);
      }
      if (!sib) {
	cout << "CASE 2: sibling doesn't exist." << endl;
	break;
        //subject = root;
        //continue;
      }
      if (getColor(sib -> getLeft()) == 'B' && getColor(sib -> getRight()) == 'B') {
	cout << "CASE 3: both sibling's children are black." << endl;
        sib -> setRed();
        subject = subject -> getParent();
        continue;
      }
      else {
        if (getColor(sib -> getLeft()) == 'B') {
	  cout << "CASE 4: sibling's right child is black, sibling's left child is red" << endl;
          sib -> getRight() -> setBlack();
          sib -> setRed();
          lRotation(sib, root);//used to be sib -> getRight()
          sib = subject -> getSibling(subject);
        }
        if (getColor(subject -> getParent()) == 'R') {
	  cout << "CASE 5: parent is red so we want to switch sibling's color to red" << endl;
	  sib -> setRed();
	}
        else {
	  cout << "CASE 5: parent is black so we want to switch sibling's color to black" << endl;
	  sib -> setBlack();
	}
        subject -> getParent() -> setBlack();
        sib -> getLeft() -> setBlack();
        rRotation(sib -> getParent(), root);//used to be sib
        subject = root;
      }
    }
  }
  subject -> setBlack();
}

void deleteRoot(treeNode* &root) {
  cout << "deleteRoot called\n" << flush;
  if (root == NULL) return;
  int numKids = (root -> getLeft() != NULL) + (root -> getRight() != NULL);
  cout << "# of children: " << numKids << "\n" << flush;

  if (numKids == 2) {//2 children
    //cout << "2 child deletion" << endl;
    //find inorder successor
    treeNode* inorderSuc = FindInorderSuc(root);
    treeNode* inorderPre = FindInorderPre(root);
    //replace target's value with inorder successor's value
    root -> setValue(inorderPre -> getValue());
    deleteNode(inorderPre, root);//2-child case has now been converted to a one-child case
    return;
  }
  else if (numKids == 0) {
    delete root;
    root = NULL;
    return;
  }
  //root has 1 child
  cout << "The root has one child\n" << flush;
  treeNode* the1Child = root -> getRight() == NULL? root -> getLeft() : root -> getRight();//gives the existing child. hmm.

  //make the1Child the root and delete the previous root
  treeNode* temp = root;
  root = the1Child;//child becomes the new root
  root -> setBlack();
  delete temp;
  return;
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

treeNode* searchN(treeNode* root, treeNode* current, int target) {
  //cout << "Remember to fix searchN." << endl;
  if (current == NULL) {
    return NULL;
  }
  if (target == current -> getValue()) {
    return current;
  }
  if (current -> getValue() < target) {
    return searchN(root, current -> getRight(), target);
  }
  return searchN(root, current -> getLeft(), target);
  //treeNode* rightResult = searchN(root, current -> getRight(), target);
  //treeNode* leftResult = searchN(root, current -> getLeft(), target);
  //if (rightResult != NULL) {
  //return rightResult;
  //}
  //return leftResult;
}
