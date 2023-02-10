#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
  slots = new tableEntry[100];
  tableSize = 100;
}

int HashTable::hashFunction(int ID) {
  return ID % tableSize;
}

void HashTable::insert(Node* student) {
  for (int i = 0; i < tableSize; i++) {//search the hash table for IDs
    for (auto j = slots[i].head; j != NULL; j++) {
      if (j -> getStudent() -> getID() == student -> getStudent() -> getID()) {
	cout << "Student with this ID already exists." << endl;
	return;
      }
    }
  }
  int index = hashFunction(student -> getStudent().getID());//hashFunction returns the index
  auto i = slots[index].head;
  if (i == NULL) {
    //set head to student
    slots[index].head = student;
    slotsUsed++;
    if (slotsUsed >= tableSize/2) {
      rehash();
    }
    return;
  }
  int counter = 0;
  while (i -> getNext() != NULL) {//go through all the slots until the end (tail)
    i = i -> getNext();
    counter++;
  }
  //Use index to determine which slot to add to
  i -> setNext(student);//Add to that slot's linked list

  //check if this bucket has 3 or more student nodes
  if (counter >= 3) {
    rehash();
  }
}

void HashTable::remove(int ID) {
  
}

void HashTable::rehash() {

}

void HashTable::print() {
  for (int i = 0; i < tableSize; i++) {//traverse the hash table
    for (auto j = slots[i].head; j != NULL; j++) {
      j -> getStudent() -> printInfo();
    }
  }
}
