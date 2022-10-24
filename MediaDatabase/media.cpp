#include <iostream>
#include <cstring>
#include "media.h"
using namespace std;

Media::Media(int Type, char Title[80], int Year) {
  type = Type;
  strcpy(title, Title);
  year = Year;
};
int Media::getType() {
  return type;
}
char* Media::getTitle() {
  char* Title;
  strcpy(Title, title);
  return Title;
}
int Media::getYear() {
  return year;
}
