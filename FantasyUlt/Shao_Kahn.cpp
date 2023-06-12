#include "Shao_Kahn.h"
#include <iostream>

Shao_Kahn::Shao_Kahn(string mode)
{
	mode == "Easy" ? setPower(16) : setPower(48);

	this->power = power;
	setName("Shao_Kahn");
	setMoney(100);
	setHp(180);
}

int Shao_Kahn::attack()
{
	srand(time(NULL));
	int move = rand() % 4 + 1;
	switch (move)
	{
	case 1:
		cout << "\nShao Kahn lands a Hammer Slam\n\n";
		return getPower() * 1.5;
		break;
	case 2:
		cout << "\nShao Kahn blows a Knee Shatter\n\n";
		return getPower() * 0.9;
		break;
	case 3:
		cout << "\nShao Kahn throws a merciless spear!\n\n";
		return getPower();
		break;
	case 4:
		cout << "\nShao Kahn unleashes his KRUSHING BLOW!\n\n";
		return getPower() * 2;
		break;
	}
	return 0;
}

void Shao_Kahn::takeDamage(int damage)
{
	setHp(getHp() - damage);
	cout << "Shao Kahn is taking damage of " << damage << " points.\n";
}
