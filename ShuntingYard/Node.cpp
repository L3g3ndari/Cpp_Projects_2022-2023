#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char Value) {
  next = NULL;
  value = Value;
  right = NULL;
  left = NULL;
  previous = NULL;
}

Node::~Node() {
  next = NULL;
}

char Node::getValue() {//returns the char
  return value;
}

Node* Node::getNext() {
  return next;
}

void Node::setNext(Node* newnext) {
  next = newnext;
}

void Node::setRight(Node* newRight) {
  right = newRight;
}

void Node::setLeft(Node* newLeft) {
  left = newLeft;
}

void Node::setPrevious(Node* newPrev) {
  previous = newPrev;
}

Node* Node::getRight() {
  return right;
}
Node* Node::getLeft() {
  return left;
}
Node* Node::getPrevious() {
  return previous;
}
