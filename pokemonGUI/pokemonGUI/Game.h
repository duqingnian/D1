#pragma once
#include "Player.h"
#include "Fight.h"
#include "World.h"


class Game
{
private:
	Player player;
	Fight onGoingFight;
	World* world;
	bool enemyTurn;

public:
	Game();
	~Game();
	Game(Player& player);
	

	//Functions
	string enemyAttack();
	System::String^ systemString(string s);

	//Getters
	inline Player& getPlayer() { return this->player; }
	inline Fight& getFight() { return this->onGoingFight; }
	inline bool isEnemyTurn() { return this->enemyTurn; }
	inline World* getWorld() { return this->world; }

	//Setters
	inline void setPlayer(Player& player) { this->player = player; }
	inline void setNewFight(Fight& fight) { this->onGoingFight = fight; }
	inline void setEnemyTurn(bool turn) { this->enemyTurn = turn; }
	inline void setWorld(World* world) { this->world = world; }

};
extern Game game;
