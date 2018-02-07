#include "Game.h"
#include <time.h>

Game game{ Player("You") };

Game::Game()
{
	this->player = Player();
	this->onGoingFight = Fight();
	this->enemyTurn = false;
}


Game::~Game()
{
}

Game::Game(Player& player) {
	this->player = player;
	this->enemyTurn = false;
}

void Game::enemyAttack() {
	if (this->enemyTurn) {// Only when enenmy turn is set to true
		//System::Threading::Thread::Sleep(2000);
		srand(time(NULL));
		int attack = rand() % 3 + 1; // attack = 0-3
		Pokemon& enemy = this->onGoingFight.getEnemy();
		Pokemon& player = this->player.getPokemon();
		if (enemy.getAbility3().getStamina() > enemy.getStamina()) { //Not enough stamina for ability 3
			attack--;
			if (enemy.getAbility2().getStamina() > enemy.getStamina()) { //Not enough stamina for ability 2
				attack--;
			}
		}
		switch (attack) {
		case 2:
			cout << this->onGoingFight.useAbility2(enemy, player) << endl;
			break;
		case 3:
			cout << this->onGoingFight.useAbility3(enemy, player) << endl;
			break;
		default:
			cout << this->onGoingFight.useAbility1(enemy, player) << endl;
			break;

		}
		this->enemyTurn = false; //end enemy turn
	}
}

System::String^ Game::systemString(string s) {
	return gcnew System::String(s.c_str());
}
