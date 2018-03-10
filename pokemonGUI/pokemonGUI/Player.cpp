#include "Player.h"



Player::Player()
{
	this->name = "";
	this->money = 0;
	this->pokemon = Pokemon();
	this->healthPotions = 0;
	this->staminaPotions = 0;
	this->score = 0;
}


Player::~Player()
{
}
Player::Player(string name) {
	this->name = name;
	this->money = 100;
	this->pokemon = Pokemon();
	this->healthPotions = 3;
	this->staminaPotions = 3;
	this->score = 0;
	this->x = 100;
	this->y = 100;
}
Player::Player(string name, Pokemon pokemon, int money, int healthPotions, int staminaPotions, int score, int x, int y) {
	this->name = name;
	this->money = money;
	this->pokemon = pokemon;
	this->healthPotions = healthPotions;
	this->staminaPotions = staminaPotions;
	this->score = score;
	this->x = x;
	this->y = y;
}
