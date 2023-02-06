#include <iostream>
#ifdef NODE
#define NODE
#include "Node.h"
#endif

using namespace std;

class HashTable {
 public:
  void insert(Node* student, int key);
  void remove(int key);
  void print();
 private:
  int tableSize;
  list<int> *table;
  struct tableEntry {
    int key;
    Node* node;
  };
  
}
