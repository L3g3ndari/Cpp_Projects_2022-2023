//https://cplusplus.com/reference/cstring/strstr/

#include <iostream>
#include <vector>
#include <cstring>
#include "vg.h"
//#include "movie.h"
//#include "music.h"

using namespace std;

void addFunction(vector <Media*> &Database);
void searchFunction(vector <Media*> Database);
void deleteFunction(vector <Media*> &Database);
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
      deleteFunction(Database);
    }

    if (strcmp(input, "QUIT") == 0) {
      cout << "Confirmation to quit the program. All your data will be lost. Do you want to quit?  (y/n)" << endl;
      char yesno[80] = "";
      cin >> yesno;
      if (yesno[0] == 'y') {
	cout << "Thank you for using the media database. Have a good day." << endl;
	exit(0);
      }
      else {
	cout << endl;
      }
    }
  }
}

void addFunction(vector <Media*> &Database) {
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
    cin.clear();
    cin.ignore(80, '\n');
    cin.get(publisher, 80);
    cout << "Rating (positive integer out of 10): ";
    cin >> rating;
    Database.push_back(new VG(typeInput, title, year, rating, publisher));//can't add VG to a vector of Media, so need to create a vector of pointers to Media
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
  char input[6] = "";
  cout << "Would you like to search by title or year?" << endl;
  cin >> input;
  cin.ignore(80, '\n');
  if (strcmp(input, "title") == 0) {
    char searchTerm[80] = "";
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
    int searchTerm = 0;
    cout << "Please type your search term (year): ";
    cin >> searchTerm;
    cout << "Here are all the results that match your search." << endl;
    vector<Media*>::iterator itr;
    for (itr = Database.begin(); itr != Database.end(); itr++) {
      if (searchTerm == (*itr) -> getYear()) {
	(*itr) -> printInfo();
      }
    }
    cout << endl;
  }
  else {
    cout << "That input does not compute." << endl;
    return;
  }  
}

void deleteFunction(vector <Media*> &Database) {
  vector <char*> toBeDeleted;
  char input[6] = "";
  cout << "Please search for the entries you want to delete. Would you like to search by title or year?" << endl;
  cin >> input;
  cin.ignore(80, '\n');
  if (strcmp(input, "title") == 0) {
    char searchTerm[80] = "";
    cout << "Please type your search term (title): ";
    cin >> searchTerm;
    vector<Media*>::iterator itr;
    for (itr = Database.begin(); itr != Database.end(); itr++) {
      char * pch;
      cout << (*itr) -> getTitle() << endl;
      pch = strstr((*itr) -> getTitle(), searchTerm);
      if (pch != NULL) {
	cout << endl;
	cout << "Here is one of the results of your search:" << endl << endl;
	(*itr) -> printInfo();
	cout << endl;
	cout << "Would you like to delete this file from your media database? This action cannot be undone. (y/n)" << endl;
	char yesno[80];
	cin >> yesno;
	cout << "-" << endl;//somehow, this print line is crucial to the functionality of the program, even though it does nothing
	if (yesno[0] == 'y') {
	  //cout << (*itr) -> getTitle() << endl;
	  toBeDeleted.push_back((*itr) -> getTitle());
     	}
	cout << "-" << endl;//somehow, this print line is crucial to the functionality of the program
      }
    }
    while (toBeDeleted.size() > 0) {
      vector<Media*>::iterator itr2;
      for (itr2 = Database.begin(); itr2 < Database.end(); itr2++) {
	if (strcmp(*toBeDeleted.begin(), (*itr2) -> getTitle()) == 0) {
	  delete *itr2;//deletes the class using a destructor
	  Database.erase(itr2);//erase the pointer to the class from Database
	  cout << *toBeDeleted.begin() << endl;
	  toBeDeleted.erase(toBeDeleted.begin());////erase the title from toBeDeleted
	  break;
	}  
      }
    } 
    cout << endl;
  }
  else if (strcmp(input, "year") == 0) {
    int searchTerm = 0;
    cout << "Please type your search term (year): ";
    cin >> searchTerm;
    cout << "Here are all the results that match your search." << endl;
    vector<Media*>::iterator itr;
    for (itr = Database.begin(); itr != Database.end(); itr++) {
      if (searchTerm == (*itr) -> getYear()) {
        (*itr) -> printInfo();
      }
    }
    cout << endl;
  }
  else {
    cout << "That input does not compute." << endl;
    return;
  }
}
