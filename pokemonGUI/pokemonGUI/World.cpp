#include "World.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

World world;

World::World()
{}


World::~World()
{
}

void World::saveWorld(string fileName) {
	ofstream worldFile;
	worldFile.open(fileName+".txt");
	for (Block b : world.blocks) {
		worldFile << b.id << " " << b.color.c_str() << "\n";
	}
	worldFile.close();
}
void World::loadWorld(string fileName) {
	world.blocks.clear();
	string line;
	ifstream worldFile(fileName+".txt");
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


