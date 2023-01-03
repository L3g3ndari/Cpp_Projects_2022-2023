#include <iostream>
#include <cstring>
#include "Node.h"
#include "Student.h"

using namespace std;

int main () {
  Node* head = new Node(Student("Jason", "Galbraith", 123456, 4.229));
  head -> getStudent.printInfo();
  //NEED TO TEST
}
