#pragma once
#include "Enemy.h"
#include <set>
#include <vector>

using namespace std;

struct Block {
	std::string color;
	int id;

};

inline bool operator < (const Block& lhs, const Block& rhs)
{//We need to overload "<" to put our struct into a set
	return lhs.id < rhs.id;
}



class World
{
public:
	World();
	~World();
	World(string name, int id, int spawnPoint, vector<Enemy*> enemies, vector<World*> exits);
	vector<Enemy*> enemies;
	vector<World*> exits;
	int spawnPoint;
	string name;
	int id;


	//Used for obstacle recognition and world save/load
	set<Block> blocks;
	string colorName = "black";
	set<int> obstacles;



	static void saveWorld(std::string fileName);
	static void loadWorld(std::string fileName);

private:

};

extern World world;

