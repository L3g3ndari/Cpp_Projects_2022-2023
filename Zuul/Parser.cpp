#include <iostream>
#include <cstring>
#include "Parser.h"
using namespace std;

Parser::Parser() {};
void Parser::parse(char* input) {
  word1 = new char[20];
  word2 = new char[20];

  int i = 0;
  for(i = 0; i < strlen(input); i++) {
    if(input[i] != ' ') {
      word1[i] = input[i];
    }
    else {
      word1[i] = '\0';
      i++;
      break;
    }
  }
  int j = 0;
  for(j=0; j < strlen(input)-i; j++) {
    word2[j] = input[j+i];
  }
  word2[j] = '\0';
}
char* Parser::getWord1() {
  return word1;
}
char* Parser::getWord2() {
  return word2;
}
