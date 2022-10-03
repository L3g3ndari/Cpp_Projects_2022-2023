/*
Nathan Wu
Tic Tac Toe Game
C++ Programming
Period 5
Mr. Galbraith
Project Completed: 9/29/22
Outside Resources Utilized: TicTacToe, by Nathan Wu, from Java Programming 2021
 */

#include <iostream>
#include <cstring>
using namespace std;

//initialize all the functions
void printBoard(int array[3][3]);
void clearBoard();
bool checkWin(int player, int board[3][3]);
bool checkTie(int board[3][3]);

int main() {
  char input[3];
  int board[3][3];
  const int BLANK = 0;
  const int X_MOVE = 1;
  const int O_MOVE = 2;
  const int X_TURN = 0;
  const int O_TURN = 1;
  int turn = X_TURN;
  int XWins = 0;
  int OWins = 0;
  bool stillPlaying;
  cout << "Welcome to TicTacToe!" << endl;
  cout << "X will start." << endl;
  cout << "Please input a move using the coordinate system." << endl;

  while (true) {
    turn = X_TURN;
    for (int row = 0; row < 3; row++) {//clears the board between games
      for (int col = 0; col < 3; col++) {
	board[row][col] = BLANK;
      }
    }
  
    stillPlaying = true;
    printBoard(board);
  
    while (stillPlaying == true) {
      while (checkWin(X_MOVE, board) == false && checkWin(O_MOVE, board) == false && checkTie(board) == false) {//checking if the game should end
	//cout << "The turn is: " << turn << endl;
	cin.get(input, 3);//get input
	cin.ignore(10, '\n');//take out return
	//cout << "You inputted: " << input << endl;
	if (strlen(input) !=  2) {//checks for invalid inputs
	  cout << "Please enter a letter followed by a number." << endl;
	}
	else if (!((input[0] == 'a' || input[0] == 'b' || input[0] == 'c') &&
		   (input[1] == '1' || input[1] == '2' || input[1] == '3'))) {
	  cout << "Your input is invalid. Please try again." << endl;
	}
	else {//if the input is valid
	  int row = input[0] - 'a';//converts to coordinates of the board array
	  int column = input[1] - '1';
	  //cout << row << ", " << column << endl;
	  if (board[row][column] == BLANK) {//checks if the space is empty
	    if (turn == X_TURN) {//if it's X's turn
	      board[row][column] = X_MOVE;//make a move for X
	      turn = 1;//switch turns
	    }
	    else {//if it's O's turn
	      board[row][column] = O_MOVE;//make a move for O
	      turn = 0;//switch turns
	    }
	    cout << endl;
	    printBoard(board);
	  }
	  else {//if the space is already occupied
	    cout << "That spot is already occupied!" << endl;
	  }
	}
      }
      //a win condition has been met, or if there is a tie
      stillPlaying = false;
      printBoard(board);
      if (checkWin(X_MOVE, board) == true) {//if X is the winner, add 1 to X's score
	XWins++;
	cout << "X has won!" << endl;
      }
      else if (checkWin(O_MOVE, board) == true) {//if O is the winner, add 1 to O's score
	OWins++;
	cout << "O has won!" << endl;
      }
      else {//if it's a tie, do nothing
	cout << "It's a tie!" << endl;
      }
      cout << "X has won " << XWins << " times. O has won " << OWins << " times." << endl;
      cout << endl;
      cout << "---------------- NEW GAME ----------------" << endl;
      cout << endl;
    }
  }
}//returns to the top and starts another game

void printBoard(int array[3][3]) {//prints the board, and any moves in the board
  cout << " \t1\t2\t3" << endl;
  for (int row = 0; row < 3; row ++) {
    char rowlabels[9] = "        ";
    rowlabels[0] = ('a'+row);
    rowlabels[1] = '\t';
    int i = 0;
    //cout << rowlabels << endl;
    //cout << endl;
    for (int col = 0; col < 3; col++) {
      if (array[row][col] == 0) {//Blanks
	rowlabels[col + 2 + i] = '\t';
      }
      else if (array[row][col] == 1) {//X's
	rowlabels[col + 2 + i] = 'X';
	i++;
	rowlabels[col + 2 + i] = '\t';
      }
      else if (array[row][col] == 2) {//O's
	rowlabels[col + 2 + i] = 'O';
	i++;
	rowlabels[col + 2 + i] = '\t';
      }
    }
    cout << rowlabels << endl;
    cout << endl;
  }
}

bool checkTie(int board[3][3]) {//checks for ties by checking if all the board spaces are occupied
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (board[row][col] == 0) {//if BLANK
	   return false;
      }
    }
  }
  return true;
}

bool checkWin(int player, int board[3][3]) {//checks for wins systematically
  if(board[0][0] == player && board[0][1] == player && board[0][2] == player) {
    return true;
  }
  if(board[1][0] == player && board[1][1] == player && board[1][2] == player) {
    return true;
  }
  if(board[2][0] == player && board[2][1] == player && board[2][2] == player) {
    return true;
  }
  if(board[0][0] == player && board[1][0] == player && board[2][0] == player) {
    return true;
  }
  if(board[0][1] == player && board[1][1] == player && board[2][1] == player) {
    return true;
  }
  if(board[0][2] == player && board[1][2] == player && board[2][2] == player) {
    return true;
  }
  if(board[0][0] == player && board[1][1] == player && board[2][2] == player) {
    return true;
  }
  if(board[0][2] == player && board[1][1] == player && board[2][0] == player) {
    return true;
  }
  return false;
}
