#pragma once
#include <string>
#include "item.h"
using namespace std;
class HealthPotion : public Item
{
private:
	
	
public:
	int heal;
	int addHealth();
	HealthPotion(string name, int heal, int price);
	void printInfo();
	void printDisplay();
	HealthPotion();
	string FormatForCSV(void);
};

