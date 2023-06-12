#include "HealthPotion.h"
#include <format>

int HealthPotion::addHealth()
{
    return this->heal;
}

HealthPotion::HealthPotion(string name, int heal, int price)
{
    setName(name);
    this->heal = heal;
    setPrice(price);
}

void HealthPotion::printInfo()
{
    cout << "NAME: " << getName() << "\tHEALING: " << addHealth() << "\n\n";
}

void HealthPotion::printDisplay()
{
    cout << "NAME: " << getName() << "\t" << "HEALING: " << addHealth() << "\t" << "PRICE: $" << getPrice() << "\n\n";
}



HealthPotion::HealthPotion()
{
    this->name = "";
    this->heal = 0;
    setPrice(0);
}

string HealthPotion::FormatForCSV(void)
{
    return format("{},{},{},{}", HealthPotionItemID, getName(), heal, getPrice());
}
