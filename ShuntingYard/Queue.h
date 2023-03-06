#include <iostream>
#include "Node.h"

using namespace std;

class Queue {
 public:
  Queue();
  ~Queue();
  void enqueue(Node*);
  Node* dequeue();
  char peek();

 private:
  Node* head;
  Node* tail;
};
