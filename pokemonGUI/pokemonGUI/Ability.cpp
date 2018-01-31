#include "Ability.h"



Ability::Ability()
{
	this->name = "";
	this->damage = 0;
	this->stamina = 0;
	this->soundFileName = "";
}


Ability::~Ability()
{
}

Ability::Ability(string name, int damage, int stamina) {
	this->name = name;
	this->damage = damage;
	this->stamina = stamina;
	this->soundFileName = "";
}
