#include <iostream>
#include "Student.h"

using namespace std;

class Node {
 public:
  Node(Student);
  ~Node();
  int getStudent();
  Node* getNext();
  void setNext(Node*);
 private:
  Student student;
  Node* next;
};
