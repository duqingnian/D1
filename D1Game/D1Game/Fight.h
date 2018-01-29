#pragma once
#include <stdlib.h>
#include "OurPokemons.h"

class Fight
{
private:
	bool fighting;
	Pokemon player;
	Pokemon enemy;
public:
	Fight();
	~Fight();
	Fight(Pokemon& player, Pokemon& enemy);

	//Functions
	int useAbility1(Pokemon& dealer, Pokemon& receiver);
	int useAbility2(Pokemon& dealer, Pokemon& receiver);
	int useAbility3(Pokemon& dealer, Pokemon& receiver);
	void declareWinner(Pokemon& winner);
	void doDmg(Pokemon pokemon);
	int calculateDamage(Ability ability, Pokemon& dealer, Pokemon& receiver);

	//Getters
	inline Pokemon& getPlayer() { return this->player; }
	inline Pokemon& getEnemy() { return this->enemy; }
	inline const bool isFighting() { return this->fighting; }

	//Setters
	inline void setPlayer(Pokemon& pokemon) { this->player = pokemon; }
	inline void setEnemy(Pokemon& pokemon) { this->enemy = pokemon; }
	inline void setFighting(bool fighting) { this->fighting = fighting; }


};

