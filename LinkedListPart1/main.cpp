/*
Linked List Part 1
Nathan Wu
C++ Programming
Mr. Galbraith
Period 5
Date Completed: 01/05/2023
Outside Sources Used: roughly reused my Student class from StudentList
 */

#include <iostream>
#include <cstring>
#include "Node.h"
#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

using namespace std;

int main () {
  Node* head = new Node(new Student("Jason", "Galbraith", 123456, 4.229));//sets the first node
  head -> getStudent().printInfo();//prints the first node
  cout << endl;
  head -> setNext(new Node(new Student("Daren", "Kostov", 508324, 3.89)));//setting the second node
  head -> getNext() -> setNext(new Node(new Student("Nathan", "Wu", 394621, 4.229)));//etc
  head -> getNext() -> getStudent().printInfo();//prints second node
  cout << endl;
  head -> getNext() -> getNext() -> getStudent().printInfo();//etc
  //head -> getNext() -> getNext() -> getNext() -> getStudent();//gives seg fault because the next node is NULL.
  cout << "Executed successfully." << endl;
}
