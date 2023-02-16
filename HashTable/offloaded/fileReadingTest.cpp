#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
  vector<char*> firstNames;
  vector<char*> lastNames;
  
  char* line = new char[20];
  char array[20];
  ifstream fnFile ("firstNameEC.txt");
  if (fnFile.is_open()) {
    while (fnFile >> array) {
      line = new char[20];
      strcpy(line, array);
      cout << line << endl;
      firstNames.push_back(line);
    }
    cout << firstNames[6] << endl;
  }
  else cout << "Unable to open first name file" << endl;

  for (int i = 0; i < 10; i++) {
    //cout << firstNames[i] << endl;
  }
  
}
