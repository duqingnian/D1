#pragma once

struct Node
{
	//properties of all class properties
	int x;
	int y;
	int gCost
		, hCost; // distance from starting node, distance from end cost and total cost
	int fCost;

};

struct PointComparatorCord
{
	bool operator()(const Node& a, const Node& b)
	{

		if (a.x == b.x && a.y == b.y) {
			return true;
		}
		else
		{
			return false;
		}
			
	}

};