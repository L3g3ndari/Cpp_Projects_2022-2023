#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"
using namespace std;

Room::Room(char* Description) {
  strcpy(description, Description);
};
char* Room::getDescription() {
  return description;
}
void Room::setExit(char* direction, Room* room) {
  exits.insert(pair<char*, Room*>(direction, room));
}
Room* Room::getExit(char* direction) {
  return exits[direction];
}
char* Room::getExitString() {
  char* returnString= new char[80];
  strcpy(returnString, "Exit: ");
  return returnString;
}
bool Room::hasExit(char* direction) {

}
