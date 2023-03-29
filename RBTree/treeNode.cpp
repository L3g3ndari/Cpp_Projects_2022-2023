#include <iostream>
#include "treeNode.h"

using namespace std;

treeNode::treeNode(int Value, char Color) {
  value = Value;
  right = NULL;
  left = NULL;
  color = Color;
}

treeNode::~treeNode() {
  value = 0;
  right = NULL;
  left = NULL;
  parent = NULL;
  color = 'B';
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

void treeNode::makeBlack(treeNode* subject) {
  color = 'B';
}

void treeNode::makeRed(treeNode* subject) {
  color = 'R';
}

char treeNode::getColor() {
  return color;
}

treeNode* &treeNode::getSibling() {
  if (parent != NULL) {
    if (parent -> getLeft() != NULL && parent -> getLeft() == this) {
      if (parent -> getRight() != NULL) {
	return parent -> getRight();
      }
    }
    if (parent -> getRight() != NULL && parent -> getRight() == this) {
      if (parent -> getLeft() != NULL) {
	return parent -> getLeft();
      }
    }
  }
  return parent;
}
