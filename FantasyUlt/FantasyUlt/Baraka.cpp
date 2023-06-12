#include "Baraka.h"
#include <iostream>

Baraka::Baraka(string mode)
{

	mode == "Easy" ? setPower(8) : setPower(16);

	
	setName("Baraka");
	setMoney(100);
	setHp(110);
}

int Baraka::attack()
{
	srand(time(NULL));
	int move = rand() % 4 + 1;
	switch (move)
	{
	case 1:
		cout << "\nBaraka lands Blade Swipes\n\n";
		return getPower() * 1.5;
		break;
	case 2:
		cout << "\nBaraka unleashes Blade Sparks\n\n";
		return getPower() * 0.9;
		break;
	case 3:
		cout << "\nBaraka unleashes Blade Decapitation!\n\n";
		return getPower() * 2;
		break;
	case 4:
		cout << "\nBaraka lands a Double Kick\n\n";
		return getPower() * 0.7;
		break;
	}
	return 0;
	
}

void Baraka::takeDamage(int damage)
{
	setHp(getHp() - damage);
	cout << "Baraka is taking damage of " << damage << " points.\n";
}
