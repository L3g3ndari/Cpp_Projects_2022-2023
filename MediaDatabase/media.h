#include <iostream>
using namespace std;

class Media {
 public:
  Media(int Type, char Title[80], int Year);
  int getType();
  char* getTitle();
  int getYear();
 protected:
  int type;
  char title[80];
  int year;
}
