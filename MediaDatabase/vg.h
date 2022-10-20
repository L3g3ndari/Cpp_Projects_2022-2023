#include <iostream>
#include "media.h"
using namespace std;

class VG : public media {
 public:
  VG(char* Publisher, int Rating);
  char* getPublisher();
  int getRating();
protected:
  char* publisher;
  int rating;
}
