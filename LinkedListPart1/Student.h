#include <iostream>

using namespace std;

class Student {
 public:
  Student(const char *firstName, const char *LastName, int idNum, float gpa);
  ~Student();
  float getGPA();
  void printInfo();
 private:
  char* name;
  char* lastName;
  int id;
  float GPA;
};
