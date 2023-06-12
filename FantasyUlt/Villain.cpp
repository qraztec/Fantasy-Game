#include "Villain.h"
#include "iostream"
using namespace std;

Villain::Villain()
{
	this->name = "";
	this->hp = 100;
	this->money = 200;
	this->power = 15;
	itemCount = 0;

}

string Villain::getName() const
{
	return this->name;
}

int Villain::getHp() const
{
	return this->hp;
}

void Villain::setName(string name)
{
	this->name = name;
}

void Villain::setPower(int villPower)
{
	this->power = villPower;
}

int Villain::getPower()
{
	return this->power;
}

void Villain::setHp(int hp)
{
	this->hp = hp;
}

void Villain::printVillain() const
{
	cout << "\nVILLAIN: " << getName() << "  | HP: " << getHp() << "\n------------------------------" << endl;
	cout << "MONEY: " << getMoney();
}

bool Villain::stillAlive() const
{
	if (hp > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Villain::getMoney() const
{
	return this->money;
}

void Villain::setMoney(int money)
{
	this->money = money;
}

//void Villain::addItem(Item* item)
//{
//	Sword* sw = dynamic_cast<Sword*>(item);
//	Axe* ax = dynamic_cast<Axe*>(item);
//	Armor* ar = dynamic_cast<Armor*>(item);
//	HealthPotion* hpt = dynamic_cast<HealthPotion*>(item);
//
//	if (sw != NULL)
//	{
//		items[itemCount] = sw;
//		this->power += sw->damage;
//
//	}
//
//	if (ax != NULL)
//	{
//		items[itemCount] = ax;
//		this->power += ax->damage;
//
//	}
//
//	if (ar != NULL)
//	{
//		items[itemCount] = ar;
//		this->hp += ar->arm;
//
//	}
//
//	if (hpt != NULL)
//	{
//		items[itemCount] = hpt;
//	}
//
//
//	itemCount++;
//}
