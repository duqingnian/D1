#pragma once
#include <string>
#include <map>
using namespace std;
class Catterr
{
public:
	Catterr();
	~Catterr();
	int level;
	int strength = 12;
	int agility = 40;
	int hp = 90;
	int stamina = 100;
	string weakness = "water";
	string type = "earth";
	map<int, string> ability1 = { { "name","Scratch" },{ "damage","10" },{ "stamina","0" } };
	map<int, string> ability2 = { { "name","Meow" },{ "damage","25" },{ "stamina","5" } };
	map<int, string> ability3 = { { "name","Tail Whack" },{ "damage","50" },{ "stamina","35" } };
};

