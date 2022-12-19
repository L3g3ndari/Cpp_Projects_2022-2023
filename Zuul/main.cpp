/*
Zuul: The Skeld
Nathan Wu
C++ Programming
Mr. Galbraith
Period 5
Project Completed: 12/19/22
Outside Sources Used: https://cplusplus.com/forum/beginner/4639/ for guidance on how to create an array of functions

This is a text-based adventure game. Type help for valid command words.

Map image can be found here: https://docs.google.com/document/d/17581iAI9M3MsyBOVWK8_JEmnMB0tLaoVv3JnHJcBYPc/edit?usp=sharing
*/

#include <iostream>
#include <cstring>
#include <vector>
#include "Parser.h"
#ifndef n
#define n
#include "Inventory.h"
#endif
#include "Room.h"
using namespace std;

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

  //CREATES ROOMS
  char* name = new char[50];
  char* description = new char[500];
  strcpy(name, "Cafeteria");//Here's what it looks like expanded. The other rooms are created in a more condensed way to save space.
  strcpy(description, "You are in the cafeteria. The room is clean and spacious. The fluorescent lights burn your eyes. There are a few empty tables. The room is filled with an eerie quiet that you aren’t expecting.");
  Room* Cafeteria = new Room(name, description);
  delete[] name;
  delete[] description;

  name = new char[50]; description = new char[500]; strcpy(name, "Corridor_1"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor1 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Upper_Engine"); strcpy(description, "You are in the upper engine room. The engine hums loudly, with the occasional clunk. You can use tools to perform maintenance on the engine.");
  Room* UpperEngine = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "MedBay"); strcpy(description, "You are in the MedBay. The air smells like a doctor's office and fresh laundry. It’s pretty cold in the room. The bioscanner sits in the corner.");
  Room* MedBay = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor_2"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor2 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Reactor"); strcpy(description, "You are in the reactor room. The reactor has been shut down. You might be able to restart it using your engineering skills.");
  Room* Reactor = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Security"); strcpy(description, "You are in the security room. The large array of computer screens all display feeds from the security cameras around the ship. You feel a strange sense of loneliness.");
  Room* Security = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Lower_Engine"); strcpy(description, "You are in the lower engine room. The engine hums loudly, with the occasional clunk. You can use tools to perform maintenance on the engine.");
  Room* LowerEngine = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor_3"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor3 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Electrical"); strcpy(description, "You are in the electrical room. Lights blink everywhere, and exposed wires look like coils of colorful snakes. The distributor is not functioning properly. You will need your engineering skills to calibrate it to its optimal settings.");
  Room* Electrical = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Storage"); strcpy(description, "You are in the storage room. Storage containers are stacked everywhere. It’s hard to move around in some places.");
  Room* Storage = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor_5"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor5 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Admin"); strcpy(description, "You are in the admin room. The workstations are abandoned. The hologram console glows dimly, casting ominous shadows around the room. To access the mission log, swipe your ID Card.");
  Room* Admin = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor 6"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor6 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Communications"); strcpy(description, "You are in the communications room. There are ghastly gouge marks on the walls and desks. The wifi is a bit spotty right now, but you really, really, want a decent wifi signal for your trip home, so you’ll need to reboot using one of the handheld computers.");
  Room* Communications = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Shields"); strcpy(description, "You are in the shield control room. The lights are bright, and there’s the body of one of your dead crewmates lying on the floor. You seem to recall his name was Dallin. There’s a control panel on the wall, but the shields are already primed, so you ignore it.");
  Room* Shields = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Corridor_4"); strcpy(description, "You are in a corridor. The lights are dimmer here, and some of the pipes along the walls \
