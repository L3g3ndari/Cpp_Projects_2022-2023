/*
Nathan Wu
Shunting Yard Algorithm
C++ Programming
Mr. Galbraith
Project Completed: 3/16/2023
Outside Sources Used: 
 - https://en.wikipedia.org/wiki/Shunting_yard_algorithm = for understanding and implementing the Shunting Yard Algorithm
 - https://en.wikipedia.org/wiki/Binary_expression_tree = for understanding and implementing the Binary Expression Tree
 - https://raj457036.github.io/Simple-Tools/prefixAndPostfixConvertor.html = significant resource for checking work and for determining the shunting yard algorithm. Did not use any code from this site.
 - Collaborated significantly with Sam van Dahl to produce binary expression tree construction

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

void shuntingYard(char* input, int len, Stack &stack, Queue &queue);
void biExTree(Stack &stack, Queue &queue, Node* &root);
bool checkHiPrec(char subject, char peeked);
int getOperatorVal(char op);
void infix(Node* current);
void prefix(Node* current);
void postfix(Node* current);
bool isOperator(char value);

int main() {
  cout << "Welcome to the Shunting Yard Algorithm Program." << endl << endl;
  cout << "Please input a mathematical expression. The expression may contain the four basic arithmetic expressions, powers, and parentheses." << endl << endl;

  Stack stack = Stack();
  Queue queue = Queue();
  Node* root = NULL;
  
  while (true) {
    char inputU[50];
    cin.getline(inputU, 50);
    //cin.clear();
    //cin.ignore(50, '\n');

//remove spaces
    char input[50];
    for (int c = 0, g = 0; c < strlen(inputU); c++) {
      if (inputU[c] != ' ') {
        input[g] = inputU[c];
        g++;
      }
    }
    //cout << "This is going into the algorithm: ";
    //for (int i = 0; i < strlen(input); i++) {
    //cout << input[i];
    //}
    cout << endl;
    
    int expressionLen = strlen(input);
    shuntingYard(input, expressionLen, stack, queue);
    //cout << endl << "Algorithm complete" << endl;
    //cout << "qSize: " << queue.getSize() << endl;
    cout << "Postfix expression from Shunting Yard Algorithm: ";
    for (int i = 0; i < queue.getSize(); i++) {
      cout << queue.enqueue(new Node(queue.dequeue()));
    }
    cout << endl;
    //char postfixSY[20];
    //for (int i = 0; i < queue.getSize(); i++) {
    //postfixSY[i] = queue.enqueue(new Node(queue.dequeue()));
    //}
    //cout << "Postfix expression from Shunting Yard Algorithm: " << postfixSY << endl;

    biExTree(stack, queue, root);

    char* output = new char[50];
    bool valid = false;
    char outType[10];
    while (valid == false) {
      cout << endl << "Please select an input type (infix, prefix, or postfix)" << endl << "Output type: ";
      cin >> outType;
      cin.clear();
      cin.ignore(10, '\n');
      if (strcmp(outType, "infix") == 0 ||
	  strcmp(outType, "prefix") == 0 ||
	  strcmp(outType, "postfix") == 0) {//if one of the valid inputs
	cout << endl;
	valid = true;
      }
      else {
	valid = false;
	cout << "That is not a valid input type." << endl;
      }
    }
    if (strcmp(outType, "infix") == 0) {
      //cout << "Constructing infix output" << endl;
      cout << "Infix Output: ";
      infix(root);
      break;
    }

    if (strcmp(outType, "prefix") == 0) {
      //cout << "Constructing prefix output" << endl;
      cout << "Prefix Output: ";
      prefix(root);
      break;
    }

    if (strcmp(outType, "postfix") == 0) {
      //cout << "Constructing postfix output" << endl << endl;
      cout << "Postfix Output: ";
      postfix(root);
      break;
    }
  }
  cout << endl << endl << "The program is complete. Goodbye." << endl;
  exit(0);
}

void shuntingYard(char* input, int len, Stack &stack, Queue &queue) {//Uses stack and queue to store elements, then returns the expression in postfix notation.
  //cout << "Performing SY algorithm..." << endl;
  int i = 0;
  int queueSize = 0;
  int stackSize = 0;
  bool closedParentheses = true;
  //cout << "Length: " << len << endl;
  while (i < len) {//traverse the inputted expression
    if (input[i] == '(') {//if character is a left parentheses
      stack.push(new Node(input[i]));
      closedParentheses = false;
      stackSize++;
    }
    if (isdigit(input[i])) {//if character is a number
      //cout << "Character " << i << " = " << input[i] << endl;
      queue.enqueue(new Node(input[i]));
      //cout << "Enqueued " << input[i] << endl;
      queueSize++;
    }
    if (input[i] == ')') {//if character is right parentheses
      //cout << "Hit a right parentheses" << endl;
      //repeatedly pop from stack and add it to the queue until a "(" is encountered.
      while (stack.peek() != '(' && stack.peek() != 'L') {//if not a "(", pop from stack and add to queue
	if (stack.peek() != ' ') {
	  queue.enqueue(new Node(stack.pop()));
	  //cout << "Enqueued " << queue.peek() << endl;
	  stackSize--;
	  queueSize++;
	}
      }
      //cout << "Removed " << stack.peek() << ", thinking it was a parenthese" << endl;
      stack.pop();//removes the "(" from the stack but doesn't add it to the queue
      closedParentheses = true;
    }
    if (//input[i] == '(' ||
	//input[i] == ')' ||
	input[i] == '+' ||
	input[i] == '-' ||
	input[i] == '*' ||
	input[i] == '/' ||
	input[i] == '^') {//if the character is an operator
      if (checkHiPrec(input[i], stack.peek()) == true) {//check if higher precedence, if subject has higher precedence
	//cout << input[i] << " has higher precedence than " << stack.peek() << endl;
	stack.push(new Node(input[i]));
	stackSize++;
      }
      else {//subject has equal or lower precedence, enqueue head of stack (pop)
	while (checkHiPrec(input[i], stack.peek()) == false) {//while precedence is lower
	  //cout << input[i] << " has lower precedence than " << stack.peek() << endl;
	  //cout << "Stack.peek() = " << stack.peek() << endl;
	  queue.enqueue(new Node(stack.pop()));
	  //cout << "Popped " << queue.peek() << " off the stack and enqueued it." << endl;
	  queueSize++;
	  stackSize--;
	  //cout << checkHiPrec(input[i], stack.peek()) << endl;
	}
	stack.push(new Node(input[i]));//afterwards, push the operator to the stack
	stackSize++;
      }
    }
    else {//potential solution to spaces
      //cout << "I think I hit a space." << endl;
    }
    i++;
  }
  //Constructing full queue
  //cout << "stackSize = " << stackSize << endl;
  //cout << "queueSize = " << queueSize << endl;
  int originalStackSize = stackSize;
  for (int i = 0; i < originalStackSize; i++) {
    //cout << i << " < " << originalStackSize << endl;
    if (stack.peek() != 'L') {
      queue.enqueue(new Node(stack.pop()));
      queueSize++;
      stackSize--;
    }
  }
  //cout << "queue is complete." << endl;
  //cout << "queueSize = " << queue.getSize() << endl;
  if (closedParentheses == false) {//give error message and clear queue
    cout << "The algorithm tried to process an invalid expression. Please check your parentheses." << endl;
    while (queue.getSize() != 0) {
      queue.dequeue();
    }
  }
}

int getOperatorVal(char op) {
  if (op == '(') return 5;
  if (op == '^') return 4;
  if (op == '*' || op == '/') return 3;
  if (op == '+' || op == '-') return 2;
  if (op == 'L') return 1;
  return 111;
}

bool checkHiPrec(char subject, char peeked) {//if subject has greater P than peeked, return true
  //cout << "Peeked: " << peeked << endl;
  if (peeked == '(') return true;
  if (getOperatorVal(subject) <= getOperatorVal(peeked)) return false;
  else return true;
}

void biExTree(Stack &stack, Queue &queue, Node* &root) {//builds the tree
  //cout << "Constructing Binary Expression Tree..." << endl;
  while (true) {
    char temp = queue.peek();
    if (isdigit(temp) == true) {//if num, push to stack
      Node* num = new Node(queue.dequeue());
      stack.push(num);
      //cout << "Pushed: " << temp << endl;
    }
    else if (temp == '+' ||
	     temp == '-' ||
	     temp == '*' ||
	     temp == '/' ||
	     temp == '^') {//if the character is an operator
      Node* n = new Node(queue.dequeue());
      if (queue.peek() == 'L') {//if queue is empty, we are at the root
	//cout << "We are at the root." << endl;
	root = n;
	Node* r = stack.popNode();
	root -> setRight(r);
	r -> setPrevious(root);
	Node* l = stack.popNode();
        root -> setLeft(l);
        l -> setPrevious(root);
	break;
      }
      else {//everything else that isn't the root
	//cout << "Creating branches" << endl;
	Node* r = stack.popNode();
        n -> setRight(r);
        r -> setPrevious(n);
        Node* l = stack.popNode();
        n -> setLeft(l);
        l -> setPrevious(n);
	stack.push(n);
      }
    }
    else {//invalid character
      cout << "Invalid character." << endl;
    }
  }
}

bool isOperator(char value) {
  if (value == '(' ||
      value == ')' ||
      value == '+' ||
      value == '-' ||
      value == '*' ||
      value == '/' ||
      value == '^') {
    return true;
  }
  else return false;
}

void infix(Node* current) {
  if (current != NULL) {
    if (isOperator(current -> getValue()) == true) {
      cout << '(';
    }
    infix(current -> getLeft());
    cout << current -> getValue();
    infix(current -> getRight());
    if (isOperator(current -> getValue()) == true) {
      cout << ')';
    }
  } 
}

void prefix(Node* current) {
  if (current == NULL) return;
  cout << current -> getValue();
  prefix(current -> getLeft());
  prefix(current -> getRight());
}

void postfix(Node* current) {
  if (current == NULL) return;
  postfix(current -> getLeft());
  postfix(current -> getRight());
  cout << current -> getValue();
}
