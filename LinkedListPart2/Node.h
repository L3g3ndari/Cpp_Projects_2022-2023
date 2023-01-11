/*
  Node class
  Contains: Constructor, Destructor, gets student pointer
  setting the next node, and getting the next node
 */
#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "Student.h"
using namespace std;
class Node{
 public:
  Node();
  Node(Student* newStudent);
  ~Node();
  Student* getStudent();
  void setNext(Node* newNext);
  Node* getNext();
 private:
  Node* next;
  Student* student;
};

#endif 
