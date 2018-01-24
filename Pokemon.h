#pragma once
#include <string>
#include <map>
using namespace std;

class Pokemon {
private:
	int level;
	int exp;
	int strength;
	int agility;
	int hp;
	int stamina;
	string weakness;
	string type;
	map<string, string> ability1 = { {"name",""},{"damage",""},{"stamina",""} };
	map<string, string> ability2 = { {"name",""},{"damage",""},{"stamina",""} };
	map<string, string> ability3 = { { "name","" },{ "damage","" },{ "stamina","" } };
};