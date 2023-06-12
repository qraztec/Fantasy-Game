#include "Armor.h"
#include <format>

Armor::Armor(string name, int arm, int price)
{
	setName(name);
	this->arm = arm;
	setPrice(price);
}

int Armor::addArmor()
{
	return this->arm;
}

void Armor::printInfo()
{
	cout << "NAME: " << getName() << "\tARMOR: " << addArmor() << "\n\n";
}

void Armor::printDisplay()
{
	cout << "NAME: " << getName() << "\t" << "ARMOR: " << addArmor() << "\t" << "PRICE: $" << getPrice() << "\n\n";
}


Armor::Armor()
{
	this->name = "";
	this->arm = 0;
	setPrice(0);
}

string Armor::FormatForCSV(void)
{
	return format("{},{},{},{}", ArmorItemID, getName(), arm, getPrice());
}
