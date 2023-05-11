#include <iostream>
#include <Node.h>

using namespace std;

class Edge {
 public:
  Edge(int Weight, Node* First, Node* Second);//constructs a node
  ~Edge();//deconstructor
  int getWeight();//returns the integer that the node stores
  void setWeight(int);
  void setFirst(Node*);
  void setSecond(Node*);
  Node* &getFirst();
  Node* &getSecond();
 private:
  int weight;
  Node* first;
  Node* second;
};
