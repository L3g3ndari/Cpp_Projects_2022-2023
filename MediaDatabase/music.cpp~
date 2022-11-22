#include <iostream>
#include <cstring>
#include "movie.h"
using namespace std;

Movie::Movie(int Type, char Title[80], int Year, int Rating, char Director[80], int Duration):Media(Type, Title, Year) {
  rating = Rating;
  strcpy(director, Director);
  duration = Duration;
};
int Movie::getRating() {
  return rating;
}
char* Movie::getDirector() {
  return director;
}
int Movie::getDuration() {
  return duration;
}
void Movie::printInfo() {
  cout << "- Movie: " << title << ", " << director << ", " << year << ", " << rating << "/10, " << duration << " min" << endl;
}
