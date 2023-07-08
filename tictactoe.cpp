#include <iostream>
#include "tictactoe.h";
using namespace std;


int ticTacToe::startup = 0;
int ticTacToe::r = 0;
int ticTacToe::c = 0;
int ticTacToe::counter = 0;
int ticTacToe::exit = 0;

ticTacToe::ticTacToe()							//default constuctor
{
	size = 3;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = '-';					//default storage of character  " - "
		}
	}
}
ticTacToe::ticTacToe(const ticTacToe& board)					//copy constructor
{
	size = board.size;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			arr[i][j] = board.arr[i][j];
		}
	}
}
int ticTacToe::get_size()						//size getter
{
	return size;
}
char ticTacToe::get_arr(int a, int b)			//array element getter
{
	return arr[a][b];
}
void ticTacToe::set_arr(int a, int b, char ch)		//character setter in array
{
	arr[a][b] = ch;
}
ticTacToe::~ticTacToe()					//destructor called
{
	cout << "\nTicTacToe Destructor Called: ";
}