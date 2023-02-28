/*
Nathan Wu
Heap
C++ Programming
Mr. Galbraith
Project Completed: 
Outside Sources Used: 

Description:
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include <cmath>

using namespace std;

void printFunction(int heap[101]);
int addFunction(int heap[101], int &heapSize);
void addByFile(int heap[101], char fileInputName[20], int &heapSize);
void deleteFunction(int heap[101], int &heapSize);
void sortHeap(int heap[101]);

int main() {
  cout << "Welcome to the Heap." << endl;
  cout << "Available Commands: \"PRINT (DISPLAY),\" \"ADD,\" \"DELETE,\" or \"QUIT\"" << endl;

  int heap[101];
  int heapSize = 0;
  for (int i = 0; i < 101; i++) {
    heap[i] = 0;
  }
  
  while(true) {//will continually ask for new command inputs
    char input[10];
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');

    if (strcmp(input, "PRINT") == 0 || strcmp(input, "DISPLAY") == 0) {//if the user types in "PRINT" or "DISPLAY the printFunction method will be run
      printFunction(heap);
    }
    /*
    if (input > 0 && input <= 1000 && heapSize < 100) {//check if the input is valid and if there is heap room
      for (int i = 1; i < 101; i++) {//add to the array in the first available slot
        if (heap[i] == 0) {
          heap[i] = input;
	}
      }
    }
    */
    if (strcmp(input, "ADD") == 0) {//if the user types in "ADD," the addFunction method will be run
      if (addFunction(heap, heapSize) == 1) {//successfully added one element
	//heapSize++;
	cout << "Heap Size: " << heapSize << endl;
	sortHeap(heap);
      }
    }

    if (strcmp(input, "DELETE") == 0) {//if the user types in "DELETE," the deleteFunction method will be run
      deleteFunction(heap, heapSize);//what is the output?
    }

    if (strcmp(input, "QUIT") == 0) {//if the user types in "QUIT," the program will stop running
      exit(0);
    }
    cout << endl;
    cout << "Expecting new command." << endl;
  }
}

void printFunction(int heap[101]) {
  for (int i = 0; i < 101; i++) {
    cout << heap[i] << " ";
  }
  //start at slot index 1 and find its children, then move to number 2 and find its children, etc.
}

int addFunction(int heap[101], int &heapSize) {
  int inputType = 0;
  int input;
  cout << "What is the type of input? Type \"1\" for console input or \"2\" for file input." << endl;
  cin >> inputType;
  cin.clear();
  cin.ignore(10, '\n');
  if (inputType == 1) {//add as console input
    cout << "What number would you like to add?" << endl;
    cin >> input;
    cin.clear();
    cin.ignore(10, '\n');
    if (input > 0 && input <= 1000 && heapSize < 100) {//check if the input is valid and if there is heap room
      for (int i = 1; i < 101; i++) {//add to the array in the first available slot
	if (heap[i] == 0) {
	  heap[i] = input;
	  //cout << "Input has been added." << endl;
	  //cout << "Slot added to: " << i << endl;
	  //cout << "heap[i] = " << heap[i] << endl;
	  heapSize++;
	  return 1;
	}
      }
      //The children of slot x are 2x and 2x+1
      //The parent of x is x/2
      //Check the slot's parent and check if it is larger or smaller, adjust by swapping if smaller
    }
    else if (heapSize > 100) {
      cout << "You have filled the heap and cannot add any more elements." << endl;
    }
    else cout << "You cannot add that element. Each element must be a number between 1 and 1000." << endl;
  }
  else if (inputType == 2) {//add from file
    char fileNameInput[20];
    cout << "What file do you want to access?" << endl;
    cin.getline(fileNameInput, 20);
    //cout << fileNameInput << endl;
    cin.clear();
    //cin.ignore(20, '\n');
    cout << fileNameInput << endl;
    if (strcmp(fileNameInput, "numFile1.txt") == 0 ||
	strcmp(fileNameInput, "numFile2.txt") == 0 ||
	strcmp(fileNameInput, "numFile3.txt") == 0 ||
	strcmp(fileNameInput, "numFile4.txt") == 0) {
      //cout << "Hellooo" << endl;
      addByFile(heap, fileNameInput, heapSize);
    }
    else {
      cout << "That file does not exist." << endl;
      return 102;
    }
  }
  else {//not one of the options
    cout << "That is not a valid input option. Please type either 1 or 2." << endl;
    return 100;
  }
  return 101;
}

