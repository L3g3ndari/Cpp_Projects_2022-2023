/*
Guessing Game in C++
Nathan Wu
C++ and Data Structures DC
Period 5
Jason Galbraith
Completed: 9/9/22
Extra Sources Utilized: Used cplusplus.com/reference/cstdlib/rand for documentation on how to generate random numbers.

The computer will pick a random number between 0 and 100, inclusive. 
The user will guess a number, and the computer will tell you if it is too high, too low, or correct. 
If it is correct, it will display how many guesses it took you, and ask if you want to play again.

Mr Galbraith's 3 (plus one extra) Commandments of C++:
- No global variables.
- No strings.
- You should include <iostream>, not stdio.
- Avoid using a mouse when possible.

*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
  bool stillPlaying = true;
  cout << "Hello. Welcome to Guessing Game." << endl;
  cout << "I will choose a number between 1 and 100." << endl;
  cout << "To guess, please type into the console and press enter." << endl;

  while (stillPlaying = true) {
    srand (time(NULL));
    int randomNum = rand() % 101; //generates random number between 1 and 100
    int guess = -1;
    int guessCount = 0;
    while (guess != randomNum) {//while they keep guessing the wrong number...
      cin >> guess;//take their guess
      guessCount++;//add one to number of guesses
      if (guess < randomNum) {//if their guess is less, tell them the number is higher.
	cout << "Sorry. My number is higher." << endl;
      }
      if (guess > randomNum) {//if their guess is higher, tell them the number is lower.
	cout << "Sorry. My number is lower." << endl;
      }
    }
    cout << "Correct! The number was " << randomNum << endl;//after they guess it correctly
    cout << "It took you " << guessCount << " tries to guess my number." << endl;
    cout << "Play Again?   (y/n)" << endl;
    char yesno[100];
    cin >> yesno;
    if (strcmp(yesno, "y") == 0) {//deterine whether or not they typed "y"
      stillPlaying = true;
      cout << "I have selected a new number. Guess away." << endl;
    }
    else {//if they didn't type "y," exit the game.
      cout << "Thanks for playing. Goodbye." << endl;
      stillPlaying = false;
      exit(0);
    }
  }
}


