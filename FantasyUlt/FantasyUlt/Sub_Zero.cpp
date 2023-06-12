#include "Sub_Zero.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

Sub_Zero::Sub_Zero(string mode)
{
	mode == "Easy" ? setPower(10) : setPower(35);
	
	setName("Sub_Zero");
	setMoney(200);
	setHp(100);
}

int Sub_Zero::attack()
{
	srand(time(0));
	int move = (rand() % 4) + 1;
	switch (move)
	{
	case 1:
		cout << "\nSub_Zero lands an Ice Freeze\n\n";
		return getPower() * 0.5;
		break;
	case 2:
		cout << "\nSub_Zero hits with Slide\n\n";
		return getPower();
		break;
	case 3:
		cout << "\nSub_Zero has performed a Ground Freeze\n\n";
		return getPower() * 0.5;
		break;
	case 4:
		cout << "\nSub_Zero unleashes ICE GRENADE\n\n";
		return getPower() * 2;
		break;
	}
	return 0;
}

void Sub_Zero::takeDamage(int damage)
{
	setHp(getHp() - damage);
	cout << "Sub_Zero is taking damage of " << damage << " points.\n";
}
