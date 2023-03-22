#include <iostream>

using namespace std;

class treeNode {
 public:
  treeNode(int Value);//constructs a node
  ~treeNode();//deconstructor
  int getValue();//returns the integer that the node stores
  void setValue(int);
  void setRight(treeNode*);
  void setLeft(treeNode*);
  treeNode* &getRight();
  treeNode* &getLeft();
  void setParent(treeNode*);
  treeNode* &getParent();
 private:
  int value;
  treeNode* right;
  treeNode* left;
  treeNode* parent;
};
