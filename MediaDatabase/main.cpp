/*
Media Database
Nathan Wu
C++ Programming
Mr. Galbraith
Period 5
Projected Completed: 11/29/22
Sources used: https://cplusplus.com/reference/cstring/strstr for learning how to use the strstr function

This program stores different types of media and their respective qualities which are entered by the user.
*/

#include <iostream>
#include <vector>
#include <cstring>
#include "vg.h"
#include "movie.h"
#include "music.h"

using namespace std;

void addFunction(vector <Media*> &Database);
void searchFunction(vector <Media*> Database);
void deleteFunction(vector <Media*> &Database);
void printFunction(vector <Media*> Database);
bool cmpStr(char* str1, char* str2);

int main() {
  vector <Media*> Database;//a vector of pointers must be used in this instance because the children can't be added directly to a vector of Media (the parent class). So we use pointers to allow us to consolidate the media being stored to one vector.
  cout << "Welcome to your Media Database." << endl;
  cout << "Available commands: ADD, SEARCH, DELETE, QUIT." << endl;
    
  while (true) {//asks for new commands and executes them when inputted
    char input[10];
    cout << "Awaiting new command: ";
    cin >> input;
    //should have used strcmp smh but this works too
    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      addFunction(Database);//adds a media to the database
    }

    if(input[0] == 'P'){
      printFunction(Database);//prints all the media in the database
    }

    if (input[0] == 'S' &&
	input[1] == 'E' &&
	input[2] == 'A' &&
	input[3] == 'R' &&
	input[4] == 'C' &&
	input[5] == 'H') {
      searchFunction(Database);//accepts a search term and displays all the media in the database that match the search term. Can search by title or year.
    }

    if (input[0] == 'D' &&
	input[1] == 'E' &&
	input[2] == 'L' &&
	input[3] == 'E' &&
	input[4] == 'T' &&
	input[5] == 'E') {
      deleteFunction(Database);//Uses the same functionality as the SEARCH function but systematically asks the user if they want to delete the search results.
    }

    if (strcmp(input, "QUIT") == 0) {//exits the program.
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

void addFunction(vector <Media*> &Database) {//adds a media to the database
  char title[80];
  int year;
  int typeInput;
  //asks for all the qualities of the media being inputted. Some of these quatities change based on the type of media.
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
    char director[80];
    int rating;
    int duration;
    cout << "Director: ";
    cin.clear();
    cin.ignore(80, '\n');
    cin.get(director, 80);
    cout << "Rating (positive integer out of 10): ";
    cin >> rating;
    cout << "Run time (in minutes): ";
    cin >> duration;
    Database.push_back(new Movie(typeInput, title, year, rating, director, duration));//the movie is added to the database
    cout << endl;
    cin.clear();
    cin.ignore(80, '\n');
    cout << title << " has been added to your database." << endl;
  }
  if (typeInput == 2) {//music
    char publisher[80];
    char artist[80];
    int duration;
    cout << "Publisher: ";
    cin.clear();
    cin.ignore(80, '\n');
    cin.get(publisher, 80);
    cout << "Artist: ";
    cin.clear();
    cin.ignore(80, '\n');
    cin.get(artist, 80);
    cin.clear();
    cin.ignore(80, '\n');
    cout<< "Duration (in seconds): ";
    cin >> duration;
    Database.push_back(new Music(typeInput, title, year, publisher, artist, duration));//the music is added to the database
    cout << endl;
    cin.clear();
    cin.ignore(80, '\n');
    cout << title << " has been added to your database." << endl;
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
    Database.push_back(new VG(typeInput, title, year, rating, publisher));//the video game is added to the database
    cout << endl;
    cout << title << " has been added to your database." << endl;
  }
  
}

void printFunction(vector <Media*> Database) {//runs through the vector of pointers and prints out everything.
  vector<Media*>::iterator i;
  for (i = Database.begin(); i < Database.end(); i++) {
    (*i) -> printInfo();
  }
}

void searchFunction(vector <Media*> Database) {//accepts a search term and displays all the media in the database that match the search term. Can search by title or year.
  char input[6] = "";
  cout << "Would you like to search by title or year?" << endl;
  cin >> input;
  cin.ignore(80, '\n');
  if (strcmp(input, "title") == 0) {//uses the strstr function to check if the search term is contained in each entry
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
  else if (strcmp(input, "year") == 0) {//checks if the searched year is equal to any of the entries' year data
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

void deleteFunction(vector <Media*> &Database) {//Uses the same functionality as the SEARCH function but systematically asks the user if they want to delete the search results.
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
	//cout << "-" << endl;//somehow, this print line was crucial to the functionality of the program for a certain period of time, even though it does nothing
	if (yesno[0] == 'y') {
	  //cout << (*itr) -> getTitle() << endl;
	  toBeDeleted.push_back((*itr) -> getTitle());
	  //cout << "toBeDeleted1: " << *toBeDeleted.begin() << endl;
     	}
	//cout << "-" << endl;//somehow, this print line was crucial to the functionality of the program for a certain period of time
      }
    }
    while (toBeDeleted.size() > 0) {
      vector<Media*>::iterator itr2;
      for (itr2 = Database.begin(); itr2 < Database.end(); itr2++) {
	//cout << "toBeDeleted2: " << *toBeDeleted.begin() << endl;
        if (cmpStr(*toBeDeleted.begin(), (*itr2) -> getTitle()) == true) {
	  delete *itr2;//deletes the class using a destructor
	  Database.erase(itr2);//erase the pointer to the class from Database
	  //cout << *toBeDeleted.begin() << endl;
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
      cout << (*itr) -> getYear() << endl;
      if ((*itr) -> getYear() == searchTerm) {
        cout << endl;
        cout << "Here is one of the results of your search:" << endl << endl;
        (*itr) -> printInfo();
        cout << endl;
        cout << "Would you like to delete this file from your media database? This action cannot be undone. (y/n)" << endl;
        char yesno[80];
        cin >> yesno;
        if (yesno[0] == 'y') {
          toBeDeleted.push_back((*itr) -> getTitle());
	}
      }
    }
    cout << endl;
  }
  else {
    cout << "That input does not compute." << endl;
    return;
  }
  while (toBeDeleted.size() > 0) {
      vector<Media*>::iterator itr2;
      for (itr2 = Database.begin(); itr2 < Database.end(); itr2++) {
        if (cmpStr(*toBeDeleted.begin(), (*itr2) -> getTitle()) == true) {
          delete *itr2;//deletes the class using a destructor
          Database.erase(itr2);//erase the pointer to the class from Database
          toBeDeleted.erase(toBeDeleted.begin());////erase the title from toBeDeleted
          break;
        }
      }
    }
}

bool cmpStr(char* str1, char* str2) {//is used in deleteFunction but is probably entirely obselete because deleteFunction was fixed on 11/21/22
  for (int i = 0; i < strlen(str1); i++) {
    if(str1[i] != '\0') {
      if(str1[i] != str2[i]) {//checking for matching characters
	return false;
      }
    }
    else if(str1[i] != str2[i]) {//checking for null character matching
      return false;
    }
  }
  return true;
}
