#include "DataAccess.h"
#include "Armor.h"
#include "Axe.h"
#include "HealthPotion.h"
#include "Sword.h"

string DataAccess::CreatePlayerRecord(Player& player)
{
    return format("{},{}", PlayerRecord, player.FormatForCSV());
}

string DataAccess::CreateItemRecord(Item& item)
{
    return format("{},{}", ItemRecord, item.FormatForCSV());
}

vector<string> DataAccess::Split(string str, string token)
{
    vector<string>result;
    while (str.size())
    {
        int index = str.find(token);
        if (index != string::npos)
        {
            result.push_back(str.substr(0, index));
            str = str.substr(index + token.size());
            if (str.size() == 0)
            {
                result.push_back(str);
            }
        }
        else
        {
            result.push_back(str);
            str = "";
        }
    }

    return result;
}

DataAccess::DataAccess(string fileName)
{
    m_fileName = fileName;
}

void DataAccess::SaveData(Player& player)
{
    ofstream file;
    file.open(m_fileName);
    auto str = CreatePlayerRecord(player);
    file << str << endl;
    auto itemList = player.getItems();
    auto itemCount = player.getItemCount();
    for (auto cnt = 0; cnt < itemCount; cnt++)
    {
        str = CreateItemRecord(*itemList[cnt]);
        file << str << endl;
    }

    file.close();
}

Player DataAccess::LoadData(void)
{
    fstream file;
    file.open(m_fileName, ios::in);
    if (!file.is_open())
    {
        throw runtime_error("Could not open file");
    }

    Player player;
    string line;
    while (getline(file, line))
    {
        auto parts = Split(line, ",");
        switch (parts[0][0])
        {
        case '1':
            player.setName(parts[1].c_str());
            player.setMoney(atoi(parts[2].c_str()));
            player.setBasePower(atoi(parts[3].c_str()));
            player.setBaseHealth(atoi(parts[4].c_str()));
            player.setBasebHPStore(atoi(parts[5].c_str()));
            player.setBaseuHPStore(atoi(parts[6].c_str()));
         
           
            break;
        case '2':
            auto itemType = atoi(parts[1].c_str());
            auto name = parts[2].c_str();
            auto price = atoi(parts[4].c_str());
            if (itemType == 1)
            {
                auto arm = atoi(parts[3].c_str());
                player.addItem(new Armor(name, arm, price));
            }
            else if (itemType == 2)
            {
                auto damage = atoi(parts[3].c_str());
                player.addItem(new Axe(name, damage, price));
            }
            else if (itemType == 3)
            {
                auto heal = atoi(parts[3].c_str());
                player.addItem(new HealthPotion(name, heal, price));
            }
            else
            {
                auto damage2 = atoi(parts[3].c_str());
                player.addItem(new Sword(name, damage2, price));
            }

            
            break;
        }
    }
    


    return player;
}
