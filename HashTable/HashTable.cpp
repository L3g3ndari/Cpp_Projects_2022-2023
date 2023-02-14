#include <iostream>
#include "HashTable.h"

using namespace std;

HashTable::HashTable() {
  slots = new tableEntry*[100];
  for (int i = 0; i < 100; i++) {
    slots[i] = new tableEntry();
  }
  tableSize = 100;
}

int HashTable::hashFunction(int ID) {
  return ID % tableSize;
}

void HashTable::insert(Node* student) {
  for (int i = 0; i < tableSize; i++) {//search the hash table for IDs
    Node* j = slots[i] -> head;
    while (j != NULL) {
      if (j -> getStudent() -> getID() == student -> getStudent() -> getID()) {
        cout << "Student with this ID already exists." << endl;
        return;
      }
      j = j -> getNext();
    }

      /*for (auto j = slots[i] -> head; j != NULL; j++) {
      cout << " 100" << endl;
      if (j -> getStudent() -> getID() == student -> getStudent() -> getID()) {
	cout << "Student with this ID already exists." << endl;
	return;
      }
      }*/
  }
  cout << " 101" << endl;
  int index = hashFunction(student -> getStudent() -> getID());//hashFunction returns the index
  Node* i = slots[index] -> head;
  if (i == NULL) {
    //set head to student
    slots[index] -> head = student;
    cout << "student has been added to the linked list ." << endl;
    slotsUsed++;
    cout << "Slots Used: " << slotsUsed << endl;
    if (slotsUsed >= tableSize/2) {
      cout << "REHASHING" << endl;
      rehash();
    }
    return;
  }
  int counter = 0;
  while (i -> getNext() != NULL) {//go through all the slots until the end (tail)
    i = i -> getNext();
    counter++;
    cout << "Counter: " << counter << endl;
  }
  //Use index to determine which slot to add to
  i -> setNext(student);//Add to that slot's linked list, MIGHT NEED TO ADD SOME MORE POINTER ARRANGING?
  cout << "student has been added to the linked list" << endl;

  //check if this bucket has 3 or more student nodes
  if (counter >= 3) {
    cout << "REHASHING" << endl;
    rehash();
  }
}

void HashTable::remove(int targetID) {
  cout << "This is the ID I'm looking for: " << targetID << endl;
  //traverse hash table
  //Don't need to check for matching targetID because main already checked
  //Use LinkedList2 as reference for changing pointers
}

void HashTable::rehash() {

}

void HashTable::print() {
  for (int i = 0; i < tableSize; i++) {//traverse the hash table
    Node* j = slots[i] -> head;
    while (j != NULL) {
      j -> getStudent() -> printInfo();
      j = j -> getNext();
    }

    /*for (auto j = slots[i] -> head; j != NULL; j++) {
      cout << "about to print a student." << endl;
      if (j != NULL) {
	cout << "really about to print a student." << endl;
	j -> getStudent() -> printInfo();
	cout << "printed a student." << endl;
      }
      else {
	cout << "j was NULL" << endl;
	}*/
  }
}
