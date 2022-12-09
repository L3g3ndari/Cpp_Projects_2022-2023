#include <iostream>
#include <cstring>
#include <vector>
#include "Parser.h"
#include "Room.h"

using namespace std;

void createRooms(vector <Room*> &rooms);
typedef void (*ExecuteCommand)(char* word2);//creates a new type called ExecuteCommand that takes a char[]
void exeGo(char* word2);
void exeGet(char* word2);
void exeDrop(char* word2);
void exeQuit(char* word2);
void exeInventory(char* word2);
void exeUse(char* word2);
void exeHelp(char* word2);
void exeDescription(char* word2);
void displayIntro();

int main() {
  ExecuteCommand execute[8] = {exeGo, exeGet, exeDrop, exeQuit, exeInventory, exeUse, exeHelp, exeDescription};//creates an array of functions that take a char[], under the typing of ExecuteCommand
  char input[80];
  bool gameOver = false;
  Parser myParser = Parser();
  vector <Room*> rooms;
  createRooms(rooms);
  /*for (vector<Room*>::iterator itr = rooms.begin(); itr != rooms.end(); itr++) {
    cout << (*itr) -> name << ", " << (*itr) -> description << endl;
    }*/
  Room* currentRoom;
  for (vector<Room*>::iterator itr = rooms.begin(); itr!= rooms.end(); itr++) {
    if(strcmp((*itr) -> name, "Cafeteria") == 0) {
      currentRoom = *itr;
    }
  }

  char validCommands[8][12] = {"go", "get", "drop", "quit", "inventory", "use", "help", "description"};
  
  cout << "Welcome to Zuul!" << endl;
  cout << endl;
  displayIntro();
  /*char testD1[] = "Description 1";
  char testD2[] = "Description 2";
  char testDir1[] = "east";
  cout << "break -1" << endl;
  Room testRoom1 = Room(testD1);
  Room testRoom2 = Room(testD2);
  cout << "break 0" << endl;
  testRoom1.setExit(testDir1, &testRoom2);
  cout << "break 1" << endl;
  cout << testRoom1.getDescription() << endl;
  cout << "break 2" << endl;
  cout << testRoom1.getExitString() << endl;
  cout << "break 3" << endl;
  */
  
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


void displayIntro() {
  cout << "You are onboard the Skeld, an intergalactic research starship. You are the sole survivor of a catastrophic encounter with hostile alien life. The aliens have savagely murdered all of your friends. Fortunately, you were able to lock the shield doors to the security room before any aliens arrived. Unfortunately, you had access to all the camera feeds during the invasion, and you saw each of your team members stalked and gruesomely mutilated by the murderous Martians. Your saving grace is that the aliens, although extremely intelligent, suffered a careless moment by the airlock, and were sucked out of the ship, along with a few of your crewmates. Now, you must fix the ship so you can return home to Earth." << endl;
  cout << endl;
}

void createRooms(vector <Room*> &rooms) {
  char* name = new char[50];
  char* description = new char[500];
  strcpy(name, "Cafeteria");
  strcpy(description, "You are in the cafeteria. The room is clean and spacious. The fluorescent lights burn your eyes. There are a few empty tables. The room is filled with an eerie quiet that you aren’t expecting.");
  rooms.push_back(new Room(name, description));
  delete[] name;
  delete[] description;
  
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 1"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Upper Engine"); strcpy(description, "You are in the upper engine room. The engine is slightly damaged. You will need some tools to repair it.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "MedBay"); strcpy(description, "You are in the MedBay. The air smells like a doctor's office and fresh laundry. It’s pretty cold in the room. The bioscanner sits in the corner.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 2"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, ""); strcpy(description, "");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, ""); strcpy(description, "");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, ""); strcpy(description, "");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, ""); strcpy(description, "");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, ""); strcpy(description, "");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;
}
