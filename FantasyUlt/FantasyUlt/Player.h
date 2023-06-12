#pragma once
using namespace std;
#include <string>
#include "Item.h"
#include "Axe.h"
#include "Sword.h"
#include "HealthPotion.h"
#include "Armor.h"

class Player
{
public:
	Player(int);
	Player();
	string getName()const;
	int getHP();
	int getMoney();
	int getPower();
	void setName(string);
	void setHP(int);
	void setMoney(int);
	void printPlayer()const;
	int attack();
	void addItem(Item* item);
	int getItemCount();
	void itemSheet();
	void setPower(int power);
	void takeDamage(int d);
	void applyUHPBoost();
	void applyBHPBoost();
	void charSpreadsheet();
	void addArmor(int);
	int getArmor();
	string FormatForCSV(void);
	Item** getItems();
	int getBasePower();
	int getBaseHealth();
	int getBasebHPStore();
	int getBaseuHPStore();
	void setBasePower(int);
	void setBaseHealth(int);
	void setBasebHPStore(int);
	void setBaseuHPStore(int);
	int uHPStore;
	int bHPStore;
	void setPlayer(int);
	//make set and get itemcount, and format for csv
	void setItemCount(int);
	
	
private:
	string name;
	int hp;
	int money;
	int power;
	int itemCount;
	Item* items[15];
	
	int ownArmor;
	int baseHealth;
	int basePower;
	int basebHPStore;
	int baseuHPStore;
	
	
};

