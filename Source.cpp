#include <iostream>
#include "tictactoe.h";
#include "UltimateTicTacToe.h";
#include <fstream>
using namespace std;

void menu()
{
	int initial_choice = 0;
	cout << "\n***************************************************************************";
	cout << "\n**                                                                       **";
	cout << "\n**                         Ultimate TicTacToe                            **";
	cout << "\n**                                                                       **";
	cout << "\n***************************************************************************";
	cout << "\n\n******  1:  Load previous Game:  ******";
	cout << "\n\n****** 2: New game:  *******";
	cout << "\n\n****** -1: To exit: ******";
	cout << "\n\nEnter choice       ";
	cin >> initial_choice;
	//if input is invalid then enter again.
	while (initial_choice != -1 && initial_choice != 1 && initial_choice != 2)
	{
		cout << "\n\n.........Invalid choice........Enter again:   ";
		cin >> initial_choice;
	}
	if (initial_choice == 1)
	{
		int win = 0;
		int choice = 1;
		int tempo = 0;
		ultimate_ticTacToe big_board_2;
		ifstream fin;
		fin.open("UltimateGame.txt");
		if (!fin)
		{
			cout << "\n********   File Not Found   *********\n\n";
			tempo = 1;
		}
		else
		{
			fin >> big_board_2;
		}
		fin.close();
		if (tempo == 1)
		{
			cout << "\n^^^^^^^^^^^^ New Game Started  ^^^^^^^^^^^^^^\n";
			cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
			cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^\n";
			cout << big_board_2;
		}
		else
		{
			cout << "\n^^^^^^^^^^^^ GAME LOADED SUCCESSFULLY ^^^^^^^^^^^^^^\n";
			cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
			cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^\n";
			cout << big_board_2;
		}
		if (ticTacToe::counter % 2 == 0)
		{
			while (choice != -1)
			{
				cout << "\nPLAYER 1 turn: ";
				big_board_2.getting_move('X');						//getting move for first player.
				if (ticTacToe::exit == -1)					//game exit check
				{
					break;
				}
				cout << big_board_2;
				if (big_board_2.win_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[ Player 1 Wins the game ]---------------- \n";
					win = 1;
					break;
				}
				if (big_board_2.draw_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 2 turn: ";
				big_board_2.getting_move('O');					//getting move for second player.
				if (ticTacToe::exit == -1)					//game exit check
				{
					break;
				}
				cout << big_board_2;
				if (big_board_2.win_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[ Player 2 Wins the game ]---------------- \n";
					break;
				}
				if (big_board_2.draw_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
					win = 1;
					break;
				}
			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')					//save data in file
				{
					ofstream fout;
					fout.open("UltimateGame.txt");
					fout << big_board_2;
					fout.close();
					cout << "\n********Game Save Successfully. *********\n";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}
		else
		{
			while (choice != -1)
			{
				cout << "\nPLAYER 2 turn: ";
				big_board_2.getting_move('O');					//getting move for second player.
				if (ticTacToe::exit == -1)					//game exit check
				{
					break;
				}
				cout << big_board_2;
				if (big_board_2.win_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[ Player 2 Wins the game ]---------------- \n";
					break;
				}
				if (big_board_2.draw_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
					win = 1;
					break;
				}

				cout << "\nPLAYER 1 turn: ";
				big_board_2.getting_move('X');						//getting move for first player.
				if (ticTacToe::exit == -1)					//game exit check
				{
					break;
				}
				cout << big_board_2;
				if (big_board_2.win_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[ Player 1 Wins the game ]---------------- \n";
					win = 1;
					break;
				}
				if (big_board_2.draw_check_bigboard() == true)
				{
					cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
					win = 1;
					break;
				}
			}
			if (win != 1)
			{
				char save;
				cout << "\n\nPress s to save the game or press any key to exit: \n";
				cin >> save;
				if (save == 's' || save == 'S')					//save data in file
				{
					ofstream fout;
					fout.open("UltimateGame.txt");
					fout << big_board_2;
					fout.close();
					cout << "\n********Game Save Successfully. *********\n";
				}
				else
				{
					cout << "\n********** EXITED **********\n";
				}
			}
		}
	}
	if (initial_choice == 2)
	{
		int win = 0;
		int choice = 1;
		ultimate_ticTacToe big_board_1;
		cout << big_board_1;
		cout << "\n^^^^^^^^^^^^ NEW GAME STARTED ^^^^^^^^^^^^^^\n";
		cout << "\n^^^^^^^ PLAYER 1 character   (X) ^^^^^^^^";
		cout << "\n^^^^^^^ Player 2 character   (O) ^^^^^^^^";
		while (choice != -1)
		{
			char temp = '\0';
			cout << "\nPLAYER 1 turn: ";
			big_board_1.getting_move('X');						//getting move for first player.
			if (ticTacToe::exit == -1)					//game exit check
			{
				break;
			}
			cout << big_board_1;
			if (big_board_1.win_check_bigboard() == true)
			{
				cout << "\n\n  ---------------[ Player 1 Wins the game ]---------------- \n";
				win = 1;
				break;
			}
			if (big_board_1.draw_check_bigboard() == true)
			{
				cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
				win = 1;
				break;
			}

			cout << "\nPLAYER 2 turn: ";
			big_board_1.getting_move('O');					//getting move for second player.
			if (ticTacToe::exit == -1)				//game exit check
			{
				break;
			}
			cout << big_board_1;
			if (big_board_1.win_check_bigboard() == true)
			{
				cout << "\n\n  ---------------[ Player 2 Wins the game ]---------------- \n";
				break;
			}
			if (big_board_1.draw_check_bigboard() == true)
			{
				cout << "\n\n  ---------------[  *  Game Drawn  *  ]---------------- \n";
				win = 1;
				break;
			}
		}
		if (win != 1)
		{
			char save;
			cout << "\n\nPress s to save the game or press any key to exit: \n";
			cin >> save;
			if (save == 's' || save == 'S')					//save data in file
			{
				ofstream fout;
				fout.open("UltimateGame.txt");
				fout << big_board_1;
				fout.close();
				cout << "\n********Game Save Successfully. *********\n";
			}
			else
			{
				cout << "\n********** EXITED **********\n";
			}
		}
	}
	if (initial_choice == -1)
	{
		cout << "\n ***********EXITED ***********\n";
	}
}

int main()
{
	menu();
}