#include <iostream>

using namespace std;

class treeNode {
 public:
  treeNode(char Value);//constructs a node
  ~treeNode();//deconstructor
  int getValue();//returns the character that the node stores
  void setRight(treeNode*);
  void setLeft(treeNode*);
  treeNode* &getRight();
  treeNode* &getLeft();
 private:
  int value;
  treeNode* right;
  treeNode* left;
};
