#pragma once
#include "Player.h"
#include "Villain.h"
class Arena
{
private:
	Player* play;
	Villain* villain;
	
public:
	Arena();
	Arena(Player& player, Villain* villain);
	void fight();
	int getPlayerVictories();
	static int totalVictories;
	static int totalGames;
	
	
};

