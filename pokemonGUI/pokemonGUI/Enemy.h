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
	int x, y;
	bool dragging;
	Pokemon pokemon;
	string pokemonName;
	string pictureLocation;
	int world;
	bool alive;

public:
	Enemy();
	Enemy(string name, Pokemon pokemon, string pokemonName, int x, int y, string pictureLocation);
	~Enemy();

	//Functions

	//Getters
	inline const int getLocation() { return this->locationBlock; }
	inline Pokemon& getPokemon() { return this->pokemon; }
	inline string getPictureLocation() { return this->pictureLocation; }
	inline const int& getWorld() { return this->world; }
	inline bool isAlive() { return this->alive; }
	inline string getName() { return this->name; }
	inline bool isDragging() { return this->dragging; }
	inline int getX() { return this->x; }
	inline int getY() { return this->y; }
	inline string getPokemonName() { return this->pokemonName; }

	//Setters
	inline void setLocation(int blockID) { this->locationBlock = blockID; }
	inline void setPokemon(Pokemon pokemon) { this->pokemon = pokemon; }
	inline void setPictureLocation(string location) { this->pictureLocation = location; }
	inline void setWorld(int world) { this->world = world; }
	inline void setAlive(bool alive) { this->alive = alive; }
	inline void setName(string name) { this->name = name; }
	inline void setDragging(bool drag) { this->dragging = drag; }
	inline void setX(const int x) { this->x = x; }
	inline void setY(const int y) { this->y = y; }
	inline void setPokemonName(string name) { this->pokemonName = name; }
};


#endif