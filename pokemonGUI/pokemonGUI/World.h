#pragma once
#include <set>

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

	std::set<Block> blocks;
	std::string colorName = "black";

	void saveWorld(std::string fileName);
	void loadWorld(std::string fileName);

};

extern World world;

