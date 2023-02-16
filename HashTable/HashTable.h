#ifndef HASH
#define HASH
#include <iostream>
#include "Node.h"

using namespace std;

class HashTable {
 public:
  HashTable();
  int hashFunction(int ID);
  void rehash();
  void insert(Node* student);
  int remove(int ID);
  void print();
 private:
  int tableSize;
  int slotsUsed;
  struct tableEntry {
    int key;
    Node* head = NULL;
  };
  tableEntry** slots;
};
#endif
