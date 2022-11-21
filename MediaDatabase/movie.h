#include <iostream>
#include "media.h"
using namespace std;

class Movie : public Media {
 public:
  Movie(int Type, char Title[80], int year, int Rating, char Director[80], int Duration);
  char* getDirector();
  int getRating();
  int getDuration();
  virtual void printInfo();
protected:
  char director[80];
  int rating;
  int duration;
};
