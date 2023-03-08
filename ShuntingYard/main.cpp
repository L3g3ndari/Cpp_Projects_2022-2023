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
#include "Node.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

char* shuntingYard(char* input, int len, Stack stack, Queue queue);

int main() {
  cout << "Welcome to the Shunting Yard Algorithm Program." << endl << endl;
  cout << "Please input a mathematical expression. The expression may contain the four basic arithmetic expressions, powers, and parentheses." << endl << endl;

  Stack stack = Stack();
  Queue queue = Queue();
  
  while (true) {
    char input[20];
    cin.getline(input, 19);
    //cin.clear();
    //cin.ignore(20, '\n');
    int expressionLen = strlen(input);
    char* SY = shuntingYard(input, expressionLen, stack, queue);
    for (int i = 0; i < strlen(SY); i++) {
      cout << SY[i];
    }
    cout << endl;
  }
}

char* shuntingYard(char* input, int len, Stack stack, Queue queue) {//Uses stack and queue to store elements, then returns the expression in postfix notation.
  cout << "Performing SY algorithm..." << endl;
  int i = 0;
  int queueSize = 0;
  int stackSize = 0;
  cout << "Length: " << len << endl;
  while (i != len) {//traverse the inputted expression
    cout << "i = " << i << endl;
    if (isdigit(input[i])) {//if character is a number
      cout << "Character " << i << " = " << input[i] << endl;
      //put into output queue
      queue.enqueue(new Node(input[i]));
      queueSize++;
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
      stack.push(new Node(input[i]));
      stackSize++;
    }
    else {//if character is a space or unrecognizable, ignore and move on
      //break;
    }
    i++;
  }
  cout << "About to start constructing postfix notation" << endl;
  //return using components from the stack and queue to get postfix notation
  char* pfNotation;
  //dequeue from queue to get the numbers
  int j = 0;
  cout << "queueSize = " << queueSize << endl;
  while (j < queueSize) {
    cout << "One iteration through queue started." << endl;
    pfNotation[j] = (queue.dequeue() -> getValue());//still getting seg fault?
    j++;
    cout << "One iteration through queue complete" << endl;
  }
  //pop off stack to get operators (in reverse order)
  cout << "stackSize = " << stackSize << endl;
  while (j < queueSize + stackSize) {
    pfNotation[j] = stack.pop();
    j++;
    cout << "One iteration through stack complete" << endl;
  }
  cout << "Finished building postfix notation, about to return." << endl;
  return pfNotation;
  //return input;
}
