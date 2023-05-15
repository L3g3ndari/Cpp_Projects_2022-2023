#include <iostream>
#include "Node.h"
#include "Edge.h"

using namespace std;

Edge::Edge(int Weight, Node* First, Node* Second) {
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

void Edge::setFirst(Node* First) {
  first = First;
}

Node* Edge::getFirst() {
  return first;
}

void Edge::setSecond(Node* Second) {
  second = Second;
}

Node* Edge::getSecond() {
  return second;
}

Node* Edge::getOtherEnd(Node* n) {
  if (n == first) return second;
  else if (n == second) return first;
  else return NULL;
}
