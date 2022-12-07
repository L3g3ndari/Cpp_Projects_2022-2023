#include <iostream>
#include <cstring>
#include <map>
using namespace std;

class Room {
 public:
  Room(char* Description);
  char* getDescription();
  void setExit(char* direction, Room* room);
  Room* getExit(char* direction);
  char* getExitString();
  bool hasExit(char* direction);
 protected:
  char* description;
  //Inventory inventory;
  map<char*, Room*> exits;
};
