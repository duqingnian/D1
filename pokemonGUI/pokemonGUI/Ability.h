#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Ability
{
private:
	string name;
	int damage;
	int stamina;
	string soundFileName;
public:
	Ability();
	~Ability();
	Ability(string name, int damage, int stamina);

	//Getters
	inline const string& getName() const { return this->name; }
	inline const int& getDamage() const { return this->damage; }
	inline const int& getStamina() const { return this->stamina; }
	inline const string& getSoundFileName() const { return this->soundFileName; }

	//Setters
	inline void setDamage(const int damage) { this->damage = damage; }
	inline void setStamina(const int stamina) { this->stamina = stamina; }
};

