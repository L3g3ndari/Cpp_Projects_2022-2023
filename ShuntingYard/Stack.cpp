#include <iostream>
#include <cstring>
#include "Stack.h"

using namespace std;

Stack::Stack() {
  head = NULL;
};

void Stack::push(Node* input) {//add to head
  if (head == NULL) {
    head = input;
  }
  else {
    Node* temp = head;
    head = input;
    head -> setNext(temp);
    temp -> setPrevious(head);
  }
  //cout << "Pushed " << input -> getValue() << endl;
}

char Stack::peek() {//returns value of head
  if (head != NULL) {
    return head -> getValue();
  }
  return 'L';
}

char Stack::pop() {//deletes head and then returns it
  if (head != NULL) {
    char temp = head -> getValue();//this is what we're returning at the end
    Node* oldHead = head;
    head = head -> getNext();//create the new head
    delete oldHead;//deletes old head
    return temp;
  }
  else {
    //cout << "Stack is empty." << endl;
    return 'L';
  }
}

Node* Stack::popNode() {//deletes head and then returns it
  if (head != NULL) {
    Node* oldHead = head;
    head = head -> getNext();//create the new head
    //delete oldHead;//deletes old head
    return oldHead;
  }
  else {
    //cout << "Stack is empty." << endl;
    return NULL;
  }
}
