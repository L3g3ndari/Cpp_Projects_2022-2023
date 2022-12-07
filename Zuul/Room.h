#include <iostream>
#include <cstring>
#include <map>
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
 protected:
  char* name;
  char* description;
  //Inventory inventory;
  map<char*, Room*> exits;
};
