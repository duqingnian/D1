#include "Enemy.h"



Enemy::Enemy()
{
	this->name = "Test";
	this->locationBlock = 71;
	this->pokemon = Catter;
	this->pictureLocation = "Pictures/character.png";
	this->world = 1;
	this->alive = true;
}


Enemy::~Enemy()
{
}
