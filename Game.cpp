#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "Globals.h"

extern struct move;

class Game
{
private:

	const char letters[3] = {
		'_', 'X', 'O'
	};

	int player, computer;

public:

	int board[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	// Constructor
	// <p> - int; represents player's choice (X = 1, O = 2)
	// <c> - int; represents computer's choice (X = 1, O = 2)
	Game(int p, int c) {
		player = p;
		computer = c;
	}

	// Converts numerical board values into X's and O's
	// <return> - string; returns string containing board values represented by X and O
	std::string stringifyBoard()
	{
		// Creates a temporary variable to store the stringified board
		std::string tBoard = "";

		for (int b = 0; b < 3; b++)
		{
			for (int i = 0; i < 3; i++)
			{
				std::string s = { letters[board[b][i]] };
				tBoard += s + " ";
			}
			tBoard += "\n";
		}
		return tBoard;
	}

	// Checks for a win
	// <return> - int; 0 if no one has won, 1 if X has won, and 2 if O has won
	int hasWon()
	{
		int winCondition = 0;

		bool lDiagonal = ((board[0][0] == board[1][1])&&(board[1][1] == board[2][2]));
		bool rDiagonal = ((board[0][2] == board[1][1])&&(board[1][1] == board[2][0]));
		if (((lDiagonal)||(rDiagonal))&&(board[1][1]!=0))
		{
			winCondition = board[1][1];
		}
		
		for (int i = 0; i < 3; i++)
		{
			bool column = ((board[0][i] == board[1][i])&&(board[1][i] == board[2][i]));
			bool row = ((board[i][0] == board[i][1])&&(board[i][1] == board[i][2]));

			if ((column)&&(board[0][i]!=0))
			{
				winCondition = board[0][i];
			}
			if (row && (board[i][0] != 0))
			{
				winCondition = board[i][0];
			}
		}

		return winCondition;
	}
	
	// Checks if the selected move is valid
	// <row> - int; the row of the intended move
	// <column> - int; the column of the intended move
	// <return> - bool; whether the square is empty or not
	bool isValidMove(int row, int column)
	{
		if (board[row][column] == 0)
		{
			return true;
		}
		return false;
	}

	bool isValidMove(struct move m)
	{
		if (board[m.row][m.column] == 0)
		{
			return true;
		}
		return false;
	}

	void makeMove(int row, int column, int choice)
	{
		board[row][column] = choice;
	}

	void makeMove(struct move m, int choice)
	{
		board[m.row][m.column] = choice;
	}
	bool areMovesLeft()
	{
		for (int b = 0; b < 3; b++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (board[b][i] == 0)
				{
					return true;
				}
			}
		}
		return false;
	}

	std::vector< struct move > getAllPossibleMoves()
	{
		std::vector< struct move > temp = {};
		struct move tMove;
		for (int b = 0; b < 3; b++)
		{
			tMove.row = b;
			for (int i = 0; i < 3; i++)
			{
				tMove.column = i;
				if (isValidMove(b, i))
				{
					temp.push_back(tMove);
				}
			}
		}
		return temp;
	}

};