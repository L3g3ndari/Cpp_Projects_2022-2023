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
  int index = hashFunction(student -> getStudent() -> getID());
    Node* j = slots[index] -> head;
    while (j != NULL) {
      if (j -> getStudent() -> getID() == student -> getStudent() -> getID()) {
        cout << "Student with this ID already exists." << endl;
        return;
      }
      j = j -> getNext();
    }
    //cout << " 101" << endl;
  Node* i = slots[index] -> head;
  if (i == NULL) {//if that bucket is empty
    //set head to student
    slots[index] -> head = student;
    cout << "Student has been added to the linked list ." << endl;
    slotsUsed++;
    cout << "Slots Used: " << slotsUsed << endl;
    /*if (slotsUsed >= tableSize/2) {
      cout << "REHASHING because more than half the table was used." << endl;
      rehash();
      }*/
    return;
  }
  int counter = 0;
  while (i -> getNext() != NULL) {//go through all the slots until the end (tail)
    i = i -> getNext();
    counter++;
    cout << "Counter: " << counter << endl;
    //check if this bucket has 3 or more student nodes
  if (counter > 3) {
    cout << "REHASHING because more than 3 collisions occured." << endl;
    rehash();
  }
  }
  //Use index to determine which slot to add to
  i -> setNext(student);//Add to that slot's linked list
  cout << "Student has been added to the linked list" << endl;
}

int HashTable::remove(int targetID) {
  //cout << "This is the ID I'm looking for: " << targetID << endl;
  int i = hashFunction(targetID);
  Node*& head = slots[i] -> head;
  if (head == NULL) {
    return 0;
  }
  if (head -> getStudent() -> getID() == targetID) {
    Node* oldHead = head;
    head = head -> getNext();
    delete oldHead;
    slotsUsed--;
    return 1;
  }
  //Node* j = slots[i] -> head;
  Node* j = head -> getNext();
  Node* previous = head;
  while (j != NULL) {
    if (j -> getStudent() -> getID() == targetID) {
      cout << "Found a match!" << endl;
      //delete that node and do the switcheroos
      previous -> setNext(j -> getNext());
      delete j;
      slotsUsed--;
      return 1;
    }
    previous = j;
    j = j -> getNext();
  }
  return 0;
}

void HashTable::rehash() {
  //create a new expanded hash table
  tableSize = tableSize*2;
  tableEntry** newTable = new tableEntry*[tableSize];
  for (int i = 0; i < tableSize; i++) {
    newTable[i] = new tableEntry();
  }
  for(int i = 0; i < tableSize/2; i++) {
    Node* j = slots[i] -> head;
    while (j != NULL) {
      int index = hashFunction(j -> getStudent() -> getID());
      Node* x = newTable[index] -> head;
      if (x == NULL) {
	//set head to student
	newTable[index] -> head = j;
	//cout << "student has been added to the linked list ." << endl;
	//slotsUsed++;
	//cout << "Slots Used: " << slotsUsed << endl;
	if (slotsUsed >= tableSize/2) {
	  //cout << "REHASHING because more than half the table was used." << endl;
	  //rehash();
	}
	cout << "This is where the nasty return used to be." << endl;
	//return;
      }
      cout << "1111111" << endl;
      int counter = 0;
      while (x -> getNext() != NULL) {//go through all the slots until the end (tail)
	cout << "222222" << endl;
	x = x -> getNext();
	counter++;
	//cout << "Counter: " << counter << endl;
      }
      cout << "333333" << endl;
      //Use index to determine which slot to add to
      x -> setNext(j);//Add to that slot's linked list, MIGHT NEED TO ADD SOME MO\
			    RE POINTER ARRANGING?
      //cout << "student has been added to the linked list" << endl;

      //check if this bucket has 3 or more student nodes
      if (counter >= 3) {
	//cout << "REHASHING because more than 3 collisions occured." << endl;
	//rehash();
      }
      j = j-> getNext();
    }
  }
  delete[] slots;
  slots = newTable;
  cout << "Rehash successful." << endl;
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
