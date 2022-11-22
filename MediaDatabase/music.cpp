#include <iostream>
#include <cstring>
#include "music.h"
using namespace std;

Music::Music(int Type, char Title[80], int Year, char Publisher[80], char Artist[80], int Duration):Media(Type, Title, Year) {
  strcpy(publisher, Publisher);
  strcpy(artist, Artist);
  duration = Duration;
};
char* Music::getPublisher() {
  return publisher;
}
char* Music::getArtist() {
  return artist;
}
int Music::getDuration() {
  return duration;
}
void Music::printInfo() {
  cout << "- Music: " << title << ", " << publisher << ", " << artist << ", " << year << ", " << duration << " sec" << endl;
}
