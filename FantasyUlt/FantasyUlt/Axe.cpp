#include "Axe.h"
#include <format>

Axe::Axe(string name, int damage, int price)
{
    setName(name);
    this->damage = damage;
    setPrice(price);
}

int Axe::attack()
{
    return damage;
}

void Axe::printInfo()
{
    cout << "NAME: " << getName() << "\tDAMAGE: " << attack() << "\n\n";
}

void Axe::printDisplay()
{
    cout << "NAME: " << getName() << "\t" << "DAMAGE: " << attack() << "\t" << "PRICE: $" << getPrice() << "\n\n";
}



Axe::Axe()
{
    this->name = "";
    this->damage = 0;
    setPrice(0);
}

string Axe::FormatForCSV(void)
{
    return format("{},{},{},{}", AxeItemID, getName(), damage, getPrice()); //try set name and price to public
    
}
