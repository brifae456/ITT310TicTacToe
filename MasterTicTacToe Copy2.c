#include <stdio.h>  
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

char board[3][3];				//Game board
const char PLAYER = 'X';		//Human player will be "X" in game
const char COMPUTER = 'O';		//Computer will be "O" in game

void resetBoard();		//2-D Array Board
void printBoard();		//2-D Character Array
int checkFreeSpaces();	//Return Type Event
void playerMove();		//Invoke Player's Move
void computerMove();	//Invoke Computer Move
char checkWinner();		//Winner Conditions
void printWinner(char);

int main()
{
	char winner = ' ';			//Set an empty space if there is currently no winner
	char response;

	do
	{
		winner = ' ';
		response = ' ';				//Setting up after game is over if player wants to play again
		resetBoard();				//Will reset the 2-D Board

		while (winner == ' ' && checkFreeSpace() != 0)			//if winner = empty space, then no winner
		{
			printBoard();

			playerMove();			//Invoke playerMove Function
			winner = checkWinner();
			if (winner != ' ' || checkFreeSpaces() == 0)		//Check for winner if there is no empty space or invoke checkFreeSpace
			{
				break;				//break out of loop
			}

			computerMove();			//Invoke playerMove Function
			winner = checkWinner();
			if (winner != ' ' || checkFreeSpaces() == 0)		//Check for winner if there is no empty space or invoke checkFreeSpace
			{
				break;				//break out of loop
			}
		}

		printBoard();
		printWinner(winner);

		printf("\nWould you like to play again? (Y/N): ");		//Print If player responded no to playing another game
		scanf_s("%c");
		scanf_s("%c", &response);
		response = toupper(response);
	} while (response == 'Y');		//reset for new game

	printf("Thanks for playing!");

	return 0;
}
void resetBoard()				//// 2-D Character Array, will set up the rows and columns
{
	for (int i = 0; i < 3; i++)		//initiate nested loop rows
	{
		for (int j = 0; j < 3; j++)		//initiate nested loop 3 times, set up columns
		{
			board[i][j] = ' ';			//Telling the squares will have nothing in them at the beginning of game
		}
	}
}
void printBoard()			//Print the character array
{
	printf(" %c |  %c  |  %c ", board[0][0], board[0][1], board[0][2]);		//signifies the three place holders, 1st row of empty spaces
	printf("\n---|---|---\n");												//signifies the 1st row of horizontal lines
	printf(" %c  |  %c | %c ", board[1][0], board[1][1], board[1][2]);		//2nd row of empty spaces
	printf("\n---|---|---\n");												//signifies 2nd horizontal line
	printf(" %c  |  %c |  %c ", board[2][0], board[2][1], board[2][2]);		//signifies 3rd row of empty spaces
	printf("\n");
}
int  checkFreeSpaces()			//return type event, will check for free spaces if at 0 game will be over.
{
	int freeSpaces = 9;		//local variable 9

	for (int i = 0; i < 3; i++)		//nested 4 loop
	{
		for (int j = 0; j < 3; j++)
		{
			if (board[i][j] != ' ')		//check if 2-d array of characters does not equal to empty space
			{
				freeSpaces--;			//Take freeSpaces local variable decrimate by 1
			}
		}
	}
	return freeSpaces;			//If empty spaces is 0 then game is over
}
void playerMove()				//when it is player move
{
	int x;					//Make two local variables of x and y Help to invoke row and column of where to move
	int y;

	do
	{
		printf("Enter row #(1-3): ");		//indicate to player to enter row # 
		scanf_s("%d", &x);					//to accept user input
		x--;								//Take away number since starts with 0
		printf("Enter column #(1-3): ");	//indicate to player to enter column #
		scanf_s("%d", &y);
		y--;

		if (board[x][y] != ' ')				//check if user inputs are to open spaces
		{
			printf("Invalid move!");		//If check is an occupied space, indicates error message
		}
		else
		{
			board[x] [y] = PLAYER;
			break;
		}
	}while (board[x][y] != ' ');			//if player  tries to input into occupied square, will allow them to enter another option
}
void computerMove()			//Invokes the computers turn
{
	//Creates a seed based on current time
	srand(time(0));			//
	int x;
	int y;

	if (checkFreeSpaces() > 0)		//Checking for free spaces
	{
		do
		{
			x = rand() % 3;			//generate 2 random numbers 0-2
			y = rand() % 3;			//generate 2 random numbers 0-2
		} while (board[x][y] != ' ');		//check to see if a spot is even open on board

		board[x][y] = COMPUTER;		//
	}
	else
	{
		printWinner(' ');			//if no spaces no winner
	}
}
char checkWinner()
{
	//check the rows
	for (int i = 0; i < 3; i++)
	{
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
		{
			return board[i][0];

		}
	}
	//check columns
	for (int i = 0; i < 3; i++)
	{
		if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
		{
			return board[0][1];
		}
	}
	//check diagonals
	if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
		{
			return board[0][0];
		}
	if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
		{
		return board[0][2];
		}

	return ' ';			//if there is no winner
}
void printWinner(char winner)
{
	if (winner == PLAYER)
	{
		printf("YOU WIN!");
	}
	else if (winner == COMPUTER)
	{
		printf("YOU LOSE!");
	}
	else {
		printf("IT'S A TIE!");
	}
}