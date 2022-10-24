#include <iostream>
#include <cstring>
#include "vg.h"
using namespace std;

VG::VG(int Type, char Title[80], int Year, int Rating, char Publisher[80]):Media(Type, Title, Year) {
  rating = Rating;
  publisher = Publisher;
};
int VG::getRating() {
  return rating;
}
char* VG::getPublisher() {
  char Publisher[80];
  strcpy(Publisher, publisher);
  return Publisher;
}
