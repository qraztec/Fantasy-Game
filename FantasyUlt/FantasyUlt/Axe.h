#pragma once
#include <string>
#include "item.h"
using namespace std;
class Axe : public Item
{
private:
	//int damage;
	
public:
	Axe(string name, int damage, int price);
	int attack();
	void printInfo();
	void printDisplay();
	Axe();
	int damage;
	string FormatForCSV(void);
};

