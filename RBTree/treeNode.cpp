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
  color = 'R';
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

void treeNode::setBlack() {
  color = 'B';
}

void treeNode::setRed() {
  color = 'R';
}

char treeNode::getColor() {
  return color;
}

treeNode* &treeNode::getSibling(treeNode* subject) {
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

treeNode* &treeNode::getGrand(treeNode* subject) {
  if (subject -> getParent() != NULL && subject -> getParent() -> getParent() != NULL) {
    return subject -> getParent() -> getParent();
  }
  else {
    return subject;
  }
}

treeNode* &treeNode::getUnc(treeNode* subject) {
  if (subject -> getParent() != NULL && subject -> getParent() -> getSibling(subject) != subject -> getParent()) {
    return subject -> getParent() -> getSibling(subject);
  }
  return subject;
}

int treeNode::childType(treeNode* subject) {//returns 1 if right, 2 if left, and 0 if none
  if (subject -> getParent() == NULL) {//we have the root, which has no parent
    return 0;
  }
  else if (subject -> getParent() -> getRight() == subject) {//if we are the right child
    return 1;
  }
  else return 2;//we must be the left child
}
