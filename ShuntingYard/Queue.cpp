#include <iostream>
#include "Queue.h"

using namespace std;

Queue::Queue() {
  head = NULL;
  tail = NULL;
  length = 0;
}

int Queue::getSize() {
  return length;
}

char Queue::enqueue(Node* input) {//add to tail
  if (tail == NULL) {
    tail = input;
    head = input;
  }
  else {
    tail -> setNext(input);
    tail = input;    
  }
  length++;
  //cout << "Enqueued " << input -> getValue() << endl;
  return input -> getValue();
}

char Queue::dequeue() {//delete head and then return it
  if (head == NULL) {
    cout << "Queue is empty." << endl;
    return 'L';
  }
  //cout << "BLAHAHA" << endl;
  char temp = head -> getValue();//this is what we're returning at the end
  Node* oldHead = head;
    //cout << "blah2" << endl;
    //cout << "Head: " << head << endl;
    //cout << "HeadNext: " << head -> getNext() << endl;
    head = head -> getNext();//create the new head
    delete oldHead;
    //cout << "Temp: " << temp << endl;
    //cout << "TempNext: " << temp -> getNext() << endl;
    //cout << "TempVal: " << temp -> getValue() << endl;
    length--;
    return temp;//change the return to char?
}

char Queue::peek() {//returns value of head
  if (head != NULL) {
    return head -> getValue();
  }
  else {
    cout << "Queue is empty." << endl;
    return 'L';
  }
}
