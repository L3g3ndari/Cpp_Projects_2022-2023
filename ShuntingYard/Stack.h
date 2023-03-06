#include <iostream>
#include "Node.h"

using namespace std;

class Stack {
 public:
  Stack();
  ~Stack();
  void push(Node*);
  char peek();
  char pop(Node*);

 private:
  Node* head;
};
