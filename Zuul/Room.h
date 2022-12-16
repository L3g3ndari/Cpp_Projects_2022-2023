#include <iostream>
#include <cstring>
#include <map>
#ifndef n
#define n
#include "Inventory.h"
#endif
using namespace std;

class Room {
 public:
  Room(char* Name, char* Description);
  char* getName();
  char* getDescription();
  void setExit(char direction, Room* room);
  Room* getExit(char direction);
  char* getExitString();
  bool hasExit(char direction);
  Inventory roomInventory;
private:
  char* name;
  char* description;
  //Inventory inventory;
  map<char, Room*> exits;
};
