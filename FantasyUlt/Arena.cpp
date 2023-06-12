#include "Arena.h"
#include "Baraka.h"
#include <stdlib.h>
#include <chrono>

#include <cstdlib>
#include <iostream>

int Arena::totalVictories = 0;

Arena::Arena()	//initializes player and villain in the arena
{
	Player players;
	Villain* villain{};
	
	this->play = &players;
	this->villain = villain;
	
}

Arena::Arena(Player& player, Villain* villain)	//initializes player and villain in the arena
{
	this->play = &player;
	
	this->villain = villain;
	
}

void Arena::fight()	//attacks each other
{
	int choice;
	while ((play->getHP() > 0) && (villain->getHp() > 0))
	{
		

		cout << "\n1. Run\n2. Attack\n3. Apply Basic HP Boost\n4. Apply Ultra HP Boost\n5. View Spreadsheet\n\n";	//choices during the fight
		cin >> choice;
		if (choice == 1)
		{
			cout << play->getName() << " ran...\n";
			break;
		}
		else if (choice == 2)
		{
			int playDam = play->attack();
			villain->takeDamage(playDam);
			int villDam = villain->attack();
			play->takeDamage(villDam);
			this_thread::sleep_for(chrono::milliseconds(900));
			
		}
		else if (choice == 3)
		{
			
			play->applyBHPBoost();
		}
		else if (choice == 4)
		{
			
			play->applyUHPBoost();
		}
		else
		{
			play->charSpreadsheet();
			continue;
		}
		

		

		

		//Victory or loss
		if (villain->getHp() <= 0)
		{
			cout << "VICTORY!\nYOU HAVE WON!\n$50 HAVE BEEN AWARDED\n\n";
			play->setMoney(play->getMoney() + 50);
			totalVictories++;
			
		}
		else if (play->getHP() <= 0)
		{
			cout << "FATALITY\nYOU HAVE LOST...\n$50 HAVE BEEN TAKEN\n\n";

			play->setMoney(play->getMoney() - 50);
			
		}
		else 
		{
			continue;
		}

	}
	

	
	
}

int Arena::getPlayerVictories()
{
	return totalVictories;
}