and ceiling gurgle or hiss. Lights blink eerily on nearby control panels.");
  Room* Corridor4 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Navigation"); strcpy(description, "You are in the navigation center of the ship. There are a lot of buttons on the dashboard. The deep darkness of space stretches before you in the cockpit’s window. You can chart the course home using a handheld computer.");
  Room* Navigation = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "O2"); strcpy(description, "You are in the O2 management room. This room supplies all the oxygen aboard the ship by recycling CO2 and using plants to regenerate O2. There’s still plenty of oxygen in the tanks, and the monitors are outputting stable readings. All air filters look clean enough to operate efficiently; you shouldn’t have to worry about cleaning them again for another 6 months.");
  Room* O2 = (new Room(name, description)); delete[] name; delete[] description;
  name = new char[50]; description = new char[500]; strcpy(name, "Weapons"); strcpy(description, "You are in the weapons room. Machines whir and beep. One of your crewmates, Jonathan, lies slumped over the controls of the laser cannons.");
  Room* Weapons = (new Room(name, description)); delete[] name; delete[] description;

  //SETS ALL EXITS
  Cafeteria -> setExit('w', Corridor1);
  Cafeteria -> setExit('s', Corridor5);
  Cafeteria -> setExit('e', Weapons);
  Corridor1 -> setExit('s', MedBay);
  Corridor1 -> setExit('w', UpperEngine);
  MedBay -> setExit('n', Corridor1);
  UpperEngine -> setExit('e', Corridor1);
  UpperEngine -> setExit('s', Corridor2);
  Corridor2 -> setExit('n', UpperEngine);
  Corridor2 -> setExit('w', Reactor);
  Corridor2 -> setExit('s', LowerEngine);
  Corridor2 -> setExit('e', Security);
  Reactor -> setExit('e', Corridor2);
  Security -> setExit('w', Corridor2);
  LowerEngine -> setExit('n', Corridor2);
  LowerEngine -> setExit('e', Corridor3);
  Corridor3 -> setExit('w', LowerEngine);
  Corridor3 -> setExit('n', Electrical);
  Corridor3 -> setExit('e', Storage);
  Electrical -> setExit('s', Corridor3);
  Storage -> setExit('w', Corridor3);
  Storage -> setExit('n', Corridor5);
  Corridor5 -> setExit('s', Storage);
  Corridor5 -> setExit('n', Cafeteria);
  Corridor5 -> setExit('e', Admin);
  Admin -> setExit('w', Corridor5);
  Storage -> setExit('e', Corridor6);
  Corridor6 -> setExit('s', Communications);
  Communications -> setExit('n', Corridor6);
  Corridor6 -> setExit('w', Storage);
  Corridor6 -> setExit('e', Shields);
  Shields -> setExit('w', Corridor6);
  Shields -> setExit('n', Corridor4);
  Corridor4 -> setExit('s', Shields);
  Corridor4 -> setExit('e', Navigation);
  Navigation -> setExit('w', Corridor4);
  Corridor4 -> setExit('w', O2);
  O2 -> setExit('e', Corridor4);
  Corridor4 -> setExit('n', Weapons);
  Weapons -> setExit('s', Corridor4);
  Weapons -> setExit('w', Cafeteria);

  //INITIALIZES INVENTORY and ITEMS
  Inventory myInventory;
  //char testItem1[] = "testItem1";
  char engineeringSkills[] = "Engineering Skills";
  char idCard[] = "ID Card";
  char fuelTank[] = "Fuel Tank";
  char handheldComputer[] = "Handheld Computer";
  char toolbox[] = "Toolbox";
  char looseWire[] = "Loose Wire";
  char notepad[] = "Notepad";
  char beaker[] = "Beaker";
  char pen[] = "Pen";
  
  //myInventory.addItem(testItem1);
  myInventory.addItem(engineeringSkills);
  myInventory.addItem(idCard);
  Storage -> roomInventory.addItem(fuelTank);
  Communications -> roomInventory.addItem(handheldComputer);
  Electrical -> roomInventory.addItem(toolbox);
  Corridor2 -> roomInventory.addItem(looseWire);
  Admin -> roomInventory.addItem(notepad);
  Admin -> roomInventory.addItem(pen);
  O2 -> roomInventory.addItem(beaker);
  
  Room* currentRoom;
  currentRoom = Cafeteria;
  
  char validCommands[8][12] = {"go", "get", "drop", "quit", "inventory", "use", "help", "description"};//a 2D array that stores all the valid command strings
  
  cout << "Welcome to Zuul!" << endl;
  cout << endl;
  displayIntro();
  cout << endl;
  execute[7](myParser.getWord2(), myInventory, currentRoom);//prints the first description
  
  while (gameOver == false) {
    cout << endl;
    cout << "Command: ";
    char input[80];
    cin.get(input, 80);//get an input from the user
    cin.clear();
    cin.ignore(80, '\n');
    myParser.parse(input);//parser splits the input into 2 command words
    //cout << myParser.getWord1() << endl;
    //cout << myParser.getWord2() << endl;

    //parser now contains 2 command words, which can be pulled by main if neccessary using getWord1() and getWord2().
    
    bool validCom = false;
    for(int i = 0; i < 8; i++) {//loops through validCommands
        if (strcmp(myParser.getWord1(), validCommands[i]) == 0) {//if word1 = one of the valid commands
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

void exeGo(char* word2, Inventory& myInventory, Room*& currentRoom) {//executed if the command is "go"
  //cout << "Executed successfully." << endl;
  //cout << "Second Word: " << word2 << endl;
  char directionMod = word2[0];
  if (currentRoom -> hasExit(directionMod)) {//checks if word2's first character is an available exit
    currentRoom = currentRoom -> getExit(directionMod);//changes currentRoom to the new room
    cout << endl << currentRoom -> getDescription() << endl;//prints the new room's description
    cout << endl << "Exits: " << endl;//prints new exits
    if (currentRoom -> hasExit('e') == true) {
      cout << "EAST" << endl;
    }
    if(currentRoom -> hasExit('w') == true) {
	cout << "WEST" << endl;
    }
    if(currentRoom -> hasExit('n') == true) {
	cout << "NORTH" << endl;
    }
    if(currentRoom -> hasExit('s') == true) {
	cout << "SOUTH" << endl;
    }
    cout << endl;
    currentRoom -> roomInventory.printInventory();//prints the items in the new room
  }
  else {
    cout << "There is no exit in that direction." << endl;
  }
}
void exeGet(char* word2, Inventory& myInventory, Room*& currentRoom){//picks up an item if it is in the room
  if (currentRoom -> roomInventory.hasItem(word2) == true) {
    myInventory.addItem(word2);
    cout << endl << "You added " << word2 << " to your inventory." << endl;
    currentRoom -> roomInventory.removeItem(word2);
    //cout << "Item was successfully removed from the room" << endl;
  }
  else {
    cout << endl << "That item is not in this room." << endl;
  }
}
void exeDrop(char* word2, Inventory& myInventory, Room*& currentRoom){//drops an item into the current room if it is in the player's inventory
  if (myInventory.hasItem(word2) == true) {
    currentRoom -> roomInventory.addItem(word2);
    cout << endl << "You dropped " << word2 << " in " << currentRoom -> getName() << "." << endl;
    myInventory.removeItem(word2);
    //cout << "Item was successfully removed from my inventory" << endl;
  }
  else {
    cout << endl << "That item is not in your inventory." << endl;
  }
}
void exeQuit(char* word2, Inventory& myInventory, Room*& currentRoom){//quits the game and exits the program
  cout << "Goodbye." << endl;
  exit(0);
}
void exeInventory(char* word2, Inventory& myInventory, Room*& currentRoom){//prints the player's inventory by calling the Inventory class's printInventory function
  cout << "My ";
  myInventory.printInventory();
}
void exeUse(char* word2, Inventory& myInventory, Room*& currentRoom){//"uses" the specified item if the item is in the player's inventory. This command has no effect if the item doesn't correspond to the room it is being used in. Items are not removed from the player's inventory when they are used.
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Upper_Engine") == 0 && strcmp(word2, "Toolbox") == 0) {
    cout << "You used your tools to perform maintenance on the Upper Engine." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Lower_Engine") == 0 && strcmp(word2, "Toolbox") == 0) {
    cout << "You used your tools to perform maintenance on the Lower Engine." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Reactor") == 0 && strcmp(word2, "Engineering Skills") == 0) {
    cout << "You used your engineering skills to restart the reactor." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Electrical") == 0 && strcmp(word2, "Engineering Skills") == 0) {
    cout << "You used your engineering skills to recalibrate the distributors in the Electrical room." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Admin") == 0 && strcmp(word2, "ID Card") == 0) {
    cout << endl << "- MISSION LOG -" << endl;
    cout << endl << "Year 3032, SOL 3764, 15:46:08:" << endl;
    cout << endl << "Just departed from Polus after setting up a planetary base on the crust's surface. Planet shows signs of habitability, may even support alien life. Returning to Earth in approximately 2000 sols with soil and atmospheric samples." << endl;
    cout << endl << "Year 3032, SOL 3765, 02:40:13:" << endl;
    cout << endl << "Systems have been breached. The airlock seems to have malfunctioned. Suspicious, hostile alien lifeforms have entered the vessel. I suspect that they were native to Polus." << endl;
    cout << endl << "Year 3032, SOL 3765, 02:59:37:" << endl;
    cout << endl << "Sending ship into full alert. It seems that the aliens are able to rapidly alter their morphological appearance. 2 crew members have already been killed while trying to interact with the imposters, thinking them to be their own crewmates." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Communications") == 0 && strcmp(word2, "Handheld Computer") == 0) {
    cout << "You used your handheld computer to restart the wifi router." << endl;
  }
  if (myInventory.hasItem(word2) == true && strcmp(currentRoom -> getName(), "Navigation") == 0 && strcmp(word2, "Handheld Computer") == 0) {//WIN CONDITION
    cout << "You used your handheld computer to chart the course for Earth. Hopefully, you will survive the 2000-sol journey without any more imposter encounters. Good luck!" << endl << endl << "Congratulations. You finished the game." << endl;
    cout << endl << "Goodbye." << endl;
    exit(0);
  }
}

void exeHelp(char* word2, Inventory& myInventory, Room*& currentRoom){//prints a vague statement and all the valid commands
  //print out help message
  cout << endl;
  cout << "You are lost. You are alone." << endl << "Valid Commands: go, inventory, get, drop, use, description, quit, help" << endl << "Navigate the ship, fix it, and get back home." << endl;
  cout << endl;
}

void exeDescription(char* word2, Inventory& myInventory, Room*& currentRoom){//prints the current room's description and the exits, as well as the items in the room
  //print the description of the current room
  cout << currentRoom -> getDescription() << endl;
  cout << endl << "Exits: " << endl;
    if (currentRoom -> hasExit('e') == true) {
    cout << "EAST" << endl;
  }
  if(currentRoom -> hasExit('w') == true) {
    cout << "WEST" << endl;
  }
  if(currentRoom -> hasExit('n') == true) {
    cout << "NORTH" << endl;
  }
  if(currentRoom -> hasExit('s') == true) {
    cout << "SOUTH" << endl;
  }
  cout << endl;
  currentRoom -> roomInventory.printInventory();
}


void displayIntro() {//gets displayed at the beginning of the game
  cout << "You are onboard the Skeld, an intergalactic research starship. You are the sole survivor of a catastrophic encounter with hostile alien life. The aliens have savagely murdered all of your friends. Fortunately, you were able to lock the shield doors to the security room before any aliens arrived. Unfortunately, you had access to all the camera feeds during the invasion, and you saw each of your team members stalked and gruesomely mutilated by the murderous Martians. Your saving grace is that the aliens, although extremely intelligent, suffered a careless moment by the airlock, and were sucked out of the ship, along with a few of your crewmates. Now, you must fix the ship so you can return home to Earth." << endl;
  cout << endl;
}


/*
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣤⣤⣤⣤⣤⣶⣦⣤⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⢀⣴⣿⡿⠛⠉⠙⠛⠛⠛⠛⠻⢿⣿⣷⣤⡀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⣿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⠈⢻⣿⣿⡄⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⡏⠀⠀⠀⣠⣶⣾⣿⣿⣿⠿⠿⠿⢿⣿⣿⣿⣄⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠁⠀⠀⢰⣿⣿⣯⠁⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⡄⠀
⠀⠀⣀⣤⣴⣶⣶⣿⡟⠀⠀⠀⢸⣿⣿⣿⣆⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣷⠀
⠀⢰⣿⡟⠋⠉⣹⣿⡇⠀⠀⠀⠘⣿⣿⣿⣿⣷⣦⣤⣤⣤⣶⣶⣶⣶⣿⣿⣿⠀
⠀⢸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠹⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠃⠀
⠀⣸⣿⡇⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠉⠻⠿⣿⣿⣿⣿⡿⠿⠿⠛⢻⣿⡇⠀⠀
⠀⣿⣿⠁⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣧⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⣿⣿⠀⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⣿⠀⠀
⠀⢿⣿⡆⠀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⣿⡇⠀⠀
⠀⠸⣿⣧⡀⠀⣿⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿⠃⠀⠀
⠀⠀⠛⢿⣿⣿⣿⣿⣇⠀⠀⠀⠀⠀⣰⣿⣿⣷⣶⣶⣶⣶⠶⠀⢠⣿⣿⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⣽⣿⡏⠁⠀⠀⢸⣿⡇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⠀⠀⠀⠀⠀⣿⣿⡇⠀⢹⣿⡆⠀⠀⠀⣸⣿⠇⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢿⣿⣦⣄⣀⣠⣴⣿⣿⠁⠀⠈⠻⣿⣿⣿⣿⡿⠏⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠈⠛⠻⠿⠿⠿⠿⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
  
 */
