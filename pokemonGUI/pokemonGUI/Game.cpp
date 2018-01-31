#include "Game.h"

Game game{ Player("You") };

Game::Game()
{
	this->player = Player();
	this->onGoingFight = Fight();
}


Game::~Game()
{
}

Game::Game(Player& player) {
	this->player = player;
}
