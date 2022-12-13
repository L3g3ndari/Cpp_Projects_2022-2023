#include <iostream>
#include <cstring>
#include <map>
//#include "Inventory.h"
using namespace std;

class Room {
 public:
  Room(char* Name, char* Description);
  char* getName();
  char* getDescription();
  void setExit(char* direction, Room* room);
  Room* getExit(char* direction);
  char* getExitString();
  bool hasExit(char* direction);
private:
  char* name;
  char* description;
  //Inventory inventory;
  map<char*, Room*> exits;
};
