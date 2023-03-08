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

void shuntingYard(char* input, int len, Stack stack, Queue queue);

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

void shuntingYard(char* input, int len, Stack stack, Queue queue) {//Uses stack and queue to store elements, then returns the expression in postfix notation.
  cout << "Performing SY algorithm..." << endl;
  int i = 0;
  int queueSize = 0;
  int stackSize = 0;
  cout << "Length: " << len << endl;
  while (i != len) {//traverse the inputted expression
    if (input[i] == '(') {//if character is a left parentheses
      stack.push(newNode(input[i]));
      stackSize++;
    }
    if (isdigit(input[i])) {//if character is a number
      //cout << "Character " << i << " = " << input[i] << endl;
      queue.enqueue(new Node(input[i]));
      queueSize++;
    }
    if (input[i] == ')') {//if character is right parentheses
      //repeatedly pop from stack and add it to the queue until a "(" is encountered.
      while (stack.peek() != '(') {//if not a "(", pop from stack and add to queue
	queue.enqueue(new Node(stack.pop()));
	stackSize--;
	queueSize++;
      }
      stack.pop();//removes the "(" from the stack but doesn't add it to the queue
    }
    if (//input[i] == '(' ||
	//input[i] == ')' ||
	input[i] == '+' ||
	input[i] == '-' ||
	input[i] == '*' ||
	input[i] == '/' ||
	input[i] == '^') {//if the character is an operator
      if (checkHiPrec(input[i], stack.peek()) == true) {//check if higher precedence, subject has higher precedence
	queue.enqueue(new Node*(input[i]));
      }
      else {//subject has equal or lower precedence, enqueue head of stack (pop)
	while (checkHiPrec(input[i], stack.peek()) == false) {//while precedence is lower
	  queue.enqueue(new Node*(stack.pop()));
	}
      }
    }
    i++;
  }
}

bool checkHiPrec(char subject, char peeked) {//if subject has greater P than peeked, return true
  if (peeked == '(') {
    return false;//we want to push the operator we are checking to the stack, regardless
  }
  if (subject == '^') {
    if (peeked != '^') {//if the stack has any other operator, '^' holds precedence
      return true;
    }
    return false;
  }
  if (subject == '*' || subject == '/') {//if '*' or '/' has equal or higher precedence to stack
    if (peeked == '+' || peeked == '-') {//only has higher precedence over '+' and '-'
      return true;
    }
    return false;
  }
  if (subject == '+' || subject == '-') {//will never have higher precedence
    return false;
  }
}

  /*
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
	     //input[i] == ')' ||
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
    else if (input[i] == ')') {
      //
    }
    else {//if character is a space or unrecognizable, ignore and move on
      //break;
    }
    i++;
  }
  cout << "About to start constructing postfix notation" << endl;
  //return using components from the stack and queue to get postfix notation
  char* pfNotation = new char[queueSize + stackSize]; 
  //dequeue from queue to get the numbers
  int j = 0;
  cout << "queueSize = " << queueSize << endl;
  for (;j < queueSize; j++) {
    cout << "One iteration through queue started." << endl;
    pfNotation[j] = (queue.dequeue());
    cout << "The char: " << pfNotation[j] << endl;
    cout << "One iteration through queue complete" << endl;
  }
  //pop off stack to get operators (in reverse order)
  cout << "stackSize = " << stackSize << endl;
  for (;j < queueSize + stackSize; j++) {
    pfNotation[j] = stack.pop();
    cout << "One iteration through stack complete" << endl;
  }
  pfNotation[j] = '\0';
  cout << "Finished building postfix notation, about to return." << endl;
  return pfNotation;
  //return input;
}
  */
