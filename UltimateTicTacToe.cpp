#include <iostream>
#include "tictactoe.h";
#include "UltimateTicTacToe.h";
#include <fstream>
using namespace std;

ultimate_ticTacToe::ultimate_ticTacToe() :bigboard()					//default constructor
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bigarr[i][j] = '-';
		}
	}
}

ultimate_ticTacToe::ultimate_ticTacToe(const ultimate_ticTacToe& board) //copy constructor
{
	for (int i = 0; i < 9; i++)
	{
		this->bigboard[i] = board.bigboard[i];
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			bigarr[i][j] = '-';
		}
	}
}

void ultimate_ticTacToe::check_board(int& check)		//board number validation check
{
	while (check <= 0 || check > 9)
	{
		cout << "\n............Invalid input...........Enter board again:  ";
		cin >> check;
	}
}

void ultimate_ticTacToe::check_move(int& check)			//user move validation check
{
	while (check <= 0 || check > bigboard->get_size())
	{
		cout << "\n............Invalid input...........Enter again:  ";
		cin >> check;
	}
}

void ultimate_ticTacToe::getting_move(char ch)			//getting row and column from user
{
	int row = 0, col = 0;
	bool flag = false;
	int temp_r = ticTacToe::r, temp_c = ticTacToe::c;
	int move_to_board = (3 * ticTacToe::r) + ticTacToe::c;

	//user can choose its turn in any board if his/her move is in already occupied board
	if (bigarr[temp_r][temp_c] == 'X' || bigarr[temp_r][temp_c] == 'O')
	{
		bool flag2 = false;
		int num = 0;
		while (!flag2)
		{
			if (num == 0)
			{
				cout << "\n\nCurrent Board #  " << move_to_board + 1 << endl;

				if (bigarr[temp_r][temp_c] == 'X')
					cout << "\n********* This board is already won by player # 1. ********\n";
				else if (bigarr[temp_r][temp_c] == 'O')
					cout << "\n********* This board is already won by player # 2. ********\n";
				else
					cout << "\n********* This board is already Drawn. ********\n";
			}
			cout << "\n\nNow Choose any Board: (Board number (1 to 9) and move left to right):   ";
			cin >> move_to_board;
			check_board(move_to_board);
			move_to_board--;
			for (int i = 0; i < 3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					int temp = (3 * i) + j;
					if (temp == move_to_board)
					{
						if (bigarr[i][j] == '-')
						{
							flag2 = true;
						}
						else
						{
							if (bigarr[i][j] == 'X')
								cout << "\n********* This board is already won by player # 1. ********\n";
							else if (bigarr[i][j] == 'O')
								cout << "\n********* This board is already won by player # 2. ********\n";
							else
								cout << "\n********* This board is already Drawn. ********\n";
						}
					}
				}
			}
			num++;
		}
		flag2 = false;
		while (!flag2)
		{
			cout << "\n\nCurrent Board is #  " << move_to_board + 1 << endl;
			cout << "\nEnter row # 1,2,3:  ";
			cin >> row;
			check_move(row);									//move validation check
			row--;
			cout << "\nEnter column # 1,2,3 :  ";
			cin >> col;
			check_move(col);
			col--;
			if (bigboard[move_to_board].get_arr(row, col) == '-')
			{
				flag2 = true;
			}
			else
			{
				cout << "\n************  Player already use this area ************* Enter again\n";
			}
		}
		ticTacToe::r = row;
		ticTacToe::c = col;
		bigboard[move_to_board].set_arr(row, col, ch);
		if (this->win_check_smallboard(bigboard[move_to_board]) == true)		//small board win check
		{
			if (ch == 'X')
				cout << "\n\n  -[ Player 1 Win board # " << move_to_board << " ]-  \n";
			else
				cout << "\n\n  -[ Player 2 Win board # " << move_to_board << " ]-  \n";
			bigarr[temp_r][temp_c] = ch;
		}
		else if (draw_check_smallboard(bigboard[move_to_board]) == true)
		{
			cout << "\n\n *** -[ >>Board # " << move_to_board + 1 << " has Drawn << ]- ***\n";
			bigarr[temp_r][temp_c] = 'D';
		}
	}
	else
	{
		while (!flag)
		{
			if (ticTacToe::startup != 1)
			{		//when game start any player will choose one board then game continues on its own
				cout << "\nEnter First Board: (Board number (1 to 9) and move left to right):   ";
				cin >> move_to_board;
				check_board(move_to_board);
				move_to_board--;
				ticTacToe::startup = 1;
			}
			cout << "\n\nCurrent Board is #  " << move_to_board + 1 << endl;
			cout << "\nEnter row # 1,2,3  |:| or -1 to exit ";
			cin >> row;
			if (row == -1)
			{
				ticTacToe::exit = -1;
				break;
			}
			check_move(row);									//move validation check
			row--;
			cout << "\nEnter column # 1,2,3 :  ";
			cin >> col;
			check_move(col);
			col--;
			if (bigboard[move_to_board].get_arr(row, col) == '-')
			{
				flag = true;
			}
			else
			{
				cout << "\n************  Player already use this area ************* Enter again\n";
			}
		}
		if (ticTacToe::exit != -1)
		{
			ticTacToe::r = row;
			ticTacToe::c = col;
			bigboard[move_to_board].set_arr(row, col, ch);
			if (this->win_check_smallboard(bigboard[move_to_board]) == true)
			{
				if (ch == 'X')
					cout << "\n\n  -[ Player 1 Win board # " << move_to_board << " ]-  \n";
				else
					cout << "\n\n  -[ Player 2 Win board # " << move_to_board << " ]-  \n";
				bigarr[temp_r][temp_c] = ch;
			}
			else if (draw_check_smallboard(bigboard[move_to_board]) == true)
			{
				cout << "\n\n *** -[ >>Board # " << move_to_board + 1 << " has Drawn << ]- ***\n";
				bigarr[temp_r][temp_c] = 'D';
			}
		}
	}
}

