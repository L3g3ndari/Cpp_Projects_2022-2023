#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

Node::Node(Student pupil) {
  student = pupil;
  next = NULL;
}

Student Node::getStudent() {
  return student;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}
