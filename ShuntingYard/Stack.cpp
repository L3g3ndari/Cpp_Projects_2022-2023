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
  cout << "Push" << endl;
}

char Stack::peek() {//returns value of head
  return head -> getValue(); 
}

char Stack::pop() {//deletes head and then returns it
  if (head == NULL) {
    cout << "Stack is empty." << endl;
    //return 'L';
  }
  char temp = head -> getValue();//this is what we're returning at the end
  Node* oldHead = head;
  head = head -> getNext();//create the new head
  delete oldHead;//deletes old head
  return temp;
}
