#include <iostream>
#ifndef MEDIA
#define MEDIA
#include "media.h"
#endif
using namespace std;

class Music : public Media {
 public:
  Music(int Type, char Title[80], int year, char Publisher[80], char Artist[80], int Duration);
  char* getPublisher();
  char* getArtist();
  int getDuration();
  virtual void printInfo();
protected:
  char publisher[80];
  char artist[80];
  int duration;
};
