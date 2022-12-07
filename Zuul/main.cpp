#include <iostream>
#include <cstring>
#include <vector>
#include "Parser.h"
#include "Room.h"

using namespace std;

//void createRooms();
typedef void (*ExecuteCommand)(char* word2);//creates a new type called ExecuteCommand that takes a char[]
void exeGo(char* word2);
void exeGet(char* word2);
void exeDrop(char* word2);
void exeQuit(char* word2);
void exeInventory(char* word2);
void exeUse(char* word2);
void exeHelp(char* word2);
void exeDescription(char* word2);

int main() {
  ExecuteCommand execute[8] = {exeGo, exeGet, exeDrop, exeQuit, exeInventory, exeUse, exeHelp, exeDescription};//creates an array of functions that take a char[], under the typing of ExecuteCommand
  char input[80];
  bool gameOver = false;
  Parser myParser = Parser();

  char validCommands[8][12] = {"go", "get", "drop", "quit", "inventory", "use", "help", "description"};
  
  cout << "Welcome to Zuul!" << endl;
  cout << endl;
  char* testD1 = "Description 1";
  char* testD2 = "Description 2";
  char* testDir1 = "east";
  Room testRoom1 = Room(testD1);
  Room testRoom2 = Room(testD2);
  testRoom1.setExit(testDir1, &testRoom2);
  cout << testRoom1.getDescription() << endl;
  cout << testRoom1.getExitString() << endl;
  
  while (gameOver == false) {
    cin.get(input, 80);
    cin.clear();
    cin.ignore(80, '\n');
    myParser.parse(input);//parser splits the input into 2 command words
    cout << myParser.getWord1() << endl;
    cout << myParser.getWord2() << endl;
    //parser now contains 2 command words, which can be pulled by main if neccessary using getWord1() and getWord2().
    //check if word1 is a valid command (set up command word bank)
    for(int i = 0; i < 8; i++) {//loops through validCommands
      if (strcmp(myParser.getWord1(), validCommands[i]) == 0) {//if word1 = one of the valid commands
	//work on executing it, but also check for word2 (which can be done in the executing step)
	execute[i](myParser.getWord2());//executes the function that is commanded
      }
    }
  }
}

void exeGo(char* word2) {
  cout << "Executed successfully." << endl;
  cout << "Second Word: " << word2 << endl;
 }
void exeGet(char* word2){}
void exeDrop(char* word2){}
void exeQuit(char* word2){}
void exeInventory(char* word2){}
void exeUse(char* word2){}


void exeHelp(char* word2){
  //print out help message
}

void exeDescription(char* word2){
  //print the description of the current room
}
