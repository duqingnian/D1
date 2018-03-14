#include "World.h"

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "OurEnemies.h"
#include "OurWorlds.h"

using namespace std;



World::World()
{
	this->name = "map1";
	this->id = 0;
	this->spawnPoint = 398;
	this->enemies = { &Enemy1, &Enemy2, &Enemy3 };
	this->pictureLocation = "./Maps/village.png";
	this->entrance = 'r';
	this->exits = {&World2};

}
World::World(string name, int id, string pictureLocation, int spawnPoint, vector<Enemy*> enemies, vector<World*> exits, char entrance) {
	this->name = name; //Also used for map name
	this->id = id; //ID
	this->spawnPoint = spawnPoint; //Where to spawn the character
	this->pictureLocation = pictureLocation; //Location of the picture
	this->enemies = enemies; //Enemies in this world
	this->exits = exits; //Worlds that are connected
	this->entrance = entrance; // l, r, t or b. Left, right, top, or bottom
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
	world.obstacles.clear();
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

	else cout << "Unable to open file" << endl;

}


