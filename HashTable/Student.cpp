#include <iostream>
#include <cstring>
#include <cmath>
#include "Student.h"

using namespace std;

Student::Student(const char *firstName, const char *LastName, int idNum, float gpa) {
  name = new char[strlen(firstName) + 1];
  lastName = new char[strlen(LastName) + 1];
  strcpy(name, firstName);
  //cout << name << endl;
  //cout << firstName << endl;
  strcpy(lastName, LastName);
  id = idNum;
  GPA = gpa;
}

Student::~Student() {
  delete[] name;
  delete[] lastName;
}

void Student::printInfo() {//ID: Name, Last Name, GPA
  //cout << "Student Info: " << endl;
  //cout << "Name: " << name << " " << lastName << endl;
  //cout << "ID Number: " << id << endl;
  //cout << "GPA: " << floor((GPA*100))/100 << endl;
  //cout << (int*)(name) << endl;
  cout << id << ": " << name << " " << lastName << ", " << floor((GPA*100))/100 << endl;
}

float Student::getGPA() {
  return GPA;
}

char* Student::getName() {
  char* fullName = new char[strlen(name) + strlen(lastName) + 2];
  strcpy(fullName, name);
  strcpy(fullName + strlen(name), " ");
  strcpy(fullName +strlen(name) + 1, lastName);
  return fullName;
  //don't forget to delete the char* when using this function
}

int Student::getID() {
  return id;
}
