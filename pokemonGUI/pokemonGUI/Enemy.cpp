#include "Enemy.h"



Enemy::Enemy()
{
	this->name = "Test";
	this->locationBlock = 51;
	this->pokemon = Catter;
	this->pokemonName = "Catter";
	this->pictureLocation = "./Pictures/enemy.png";
	this->world = 1;
	this->alive = true;
	this->x = 20;
	this->y = 20;
	this->dragging = false;
}

Enemy::Enemy(string name, Pokemon pokemon, string pokemonName,
		int x, int y, string pictureLocation){
	this->name = name;
	this->pokemon = pokemon;
	this->pokemonName = pokemonName;
	this->x = x;
	this->y = y;
	this->pictureLocation = pictureLocation;
	this->alive = true;
	this->dragging = false;
}

Enemy::~Enemy()
{
}
