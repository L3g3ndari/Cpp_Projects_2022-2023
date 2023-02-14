#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
 vector<char*> firstNames;
 vector<char*> lastNames;

  char line[20];
  ifstream fnFile ("firstName.txt");
  if (fnFile.is_open()) {
    while ((fnFile >> line)) {
      cout << line << endl;
      firstNames.push_back(line);
    }
    cout << firstNames[2] << endl;
  }
  else cout << "Unable to open first name file" << endl;

  for (int i = 0; i < 10; i++) {
    //cout << firstNames[i] << endl;
  }
  
}
