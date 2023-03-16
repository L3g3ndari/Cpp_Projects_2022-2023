#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack();
  //~Stack();
  void push(Node* head);
  char peek();
  char pop();

 private:
  Node* head;
};
