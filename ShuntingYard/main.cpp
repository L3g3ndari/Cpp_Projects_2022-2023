/*
Nathan Wu
Shunting Yard Algorithm
C++ Programming
Mr. Galbraith
Project Completed: 
Outside Sources Used: 

This program uses a shunting yard algorithm and a binary expression tree to convert mathematical expressions to infix, prefix, or postfix notation.
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <ctype.h>
#include <cstring>

using namespace std;

char* shuntingYard(char* input, int len);

int main() {
  cout << "Welcome to the Shunting Yard Algorithm Program." << endl << endl;
  cout << "Please input a mathematical expression. The expression may contain the four basic arithmetic expressions, powers, and parentheses." << endl << endl;

  while (true) {
    char input[20];
    cin.getline(input, 19);
    //cin.clear();
    //cin.ignore(20, '\n');
    int expressionLen = strlen(input);
    shuntingYard(input, expressionLen);
    cout << input << endl;
  }
}

char* shuntingYard(char* input, int len) {
  cout << "Performing SY algorithm..." << endl;
  int i = 0;
  cout << "Length: " << len << endl;
  while (i != len) {//traverse the inputted expression
    cout << "i = " << i << endl;
    if (isdigit(input[i])) {//if character is a number
      cout << "Character " << i << " = " << input[i] << endl;
      //put into output queue
    }
    else if (input[i] == '(' ||
	     input[i] == ')' ||
	     input[i] == '+' ||
	     input[i] == '-' ||
	     input[i] == '*' ||
	     input[i] == '/' ||
	     input[i] == '^') {//if the character is an operator
      cout << "Character " << i << " is an operator." << endl;
      //push to stack
    }
    else {//if character is a space or unrecognizable, ignore and move on
      //break;
    }
    i++;
  }
  return input;
}
