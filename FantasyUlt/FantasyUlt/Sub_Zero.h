#pragma once
#include <string>
#include "Villain.h"
using namespace std;
class Sub_Zero : public Villain
{
private:
	int power;
	//FIXME: ADD More modifiers to attack
public:
	Sub_Zero(string);
	int attack();
	void takeDamage(int);
	//FIXME: ADD more modifiers to attack
};

