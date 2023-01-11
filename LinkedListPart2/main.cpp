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

void printFunction();
void addFunction();
void deleteFunction();
void averageFunction();

int main() {
  cout << "Welcome to the Student List Program" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" \"AVERAGE,\" or \"QUIT\"" << endl;

   while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;

    if (input[0] == 'P' &&//I know that I could have used strcmp, but don't hate me, I just used my StudentList code from the beginning of the year.
        input[1] == 'R' &&
        input[2] == 'I' &&
        input[3] == 'N' &&
        input[4] == 'T') {//if the user types in "PRINT," the printFunction method will be run
      printFunction();
    }

    if (input[0] == 'A' &&
        input[1] == 'D' &&
        input[2] == 'D') {//if the user types in "ADD," the addFunction method will be run
      addFunction();
    }

    if (strcmp(input, "AVERAGE") == 0) {
      averageFunction();
    }

    if (input[0] == 'D' &&
        input[1] == 'E' &&
        input[2] == 'L' &&
        input[3] == 'E' &&
        input[4] == 'T' &&
        input[5] == 'E') {//if the user types in "DELETE," the deleteFunction method will be run
      deleteFunction();
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

void printFunction() {}
void addFunction() {}
void deleteFunction() {}
void averageFunction() {}






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
