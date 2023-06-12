#pragma once
#include <string>
#include <iostream>
using namespace std;

#define ArmorItemID				1
#define AxeItemID				2
#define HealthPotionItemID		3
#define SwordItemID				4

class Item
{
public:
	int price;
	string name;
public:
	Item();
	Item(string, int);
	int getPrice();
	void setPrice(int price);
	string getName();
	void setName(string);
	virtual void printDisplay();
	virtual void printInfo();
	virtual string FormatForCSV(void) = 0;
};

