#include <iostream>
#include "Vertex.h"

using namespace std;

Vertex::Vertex(char* Label) {
  label = Label;
}

Vertex::~Vertex() {
  label = "[Empty]";
}

char* Vertex::getLabel() {//returns the label
  return label;
}

void Vertex::setLabel(char* newLabel) {
  label = newLabel;
}
