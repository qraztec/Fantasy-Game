#include "Player.h"
using namespace std;
#include <cstdlib>
#include "iostream"
#include <format>




Player::Player(int player)
{
	
	this->basebHPStore = 0;
	this->baseuHPStore = 0;
	this->baseHealth = 100;
	this->ownArmor = 0;
	this->bHPStore = 0;
	this->uHPStore = 0;
	this->hp = 0;
	this->name = "";
	this->money = 0;
	this->power = 0;
	switch (player)
	{
	case 1:
		this->name = "Scorpion";
		this->hp = 100;
		this->money = 200;
		this->power = 20;
		this->basePower = 20;
		break;
	case 2:
		this->name = "Raiden";
		this->hp = 100;
		this->money = 190;
		this->power = 24;
		this->basePower = 24;
		break;
	case 3:
		this->name = "Sonya Blade";
		this->hp = 100;
		this->money = 220;
		this->power = 18;
		this->basePower = 18;
		break;
	}

	this->itemCount = 0;
	
	
}

void Player::setPlayer(int pick)
{
	this->basebHPStore = 0;
	this->baseuHPStore = 0;
	this->baseHealth = 100;
	this->ownArmor = 0;
	this->bHPStore = 0;
	this->uHPStore = 0;
	this->hp = 0;
	this->name = "";
	this->money = 0;
	this->power = 0;
	switch (pick)
	{
	case 1:
		this->name = "Scorpion";
		this->hp = 100;
		this->money = 200;
		this->power = 20;
		this->basePower = 20;
		break;
	case 2:
		this->name = "Raiden";
		this->hp = 100;
		this->money = 190;
		this->power = 24;
		this->basePower = 24;
		break;
	case 3:
		this->name = "Sonya Blade";
		this->hp = 100;
		this->money = 220;
		this->power = 18;
		this->basePower = 18;
		break;
	}
}

void Player::setItemCount(int ic)
{
	this->itemCount = ic;
}

Player::Player()
{
	
	setName("Scorpion");
	
	
	this->basebHPStore = 0;
	this->baseuHPStore = 0;
	this->baseHealth = 100;
	this->ownArmor = 0;
	this->bHPStore = 0;
	this->uHPStore = 0;
	this->hp = 100;
	this->name = "";
	this->money = 200;
	this->power = 20;
	this->itemCount = 0;
}

string Player::getName() const
{
	return name;
}

int Player::getHP()
{
	return this->hp;
}

int Player::getMoney()
{
	return this->money;
}

int Player::getPower()
{
	return this->power; //add basepower
}


void Player::setName(string n)
{
	this->name = n;
}

void Player::setHP(int hp)
{
	this->hp = hp;
}

void Player::setMoney(int money)
{
	this->money = money;
}

void Player::printPlayer() const
{
	cout << "\nPLAYER: " << name << "  | HP: " << hp << "\n------------------------------" << endl;
	cout << "\nMONEY: " << money << endl;
}

int Player::attack()
{
	srand(time(NULL));
	int move = rand() % 4 + 1;
	switch (move)
	{
	case 1:
		cout << endl << getName() << " makes a Punch\n\n";
		return power;
		break;
	case 2:
		cout << endl << getName() << " lands a Kick\n\n";
		
		return power * 0.4;
		break;
	case 3:
		cout << endl << getName() << " uses a Special Move!\n\n";
		
		return power * 1.5;
		break;
	case 4:
		cout << endl << getName() << " executes BRUTALITY!\n\n";
		
		return power *1.5;
		break;
	}
	return 0;
}

void Player::addItem(Item* item)
{
	Sword* sw = dynamic_cast<Sword*>(item);
	Axe* ax = dynamic_cast<Axe*>(item);
	Armor* ar = dynamic_cast<Armor*>(item);
	HealthPotion* hpt = dynamic_cast<HealthPotion*>(item);
	
	if (sw != NULL)
	{
		items[itemCount] = sw;
		this->power += sw->damage;
		
	}

	if (ax != NULL)
	{
		items[itemCount] = ax;
		this->power += ax->damage;
		
	}

	if (ar != NULL)
	{
		items[itemCount] = ar;
		this->hp += ar->arm;
		addArmor(ar->arm);
		
	}

	if (hpt != NULL)
	{
		items[itemCount] = hpt;
		if (hpt->heal == 10)
		{
			bHPStore++;
		}
		else
		{
			uHPStore++;
		}
	}

	
	itemCount++;
}



int Player::getItemCount()
{
	return itemCount;
}

void Player::itemSheet()
{
	if (itemCount == 0)
	{
		cout << "You have no items...\n\n";
	}
	else
	{
		cout << "ITEMS\n------------------------------\n";
		for (int i = 0; i < itemCount; i++)
		{
			cout << "\t";
			items[i]->printInfo();
			cout << "\n";
		}
		cout << "\n";
	}
}

void Player::setPower(int power)
{
	this->power = power;
}

void Player::takeDamage(int d)
{
	setHP(getHP() - d);
	cout << getName() << " is taking damage of " << d << " points.\n\n";
}

void Player::applyUHPBoost()
{
	if (uHPStore > 0)
	{
		cout << "Applying Ultra HP Boost\n\n";
		setHP(getHP() + 30);
	}
	else
	{
		cout << "No Ultra HP Boosts left\n";
	}
	uHPStore--;
	
}

void Player::applyBHPBoost()
{
	if (bHPStore > 0)
	{
		cout << "Applying Basic HP Boost\n\n";
		setHP(getHP() + 10);
	}
	else 
	{
		cout << "No Basic HP Boosts left\n";
	}
	bHPStore--;
}

void Player::charSpreadsheet()
{
	cout << "PLAYER INFO:\n";
	cout << "NAME:\t" << getName() << endl;
	cout << "MONEY:\t" << getMoney() << endl;
	cout << "POWER:\t" << getPower() << endl;
	cout << "HP\t" << getHP() << endl;
	cout << "NUMBER OF BASIC HP BOOST SHOTS LEFT\t" << bHPStore << endl;
	cout << "NUMBER OF ULTRA HP BOOST SHOTS LEFT\t" << uHPStore << endl << endl;
}

void Player::addArmor(int arms)
{
	ownArmor += arms;
}

int Player::getArmor()
{
	return ownArmor;
}

string Player::FormatForCSV(void)
{
	return format("{},{},{},{},{},{}", name, money, basePower, baseHealth, 0, 0);
}

Item** Player::getItems()
{
	return items;
}

int Player::getBasePower()
{
	return basePower;
}

int Player::getBaseHealth()
{
	return baseHealth;
}

int Player::getBasebHPStore()
{
	return basebHPStore;
}

int Player::getBaseuHPStore()
{
	return baseuHPStore;
}

void Player::setBasePower(int bp)
{
	this->basePower = bp;
	this->power = basePower;
}

void Player::setBaseHealth(int bh)
{
	this->baseHealth = bh;
	this->hp = baseHealth;
}

void Player::setBasebHPStore(int bhpStore)
{
	this->basebHPStore = bhpStore;
	this->bHPStore = basebHPStore;
}

void Player::setBaseuHPStore(int buhpStore)
{
	this->baseuHPStore = buhpStore;
	this->uHPStore = baseuHPStore;
}



