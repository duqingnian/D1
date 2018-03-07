#ifndef ENEMY_H
#define ENEMY_H
#pragma once
#include "Pokemon.h"
#include "OurPokemons.h"
#include <string>
using namespace std;

class Enemy
{
private:
	string name;
	int locationBlock;
	Pokemon pokemon;
	string pictureLocation;
	int world;
	bool alive;

public:
	Enemy();
	~Enemy();

	//Functions

	//Getters
	inline const int getLocation() { return this->locationBlock; }
	inline Pokemon getPokemon() { return this->pokemon; }
	inline string getPictureLocation() { return this->pictureLocation; }
	inline const int& getWorld() { return this->world; }
	inline bool isAlive() { return this->alive; }
	inline string getName() { return this->name; }

	//Setters
	inline void setLocation(int blockID) { this->locationBlock = blockID; }
	inline void setPokemon(Pokemon pokemon) { this->pokemon = pokemon; }
	inline void setPictureLocation(string location) { this->pictureLocation = location; }
	inline void setWorld(int world) { this->world = world; }
	inline void setAlive(bool alive) { this->alive = alive; }
	inline void osetName(string name) { this->name = name; }
};

#endif