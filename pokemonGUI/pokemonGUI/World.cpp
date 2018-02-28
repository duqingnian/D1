#include "World.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

World world;

World::World()
{
	this->name = "";
	this->id = 0;
	this->spawnPoint = 51;

}
World::World(string name, int id, int spawnPoint, vector<Enemy*> enemies, vector<World*> exits) {
	this->name = name;
	this->id = id;
	this->spawnPoint = spawnPoint;
	this->enemies = enemies;
	this->exits = exits;

}

World::~World()
{
}

void World::saveWorld(string fileName) {
	ofstream worldFile;
	worldFile.open("Maps/"+fileName+".txt");
	for (Block b : world.blocks) {
		worldFile << b.id << " " << b.color.c_str() << "\n";
	}
	worldFile.close();
}
void World::loadWorld(string fileName) {
	world.blocks.clear();
	string line;
	ifstream worldFile("Maps/"+fileName+".txt");
	if (worldFile.is_open())
	{
		while (getline(worldFile, line))
		{
			Block b;
			stringstream ss(line);
			ss >> b.id;
			ss >> b.color;
			world.blocks.insert(b);
		}
		worldFile.close();
	}

	else cout << "Unable to open file";

}


