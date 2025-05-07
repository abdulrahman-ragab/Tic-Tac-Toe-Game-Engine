#include <iostream>
#include <string>
#include <map>      // Needed for std::map
#include <utility>



class Board
{
	public:
	char boardGrid[3][3]={{' ',' ',' '}, {' ',' ',' '},{' ',' ',' '}};
		Board(){}
		~Board(){}
		bool isFull();
		bool isWinner();
		void Board_Display();
};

	bool Board::isFull()
	{
		for(int i=0; i<3;i++)
		{
			for(int j=0; j<3;j++)
			{
				if (boardGrid[i][j] != 'X' && boardGrid[i][j] != 'O')
					return 0;
			}
		}
		return 1;
	}
	bool Board::isWinner()
	{
		char symbols [] = {'X', 'O'};
		for (char symbol : symbols)
		{
			if ((boardGrid[0][0] == symbol && boardGrid[0][1] == symbol && boardGrid[0][2] == symbol)||
				(boardGrid[1][0] == symbol && boardGrid[1][1] == symbol && boardGrid[1][2] == symbol)||
				(boardGrid[2][0] == symbol && boardGrid[2][1] == symbol && boardGrid[2][2] == symbol)||
				(boardGrid[0][0] == symbol && boardGrid[1][0] == symbol && boardGrid[2][0] == symbol)||
				(boardGrid[0][1] == symbol && boardGrid[1][1] == symbol && boardGrid[2][1] == symbol)||
				(boardGrid[0][2] == symbol && boardGrid[1][2] == symbol && boardGrid[2][2] == symbol)||
				(boardGrid[0][0] == symbol && boardGrid[1][1] == symbol && boardGrid[2][2] == symbol)||
				(boardGrid[2][0] == symbol && boardGrid[1][1] == symbol && boardGrid[0][2] == symbol)
				)
				{
					
				std::cout<<"Player "<<symbol<<" WIN"<<std::endl;
				return 1;
				}
		}
			
		return 0;

	}
	void Board::Board_Display()
	{
		for(int i=0; i<3;i++)
		{
			for(int j=0; j<3;j++)
			{
				std::cout<<"["<<boardGrid[i][j]<<"]";
			}
			std::cout<<std::endl;
		}
	}


class CreatPlayer
{
	public:
		char player;
		int value;

	CreatPlayer(char s): player(s){}
	~CreatPlayer(){}
	int PlayNow();
	void get_data();
};

void CreatPlayer::get_data()
{
	std::cin>>value;
}
int CreatPlayer::PlayNow()
{
	std::cout<<"Player "<<player<<" Cell No. :";
	get_data();
	while (!(value <= 8 && value >= 0))
	{	std::cout<<"Pleas Enter valid Number 0 to 8 "<<std::endl;
		std::cout<<"Player "<<player<<" Cell No. :";
		get_data();
	}
	return value;
}

class Game
{
	std::map<int, std::pair<int, int>> index = { {0, {0, 0}}, {1, {0, 1}}, {2, {0, 2}},
												{3, {1, 0}}, {4, {1, 1}}, {5, {1, 2}},
												{6, {2, 0}}, {7, {2, 1}}, {8, {2, 2}}	};
	public:
		Board NewBoard;
		CreatPlayer Player1 = CreatPlayer('X');
		CreatPlayer Player2 = CreatPlayer('O');
		Game(){
			std::cout<<"New Game Start"<<std::endl;
			std::cout<<"Player 1 (X) will start, Select Cells from 0 to 8: "<<std::endl;
			NewBoard.Board_Display();
			GameCkeck();
		}
		~Game(){}
		void GameTurn(int iteration);
		void GameCkeck();
};
void Game::GameTurn(int iteration)
{
	int cell_no = -1;
	if(iteration%2 == 0)
		cell_no = Player1.PlayNow();
	
	else
		cell_no = Player2.PlayNow();

	auto [i, j] = index[cell_no];

	if (NewBoard.boardGrid[i][j] != 'X' && NewBoard.boardGrid[i][j] != 'O')
		iteration%2 == 0? NewBoard.boardGrid[i][j] = 'X' : NewBoard.boardGrid[i][j] = 'O';
	
	else
	{
		std::cout<<"This cell was already Filled !! "<<std::endl;
		GameTurn(iteration);
	}
}

void Game::GameCkeck()
{	
	int i = 0;
	while (!NewBoard.isFull() && i < 9)
	{	
		if (NewBoard.isWinner())
			break;

		GameTurn(i);
		NewBoard.Board_Display();
		i++;
	}
	if (NewBoard.isFull() && !NewBoard.isWinner())
		std::cout << "Board is Full - It's a Draw!" << std::endl;
}



int main()
{
	{
		Game newgame;
	}
	char in;
	std::cout << "Press R to Restart:  ";
	std::cin>>in;
	while (in == 'R' || in == 'r')
	{
		Game Renewgame;
		std::cout << "Press R to Restart:  ";
		std::cin>>in;
	}
	return 0;
}
