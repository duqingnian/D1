#pragma once
#include <string>
#include <map>
#include <iostream>
using namespace std;

class Pokemon {
private:
	string name;
	int level;
	int exp;
	int strength;
	int agility;
	int HP;
	int maxHP;
	int stamina;
	int maxStamina;
	string weakness;
	string type;
	string pictureFileName;
	map<string, string> ability1 = { {"name",""},{"damage",""},{"stamina",""} };
	map<string, string> ability2 = { {"name",""},{"damage",""},{"stamina",""} };
	map<string, string> ability3 = { { "name","" },{ "damage","" },{ "stamina","" } };

public:
	Pokemon();
	Pokemon(string name, int level,
		int exp, int strength, int agility,
		int hp, int maxHP, int maxStamina,
		string weakness, string type,
		string pictureFileName,
		map<string, string> ability1,
		map<string, string> ability2,
		map<string, string> ability3);
	virtual ~Pokemon();

	//Functions
	void levelUp();
	void heal(int health);
	void receiveDmg(int dmg);
	void printStats();
	
	//Getters
	inline const string& getName() const { return this->name; }
	inline const int& getLevel() const { return this->level; }
	inline const int& getExp() const { return this->exp; }
	inline const int& getStrength() const { return this->strength; }
	inline const int& getAgility() const { return this->agility; }
	inline const int& getHP() const { return this->HP; }
	inline const int& getMaxHP() const { return this->maxHP; }
	inline const int& getStamina() const { return this->stamina; }
	inline const int& getMaxStamina() const { return this->maxStamina; }
	inline const string& getWeakness() const { return this->weakness; }
	inline const string& getType() const { return this->type; }
	inline const string& getPictureFileName() const { return this->pictureFileName; }
	inline const map<string, string>& getAbility1() const { return this->ability1; }
	inline const map<string, string>& getAbility2() const { return this->ability2; }
	inline const map<string, string>& getAbility3() const { return this->ability3; }
	inline const bool isAlive() { return this->HP > 0; }

	//Setters
	inline void gainExp(const int exp) { this->exp += exp; }
	inline void changeName(string name) { this->name = name; }

};