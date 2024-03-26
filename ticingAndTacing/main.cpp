#include <iostream>
#include <string>
using namespace std;

// define board 
int board[3][3] = {
	{0, 0, 0},
	{0, 0, 0},
	{0, 0, 0}
};

bool isGameOver = false;
int player, computer;

// <array> - a pointer to an array with 3 columns
// <rows> - the # of rows in the array
// <return> - a string containing the 3x3 array values separated by whitespace
string stringifyBoard(int (*array)[3], size_t rows)
{
	// Creates a temporary variable to store the stringified board
	string tBoard = "";

	for (int b = 0; b < rows; b++)
	{
		for (int i = 0; i < 3; i++)
		{
			string temp = "null";
			switch (array[b][i])
			{
				case 0:
					temp = "-";
					break;
				case 1:
					temp = "X";
					break;
				case 2:
					temp = "O";
					break;
			}
			tBoard += temp + " ";
		}
		tBoard += "\n";
	}
	return tBoard;
}

void checkPlayer()
{
	string t = "";
	cout << "Would you like to play X or O? ";
	cin >> t;
	if (!(t.compare("X") == 0 || t.compare("O") == 0))
	{
		cout << "Invalid input, try again!" << endl;
		checkPlayer();
	} else if (t.compare("X") == 0) {
		player = 1;
		computer = 2;
	} else {
		player = 2;
		computer = 1;
	}
}

int main()
{

}