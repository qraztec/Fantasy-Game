#include "Store.h"
#include <iostream>
#include <time.h>



Store::Store(Player& player)
{
	this->play = &player;
	this->itemPick = 0;
	items[0] = new Sword("Black Dragon Sword", 20, 100);
	items[1] = new Axe("Battle Axe", 30, 150);
	items[2] = new Sword("High Edenian Sword", 60, 300);
	items[3] = new HealthPotion("Basic Health Potion", 10, 20);
	items[4] = new HealthPotion("Basic Health Potion", 10, 20);
	items[5] = new HealthPotion("Ultra Health Potion", 30, 40); //trouble setting to 30
	items[6] = new Armor("Dragon King's Helmet", 20, 50);
	items[7] = new Armor("Emperor Shao Khan's Helmet", 60, 150);
	itemCount = 8;
}

//Store::~Store()
//{
//	for (int i = 0; i < 8; i++)
//		delete items[i];
//}



void Store::purchase(int choice)
{
	this->itemPick = choice;
	this->itemPick = itemPick - 1;
	play->addItem(items[this->itemPick]);
	play->setMoney(play->getMoney() - items[this->itemPick]->getPrice());

	
}

void Store::displayItems()
{
	cout << "\nIN STORE:\n";
	for (int i = 0; i < itemCount; i++)
	{
		cout << "\t" << (i + 1) << ".\t";
		items[i]->printDisplay();
		cout << endl;
	}
	cout << endl;
}


