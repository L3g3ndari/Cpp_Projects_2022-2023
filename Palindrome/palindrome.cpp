/*
Palindrome
Nathan Wu
C++ 2022-23, P5
Jason Galbraith
Date Completed: 9/19/22
External Sources Utilized: None.

The program takes an input from the user and determines whether or not it is a palindrome or not.
Inputs are limited to 80 characters. Special characters and numbers will be removed.

 */

#include <iostream>
#include <cstring>
using namespace std;

int main () {
  cout << "Hello. Welcome to the Palindrome Program." << endl;
  cout << "Please input some text. I will determine if it is a palindrome or not." << endl;

  char inputStr[81];
  char compareStr[81];
  int len = 0;
  cin.get(inputStr, 81);//get input from user, up to 80 characters
  //process the input to remove spaces and special characters
  //char inputStrPr[81] = inputStr.erase(inputStrbegin(), inputStr.end(), ' '), inputStr.end());
  cout << "This is what you inputted: " << inputStr << endl;
  int count = 0;
  
  //copy inputStr compareStr but with some processing to remove spaces, special characters, and change everything to lowercase
  for (int i = 0; i < 80; i++) {
    if (inputStr[i] != '\0') {//if the character isn't the null character
      if (inputStr[i] > 96 && inputStr[i] < 123) {//and if the character is a lowercase letter
       	compareStr[count] = inputStr[i];//copy the character to compareStr
	count++;
      }
      else if (inputStr[i] > 64 && inputStr[i] < 91) {//if character is an uppercase letter
	compareStr[count] = inputStr[i] + 32;//copy the character to compareStr as a lowercase letter
	count++;
      }
    }
    else {
      compareStr[count] = '\0';//manually add a null character
      len = count;
      i = 80;//used to break out of the for loop so that no other characters are read
    }
  }

  //cout << "This is compareStr: " << compareStr << endl;
  //cout << "This is the value of len: " << len << endl;
  char compareStr2[len + 1];
  char compareStrOG[len + 1];
  //copy compareStr into compareStr2, but backwards
  for (int i = 0; i < len; i++) {
    compareStr2[i] = compareStr[len - 1 - i];
    compareStrOG[i] = compareStr[i];
    //cout << compareStr2 << endl;
  }
  
  //Comparing the values of each char to see if any don't line up
  for (int i = 0; i < count - 1; i++) {
    int valueOG = int(compareStrOG[i]);
    int valueCompare = int (compareStr2[i]);
    if (valueOG != valueCompare) {//if the char values don't match
      cout << "Not a Palindrome." << endl;
      exit(0);
    }
    else {
      cout << "Palindrome." << endl;
      exit(0);
    }
  }
  
}

