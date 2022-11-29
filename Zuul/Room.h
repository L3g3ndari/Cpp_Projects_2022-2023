#include <iostream>
using namespace std;

class Room {
 public:
  Room(char Description[1000], map exits);
  char* getDescription();
  void setExit();
  Room getExit(char* direction);
  bool hasExit(char* direction);
 protected:
  char* description;
  //continue working here
};
