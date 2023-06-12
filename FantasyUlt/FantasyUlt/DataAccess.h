#pragma once

#include <string>
#include <format>
#include <iostream>
#include <fstream>
#include <vector>

#include "Player.h"
using namespace std;

#define PlayerRecord 1
#define ItemRecord 2
class DataAccess
{
private:
	string m_fileName;
	string CreatePlayerRecord(Player& player);
	string CreateItemRecord(Item& item);
	vector<string> Split(string str, string token);
public:
	DataAccess(string fileName);
	void SaveData(Player& cart);
	Player LoadData(void);

};

