/*

Tic Tac Toe Game

This is a two player tic tac toe game in c++.
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

//array that contains places in the board
char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

//variable declaration
int choice;
int row, column;
char turn = 'X';
bool draw = false;

//board func
void displayBoard();

//player turn func
void playerTurn();

//game outcome func
bool gameover();

//ascii func
void displayName();


//main
int main()
{
	cout << "Tic Tac Toe" << endl;

	do
	{
		displayBoard();
		playerTurn();
		gameover();
	} while (gameover());

	if (turn == 'X' && draw == false)
		cout << " Player 1 has won!" << endl;
	else if (turn == 'O' && draw == false)
		cout << " Player 2 has won!" << endl;
	else
		cout << "Draw!" << endl;

	return 0;

}

// function to show the current status of the game board
void displayBoard()
{
	cout << "Player 1 -- X  Player 2 -- O" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[1][0] << "  |  " << board[1][1] << "  |  " << board[1][2] << "  " << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[2][0] << "  |  " << board[2][1] << "  |  " << board[2][2] << "  " << endl;
	cout << "     |     |     " << endl;

}

// function to get player's moves and update the board
void playerTurn()
{
	if (turn == 'X')
		cout << "Player 1 -- X turn : " << endl;
	else if (turn == 'O')
		cout << "player 2 -- O turn : " << endl;

	//user input
	//updating board 
	cin >> choice;

	//switch to get which row/column will update
	switch (choice)
	{
	case 1: row = 0; column = 0; break;
	case 2: row = 0; column = 1; break;
	case 3: row = 0; column = 2; break;
	case 4: row = 1; column = 0; break;
	case 5: row = 1; column = 1; break;
	case 6: row = 1; column = 2; break;
	case 7: row = 2; column = 0; break;
	case 8: row = 2; column = 1; break;
	case 9: row = 2; column = 2; break;
	default:
		cout << "invalid choice" << endl;
	}

	//updates the board with 'X' if not already occupied
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'X';
		turn = 'O';
	}
	//updates the board with 'O' if not already occupied
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O')
	{
		board[row][column] = 'O';
		turn = 'X';
	}
	else
	{   //if space is already occupied 
		cout << " Square already filled. Please choose another" << endl;
		playerTurn();
	}

	//displayBoard();
}

// function that calculates the outcome of the game. Win/Draw
bool gameover()
{
	//checks win for rows and columns
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i])
			return false;
	}
	//checks win for diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][0] == board[2][2])
		return false;

	//checks if the game continues 
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (board[i][j] != 'X' && board[i][j] == 'O')
				return true;

}