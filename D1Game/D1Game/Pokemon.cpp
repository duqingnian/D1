#include "Pokemon.h"

//Initialising a pokemon
Pokemon::Pokemon() {
	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->strength = 0;
	this->agility = 0;
	this->HP = 0;
	this->maxHP = 0;
	this->stamina = 0;
	this->maxStamina = 0;
	this->weakness = "";
	this->type = "";
	this->pictureFileName = "";
	this->ability1 = Ability();
	this->ability2 = Ability();
	this->ability3 = Ability();
}

Pokemon::Pokemon(string name, int level,
	int exp, int strength, int agility,
	int hp, int maxHP, int maxStamina,
	string weakness, string type,
	string pictureFileName,
	Ability ability1,
	Ability ability2,
	Ability ability3) {
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->strength = strength;
	this->agility = agility;
	this->HP = maxHP;
	this->maxHP = maxHP;
	this->stamina = maxStamina;
	this->maxStamina = maxStamina;
	this->weakness = weakness;
	this->type = type;
	this->pictureFileName = pictureFileName;
	this->ability1 = ability1;
	this->ability2 = ability2;
	this->ability3 = ability3;
}
Pokemon::~Pokemon() {

}

void Pokemon::heal(int healAmount) { //Heal back HP
	int newHP = this->HP + healAmount;
	if (newHP > maxHP) {
		this->HP = maxHP;
	}
	else {
		this->HP = newHP;
	}
}
void Pokemon::addStamina(int staminaAmount) { //Heal back HP
	int newStamina = this->stamina + staminaAmount;
	if (newStamina > maxStamina) {
		this->stamina = maxStamina;
	}
	else {
		this->stamina = newStamina;
	}
}
void Pokemon::levelUp() { //level Up
	if (this->exp >= 100) {
		this->level += 1;
		this->exp -= 100;
		this->strength += 5;
		this->agility += 5;
		this->maxHP += 10;
		this->HP = this->maxHP;
		this->maxStamina += 10;
		this->stamina = this->maxStamina;

		cout << this->name << " leveled up to level: " << this->level << endl;
	}
	else {
		cout << "Not enough XP to level up" << endl;
	}

}
void Pokemon::receiveDmg(const int dmg) { //Subtract HP
	int newHP = this->HP - dmg;
	if (newHP < 0) {
		this->HP = 0;
	}
	else {
		this->HP = newHP;
	}
}
void Pokemon::printStats() {
	cout << "Name:" << this->name << endl;
	cout << "Level:" << this->level << endl;
	cout << "Experience:" << this->exp << endl;
	cout << "Strength:" << this->strength << endl;
	cout << "Agility:" << this->agility << endl;
	cout << "HP:" << this->HP << "/" << this->maxHP << endl;
	cout << "Stamina:" << this->stamina << "/" << this->maxStamina << endl;
	cout << "Weakness:" << this->weakness << endl;
	cout << "Type:" << this->type << endl;
}