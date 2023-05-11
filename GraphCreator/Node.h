#include <iostream>

using namespace std;

class Node {
 public:
  Node(int Label);//constructs a node
  ~treeNode();//deconstructor
  char* getLabel();//returns the integer that the node stores
  void setLabel(char*);
 private:
  int label;
};
