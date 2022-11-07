#include <iostream>
#include <cstring>
#include "vg.h"
using namespace std;

VG::VG(int Type, char Title[80], int Year, int Rating, char Publisher[80]):Media(Type, Title, Year) {
  rating = Rating;
  strcpy(publisher, Publisher);
};
int VG::getRating() {
  return rating;
}
char* VG::getPublisher() {
  return publisher;
}
void VG::printInfo() {
  cout << "- Video Game: " << title << ", " << publisher << ", " << year << ", " << rating << "/10" << endl;
}
