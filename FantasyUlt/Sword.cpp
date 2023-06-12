#include "Sword.h"
#include <format>

Sword::Sword(string name, int damage, int price)
{
	setName(name);
	this->damage = damage;
	setPrice(price);
}

int Sword::attack()
{
	return damage;
}

void Sword::printInfo()
{
	cout << "NAME: " << getName() << "\tDAMAGE: " << attack() << "\n\n";
}

void Sword::printDisplay()
{
	cout << "NAME: " << getName() << "\t" << "DAMAGE: " << attack() << "\t" << "PRICE: $" << getPrice() << "\n\n";
}



Sword::Sword()
{
	this->name = "";
	this->damage = 0;
	setPrice(0);
}

string Sword::FormatForCSV(void)
{
	return format("{},{},{},{}", SwordItemID, getName(), damage, getPrice());
}
