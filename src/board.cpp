#include "board.h"

Board::Board()
{
	for(int x=0;x<3;x++)
	{
		mBoard.push_back(std::vector<space_value>(3, space_value::EMPTY));
	}
}

void Board::DrawBoard()
{
	std::cout << "      BOARD\n";
	std::cout << "      A   " << "B   " << "C   \n";
	std::cout << "    +---+---+---+\n";
	std::cout << "1   | "<< this->DrawChar(mBoard[0][0]) <<" | "<< this->DrawChar(mBoard[1][0]) << " | "<< this->DrawChar(mBoard[2][0]) <<" |\n";
	std::cout << "    +---+---+---+\n";
	std::cout << "2   | "<< this->DrawChar(mBoard[0][1]) <<" | "<< this->DrawChar(mBoard[1][1]) << " | "<< this->DrawChar(mBoard[2][1]) <<" |\n";
	std::cout << "    +---+---+---+\n";
	std::cout << "3   | "<< this->DrawChar(mBoard[0][2]) <<" | "<< this->DrawChar(mBoard[1][2]) << " | "<< this->DrawChar(mBoard[2][2]) <<" |\n";
	std::cout << "    +---+---+---+\n";
}

std::string Board::DrawChar(space_value space)
{
	if(space == space_value::X)
	{
		return "X";
	}
	else if(space == space_value::O)
	{
		return "O";
	}

	return " ";
}

void Board::InputChar(std::string space_position)
{
	//'A' CASES
	if(space_position == "a1")
	{
		if(player_choice == "X")
		{
			mBoard[0][0] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[0][0] = space_value::O;
		}
	}

	if(space_position == "a2")
	{
		if(player_choice == "X")
		{
			mBoard[0][1] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[0][1] = space_value::O;
		}
	}

	if(space_position == "a3")
	{
		if(player_choice == "X")
		{
			mBoard[0][2] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[0][2] = space_value::O;
		}
	}

	//'B' CASES
	if(space_position == "b1")
	{
		if(player_choice == "X")
		{
			mBoard[1][0] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[1][0] = space_value::O;
		}
	}

	if(space_position == "b2")
	{
		if(player_choice == "X")
		{
			mBoard[1][1] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[1][1] = space_value::O;
		}
	}

	if(space_position == "b3")
	{
		if(player_choice == "X")
		{
			mBoard[1][2] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[1][2] = space_value::O;
		}
	}

	//'C' CASES
	if(space_position == "c1")
	{
		if(player_choice == "X")
		{
			mBoard[2][0] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[2][0] = space_value::O;
		}
	}

	if(space_position == "c2")
	{
		if(player_choice == "X")
		{
			mBoard[2][1] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[2][1] = space_value::O;
		}
	}

	if(space_position == "c3")
	{
		if(player_choice == "X")
		{
			mBoard[2][2] = space_value::X;
		}
		else if(player_choice == "O")
		{
			mBoard[2][2] = space_value::O;
		}
	}
}

void Board::SetPlayerChoice(std::string player_choice)
{
	if(player_choice == "x" || player_choice == "X")
	{
		this->player_choice = "X";
		this->computer_choice = "O";
	}
	else if(player_choice == "o" || player_choice == "O")
	{
		this->player_choice = "O";
		this->computer_choice = "X";
	}
}

bool Board::PlayerWin()
{
	//Set player choice to make sure comparisons are correct
	space_value player_value;

	if(player_choice == "X")
	{
		player_value = space_value::X;
	}
	else if(player_choice == "O")
	{
		player_value = space_value::O;
	}

	//Horizontal checks
	if(mBoard[0][0] == player_value && mBoard[1][0] == player_value && mBoard[2][0] == player_value)
	{
		return true;
	}
	if(mBoard[0][1] == player_value && mBoard[1][1] == player_value && mBoard[2][1] == player_value)
	{
		return true;
	}
	if(mBoard[0][2] == player_value && mBoard[1][2] == player_value && mBoard[2][2] == player_value)
	{
		return true;
	}

	//Vertical checks
	if(mBoard[0][0] == player_value && mBoard[0][1] == player_value && mBoard[0][2] == player_value)
	{
		return true;
	}
	if(mBoard[1][0] == player_value && mBoard[1][1] == player_value && mBoard[1][2] == player_value)
	{
		return true;
	}
	if(mBoard[2][0] == player_value && mBoard[2][1] == player_value && mBoard[2][2] == player_value)
	{
		return true;
	}

	//diagonal checks
	if(mBoard[0][0] == player_value && mBoard[1][1] == player_value && mBoard[2][2] == player_value)
	{
		return true;
	}
	if(mBoard[0][2] == player_value && mBoard[1][1] == player_value && mBoard[2][0] == player_value)
	{
		return true;
	}

	return false;
}

bool Board::ComputerWin()
{
	//Set player choice to make sure comparisons are correct
	space_value computer_value;
	if(player_choice == "X")
	{
		computer_value = space_value::O;
	}
	else if(player_choice == "O")
	{
		computer_value = space_value::X;
	}

	//Horizontal checks
	if(mBoard[0][0] == computer_value && mBoard[1][0] == computer_value && mBoard[2][0] == computer_value)
	{
		return true;
	}
	if(mBoard[0][1] == computer_value && mBoard[1][1] == computer_value && mBoard[2][1] == computer_value)
	{
		return true;
	}
	if(mBoard[0][2] == computer_value && mBoard[1][2] == computer_value && mBoard[2][2] == computer_value)
	{
		return true;
	}

	//Vertical checks
	if(mBoard[0][0] == computer_value && mBoard[0][1] == computer_value && mBoard[0][2] == computer_value)
	{
		return true;
	}
	if(mBoard[1][0] == computer_value && mBoard[1][1] == computer_value && mBoard[1][2] == computer_value)
	{
		return true;
	}
	if(mBoard[2][0] == computer_value && mBoard[2][1] == computer_value && mBoard[2][2] == computer_value)
	{
		return true;
	}

	//diagonal checks
	if(mBoard[0][0] == computer_value && mBoard[1][1] == computer_value && mBoard[2][2] == computer_value)
	{
		return true;
	}
	if(mBoard[0][2] == computer_value && mBoard[1][1] == computer_value && mBoard[2][0] == computer_value)
	{
		return true;
	}

	return false;
}

void Board::ComputerTurn()
{
	bool TurnComplete = false;

	std::srand(time(0));
	int x = std::rand() % 3;
	int y = std::rand() % 3;

	while(!TurnComplete)
	{
		if(mBoard[x][y] == space_value::EMPTY)
		{
			if(computer_choice == "X")
			{
				mBoard[x][y] = space_value::X;
			}
			else if(computer_choice == "O")
			{
				mBoard[x][y] = space_value::O;
			}
			TurnComplete = true;
		}
		else if(mBoard[x][y] == space_value::X || mBoard[x][y] == space_value::O)
		{
			std::srand(time(0));
			x = std::rand() % 3;
			y = std::rand() % 3;
		}
	}

	std::cout << "COMPUTER CHOOSES: " << x << y << std::endl;
}