#include <iostream>
#include <cstring>
#include <vector>
#include "Parser.h"

using namespace std;

//void createRooms();


int main() {
  char input[80];
  bool gameOver = false;
  Parser myParser = Parser();
  
  while (gameOver == false) {
    cin.get(input, 80);
    cin.clear();
    cin.ignore(80, '\n');
    myParser.parse(input);
    cout << myParser.getWord1() << endl;
    cout << myParser.getWord2() << endl;
    //parser splits the input into 2 command words
    //parser now contains 2 command words, which can be pulled by main if neccessary.
    //check if word1 is a valid command
  }
}
