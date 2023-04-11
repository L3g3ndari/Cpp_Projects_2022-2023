#include <iostream>

using namespace std;

class treeNode {
 public:
  treeNode(int Value, char Color);//constructs a node
  ~treeNode();//deconstructor

  int getValue();//returns the integer that the node stores
  void setValue(int);

  void setRight(treeNode*);
  void setLeft(treeNode*);
  treeNode* &getRight();
  treeNode* &getLeft();

  void setParent(treeNode*);
  treeNode* &getParent();

  treeNode* &getSibling(treeNode*);
  treeNode* &getGrand(treeNode*);
  treeNode* &getUnc(treeNode*);
  
  void setBlack();
  void setRed();
  char getColor();

  int childType(treeNode*);
  
 private:
  int value;
  treeNode* right;
  treeNode* left;
  treeNode* parent;
  char color;
};
