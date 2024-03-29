// 13Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "Objects.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	World* game = new World();

	while (!game->shouldGameEnd()) {

		// Beginning of a new turn

		system("cls");

		game->startNewTurn();

		cout << "-----------------------------------" << endl;
		cout << game->getCurrentPlayer() << " it is your turn!" << endl;

		cout << endl;

		cout << "Your hand: " << game->getPlayerHand() << endl;;
		cout << "Your highest stacked card: " << game->getPlayerStack() << endl;

		game->resetOptions();

		cout << game->getPlayerOptions(true) << endl;
		
		cout << "Enter an option: ";
		game->parseInputOption(game->waitForInput(true));

		// Continuing the current player with a new turn
		while (!game->shouldTurnEnd()) {

			cout << endl << endl;

			cout << "Your hand: " << game->getPlayerHand() << endl;;
			cout << "Your highest stacked card: " << game->getPlayerStack() << endl;
			
			game->resetOptions();
			cout << game->getPlayerOptions(false) << endl;
			
			cout << "Enter an option: ";
			game->parseInputOption(game->waitForInput(true));
		}
	}

	cout << endl << "Congratulations " << game->getCurrentPlayer() << " you won!";
}