#pragma once
#include <string>
#include "item.h"
using namespace std;
class Armor : public Item
{
private:
	//int arm;
	
public:
	Armor(string name, int arm, int price);
	int addArmor();
	void printInfo();
	void printDisplay();
	Armor();
	int arm;
	string FormatForCSV(void);
};

