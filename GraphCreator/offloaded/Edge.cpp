#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Edge::Edge(int Weight, Vertex* First, Vertex* Second) {
  weight = Weight;
  first = First;
  second = Second;
}

Edge::~Edge() {
  weight = 0;
  first = NULL;
  second = NULL;
}

int Edge::getWeight() {//returns the weight
  return weight;
}

void Edge::setWeight(int newWeight) {
  weight = newWeight;
}

void Edge::setFirst(Vertex* First) {
  first = First;
}

Vertex* Edge::getFirst() {
  return first;
}

void Edge::setSecond(Vertex* Second) {
  second = Second;
}

Vertex* Edge::getSecond() {
  return second;
}

Vertex* Edge::getOtherEnd(Vertex* v) {
  if (v == first) return second;
  else if (v == second) return first;
  else return NULL;
}
