#include "pch.h"
#include "CppUnitTest.h"
#include "Sub_Zero.cpp"
#include "Villain.cpp"
#include "Kitana.cpp"
#include "Baraka.cpp"
#include "Player.cpp"
#include "Item.cpp"

//Unit Tests Class


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using namespace std;

#include <cstdlib>

namespace FantasyUltTests
{
	TEST_CLASS(FantasyUltTests)
	{
	public:
		
		TEST_METHOD(TestSub_Zero)	//Tests sub zero damage
		{
			Sub_Zero sub1("Hard");
			int damage1 = sub1.attack();
			bool dam1 = false;
			
			if ((damage1 == 17) || (damage1 == 35) || (damage1 == 70))
			{
				dam1 = true;
			}

			Assert::AreEqual(true, dam1);

			Sub_Zero sub2("Easy");
			int damage2 = sub2.attack();
			bool dam2 = false;

			if ((damage2 == 5) || (damage2 == 10) || (damage2 == 20))
			{
				dam2 = true;
			}

			Assert::AreEqual(true, dam2);

			string playerName = sub2.getName();
			int playerHp = sub2.getHp();
			int playerMoney = sub2.getMoney();
			Assert::AreEqual((string)"Sub_Zero", playerName);
			Assert::AreEqual(100, playerHp);
			Assert::AreEqual(200, playerMoney);
			
		}

		TEST_METHOD(TestKitana)	//Tests kitana damage
		{
			Kitana kit1("Hard");
			int damage1 = kit1.attack();
			bool dam1 = false;

			if ((damage1 == 30) || (damage1 == 7) || (damage1 == 45))
			{
				dam1 = true;
			}

			Assert::AreEqual(true, dam1);

			Kitana kit2("Easy");
			int damage2 = kit2.attack();
			bool dam2 = false;

			if ((damage2 == 12) || (damage2 == 3) || (damage2 == 18))
			{
				dam2 = true;
			}

			Assert::AreEqual(true, dam2);

			string playerName = kit2.getName();
			int playerHp = kit2.getHp();
			int playerMoney = kit2.getMoney();
			Assert::AreEqual((string)"Kitana", playerName);
			Assert::AreEqual(90, playerHp);
			Assert::AreEqual(300, playerMoney);

		}

		TEST_METHOD(TestBaraka) //Tests baraka damage
		{
			Baraka bak1("Hard");
			int damage1 = bak1.attack();
			bool dam1 = false;

			if ((damage1 == 24) || (damage1 == 14) || (damage1 == 32) || (damage1 == 11))
			{
				dam1 = true;
			}

			Assert::AreEqual(true, dam1);

			Baraka bak2("Easy");
			int damage2 = bak2.attack();
			bool dam2 = false;

			if ((damage2 == 12) || (damage2 == 7) || (damage2 == 16) || (damage2 == 5))
			{
				dam2 = true;
			}

			Assert::AreEqual(true, dam2);

			string playerName = bak2.getName();
			int playerHp = bak2.getHp();
			int playerMoney = bak2.getMoney();
			Assert::AreEqual((string)"Baraka", playerName);
			Assert::AreEqual(110, playerHp);
			Assert::AreEqual(100, playerMoney);

		}

		TEST_METHOD(TestPlayer) //Tests player damage
		{
			Player play(1);
			int damage1 = play.attack();
			bool dam1 = false;

			if ((damage1 == 20) || (damage1 == 8) || (damage1 == 30) || (damage1 == 50))
			{
				dam1 = true;
			}

			int itemCount = play.getItemCount();

			Assert::AreEqual(true, dam1);

			string playerName = play.getName();
			int playerHp = play.getHP();
			int playerMoney = play.getMoney();
			
			Assert::AreEqual((string)"Scorpion", playerName);
			Assert::AreEqual(100, playerHp);
			Assert::AreEqual(200, playerMoney);
			Assert::AreEqual(0, itemCount);

			play.setMoney(playerMoney - 40);
			playerMoney = play.getMoney();
			Assert::AreEqual(160, playerMoney);
			
			


		}

		
	};
}
