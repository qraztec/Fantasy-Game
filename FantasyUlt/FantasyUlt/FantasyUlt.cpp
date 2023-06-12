// FantasyUlt.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "DataAccess.h"
#include "Player.h"
#include "Villain.h"
#include "Item.h"
#include <iostream>
#include "Baraka.h"
#include "Arena.h"
#include <stdlib.h>
#include <chrono>
#include "Store.h"
#include <cstdlib>
#include <iostream>
#include "Kitana.h"
#include "Sub_Zero.h"
#include "Shao_Kahn.h"





int main()
{
    /*  std::cout << "Hello World!\n";
      Player play(1);
      Item* sword = new Sword("Silver Sword", 100, 40);

      play.addItem(sword);
      cout << play.getItemCount();*/
    DataAccess da("PlayerFile.txt");
    cout << "PICK NUMBER.\n1. NEW PLAYER\n2. LOAD PREVIOUS PLAYER\n";
    int gameChoice;
    cin >> gameChoice;
    Player player;

    if (gameChoice == 1)
    {
        cout << "Welcome to the Kombat Tournament. Choose a fighter to fight for Earth's freedom. \nIf you win 4 battles, Earth will stay free. If not, eternal damnation will hit Earth.\n\n";
        cout << "FIGHTERS (Pick Number of Fighter You Wish to Choose):\n";
        cout << "1. Scorpion\n";
        cout << "2. Raiden\n";
        cout << "3. Sonya Blade\n\n";
        int pick;
        cin >> pick;
        player.setPlayer(pick);
    }
    else 
    {
        Player player2 = da.LoadData();
      //  player2.charSpreadsheet();
        player.setName(player2.getName());
        player.setHP(player2.getHP());
        player.setMoney(player2.getMoney());
        player.setPower(player2.getPower());
        player.setBaseuHPStore(player2.uHPStore);
        player.setBasebHPStore(player2.bHPStore);
        
    }


    
       

        cout << "Character spreadhseet: \n";
        player.charSpreadsheet();

        cout << "Before your first battle, would you like to purchase an item from the store? (y/n) ";
        string answer;
        cin >> answer;
        Store store(player);
        while (tolower(answer[0]) == 'y')
        {
            store.displayItems();
            cout << "Which item would you like to purchase? (Press 0 to opt out)\n";
            int ans = 0;
            cin >> ans;
            if (ans == 0)
            {
                break;
            }
            store.purchase(ans);
            cout << "$ " << player.getMoney() << "\n\n";
            cout << "Would you like to purchase another item from the store? (y/n)";
            cin >> answer;

        }

        string choice;
        cout << "Would you like to view your spreadsheet? (y/n) ";
        cin >> choice;
        if (tolower(choice[0]) == 'y')
        {
            player.charSpreadsheet();
        }


        string mode = "";
        cout << "\nFirst Enemy.... Baraka!\n\n";
        cout << "Choose Difficult for Baraka: Hard or Easy\n";
        cin >> mode;



        Villain* bak = new Baraka(mode);
        //  cout << "$ " << player.getMoney() << "\n\n";
        Arena arena(player, bak);
        arena.fight();

        if (player.getHP() <= 0)
        {
            player.setHP(50);
        }
        else
        {
            player.setHP(100 + player.getArmor());
        }



        // cout << "$ " << player.getMoney() << "\n\n";

        cout << "Character spreadhseet: \n";
        player.charSpreadsheet();



        cout << "Save Data? (y/n) ";
        string sdChoice;
        cin >> sdChoice;
        if (tolower(sdChoice[0]) == 'y')
        {
            da.SaveData(player);
            cout << "\nSaved!\n\n";
            exit;

        }

        cout << "Would you like to purchase an item from the store? (y/n) ";
        // string answer;
        cin >> answer;
        //  Store store(player);
        while (tolower(answer[0]) == 'y')
        {
            store.displayItems();
            cout << "Which item would you like to purchase? (Press 0 to opt out)\n";
            int ans = 0;

            cin >> ans;
            if (ans == 0)
            {
                break;
            }
            store.purchase(ans);
            cout << "$ " << player.getMoney() << "\n\n";
            cout << "Would you like to purchase another item from the store? (y/n)";
            cin >> answer;

        }

        // string choice;
        cout << "Would you like to view your spreadsheet again? (y/n) ";
        cin >> choice;
        if (tolower(choice[0]) == 'y')
        {
            player.charSpreadsheet();
        }

        // string mode = "";
        cout << "Second Enemy.... Kitana!\n\n";
        cout << "Choose Difficult for Kitana: Hard or Easy\n";
        cin >> mode;



        Villain* kit = new Kitana(mode);
        //  cout << "$ " << player.getMoney() << "\n\n";
        Arena arena2(player, kit);
        arena2.fight();


        if (player.getHP() <= 0)
        {
            player.setHP(50);
        }
        else
        {
            player.setHP(100 + player.getArmor());
        }




        // cout << "$ " << player.getMoney() << "\n\n";

        cout << "Character spreadhseet: \n";
        player.charSpreadsheet();

        cout << "Save Data? (y/n) ";
       // string sdChoice;
        cin >> sdChoice;
        if (tolower(sdChoice[0]) == 'y')
        {
            da.SaveData(player);
            cout << "\nSaved!\n\n";
            exit;

        }

        cout << "Would you like to purchase an item from the store? (y/n) ";
        // string answer;
        cin >> answer;
        // Store store(player);
        while (tolower(answer[0]) == 'y')
        {
            store.displayItems();
            cout << "Which item would you like to purchase? (Press 0 to opt out)\n";
            int ans = 0;
            cin >> ans;
            if (ans == 0)
            {
                break;
            }
            store.purchase(ans);
            cout << "$ " << player.getMoney() << "\n\n";
            cout << "Would you like to purchase another item from the store? (y/n)";
            cin >> answer;

        }

        //string choice;
        cout << "Would you like to view your spreadsheet again? (y/n) ";
        cin >> choice;
        if (tolower(choice[0]) == 'y')
        {
            player.charSpreadsheet();
        }

        // string mode = "";
        cout << "Third Enemy.... Sub_Zero!\n\n";
        cout << "Choose Difficult for Sub_Zero: Hard or Easy\n";
        cin >> mode;
        //  Player player(1);


        Villain* sub = new Sub_Zero(mode);
        // cout << "$ " << player.getMoney() << "\n\n";
        Arena arena3(player, sub);
        arena3.fight();


        if (player.getHP() <= 0)
        {
            player.setHP(50);
        }
        else
        {
            player.setHP(100 + player.getArmor());
        }




        // cout << "$ " << player.getMoney() << "\n\n";

        cout << "Character spreadhseet: \n";
        player.charSpreadsheet();

        cout << "Save Data? (y/n) ";
       // string sdChoice;
        cin >> sdChoice;
        if (tolower(sdChoice[0]) == 'y')
        {
            da.SaveData(player);
            cout << "\nSaved!\n\n";
            exit;

        }

        cout << "Would you like to purchase an item from the store before the final boss? (y/n) ";
        // string answer;
        cin >> answer;
        //Store store(player);
        while (tolower(answer[0]) == 'y')
        {
            store.displayItems();
            cout << "Which item would you like to purchase? (Press 0 to opt out)\n";
            int ans = 0;
            cin >> ans;
            if (ans == 0)
            {
                break;
            }
            store.purchase(ans);
            cout << "$ " << player.getMoney() << "\n\n";
            cout << "Would you like to purchase another item from the store? (y/n)";
            cin >> answer;

        }

        //  string choice;
        cout << "Would you like to view your spreadsheet again? (y/n) ";
        cin >> choice;
        if (tolower(choice[0]) == 'y')
        {
            player.charSpreadsheet();
        }

        cout << "\n\nFinal Boss SHAO KAHN challenges you to a final duel for his lust to take over Earth! (Hard or Easy)\n\n";
        
        cin >> mode;

        Villain* shao = new Shao_Kahn(mode);
        //  cout << "$ " << player.getMoney() << "\n\n";
        Arena arena4(player, shao);
        arena4.fight();

        cout << "End of Tournament!\n";

        int victories = arena.getPlayerVictories();
        cout << "You have won " << victories << " battles.";
        if (victories == 4)
        {
            cout << "\nYOU HAVE WON THE KOMBAT TOURNAMENT AND SAVED EARTH FROM DOOM!";
        }
        else
        {
            cout << "\nYOU HAVE LOST THE KOMBAT TOURNAMENT AND MADE EARTH A SLAVE TO THE KOMBAT GODS!!\nYOU ARE WORTHLESS! OFF WITH YOUR HEAD!";
        }



    

    

        
    }
   
    


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
