#include <iostream>
#include <cstring>
#include <map>
#include "Room.h"
using namespace std;

Room::Room(char* Name, char* Description) {
  name = new char[strlen(Name) +1];
  strcpy(name, Name);
  description = new char[strlen(Description)+1];
  strcpy(description, Description);
};
char* Room::getName() {
  return name;
}
char* Room::getDescription() {
  return description;
}
void Room::setExit(char direction, Room* room) {
  //char* directionStr = new char[10];
  //strcpy (directionStr, direction);
  exits.insert(pair<char, Room*>(direction, room));
}
Room* Room::getExit(char direction) {
  return exits[direction];
}
char* Room::getExitString() {
  char* returnString= new char[80];
  strcpy(returnString, "Exits: ");
  strcpy(returnString, "testing");
  return returnString;
}
bool Room::hasExit(char direction) {
  if(exits[direction] != NULL) {
    return true;
  }
  return false;
}
