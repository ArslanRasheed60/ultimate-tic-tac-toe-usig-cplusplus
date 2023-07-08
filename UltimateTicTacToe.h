#pragma once
#include <iostream>
#include "tictactoe.h";
#include <fstream>
using namespace std;

class ultimate_ticTacToe
{
	ticTacToe bigboard[9];
	char bigarr[3][3];
public:

	ultimate_ticTacToe(); 					//default constructor
	ultimate_ticTacToe(const ultimate_ticTacToe& board); //copy constructor
	~ultimate_ticTacToe();				//destructor
	void check_board(int& check);		//check board number is valid or not
	void getting_move(char ch);			//getting rows and columns from user
	void check_move(int& check);		//check user move is valid or not
	bool win_check_bigboard();
	bool win_check_smallboard(ticTacToe& board);
	bool draw_check_smallboard(ticTacToe& board);
	bool draw_check_bigboard();
	friend ostream& operator<<(ostream& out, ultimate_ticTacToe& board);				//board output
	friend ofstream& operator<<(ofstream& out, ultimate_ticTacToe& board);  // write in file
	friend ifstream& operator>>(ifstream& fin, ultimate_ticTacToe& board);	// read from file
};