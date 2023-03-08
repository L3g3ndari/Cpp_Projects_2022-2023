#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  head = NULL;
  tail = NULL;
}

void Queue::enqueue(Node* input) {//add to tail
  if (tail == NULL) {
    tail = input;
    head = input;
  }
  else {
    tail -> setNext(input);
    tail = input;    
  }
  cout << "Enqueue" << endl;
}

Node* Queue::dequeue() {//delete head and then return it
  if (head == NULL) {
    cout << "Stack is empty." << endl;
    return NULL;
  }
  else {
    Node* temp = head;//this is what we're returning at the end
    head = head -> getNext();//create the new head
    return temp;//change the return to char?
  }
}

char Queue::peek() {//returns value of head
  return head -> getValue();
}
