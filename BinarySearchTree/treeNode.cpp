#include <iostream>
#include "treeNode.h"

using namespace std;

treeNode::treeNode(int Value) {
  value = Value;
  right = NULL;
  left = NULL;
}

treeNode::~treeNode() {
  value = 0;
  right = NULL;
  left = NULL;
  parent = NULL;
}

int treeNode::getValue() {//returns the int
  return value;
}

void treeNode::setValue(int newValue) {
  value = newValue;
}

void treeNode::setRight(treeNode* newRight) {
  right = newRight;
  if (right != NULL)
    right -> setParent(this);
}

void treeNode::setLeft(treeNode* newLeft) {
  left = newLeft;
  if (left != NULL)
    left -> setParent(this);
}

treeNode* &treeNode::getRight() {
  return right;
}

treeNode* &treeNode::getLeft() {
  return left;
}

void treeNode::setParent(treeNode* newParent) {
  parent = newParent;
}

treeNode* &treeNode::getParent() {
  return parent;
}
