#pragma once
#include <string>
#include "Villain.h"
using namespace std;
class Shao_Kahn : public Villain
{
private:
	int power;
	//FIXME: ADD More modifiers to attack
public:
	Shao_Kahn(string);
	int attack();
	void takeDamage(int);
	//FIXME: ADD more modifiers to attack
};