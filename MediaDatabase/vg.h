#include <iostream>
#include "media.h"
using namespace std;

class VG : public Media {
 public:
  VG(char* Publisher, int Rating);
  char* getPublisher();
  int getRating();
protected:
  char* publisher;
  int rating;
};
