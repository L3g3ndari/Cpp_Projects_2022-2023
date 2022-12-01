#include <iostream>
#include <cstring>
using namespace std;

class Parser {
 public:
  Parser();
  void parse(char* input);
  char* getWord1();
  char* getWord2();
 protected:
  char* word1;
  char* word2;
};
