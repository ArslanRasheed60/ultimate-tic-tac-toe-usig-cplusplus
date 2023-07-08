#pragma once
#include <iostream>
using namespace std;

class ticTacToe
{
	char arr[3][3];
	int size;
public:
	static int startup;					//from which board user want to start then no any player will choose the board

	//use for moving on one board to another board
	static int r;
	static int c;

	// counter will use while reading data from file. it will tells us which player exit the
	// game and which player has next move to continue the game
	static int counter;

	static int exit;				//exit the game any time while playing

	ticTacToe();							//default constuctor
	ticTacToe(const ticTacToe& board);					//copy constructor
	int get_size();						//size getter
	char get_arr(int a, int b);			//array element getter
	void set_arr(int a, int b, char ch);		//character setter in array
	~ticTacToe();
};