#include <iostream>
#include <cstring>
#include "Parser.h"
using namespace std;

Parser::Parser() {};
void Parser::parse(char* input) {
  word1 = new char[20];
  word2 = new char[20];
  //strcpy (word2, "1");
  
  int i = 0;
  cout << "Input:" << input << endl;
  for(i = 0; i < strlen(input); i++) {
    if(input[i] != ' ' && input[i] != '\0') {
      word1[i] = input[i];
    }
    else {
      //i++;
      break;
    }
  }
  word1[i] = '\0';
  if (input[i] == '\0') {
    strcpy (word2, "1");
  }
  else {
i++;
  int j = 0;
  for(j=0; j < strlen(input)-i; j++) {
    word2[j] = input[j+i];
  }
  word2[j] = '\0';
  }
}
char* Parser::getWord1() {
  return word1;
}
char* Parser::getWord2() {
  return word2;
}

