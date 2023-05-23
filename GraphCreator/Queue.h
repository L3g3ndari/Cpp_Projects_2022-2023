#include <iostream>
#include "Vertex.h"

using namespace std;

class Queue {
 public:
  Queue();
  //~Queue();
  char enqueue(Vertex*);
  char dequeue();
  char peek();
  int getSize();

 private:
  Vertex* head;
  Vertex* tail;
  int length;
};
