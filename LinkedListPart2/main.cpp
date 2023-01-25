/*
Linked List Part 2
Nathan Wu
C++ Programming
Mr. Galbraith
Period 5
Date Completed: 01/05/2023
Outside Sources Used:
 */

#include <iostream>
#include <cstring>
#include "Node.h"
//#ifndef STUDENT
//#define STUDENT
#include "Student.h"
//#endif

using namespace std;

void printFunction(Node*);
void addFunction(Node*&);
void deleteFunction(Node*);
void averageFunction(Node*);
Node* getPrevious(Node*, int);

int main() {
  cout << "Welcome to the Student List Program" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" \"AVERAGE,\" or \"QUIT\"" << endl;

  Node* head = NULL;
  
   while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (input[0] == 'P' &&//I know that I could have used strcmp, but don't hate me, I just used my StudentList code from the beginning of the year.
        input[1] == 'R' &&
        input[2] == 'I' &&
        input[3] == 'N' &&
        input[4] == 'T') {//if the user types in "PRINT," the printFunction method will be run
      printFunction(head);
    }

    if (input[0] == 'A' &&
        input[1] == 'D' &&
        input[2] == 'D') {//if the user types in "ADD," the addFunction method will be run
      addFunction(head);
    }

    if (strcmp(input, "AVERAGE") == 0) {
      averageFunction(head);
    }

    if (input[0] == 'D' &&
        input[1] == 'E' &&
        input[2] == 'L' &&
        input[3] == 'E' &&
        input[4] == 'T' &&
        input[5] == 'E') {//if the user types in "DELETE," the deleteFunction method will be run
      deleteFunction(head);
    }

    if (input[0] == 'Q' &&
        input[1] == 'U' &&
        input[2] == 'I' &&
        input[3] == 'T') {//if the user types in "QUIT," the program will stop running
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction(Node* head) {
  if(head == NULL) {
    return;
  }
  head -> getStudent() -> printInfo();
  cout << endl;
  printFunction(head -> getNext());
}

void addFunction(Node*& head) {
  char firstName[64];
  char lastName[64];
  int idNum;
  float gpa;
  cout << "What is the student's first name?" << endl;
  cin.getline(firstName, 64);
  //cin.clear();
  //cin.ignore(64, '\n');
  cout << "What is the student's last name?" << endl;
  cin.getline(lastName, 64);
  cout << "What is the student's ID number?" << endl;
  cin >> idNum;
  cout << "Please enter the student's grade point average." << endl;
  cin >> gpa;
  //Add a new node with this information
  Node* secondNode = new Node(new Student(firstName, lastName, idNum, gpa));
  cout << "secondNode: " << secondNode << endl;
  //Recurse through all the nodes
  Node* firstNode = getPrevious(head, idNum);
  cout << "firstNode: " << firstNode << endl;
  Node* thirdNode = NULL;
  if (head == NULL) {//adding first Node
    cout << "if statement!" << endl;
    head = secondNode;
  }
  else if (firstNode == NULL) {//adding node before head
    cout << "hit the first else if statement" << endl;
    Node* oldHead = head;//store head
    head = secondNode;//set head to second
    head -> setNext(oldHead);//set head's next to old head
    //thirdNode = firstNode -> getNext();
    cout << "thirdNode: " << thirdNode << endl;
    //firstNode -> setNext(secondNode);
    //secondNode -> setNext(thirdNode);
  }
  else if(head != NULL) {//adding node after head
    cout << "hit the second else if statement" << endl;
    thirdNode = firstNode -> getNext();
    cout << "thirdNode: " << thirdNode << endl;
    firstNode -> setNext(secondNode);
    secondNode -> setNext(thirdNode);
  }
  //Check for IDs that are less than the one we want to add (1st, 2nd, 3rd; 2nd is the one we want to add)
  //Store the address of the 3rd node
  //Set 1st node's "next" to be 2nd's address.
  //Set 2nd node's "next to be the stored 3rd.
  cout << endl;
  cout << firstName << " " << lastName << " added." << endl;
}

void deleteFunction(Node* head) {
  if (head != NULL) {
    cout << "ID: ";
    int targetID;
    cin >> targetID;
    Node* targetNode = getPrevious(head, targetID);
    //cout << "Address of targetNode: " << targetNode << endl;
    //cout << "targetNode: " << targetNode -> getStudent() -> getID() << endl;
    if (targetNode == NULL || targetNode == NULL || targetNode -> getStudent() -> getID() != targetID) {//if it is not the node we want or if the node doesn't exist...
      cout << "Student not found." << endl;
      return;
    }
    cout << "This is the student we found: " << endl;
    targetNode -> getStudent() -> printInfo();
  }
}

void averageFunction(Node* head) {
  int average;
  
}

Node* getPrevious(Node* targetNode, int id) {//targetNode stores the nodes we are recursing through. id stores the id of the node we want to compare.
  if(targetNode == NULL) {
    return NULL;
  }
  else if (targetNode -> getStudent() -> getID() > id) {
    return NULL;//signaling that this is the one we want
  }
  Node* next = getPrevious(targetNode -> getNext(), id);//goes to the next node
  if (next == NULL) {
    return targetNode;
  }
  else {
    return next;
  }
}




/*TEST CODE from Part 1
int main () {
  Node* head = new Node(new Student("Jason", "Galbraith", 123456, 4.229));//sets the first node
  head -> getStudent() -> printInfo();//prints the first node
  cout << endl;
  head -> setNext(new Node(new Student("Daren", "Kostov", 508324, 3.89)));//setting the second node
  head -> getNext() -> setNext(new Node(new Student("Nathan", "Wu", 394621, 4.229)));//etc
  head -> getNext() -> getStudent() -> printInfo();//prints second node
  cout << endl;
  head -> getNext() -> getNext() -> getStudent() -> printInfo();//etc
  //head -> getNext() -> getNext() -> getNext() -> getStudent();//gives seg fault because the next node is NULL.
  cout << "Executed successfully." << endl;
}
*/
