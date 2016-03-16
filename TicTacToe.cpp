#include<iostream>

using namespace std;

class TicTacToe
{
private:
	
public:
	TicTacToe();
	int** get();			//return game data
	void move(int row, int col);		//make a move
	void over();					//check to see who won
	int win();						//return int winner
	int retplay();
	int game[3][3];				//game data
	int winner;						//winner
	int play;						//player's turn
};
TicTacToe::TicTacToe()					//constructor
{
	play = 1;
	winner = 0;

	for (int i = 0; i<3; i++)
	{
		for (int j = 0; j<3; j++)
			game[i][j] = 0;				//initialise all values to zero
	}
}

int** TicTacToe::get(void)
{
	
	return (int**)game;					//copies the game data to the input array
}

void TicTacToe::move(int row, int col)
{
	static int player = 1;				//start with player 1. increment player at end of function						

	if (row>2 || row<0 || col>2 || col<0)
		throw out_of_range("Invalid input");
	//catch ()		SORT THIS OUT

	if (game[row][col] != 0)				//check if overwriting a previous move
	{
		cout << endl << "Invalid position!" << endl << "Hit enter to continue..." << endl;
		cin.get();
		cin.get();
		player--;						//still same players turn
	}
	else
		game[row][col] = player;

	player++;							//increment player
	if (player == 3) player = 1;			//if player increments to 3, loop back to player 1	

	play = player;

}

void TicTacToe::over()
{
	for (int i = 0; i<3; i++)				//loop through rows
	{
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][2] == 1)
			winner = 1;
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][2] == 2)
			winner = 2;
	}

	for (int j = 0; j<3; j++)	//loop through columns
	{
		if (game[0][j] == game[1][j] && game[j][1] == game[2][j] && game[2][j] == 1)
			winner = 1;
		if (game[0][j] == game[1][j] && game[j][1] == game[2][j] && game[2][j] == 2)
			winner = 2;
	}
	//check diagonals

	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] == 1)
		winner = 1;
	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] == 2)
		winner = 2;

	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[2][0] == 1)
		winner = 1;
	if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[2][0] == 2)
		winner = 2;

	//player 1 wins => winner=1
	//player 2 wins => winner=2
	//draw => winner=0
}

int TicTacToe::win()
{
	for (int i = 0; i<3; i++)	//checking across rows
	{
		if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][2] == 1)
			winner = 1;
		else if (game[i][0] == game[i][1] && game[i][1] == game[i][2] && game[i][2] == 2)
			winner = 2;
	}

	for (int i = 0; i<3; i++)	//checking across columns
	{
		if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[2][i] == 1)
			winner = 1;
		else if (game[0][i] == game[1][i] && game[1][i] == game[2][i] && game[2][i] == 2)
			winner = 2;
	}

	if (game[0][0] == game[1][1] && game[1][1] == game[2][2] && game[2][2] == 1)	//checking diagonals
		winner = 1;
	else if (game[0][2] == game[1][1] && game[1][1] == game[2][0] && game[2][0] == 2)
		winner = 2;

	return winner;
}

int TicTacToe::retplay()
{

	return play;
}


int main()
{
	TicTacToe board1;

	int r, c;	//row and col input from user
	int w = 0;	//winner value	
	int counter = 1;

	while (w == 0)
	{
		system("cls");
		int** values = board1.get();			//pointer to game data		//either data becomes corrupt or somehing

		cout << "     1   2   3" << endl << "   +---+---+---+" << endl;		//output board
		for (int i = 0; i<3; i++)
			cout << " " << i + 1 << " | " << values++ << " | " << values++ << " | " << values++ << " |" << endl << "   +---+---+---+" << endl;

		cout << endl << "Player " << board1.retplay() << "'s turn";
		cout << endl << "row:";
		cin >> r;
		cout << endl << "col:";
		cin >> c;

		board1.move(r - 1, c - 1);
		counter++;

		w = board1.win();

	}

	system("pause");
	return 0;
}
