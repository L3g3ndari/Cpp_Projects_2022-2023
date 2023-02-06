#include <iostream>
#ifndef STUDENT
#define STUDENT
#include "Student.h"
#endif

using namespace std;

class Node {
 public:
  Node(Student*);//constructs a node from a student pointer
  ~Node();//deconstructor
  Student getStudent();//returns the value of student, including name, lastName, id, and GPA.
  Node* getNext();//gives the next pointer in the linked list
  void setNext(Node*);//sets the next pointer in the linked list
 private:
  Student* student;
  Node* next;
};
