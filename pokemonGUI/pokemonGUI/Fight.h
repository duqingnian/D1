#ifndef FIGHT_H
#define FIGHT_H
#pragma once
#include <stdlib.h>
#include "OurPokemons.h"
#include "Player.h"
#include "Enemy.h"

class Fight
{
private:
	bool fighting;
	Player *player;
	Pokemon *pokemon;
	Pokemon *enemy;
	Enemy *enemyCharacter;

public:
	Fight();
	~Fight();
	Fight(Player* player, Enemy* enemy);


	int MONEY_FOR_WIN = 50;
	int EXPERIENCE_FOR_WIN = 30;
	int POTION_HEAL_AMOUNT = 50;

	//Functions
	string useAbility1(Pokemon& dealer, Pokemon& receiver);
	string useAbility2(Pokemon& dealer, Pokemon& receiver);
	string useAbility3(Pokemon& dealer, Pokemon& receiver);
	string declareWinner(Pokemon& winner);
	int calculateDamage(Ability ability, Pokemon& dealer, Pokemon& receiver);
	string useHealthPotion();
	string useStaminaPotion();

	//Getters
	inline Player& getPlayer() { return *this->player; }
	inline Pokemon& getPokemon() { return this->player->getPokemon(); }
	inline Pokemon& getEnemy() { return *this->enemy; }
	inline Enemy& getEnemyCharacte() { return *this->enemyCharacter; }
	inline bool isFighting() { return this->fighting; }

	//Setters
	inline void setPokemon(Pokemon& pokemon) { this->pokemon = &pokemon; }
	inline void setPlayer(Player& pokemon) { this->player = player; }
	inline void setEnemy(Pokemon pokemon) { this->enemy = &pokemon; }
	inline void setFighting(bool fighting) { this->fighting = fighting; }
	inline void setEnemyCharacter(Enemy character) { this->enemyCharacter = &character; }


};

#endif