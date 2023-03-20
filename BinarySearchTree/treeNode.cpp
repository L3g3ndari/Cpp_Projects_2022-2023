#include <iostream>
#include "treeNode.h"

using namespace std;

treeNode::treeNode(char Value) {
  value = Value;
  right = NULL;
  left = NULL;
}

treeNode::~treeNode() {
  value = 0;
  right = NULL;
  left = NULL;
}

int treeNode::getValue() {//returns the char
  return value;
}

void treeNode::setRight(treeNode* newRight) {
  right = newRight;
}

void treeNode::setLeft(treeNode* newLeft) {
  left = newLeft;
}

treeNode* &treeNode::getRight() {
  return right;
}
treeNode* &treeNode::getLeft() {
  return left;
}
