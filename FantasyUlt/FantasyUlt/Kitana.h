#pragma once
#include <string>
#include "Villain.h"
using namespace std;
class Kitana : public Villain
{
private:
	int power;
	//FIXME: ADD More modifiers to attack
public:
	Kitana(string);
	int attack();
	void takeDamage(int);
	//FIXME: ADD more modifiers to attack
};