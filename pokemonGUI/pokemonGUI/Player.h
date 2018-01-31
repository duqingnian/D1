#pragma once
#include "OurPokemons.h"
class Player
{
private:
	string name;
	Pokemon pokemon;
	int money;
	int healthPotions;
	int staminaPotions;
	int score;

public:
	Player();
	~Player();
	Player(string name);
	Player(string name, Pokemon pokemon, int money, int healthPotions, int staminaPotions, int score);

	//Functions

	//Getters
	inline const string& getName() const { return this->name; }
	inline Pokemon& getPokemon() { return this->pokemon; }
	inline const int& getMoney() const { return this->money; }
	inline const int& getHealthPotions() const { return this->healthPotions; }
	inline const int& getStaminaPotions() const { return this->staminaPotions; }
	inline const int& getScore() const { return this->score; }

	//Setters
	inline void setPokemon(Pokemon pokemon) { this->pokemon = pokemon; }
	inline void setName(string name) { this->name = name; }
	inline void addMoney(int amount) { this->money += amount; }
	inline void removeMoney(int amount) { this->money -= amount; }
	inline void addHealthPotion() { this->healthPotions += 1; }
	inline void removeHealthPotion() { this->healthPotions -= 1; }
	inline void addStaminaPotion() { this->staminaPotions += 1; }
	inline void removeStaminaPotion() { this->staminaPotions -= 1; }
	inline void addScore(int score) { this->score += score; }

};

