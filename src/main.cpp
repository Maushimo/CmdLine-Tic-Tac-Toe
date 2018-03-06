#include <iostream>
#include <string>
#include "board.h"
//enums to handle different states
enum class GAME_STATES {SELECTION, PLAYING, WIN, LOSE};

GAME_STATES CurrentGameState = GAME_STATES::SELECTION;
//game board object
Board* board = new Board();

int main(int argc, char const *argv[])
{
	if(CurrentGameState == GAME_STATES::SELECTION)
	{
		std::string player_selection;

		std::cout << "|---TIC-TAC-TOE---|" << std::endl;
		std::cout << "Which player do you want to be? X or O?" << std::endl;
		std::cin >> player_selection;

		board->SetPlayerChoice(player_selection);

		CurrentGameState = GAME_STATES::PLAYING;
	}

	while(CurrentGameState == GAME_STATES::PLAYING)
	{
		std::string player_input;
		
		//std::cout << "Player is: " << board->GetPlayer() << std::endl;
		board->DrawBoard();
		std::cout << "\n";
		std::cout << "Input the space you wish to place your " << board->GetPlayer() << std::endl;
		std::cin >> player_input;

		board->InputChar(player_input);
		player_input = "";

		board->ComputerTurn();

		if(board->PlayerWin())
		{
			CurrentGameState = GAME_STATES::WIN;
		}

		if(board->ComputerWin())
		{
			CurrentGameState = GAME_STATES::LOSE;
		}
	}

	if(CurrentGameState == GAME_STATES::WIN)
	{
		board->DrawBoard();
		std::cout << "Congratulations, you won!\n";
	}
	else if(CurrentGameState == GAME_STATES::LOSE)
	{
		board->DrawBoard();
		std::cout << "Sorry, you lost!\n";
	}
	return 0;
}