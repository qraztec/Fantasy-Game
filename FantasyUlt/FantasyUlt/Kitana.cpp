#include "Kitana.h"
#include <iostream>

Kitana::Kitana(string mode)
{

	mode == "Easy" ? setPower(12) : setPower(30);
	
	setName("Kitana");
	setMoney(300);
	setHp(90);
}

int Kitana::attack()
{
	srand(time(NULL));
	int move = rand() % 4 + 1;
	switch (move)
	{
	case 1:
		cout << "\nKitana hits with Fan Swipe\n\n";
		return getPower();
		break;
	case 2:
		cout << "\nKitana hits with Fan Throwk\n\n";
		return getPower() * 0.25;
		break;
	case 3:
		cout << "\nKitana blows a Square Wave Punch!\n\n";
		return getPower();
		break;
	case 4:
		cout << "\nKitana blows a KISS OF DEATH\n\n";
		return getPower() * 1.5;
		break;
	}
	return 0;
}

void Kitana::takeDamage(int damage)
{
	setHp(getHp() - damage);
	cout << "Kitana is taking damage of " << damage << " points.\n";
}
