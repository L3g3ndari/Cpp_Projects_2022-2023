#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

class Inventory {
 public:
  Inventory();
  void addItem(char*);
  void removeItem(char*);
  void printInventory();
  bool hasItem(char*);
 private:
  vector<char*> items;
};
