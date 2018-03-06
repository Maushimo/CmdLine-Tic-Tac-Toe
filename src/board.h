#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

enum class space_value {EMPTY, X, O};

class Board
{
public:
	Board();

	void DrawBoard();
	//method to determine what to print at that specific space
	std::string DrawChar(space_value space);
	void InputChar(std::string space_position);
	void SetPlayerChoice(std::string player_choice);
	//Two separate end states
	bool PlayerWin();
	bool ComputerWin();
	//method to process computer turns
	void ComputerTurn();
	//return player selection
	std::string GetPlayer();
private:
	//2D int array representing board - 0 = empty, 1 = 'x', 2 = 'o'
	std::vector<std::vector<space_value>> mBoard;
	std::string player_choice;
	std::string computer_choice;
};