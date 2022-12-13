#include <iostream>
#include <cstring>
#include <vector>
#include "Parser.h"
#include "Inventory.h"
#include "Room.h"

using namespace std;

void createRooms(vector <Room*> &rooms);
typedef void (*ExecuteCommand)(char* word2, Inventory&, Room*&);//creates a new type called ExecuteCommand that takes a char[]
void exeGo(char* word2, Inventory&, Room*&);
void exeGet(char* word2, Inventory&, Room*&);
void exeDrop(char* word2, Inventory&, Room*&);
void exeQuit(char* word2, Inventory&, Room*&);
void exeInventory(char* word2, Inventory&, Room*&);
void exeUse(char* word2, Inventory&, Room*&);
void exeHelp(char* word2, Inventory&, Room*&);
void exeDescription(char* word2, Inventory&, Room*&);
void displayIntro();

int main() {
  ExecuteCommand execute[8] = {exeGo, exeGet, exeDrop, exeQuit, exeInventory, exeUse, exeHelp, exeDescription};//creates an array of functions that take a char[], under the typing of ExecuteCommand
  bool gameOver = false;
  Parser myParser = Parser();
  vector <Room*> rooms;
  createRooms(rooms);
  /*for (vector<Room*>::iterator itr = rooms.begin(); itr != rooms.end(); itr++) {
    cout << (*itr) -> name << ", " << (*itr) -> description << endl;
    }*/
  Inventory myInventory;
  char testItem1[] = "testItem1";
  myInventory.addItem(testItem1);
  myInventory.printInventory();
  Room* currentRoom;
  for (vector<Room*>::iterator itr = rooms.begin(); itr!= rooms.end(); itr++) {
    if(strcmp((*itr) -> getName(), "Cafeteria") == 0) {
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
    char input[80];
    cin.get(input, 80);
    cin.clear();
    cin.ignore(80, '\n');
    myParser.parse(input);//parser splits the input into 2 command words
    cout << myParser.getWord1() << endl;
    cout << myParser.getWord2() << endl;
    //parser now contains 2 command words, which can be pulled by main if neccessary using getWord1() and getWord2().
    //check if word1 is a valid command (set up command word bank)
    bool validCom = false;
    for(int i = 0; i < 8; i++) {//loops through validCommands
        if (strcmp(myParser.getWord1(), validCommands[i]) == 0) {//if word1 = one of the valid commands
	//work on executing it, but also check for word2 (which can be done in the executing step)
	execute[i](myParser.getWord2(), myInventory, currentRoom);//executes the function that is commanded
	validCom = true;
      }
      if (validCom == true) {
	break;
      }
    }
    if (validCom == false) {
      cout << "That is not a valid command. The valid commands are: go, inventory, get, drop, use, description, quit, help." << endl;
    }    
  }
}

void exeGo(char* word2, Inventory& myInventory, Room*& currentRoom) {
  //cout << "Executed successfully." << endl;
  //cout << "Second Word: " << word2 << endl;
  currentRoom = currentRoom -> getExit(word2);
  
 }
void exeGet(char* word2, Inventory& myInventory, Room*& currentRoom){}
void exeDrop(char* word2, Inventory& myInventory, Room*& currentRoom){}
void exeQuit(char* word2, Inventory& myInventory, Room*& currentRoom){
  cout << "Good bye." << endl;
  exit(0);
}
void exeInventory(char* word2, Inventory& myInventory, Room*& currentRoom){
  myInventory.printInventory();
}
void exeUse(char* word2, Inventory& myInventory, Room*& currentRoom){}

void exeHelp(char* word2, Inventory& myInventory, Room*& currentRoom){
  //print out help message
  cout << endl;
  cout << "You are lost. You are alone." << endl << "Valid Commands: go, inventory, get, drop, use, description, quit, help" << endl << "Navigate the ship, fix it, and get back home." << endl;
  cout << endl;
}

void exeDescription(char* word2, Inventory& myInventory, Room*& currentRoom){//doesn't have an arguement. If problems arise, maybe put it back in?
  //print the description of the current room
  cout << currentRoom -> getDescription() << endl;
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

  name = new char[50]; description = new char[500]; strcpy(name, "Reactor"); strcpy(description, "You are in the reactor room. The reactor has been shut down. You might be able to restart it using your engineering skills.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Security"); strcpy(description, "You are in the security room. The large array of computer screens all display feeds from the security cameras around the ship. You feel a strange sense of loneliness.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Lower Engine"); strcpy(description, "You are in the upper engine room. The engine’s fuel gauge is getting low. You will need to refill it for the journey home.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 3"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Electrical"); strcpy(description, "You are in the electrical room. Lights blink everywhere, and exposed wires look like coils of colorful snakes. The distributor is not functioning properly. You will need your engineering skills to calibrate it to its optimal settings.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Storage"); strcpy(description, "You are in the storage room. Storage containers are stacked everywhere. It’s hard to move around in some places.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 5"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Admin"); strcpy(description, "You are in the admin room. The workstations are abandoned. The hologram console glows dimly, casting ominous shadows around the room.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "[Corridor 6"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Communications"); strcpy(description, "You are in the communications room. There are ghastly gouge marks on the walls and desks. But you really, really, want a decent wifi signal for your trip home, so you’ll need to reboot using one of the handheld computers.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Shields"); strcpy(description, "You are in the shield control room. The lights are bright, and there’s the body of one of your dead crewmates lying on the floor. You seem to recall his name was Dallin. There’s a control panel on the wall, but the shields are already primed, so you ignore it.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 4"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls \
and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Navigation"); strcpy(description, "You are in the navigation center of the ship. There are a lot of buttons on the dashboard. The deep darkness of space stretches before you in the cockpit’s window. You’ll need to chart the course home, but you can’t do that until you’ve completed all of your other tasks.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "O2"); strcpy(description, "You are in the O2 management room. This room supplies all the oxygen aboard the ship by recycling CO2 and using plants to regenerate O2. There’s still plenty of oxygen in the tanks, and the monitors are outputting stable readings. All air filters look clean enough to operate efficiently; you shouldn’t have to worry about cleaning them again for another 6 months.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Weapons"); strcpy(description, "You are in the weapons room. Machines whir and beep. One of your crewmates, Jonathan, lies slumped over the controls of the laser cannons.");
  rooms.push_back(new Room(name, description)); delete[] name; delete[] description;
}
