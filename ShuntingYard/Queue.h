#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
 public:
  Queue();
  //~Queue();
  char enqueue(Node*);
  char dequeue();
  char peek();
  int getSize();

 private:
  Node* head;
  Node* tail;
  int length;
};
