#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Game.cpp"

extern struct move;

extern int player, computer;

int score(Game currentGame)
{
	if (currentGame.hasWon() > 0)
	{
		return (currentGame.hasWon() == computer) ? 10 : -10;
	}
	else {
		return 0;
	}
}


int minMax(Game currentGame, int depth, bool isMax)
{
	if (!currentGame.areMovesLeft())
	{
		return score(currentGame);
	}

	if (isMax)
	{
		int best = -1000;

		for (int b = 0; b < 3; b++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (currentGame.isValidMove(b, i))
				{
					currentGame.makeMove(b, i, computer);

					best = std::max(best, minMax(currentGame, depth + 1, !isMax));

					currentGame.makeMove(b, i, 0);
				}
			}
		}
		return best;
	}
	else {
		int best = 1000;

		for (int b = 0; b < 3; b++)
		{
			for (int i = 0; i < 3; i++)
			{
				if (currentGame.isValidMove(b, i))
				{
					currentGame.makeMove(b, i, player);

					best = std::min(best, minMax(currentGame, depth + 1, !isMax));

					currentGame.makeMove(b, i, 0);
				}
			}
		}
		return best;
	}

}

struct move findBestMove(Game currentGame)
{
	struct move bestMove;
	int bestVal = -1000;
	for (int b = 0; b < 3; b++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (currentGame.isValidMove(b, i))
			{
				currentGame.makeMove(b, i, computer);

				int moveVal = minMax(currentGame, 0, false);

				currentGame.makeMove(b, i, 0);

				if (moveVal > bestVal)
				{
					bestMove.row = b;
					bestMove.column = i;
					bestVal = moveVal;
				}
			}
		}
	}

	return bestMove;
}


