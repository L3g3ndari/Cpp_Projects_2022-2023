#include <iostream>
#include <vector>
#include <cstring>
#include "vg.h"
//#include "movie.h"
//#include "music.h"

using namespace std;

void addFunction();
void searchFunction();
void deleteFunction();

int main() {
  vector <Media> Media;
  cout << "Welcome to your Media Database." << endl;
  cout << "Available commands: ADD, SEARCH, DELETE, QUIT." << endl;
    
  while (true) {
    char input[10];
    cout << "Awaiting new command "
    cin >> input;

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      //addFunction();
      cout << "1" << endl;
    }

    if (input[0] == 'S' &&
	input[1] == 'E' &&
	input[2] == 'A' &&
	input[3] == 'R' &&
	input[4] == 'C' &&
	input[5] == 'H') {
      //searchFunction();
      cout << "2" << endl;
    }

    if (input[0] == 'D' &&
	input[1] == 'E' &&
	input[2] == 'L' &&
	input[3] == 'E' &&
	input[4] == 'T' &&
	input[5] == 'E') {
      //deleteFunction();
      cout << "3" << endl;
    }
    
  }
}

void addFunction() {
  char title[80];
  char year[5];
  char typeInput[3];
  cout << "Title: ";
  cin >> title;
  cout << "Year Published: ";
  cin >> year;
  cout << "What is the type of your media entry? \n Type \"1\" for movies, \"2\" for music, and \"3\" for video games."
    cin >> typeInput;
  if (typeInput[0] == '1') {//movie

  }
  if (typeInput[0] == '2') {//music

  }
  if (typeInput[0] == '3') {//video games

  }
}
