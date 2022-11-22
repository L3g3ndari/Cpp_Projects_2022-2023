#include <iostream>
#ifndef MEDIA
#define MEDIA
#include "media.h"
#endif
using namespace std;

class VG : public Media {
 public:
  VG(int Type, char Title[80], int year, int Rating, char Publisher[80]);
  char* getPublisher();
  int getRating();
  virtual void printInfo();
protected:
  char publisher[80];
  int rating;
};
