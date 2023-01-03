#include <iostream>
#include <cstring>
#include <cmath>
#include "Student.h"

using namespace std;

Student::Student(const char *firstName, const char *LastName, int idNum, float gpa) {
  name = new char[strlen(firstName) + 1];
  lastName = new char[strlen(LastName) + 1];
  strcpy(name, firstName);
  strcpy(lastName, LastName);
  id = idNum;
  GPA = gpa;
}

void Student::printInfo() {
  cout << "Student Info: " << endl;
  cout << "Name: " << name << " " << lastName << endl;
  cout << "ID Number: " << id << endl;
  cout << "GPA: " << floor((GPA*100)/100) << endl;
}

float Student::getGPA() {
  return GPA;
}
