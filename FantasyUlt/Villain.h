#pragma once
#include <string>
#include "Item.h"
#include "Store.h";
#include "Axe.h"
#include "Sword.h"
#include "HealthPotion.h"
#include "Armor.h"
using namespace std;
class Villain
{
private:
	string name;
	int hp;
	int money;
	int itemCount;
	int power;
	Item* items[15];
	
public:
	Villain();
	string getName()const;
	int getHp()const;
	void setName(string);
	void setPower(int);
	int getPower();
	void setHp(int);
	void printVillain()const;
	bool stillAlive()const;
	virtual void takeDamage(int d) = 0;
	virtual int attack() = 0;
	int getMoney()const;
	void setMoney(int);
	void addItem(Item* item);
	
};

