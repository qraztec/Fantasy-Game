#pragma once
#include <string>
#include "item.h"
using namespace std;
class Sword : public Item
{
private:
	//int damage;
	string name;
public:
	Sword(string name, int damage, int price);
	int attack();
	void printInfo();
	void printDisplay();
	Sword();
	int damage;
	string FormatForCSV(void);
};