void addByFile(int heap[101], char fileNameInput[20], int &heapSize) {
  cout << "Reading from \"" << fileNameInput << "\"" << endl;
  int temp[100];
  for (int i = 0; i < 100; i++) {
    temp[i] = 0;
  }
  int num;
  //int count = 0;
  //int input;
  ifstream File (fileNameInput);
  if (File.is_open()) {
    while (File >> num) {
      //cout << num << " ";
      //cout << "Heap Size: " << heapSize << endl;
      if (num > 0 && num <= 1000 && heapSize+1 < 101 && heap[heapSize+1] == 0) {
	//cout << num << " ";
	heap[heapSize+1] = num;
	heapSize++;
      }
    }
    cout << endl;
    /*
    for (int i = 0; i < 100; i++) {//ensures that the file translated to the temporary array correctly
      cout << temp[i] << endl;
      input = temp[i];
      cout << input << endl;
      if (input > 0 && input <= 1000 && heapSize < 100 && heap[i] == 0) {
	heap[i] = input;
      }
    }
  }
  else {
    cout << "Unable to open first name file" << endl;
  }

  for (int i = 1; i < 101; i++) {//add to the array in the first available slot
    if (heap[i] == 0) {
      //heap[i] = input;
      //cout << "Input has been added." << endl;
      //cout << "Slot added to: " << i << endl;
      //cout << "heap[i] = " << heap[i] << endl;
      //return 1;
      }*/
  }
  cout << "Adding from file is complete." << endl;
  sortHeap(heap);
  cout << "Sorting complete." << endl;
}

void deleteFunction(int heap[101], int &heapSize) {
  cout << "Would you like to delete the root (\"r\"), or all of the heap (\"a\")?" << endl;
  char ans[2];
  cin >> ans;
  int switchTargetIndex;
  if (strcmp(ans, "r") == 0) {//delete root
    int temp = heap[heapSize];
    heap[heapSize] = heap[1];//switch the root with the last slot
    heap[1] = temp;//switch complete
    cout << "Out: " << heap[heapSize] << endl;
    heap[heapSize] = 0;//erase the original root
    heapSize--;
    sortHeap(heap);
  }
  else if (strcmp(ans, "a") == 0) {//delete whole heap
    cout << "Out: ";
    while (heapSize != 0) {
      int temp = heap[heapSize];
      heap[heapSize] = heap[1];//switch the root with the last slot
      heap[1] = temp;//switch complete
      cout << heap[heapSize] << ", ";
      heap[heapSize] = 0;//erase the original root
      heapSize--;
      sortHeap(heap);
    }
    //look at root
    //stuff
    cout << endl << "Deleted whole heap." << endl;
  }
  else {
    cout << "That was not a valid input." << endl;
  }
}

void sortHeap(int heap[101]) {
  //The children of slot x are 2x and 2x+1
  //The parent of x is x/2
  //Check the slot's parent and check if it is larger or smaller, adjust by swapping if smaller
  for (int i = 1; i < 50; i++) {
    if (heap[i] != 0) {
      while (heap[i] < heap[i*2] && heap[i*2] != 0) {//check if parent is less than left child
	int temp = heap[i];
	heap[i] = heap[i*2];
	heap[i*2] = temp;
	//cout << "Performed swap with left child!" << endl;
	sortHeap(heap);//call itself to loop it until completely sorted
      }
      while (heap[i] < heap[i*2+1] && heap[i*2+1] != 0) {//check if parent is less than right child
	int temp = heap[i];
	heap[i] = heap[i*2+1];
	heap[i*2+1] = temp;
	//cout << "Performed swap with right child!" << endl;
	sortHeap(heap);//call itself to loop it until completely sorted
      }
    }
  }
}

//STILL NEED TO FIX

//Deleting from wrong spot, leaving a weird 0
//Adding from file still doesn't work, won't grab individual numbers
//Print as a tree
