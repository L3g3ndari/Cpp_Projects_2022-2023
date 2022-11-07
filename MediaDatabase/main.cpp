#include <iostream>
#include <vector>
#include <cstring>
#include "vg.h"
//#include "movie.h"
//#include "music.h"

using namespace std;

void addFunction(vector <Media*> &DatabasePtr);
void searchFunction(vector <Media*> Database);
void deleteFunction();
void printFunction(vector <Media*> Database);

int main() {
  vector <Media*> Database;
  //vector <Media> *DatabasePtr = &Database;
  cout << "Welcome to your Media Database." << endl;
  cout << "Available commands: ADD, SEARCH, DELETE, QUIT." << endl;
    
  while (true) {
    char input[10];
    cout << "Awaiting new command: ";
    cin >> input;

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      addFunction(Database);
      //cout << "1" << endl;
    }

    if(input[0] == 'P'){
      printFunction(Database);
    }

    if (input[0] == 'S' &&
	input[1] == 'E' &&
	input[2] == 'A' &&
	input[3] == 'R' &&
	input[4] == 'C' &&
	input[5] == 'H') {
      searchFunction(Database);
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

void addFunction(vector <Media*> &DatabasePtr) {
  char title[80];
  int year;
  int typeInput;
  cout << "Title: ";
  cin.clear();
  cin.ignore(80, '\n');
  cin.get(title, 80);
  cout << "Year Published: ";
  cin >> year;
  cout << "What is the type of your media entry? \n Type \"1\" for movies, \"2\" for music, and \"3\" for video games." << endl;
  cout << "Type: ";
  cin >> typeInput;
  if (typeInput == 1) {//movie

  }
  if (typeInput == 2) {//music

  }
  if (typeInput == 3) {//video games
    char publisher[80];
    int rating;
    cout << "Publisher: ";
    cin >> publisher;
    cout << "Rating (positive integer out of 10): ";
    cin >> rating;
    DatabasePtr.push_back(new VG(typeInput, title, year, rating, publisher));//can't add VG to a vector of Media, so need to create a vector of pointers to Media
    cout << endl;
    cout << title << " has been added to your database." << endl;
  }
  
}

void printFunction(vector <Media*> Database) {
  vector<Media*>::iterator i;
  for (i = Database.begin(); i < Database.end(); i++) {
    (*i) -> printInfo();
  }
}

void searchFunction(vector <Media*> Database) {
  char searchTerm[80] = "";
  char input[6] = "";
  cout << "Would you like to search by title or year?" << endl;
  cin >> input;
  cin.ignore(80, '\n');
  if (strcmp(input, "title") == 0) {
    cout << "Please type your search term (title): ";
    cin >> searchTerm;
    cout << "Here are all the results that match your search." << endl;
    vector<Media*>::iterator itr;
    for (itr = Database.begin(); itr != Database.end(); itr++) {
      char * pch;
      pch = strstr((*itr) -> getTitle(), searchTerm);
      if (pch != NULL) {
	(*itr) -> printInfo();
      }
    }
    cout << endl;
  }
  else if (strcmp(input, "year") == 0) {
    cout << "Please type your search term (year): ";
  }
  else {
    cout << "That input does not compute." << endl;
    return;
  }
  
}
