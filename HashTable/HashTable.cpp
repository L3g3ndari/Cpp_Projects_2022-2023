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
  int index = hashFunction(student -> getStudent().getID());//hashFunction returns the index
  for (auto i = slots[index].head; i != NULL; i = i -> getNext()) {
    //slots[index].head//Use index to determine which slot to add to
  //Add to that slot's linked list
  }
}

void HashTable::remove(int ID) {
  
}

void HashTable::rehash() {

}

void HashTable::print() {

}
