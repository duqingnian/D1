#include "Game.h"
#include <time.h>
#include "OurWorlds.h"

Game game{ Player("You") };

Game::Game()
{
	this->player = Player();
	this->onGoingFight = Fight();
	this->enemyTurn = false;
	this->world = &World1;
}


Game::~Game()
{
}

Game::Game(Player& player) {
	this->player = player;
	this->enemyTurn = false;
	this->world = &World1;
}

string Game::enemyAttack() {
	if (this->enemyTurn) {// Only when enenmy turn is set to true
		string out;
		srand(time(NULL)); //Seed the random number generator
		int attack = rand() % 3 + 1; // attack = 0-3
		Pokemon& enemy = this->onGoingFight.getEnemy();
		Pokemon& player = this->player.getPokemon();

		if (enemy.getAbility3().getStamina() > enemy.getStamina()) { 
			//Not enough stamina for ability 3
			attack--;
			if (enemy.getAbility2().getStamina() > enemy.getStamina()) { 
				//Not enough stamina for ability 2
				attack--;
			}
		}
		switch (attack) {
		case 2:
			out = this->onGoingFight.useAbility2(enemy, player);
			break;
		case 3:
			out = this->onGoingFight.useAbility3(enemy, player);
			break;
		default:
			out = this->onGoingFight.useAbility1(enemy, player);
			break;

		}
		this->enemyTurn = false; //end enemy turn
		return out;
	}
	return "";
}

System::String^ Game::systemString(string s) {
	//For conversions from std::string to System::String^
	return gcnew System::String(s.c_str());
}
