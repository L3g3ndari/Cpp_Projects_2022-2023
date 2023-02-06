#include <iostream>
#ifdef NODE
#define NODE
#include "Node.h"
#endif

using namespace std;

class HashTable {
 public:
  void insert();
  void remove();
  void 
 private:
  struct tableEntry {
    int key;
    Node* node;
  };
  
}
