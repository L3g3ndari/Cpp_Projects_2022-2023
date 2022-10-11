/*
Nathan Wu
Student List Program
C++ Programming
Period 5
Mr. Galbraith
Project Completed: 10/11/2022
Outside Resources Utilized: Created in collaboration with Daren Kostov. Used https://www.geeksforgeeks.org/how-does-a-vector-work-in-c/ to help me understand vectors. Used https://www.youtube.com/watch?v=2ybLD6_2gKM to help me understand pointers.

This program takes 4 different commands which allow a user to manipulate a student directory system. The program can store the students' names, ID number, and gpa.
 */

#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

struct Student {//initializes the struct of Student objects
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
void deleteFunction(vector <Student> *StudentListPtr);

int main() {
  vector <Student> StudentList;//initializes a vector (a dynamic array) of Students (which are the struct)
  vector <Student> *StudentListPtr = &StudentList;//initializes a pointer that can get/modify the value of the StudentList
  cout << "Welcome to the Student List Program" << endl;
  cout << "Available Commands: \"PRINT,\" \"ADD,\" \"DELETE,\" or \"QUIT\"" << endl;

  //StudentList.push_back(Student());
  //char random[64] = "Nathan";
  //strcpy(StudentList[0].name, random);
  
  while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    
    if (input[0] == 'P' &&
	input[1] == 'R' &&
	input[2] == 'I' &&
	input[3] == 'N' &&
	input[4] == 'T') {//if the user types in "PRINT," the printFunction method will be run
      printFunction(StudentList);
    }

    if (input[0] == 'A' &&
	input[1] == 'D' &&
	input[2] == 'D') {//if the user types in "ADD," the addFunction method will be run
      addFunction(StudentListPtr);
    }

    if (input[0] == 'D' &&
	input[1] == 'E' &&
	input[2] == 'L' &&
	input[3] == 'E' &&
	input[4] == 'T' &&
	input[5] == 'E') {//if the user types in "DELETE," the deleteFunction method will be run
      deleteFunction(StudentListPtr);
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

void printFunction(vector <Student> StudentList) {//prints out each student in the vector and their corresponding information
  vector<Student>::iterator ptr;
  for (ptr = StudentList.begin(); ptr < StudentList.end(); ptr++) {
    cout << "Name: " << ptr -> name << " " << ptr -> lastName << ";   ID#: " << ptr -> id << ";   GPA: " << floor(ptr -> GPA*100)/100 << endl;
  }
}

void addFunction(vector <Student> *StudentListPtr) {//adds a new student into the vector
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
  StudentListPtr -> push_back(Student(firstName, lastName, idNum, gpa));//adding a student into the vector will all the associated information
  cout << endl;
  cout << firstName << " " << lastName << " added." << endl;
}

void deleteFunction(vector <Student> *StudentListPtr) {//goes through the vector of students, trying to match an inputted ID number. If the ID number inputted matches an ID number found in the vector, that student is deleted from the vector.
  cout << "ID: ";
  int target;
  cin >> target;
  vector<Student>::iterator itr;
  for (itr = StudentListPtr -> begin(); itr < StudentListPtr -> end(); itr++) {
    if (itr -> id == target) {
      cout << itr -> name << " " << itr -> lastName << " has been deleted from the system." << endl;
      StudentListPtr -> erase(itr);
      return;
    }
  }
  cout << "This student does not exist." << endl; //if the inputted ID number can't be found
}
