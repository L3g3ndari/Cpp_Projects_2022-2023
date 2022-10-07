/*
Nathan Wu
Student List Program
C++ Programming
Period 5
Mr. Galbraith
Project Completed: 
Outside Resources Utilized:
 */

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

struct Student {
  char name[64];
  char lastName[64];
  int id;
  float GPA;
  Student(char *firstName, char *LastName, int idNum, float gpa) {
    strcpy(name, firstName);
    strcpy(lastName, LastName);
    id = idNum;
    GPA = gpa;
  }
};

//initialize functions
void printFunction(vector <Student> StudentList);
void addFunction(vector <Student> *StudentListPtr);
void deleteFunction();

int main() {
  vector <Student> StudentList;//initializes a vector (a dynamic array) of Students (which are the struct)
  vector <Student> *StudentListPtr = &StudentList;//initializes a pointer that can get/modify the value of the StudentList
  cout << "Welcome to the Student List Program" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" or \"QUIT\"" << endl;

  //StudentList.push_back(Student());
  //char random[64] = "Nathan";
  //strcpy(StudentList[0].name, random);
  
  while(true) {
    char input[10];
    cin >> input;
    
    if (input[0] == 'P' &&
	input[1] == 'R' &&
	input[2] == 'I' &&
	input[3] == 'N' &&
	input[4] == 'T') {
      printFunction(StudentList);
    }

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {
      addFunction(StudentListPtr);
    }

    if (input[0] == 'D' &&
	input[1] == 'E' &&
	input[2] == 'L' &&
	input[3] == 'E' &&
	input[4] == 'T' &&
	input[5] == 'E') {
      //deleteFunction();
    }

    if (input[0] == 'Q' &&
	input[1] == 'U' &&
	input[2] == 'I' &&
	input[3] == 'T') {
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction(vector <Student> StudentList) {//Next step: Daren said: "Put the pointer in the add function."
  vector<Student>::iterator ptr;
  for (ptr = StudentList.begin(); ptr < StudentList.end(); ptr++) {
    cout << "Name: " << ptr -> name << " " << ptr -> lastName << ";   ID#: " << ptr -> id << ";   GPA: " << ptr -> GPA << endl;
  }
}

void addFunction(vector <Student> *StudentListPtr) {
  char firstName[64];
  char lastName[64];
  int idNum;
  float gpa;
  cout << "What is the student's first name?" << endl;
  cin >> firstName;
  cout << "What is the student's last name?" << endl;
  cin >> lastName;
  cout << "What is the student's ID number?" << endl;
  cin >> idNum;
  cout << "Please enter the student's grade point average." << endl;
  cin >> gpa;
  StudentListPtr -> push_back(Student(firstName, lastName, idNum, gpa));//adding a empty student struct to the vector
  cout << endl;
  cout << firstName << " " << lastName << " added." << endl;
}
