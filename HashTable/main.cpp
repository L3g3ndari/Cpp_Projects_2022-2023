/*
Nathan Wu
Hash Table Student List
C++ Programming
Mr. Galbraith
Project Completed: 
Outside Sources Used: Used https://www.geeksforgeeks.org/c-program-hashing-chaining/ to help understand hash tables, https://www.digitalocean.com/community/tutorials/getline-in-c-plus-plus and https://cplusplus.com/doc/tutorial/files/ for reading from files
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cstring>
//#ifndef STUDENT
//#define STUDENT
#include "Student.h"
#include "Node.h"
#include "HashTable.h"
//#endif

using namespace std;

void addRandomStudent(HashTable& HT, int* randomID, vector<char*> firstNames, vector<char*> lastNames);
void printFunction(HashTable HT);
void addFunction(HashTable& HT);
int deleteFunction(HashTable& HT);

int main() {
  cout << "Welcome to the Student Database, brought to you by hash tables" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" \"RANDOM,\" or \"QUIT\"" << endl;

  vector<char*> firstNames;
  vector<char*> lastNames;
  srand(time(0));
  
  char* line = new char[20];
  char array[20];
  ifstream fnFile ("firstName.txt");
  if (fnFile.is_open()) {
    while (fnFile >> array) {
      line = new char[20];
      strcpy(line, array);
      //cout << line << endl;
      firstNames.push_back(line);
    }
  }
  else cout << "Unable to open first name file" << endl;

  char* line2 = new char[20];
  char array2[20];
  ifstream lsFile ("lastName.txt");
  if (fnFile.is_open()) {
    while (fnFile >> array2) {
      line2 = new char[20];
      strcpy(line2, array2);
      //cout << line << endl;
      lastNames.push_back(line2);
    }
  }
  else cout << "Unable to open first name file" << endl;
  
  for (int i = 0; i < strlen(firstNames.back())+2; i++) {
    //cout << i << "==" << firstNames.back()[i] << "==" << endl;
  }
  
  //firstNames.back()[strlen(firstNames.back())-1] = '\0';
  //cout << firstNames.back() << endl;//This is the last element, which in theory is the last s \
tudent and EOF
  //return 0;
  
  HashTable HT = HashTable();
  int randomStudentID = 1;
  //addRandomStudent(HT, &randomStudentID, firstNames, lastNames);
  
    while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (strcmp(input, "PRINT") == 0) {//if the user types in "PRINT," the printFunction method will be run
      printFunction(HT);
    }

    if (strcmp(input, "ADD") == 0) {//if the user types in "ADD," the addFunction method will be run
      addFunction(HT);
    }

    if (strcmp(input, "DELETE") == 0) {//if the user types in "DELETE," the deleteFunction method will be run
      if (deleteFunction(HT) == 0) {
	cout << "Student was not found." << endl;
      }
      else {
	cout << "Student was deleted." << endl;
      }
    }

    if (strcmp(input, "RANDOM") == 0) {//adds a random student to the hash table
      cout << "How many students do you want to generate?" << endl;
      int num;
      cin >> num;
      cin.clear();
      cin.ignore(10, '\n');
      for (int i = 0; i < num; i++) {
	addRandomStudent(HT, &randomStudentID, firstNames, lastNames);
	randomStudentID++;
      }
    }

    if (strcmp(input, "QUIT") == 0) {//if the user types in "QUIT," the program will stop running
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction(HashTable HT) {
  HT.print();
}

void addFunction(HashTable& HT) {
  char firstName[64];
  char lastName[64];
  int idNum;
  float gpa;
  cout << "What is the student's first name?" << endl;
  cin.getline(firstName, 64);
  cout << firstName << endl;
  //cin.clear();
  //cin.ignore(64, '\n');
  cout << "What is the student's last name?" << endl;
  cin.getline(lastName, 64);
  cout << "What is the student's ID number?" << endl;
  cin >> idNum;
  cout << "Please enter the student's grade point average." << endl;
  cin >> gpa;
  //Add a new node with this information to the hash table
  HT.insert(new Node(new Student(firstName, lastName, idNum, gpa)));
  cout << endl;
  cout << firstName << " " << lastName << " added." << endl;
  
}

int deleteFunction(HashTable& HT) {
  cout << "ID: ";
  int targetID;
  cin >> targetID;
  return HT.remove(targetID);
}

void addRandomStudent(HashTable& HT, int* randomID, vector<char*> firstnames, vector<char*> lastnames) {
  cout << "1" << endl;
  //char* randomFirstName = firstnames[rand() % firstnames.size()];
  //char* randomLastName = lastnames[rand() % lastnames.size()];
  char* randomFirstName = new char[20];
  randomFirstName = firstnames[rand() % firstnames.size()];
  char FNarray[20];
  strcpy(randomFirstName, FNarray);

  cout << "2" << endl;
  int incrementedID;
  float randomGPA;
  //DON'T USE srand(time(0)) or else the seed will reset every time
  cout << "3" << endl;
  float randomInt = ((float)rand()/(float)(RAND_MAX)) * 4;
  cout << "4" << endl;
  //float randomFloat = ceil(100 * ((float)(rand()) / (float)(RAND_MAX)))/100;
  randomGPA = randomInt;
  cout << randomGPA << endl;
  cout << "ID will be: " << *randomID << endl;
  HT.insert(new Node(new Student(randomFirstName, randomFirstName, *randomID, randomGPA)));
  (*randomID)++;
  cout << "randomID after adding: " << *randomID << endl;
  cout << "5" << endl;
}
