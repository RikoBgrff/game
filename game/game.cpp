#include <iostream>
#include <fstream>

#include <list>
#include <string>

#include "Base.h"
#include "Red.h"
#include "DarkRed.h"
#include "Blue.h"
#include "Green.h"

class Player {
public:
	Base* card1 = nullptr;
	Base* card2 = nullptr;
};
void display(std::list<Player>* players) {
	std::cout << "Player 1 Cards: ";
	for (auto game : *players)
	{
		std::string tempName1 = (typeid(*game.card1)).name();
		std::string card1Name = tempName1.substr(6, 1);

		std::cout << card1Name << ",";
	}
	std::cout << "\nPlayer 2 Cards: ";
	for (auto game : *players)
	{
		std::string tempName2 = (typeid(*game.card2)).name();
		std::string card2Name = tempName2.substr(6, 1);

		std::cout << card2Name << ",";
	}
	std::cout << "\n\nPlayer 1 Points:";
	for (auto game : *players)
	{
		std::cout << game.card1->getResult() << " ";
	}
	std::cout << "\nPlayer 2 Points:";
	for (auto game : *players)
	{
		std::cout << game.card2->getResult() << " ";
	}
	std::cout << std::endl;
	std::cout << "\nPlayer 1's Score:";
	int player1lose = 0;
	int player1equal = 0;
	int player1win = 0;
	for (auto game : *players) {
		if (game.card1->getResult() == 0) {
			player1lose++;
		}
		if (game.card1->getResult() == 1) {
			player1equal++;
		}
		if (game.card1->getResult() == 2) {
			player1win++;
		}
	}
	std::cout << "Lose:" << player1lose << " Equal:" << player1equal << " Win:" << player1win;

	std::cout << "\nPlayer 2's Score:";
	int player2lose = 0;
	int player2equal = 0;
	int player2win = 0;
	for (auto game : *players) {
		if (game.card2->getResult() == 0) {
			player2lose++;
		}
		if (game.card2->getResult() == 1) {
			player2equal++;
		}
		if (game.card2->getResult() == 2) {
			player2win++;
		}
	}
	std::cout << "Lose:" << player2lose << " Equal:" << player2equal << " Win:" << player2win << std::endl;

	if (player1win > player2win) {
		std::cout << "Winner is Player 1 (" << player1win << " Points)" << std::endl;
	}
	else if (player1win == player2win) {
		std::cout << "\nScores are equal,both players are winner! <3" << std::endl;
	}
	else if (player1win < player2win) {
		std::cout << "Winner is Player 2 (" << player2win << " Points)" << std::endl;
	}
	else {
		std::cout << "Error Occured\nProgram Terminated!" << std::endl;
		exit(1);
	}
}

int main() {
#pragma region Variables
	std::list<Player>* players = new std::list<Player>;
	std::string line1;
	std::string line2;
	std::string fileSource = "Kartlar.txt";
	Base* card1 = NULL;
	Base* card2 = NULL;
#pragma endregion

#pragma region readCards
	std::ifstream document(fileSource);
	if (document.is_open()) {
		std::getline(document, line1);
		while (getline(document, line2)) {
			document.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	}
	document.close();
#pragma endregion 

#pragma region formatCardList1
	for (int i = 0; i < line1.size(); i++) {

		if (line1[i] < 'A' || line1[i] > 'Z' &&
			line1[i] < 'a' || line1[i] > 'z')
		{
			line1.erase(i, 1);
			i--;
		}
	}
#pragma endregion

#pragma region formatCardList2
	for (int i = 0; i < line2.size(); i++) {

		if (line2[i] < 'A' || line2[i] > 'Z' &&
			line2[i] < 'a' || line2[i] > 'z')
		{
			line2.erase(i, 1);
			i--;
		}
	}
#pragma endregion

	if (line1.size() != line2.size()) {
		std::cout << "Card counts are not equal!\nPlease Check Cards" << std::endl;
		exit(1);
	}

	else {
		for (int i = 0; i < line1.size(); i++)
		{


			char card1code = line1[i];
			char card2code = line2[i];

			switch (card1code)
			{
			case 'R': {
				card1 = new Red();
				break;
			}
			case 'D': {
				card1 = new DarkRed();
				break;
			}
			case 'B': {
				card1 = new Blue();
				break;
			}
			case 'G': {
				card1 = new Green();
				break;
			}
			default:
				std::cout << "Card Code Could Not Recognized\nPlease Try Again";
				exit(1);
				break;
			}

			switch (card2code)
			{
			case 'R': {
				card2 = new Red();
				break;
			}
			case 'D': {
				card2 = new DarkRed();
				break;
			}
			case 'B': {
				card2 = new Blue();
				break;
			}
			case 'G': {
				card2 = new Green();
				break;
			}
			default:
				std::cout << "Card Code Could Not Recognized\nPlease Check Card List";
				exit(1);
				break;
			}

			Player tempPlayer;
			tempPlayer.card1 = card1;
			tempPlayer.card2 = card2;
			players->insert(players->begin(), tempPlayer);
		}
		for (auto player : *players)
		{
			player.card1->compare(*player.card2);
			player.card2->compare(*player.card1);

		}
		display(players);
	}

}





