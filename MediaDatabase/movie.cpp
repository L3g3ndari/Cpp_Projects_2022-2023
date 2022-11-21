#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

Movie::Movie(int Type, char Title[80], int Year, int Rating, char Director[80], int Duration):Media(Type, Title, Year) {
  rating = Rating;
  strcpy(publisher, Publisher);
};
int Movie::getRating() {
  return rating;
}
char* Movie::getPublisher() {
  return publisher;
}
void Movie::printInfo() {
  cout << "- Video Game: " << title << ", " << publisher << ", " << year << ", " << rating << "/10" << endl;
}
