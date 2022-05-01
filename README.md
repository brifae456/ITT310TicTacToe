# ITT310TicTacToe Brian Gurule

#include <stdio.h>  //
#include <ctype.h>
#include <time.h>
#include <stdlib.h>

char board[3][3],				//Game baord
const char PLAYER = 'X';		//Human player will be "X" in game
const char COMPUTER = 'O';		//Computer will be "O" in game

int main()
{
	char winner = ' ';			//Set an empty space if there is currently no winner

	resetBoard();				//Will reset the 2-D Board
	printBoard();
}

void resetBoard();				// 2-D Character Array, will set up the rows and columns
{
	for (int i = 0; i < 3; i++)		//initiate nested loop 3 times, set up rows 
	{
		for (int j = 0; j < 3; j++)		//initiate nested loop 3 times, set up columns
			board[i][j] = ' ';			//Telling the squares will have nothing in them at the beginning of game
	}
}
void printBoard();				//Print the character array
{
	printf(" %c |  %c  |  %c ", board[0][0], board[0][1], board[0][2]);		//signifies the three place holders, 1st row of empty spaces
	printf("\n---|---|---\n");												//signifies the 1st row of horizontal lines
	printf(" %c  |  %c | %c ", board[1][0], board[1][1], board[1][2]);		//2nd row of empty spaces
	printf("\n---|---|---\n");												//signifies 2nd horizontal line
	printf(" %c  |  %c |  %c ", board[2][0], board[2][1], board[2][2]);		//signifies 3rd row of empty spaces
	printf("\n");
}
int  checkFreeSpaces();			//return type event, will check for free spaces if at 0 game will be over.
{

}
void playerMove();				//when it is player move
{

}
void computerMove();			//Invokes the computers turn
{

}
char checkWinner();		
{

}
void printWinner(char winner);	//one parameter
{

}