bool ultimate_ticTacToe::win_check_smallboard(ticTacToe& board)
{
	int count = 1;
	int size = 3;
	for (int i = 0; i < size - 1; i++)					//forward diagonal check
	{
		if (board.get_arr(i, i) == board.get_arr(i + 1, i + 1) && board.get_arr(i, i) != '-')
			count++;
	}
	if (count == size)
		return true;

	count = 1;
	for (int i = 0; i < size - 1; i++)					//backward diagonal check
	{
		if (board.get_arr(i, size - 1 - i) == board.get_arr(i + 1, size - 2 - i) && board.get_arr(i, size - 1 - i) != '-')
			count++;
	}
	if (count == size)
		return true;

	for (int i = 0; i < size; i++)						//rows check
	{
		count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (board.get_arr(i, j) == board.get_arr(i, j + 1) && board.get_arr(i, j) != '-')
				count++;
		}
		if (count == size)
			return true;
	}

	for (int i = 0; i < size; i++)						//columns check
	{
		int count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (board.get_arr(j, i) == board.get_arr(j + 1, i) && board.get_arr(j, i) != '-')
				count++;
		}
		if (count == size)
			return true;
	}
	return false;
}

bool ultimate_ticTacToe::win_check_bigboard()
{
	int count = 1;
	int size = 3;
	for (int i = 0; i < size - 1; i++)					//forward diagonal check
	{
		if (bigarr[i][i] == bigarr[i + 1][i + 1] && bigarr[i][i] != '-' && bigarr[i][i] != 'D')
			count++;
	}
	if (count == size)
		return true;

	count = 1;
	for (int i = 0; i < size - 1; i++)					//backward diagonal check
	{
		if (bigarr[i][size - 1 - i] == bigarr[i + 1][size - 2 - i] && bigarr[i][size - 1 - i] != '-' && bigarr[i][size - 1 - i] != 'D')
			count++;
	}
	if (count == size)
		return true;

	for (int i = 0; i < size; i++)						//rows check
	{
		count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (bigarr[i][j] == bigarr[i][j + 1] && bigarr[i][j] != '-' && bigarr[i][j] != 'D')
				count++;
		}
		if (count == size)
			return true;
	}

	for (int i = 0; i < size; i++)						//columns check
	{
		int count = 1;
		for (int j = 0; j < size - 1; j++)
		{
			if (bigarr[j][i] == bigarr[j + 1][i] && bigarr[j][i] != '-' && bigarr[j][i] != 'D')
				count++;
		}
		if (count == size)
			return true;
	}
	return false;
}

