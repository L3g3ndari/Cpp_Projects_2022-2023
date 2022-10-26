#include <iostream>
#include "media.h"
using namespace std;

class VG : public Media {
 public:
  VG(int Type, char Title[80], int year, int Rating, char Publisher[80]);
  char* getPublisher();
  int getRating();
protected:
  char* publisher;
  int rating;
};
