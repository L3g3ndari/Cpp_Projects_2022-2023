#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node(Student* pupil) {
  student = pupil;
  next = NULL;
}

Node::~Node() {
  delete student;
}

Student* Node::getStudent() {//returns the "value" which is the student class
  return (student);
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

