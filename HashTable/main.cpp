/*
Nathan Wu
Hash Table Student List
C++ Programming
Mr. Galbraith
Project Completed: 
Outside Sources Used: Used https://www.geeksforgeeks.org/c-program-hashing-chaining/ to help understand hash tables
*/

#include <iostream>
#include <cmath>
#include <cstring>
//#ifndef STUDENT
//#define STUDENT
#include "Student.h"
#include "Node.h"
//#endif

using namespace std;

void addRandomStudent(int randomStudentID);
void printFunction();
void addFunction(HashTable& HT);
void deleteFunction();

int main() {
  cout << "Welcome to the Student Database, brought to you by hash tables" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" \"RANDOM,\" or \"QUIT\"" << endl;

  HashTable HT = HashTable;
  int randomStudentID = 1;
  addRandomStudent(randomStudentID);
  
    while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (input[0] == 'P' &&//I know that I could/should have used strcmp, but don't hate me, I just used my StudentList code from the beginning of the year.
        input[1] == 'R' &&
        input[2] == 'I' &&
        input[3] == 'N' &&
        input[4] == 'T') {//if the user types in "PRINT," the printFunction method will be run
      //printFunction();
    }

    if (input[0] == 'A' &&
        input[1] == 'D' &&
        input[2] == 'D') {//if the user types in "ADD," the addFunction method will be run
      //addFunction();
    }

    if (input[0] == 'D' &&
        input[1] == 'E' &&
        input[2] == 'L' &&
        input[3] == 'E' &&
        input[4] == 'T' &&
        input[5] == 'E') {//if the user types in "DELETE," the deleteFunction method will be run
      //deleteFunction();
    }

    if (strcmp(input, "RANDOM") == 0) {//adds a random student to the hash table
      cout << "How many students do you want to generate?" << endl;
      int num;
      cin >> num;
      cin.clear();
      cin.ignore(10, '\n');
      for (int i = 0; i != num + 1; i++) {
	addRandomStudent(randomStudentID);
      }
    }

    if (input[0] == 'Q' &&
        input[1] == 'U' &&
        input[2] == 'I' &&
        input[3] == 'T') {//if the user types in "QUIT," the program will stop running
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction() {

}

void addFunction() {
  char firstName[64];
  char lastName[64];
  int idNum;
  float gpa;
  cout << "What is the student's first name?" << endl;
  cin.getline(firstName, 64);
  //cin.clear();
  //cin.ignore(64, '\n');
  cout << "What is the student's last name?" << endl;
  cin.getline(lastName, 64);
  cout << "What is the student's ID number?" << endl;
  cin >> idNum;
  cout << "Please enter the student's grade point average." << endl;
  cin >> gpa;
  //Add a new node with this information to the hash table

  cout << endl;
  cout << firstName << " " << lastName << " added." << endl;
  
}

void deleteFunction() {
  cout << "ID: ";
  int targetID;
  cin >> targetID;
  //traverse hash table and check each ID. Compare with targetID.
  //If there is a match, call hashTable's delete function on that student.
}

void addRandomStudent(int randomID) {
  char* randomFirstName;
  char* randomLastName;
  int incrementedID;
  float randomGPA;
  srand(time(0));
  int randomInt = (rand() % 4);
  float randomFloat = ceil(100 * ((float)(rand()) / (float)(RAND_MAX)))/100;
  randomGPA = randomInt + randomFloat;
  cout << randomGPA << endl;
  cout << randomID;
}
