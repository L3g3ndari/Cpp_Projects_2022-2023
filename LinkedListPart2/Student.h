#ifndef STUDENT
#define STUDENT
#include <iostream>

using namespace std;

class Student {
 public:
  Student(const char *firstName, const char *LastName, int idNum, float gpa);
  ~Student();
  char* getName();
  int getID();
  float getGPA();
  void printInfo();
 private:
  char* name;
  char* lastName;
  int id;
  float GPA;
};

#endif
