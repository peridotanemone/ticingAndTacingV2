#include <iostream>
#include <string>
#include <map>

#include "Game.cpp"
#include "MinMax.cpp"

using namespace std;

extern int player, computer;
extern struct move;

const map<string, int> grid{ {"A",0},{"B",1},{"C",2} };

int winningPlayer = 0;
bool isFirstTime = true;

void checkPlayer()
{
	string t = "";
	cout << "Would you like to play X or O? ";
	cin >> t;
	if (!(t.compare("X") == 0 || t.compare("O") == 0))
	{
		cout << "Invalid input, try again!" << endl;
		checkPlayer();
		return;
	} else if (t.compare("X") == 0) {
		player = 1;
		computer = 2;
	} else {
		player = 2;
		computer = 1;
	}
}

struct move takePlayerInput(Game currentGame)
{
	struct move tMove;

	string column = "";
	string row = "";
	cout << "Your turn! Input your choice using two letters to represent the row and column" << endl << "EXAMPLE: C A" << endl;
	cin >> row >> column;
	if (!((grid.count(column) == 1) && (grid.count(row) == 1))) {
		cout << "Invalid input, try again!" << endl;
		takePlayerInput(currentGame); 
	}
	else {
		tMove.column = grid.at(column);
		tMove.row = grid.at(row);
	}
	if (currentGame.isValidMove(tMove))
	{
		return tMove;
	}
	else {
		cout << "Invalid input, try again!" << endl;
		takePlayerInput(currentGame);
	}

}

void playGame(Game currentGame, bool isPlayer)
{
	if (isPlayer)
	{
		currentGame.makeMove(takePlayerInput(currentGame), player);
	}
	else {
		if (isFirstTime && currentGame.isValidMove(1, 1)) {
			currentGame.makeMove(1, 1, computer);
			isFirstTime = false;
		}
		else {
			currentGame.makeMove(findBestMove(currentGame), computer);
		}
	}
	cout << currentGame.stringifyBoard() << endl;
	
	if (currentGame.areMovesLeft()&&(currentGame.hasWon() == 0))
	{
		playGame(currentGame, !isPlayer);
	}
	else {
		winningPlayer = currentGame.hasWon();
	}
}

int main()
{
	checkPlayer();
	Game cGame(player, computer);
	cout << cGame.stringifyBoard() << endl;
	playGame(cGame, (player == 1) ? true : false);
	cout << "Game over!" << endl;
	if (winningPlayer == player)
	{
		cout << "You win!";
	}
	else if (winningPlayer == computer) {
		cout << "Computer wins!";
	}
	else {
		cout << "Tie!";
	}

} 