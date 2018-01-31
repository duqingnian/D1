#pragma once
#include "Player.h"
#include "Fight.h"


class Game
{
private:
	Player player;
	Fight onGoingFight;

public:
	Game();
	~Game();
	Game(Player& player);

	//Functions

	//Getters
	inline Player& getPlayer() { return this->player; }
	inline Fight& getFight() { return this->onGoingFight; }
	//Setters
	inline void setPlayer(Player& player) { this->player = player; }
	void setNewFight(Fight& fight) { this->onGoingFight = fight; }
};
extern Game game;
