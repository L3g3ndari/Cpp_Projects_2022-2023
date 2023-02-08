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
  void remove(int ID);
  void print();
 private:
  int tableSize;
  struct tableEntry {
    int key;
    Node* head;
  };
  tableEntry* slots;
};
#endif
