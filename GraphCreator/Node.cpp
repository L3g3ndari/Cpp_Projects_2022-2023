#include <iostream>
#include "Node.h"

using namespace std;

Node::Node(char* Label) {
  label = Label;
}

Node::~Node() {
  label = "[Empty]";
}

char* Node::getLabel() {//returns the label
  return label;
}

void Node::setLabel(char* newLabel) {
  label = newLabel;
}
