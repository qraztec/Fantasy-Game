#include "Item.h"

Item::Item()
{
	this->price = 40;
}

Item::Item(string name, int price)
{
	this->name = name;
	this->price = price;
}

int Item::getPrice()
{
	return this->price;
}

void Item::setPrice(int price)
{
	this->price = price;
}

string Item::getName()
{
	return this->name;
}

void Item::setName(string name)
{
	this->name = name;
}

void Item::printDisplay()
{
	cout << "NAME: " << getName() << "\t" << "PRICE: $" << getPrice() << "\n\n";
}

void Item::printInfo()
{
	cout << "NAME: " << getName() << "\n\n";
}
