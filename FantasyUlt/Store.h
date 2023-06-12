#pragma once
#include "Item.h"
#include "Player.h"
#include "Villain.h"
class Store
{
private:
	int itemPick;
	int itemCount;
	Item* items[15];
	Player* play;
	
public:
	Store(Player& player);
	/*~Store();*/
	void purchase(int choice);
	void displayItems();
	
};

