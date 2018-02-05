#pragma once
#include "Player.h"
#include "Fight.h"


class Game
{
private:
	Player player;
	Fight onGoingFight;
	bool enemyTurn;

public:
	Game();
	~Game();
	Game(Player& player);

	//Functions
	void enemyAttack();
	System::String^ systemString(string s);

	//Getters
	inline Player& getPlayer() { return this->player; }
	inline Fight& getFight() { return this->onGoingFight; }
	inline bool isEnemyTurn() { return this->enemyTurn; }

	//Setters
	inline void setPlayer(Player& player) { this->player = player; }
	void setNewFight(Fight& fight) { this->onGoingFight = fight; }
	inline void setEnemyTurn(bool turn) { this->enemyTurn = turn; }

};
extern Game game;
