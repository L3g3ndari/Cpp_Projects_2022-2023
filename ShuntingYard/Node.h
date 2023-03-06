#ifndef NODE
#define NODE
#include <iostream>

using namespace std;

class Node {
 public:
  Node(char Value);//constructs a node
  ~Node();//deconstructor
  char getValue();//returns the character that the node stores
  Node* getNext();//gives the next pointer in the linked list
  void setNext(Node*);//sets the next pointer in the linked list
  void setRight(Node*);
  void setLeft(Node*);
  void setPrevious(Node*);
  Node* getRight();
  Node* getLeft();
  Node* getPrevious();
 private:
  char value;
  Node* next;
  Node* right;
  Node* left;
  Node* previous;
};

#endif