bool ultimate_ticTacToe::draw_check_smallboard(ticTacToe& board)
{
	int draw_count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (board.get_arr(i, j) != '-')
				draw_count++;
		}
	}
	if (draw_count == 9)
		return true;
	else
		return false;
}
bool ultimate_ticTacToe::draw_check_bigboard()
{
	int draw_count = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (bigarr[i][j] != '-')
				draw_count++;
		}
	}
	if (draw_count == 9)
		return true;
	else
		return false;
}

ostream& operator<<(ostream& out, ultimate_ticTacToe& board)			//output of board
{
	out << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int m = (i * 3); m < 3 * (i + 1); m++)
			{
				for (int k = 0; k < 3; k++)
				{
					out << " " << board.bigboard[m].get_arr(j, k);
					if (k < 2)
						out << " |";
				}
				out << "  |  ";
			}
			out << endl;
			for (int n = 0; n < 3; n++)
			{
				for (int p = 0; p < 10; p++)
				{
					if (j < 2)
						out << '~';
					else
						out << " ";
				}
				out << "  |  ";
			}
			out << endl;
		}
		out << endl;
		if (i < 2)
		{
			for (int r = 0; r < 43; r++)
			{
				out << '~';
			}
		}
		out << endl;
		if (i < 2)
		{
			for (int n = 0; n < 3; n++)
			{
				for (int p = 0; p < 10; p++)
				{
					out << " ";
				}
				out << "  |  ";
			}
		}
		out << endl;
	}
	return out;
}

ofstream& operator<<(ofstream& out, ultimate_ticTacToe& board)		//write in file
{
	/*number system is used to write data in file*/
	out << ticTacToe::startup;
	out << endl;
	out << ticTacToe::r;
	out << endl;
	out << ticTacToe::c;
	out << endl;
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			int temp = board.bigarr[j][k];
			out << temp;
		}
	}
	out << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				int temp = board.bigboard[i].get_arr(j, k);
				out << temp;
			}
		}
	}

	return out;
}

ifstream& operator>>(ifstream& fin, ultimate_ticTacToe& board)			//read from file
{
	char ch;
	fin >> ch;
	ticTacToe::startup = (int)ch - 48;
	fin >> ticTacToe::r;
	fin >> ticTacToe::c;
	for (int j = 0; j < 3; j++)
	{
		for (int k = 0; k < 3; k++)
		{
			char ch1, ch2;
			fin >> ch1 >> ch2;
			int temp = ((int)ch1 - 48) * 10 + ((int)ch2 - 48);
			board.bigarr[j][k] = temp;
		}
	}
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				char ch1, ch2;
				fin >> ch1 >> ch2;
				int temp = ((int)ch1 - 48) * 10 + ((int)ch2 - 48);
				board.bigboard[i].set_arr(j, k, temp);
				if (board.bigboard[i].get_arr(j, k) != '-')
				{
					ticTacToe::counter++;
				}
			}
		}
	}
	return fin;
}

ultimate_ticTacToe::~ultimate_ticTacToe()				//destructor
{		//no any pointer so there is no need of destructor
	cout << "\nUltimate TicTacToe Destructor Called: ";
};
