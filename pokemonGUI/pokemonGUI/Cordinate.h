#ifndef CORDINATE_H
#define CORDINATE_H
#pragma once
#include <stack>
#include <vector>



struct Node
{
	//properties of all class properties
	int y;
	int x;
	int parentX;
	int parentY;
	float gCost
		, hCost; // distance from starting node, distance from end cost and total cost
	float fCost;

};

inline bool operator < (const Node& lhs, const Node& rhs)
{//We need to overload "<" to put our struct into a set
	return lhs.fCost < rhs.fCost;
}


class Cordinate {
public:
	

	static bool isValid(int x, int y) { //If our Node is an obstacle it is not valid
		int id = x + y * (1000 / 20);
		if (world.obstacles.count(id) == 0) {
			if (x < 0 || y < 0) {
				return false;
			}
			return true;
		} 
		return false;
	}

	static bool isDestination(int x, int y, Node dest) {
		if (x == dest.x && y == dest.y) {
			return true;
		}
		return false;
	}

	static double calculateH(int x, int y, Node dest) {
		double H = (sqrt((x - dest.x)*(x - dest.x)
			+ (y - dest.y)*(y - dest.y)));
		return H;
	}


	static vector<Node> makePath(array<array<Node,25>,50> map, Node dest) {
		try {
			int x = dest.x;
			int y = dest.y;
			stack<Node> path;
			vector<Node> usablePath;

			
			while (!(map[x][y].parentX == x && map[x][y].parentY == y) && map[x][y].x != -1 && map[x][y].y != -1) {

				path.push(map[x][y]);
				int tempX = map[x][y].parentX;
				int tempY = map[x][y].parentY;
				x = tempX;
				y = tempY;
				
			}

			path.push(map[x][y]);

			while (!path.empty()) {
				Node top = path.top();
				path.pop();
				//cout << top.x << " " << top.y << endl;
				usablePath.emplace_back(top);
			}
			return usablePath;
		}
		catch(const exception& e){
			cout << e.what() << endl;
		}
	}


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



	static vector<Node> aStar(Node player, Node dest) {
		vector<Node> empty;
		if (isValid(dest.x, dest.y) == false) {
			cout << "Destination is an obstacle" << endl;
			return empty;
			//Destination is invalid
		}
		if (isDestination(player.x, player.y, dest)) {
			cout << "You are the destination" << endl;
			return empty;
			//You clicked on yourself
		}

		bool closedList[50][25];

		//Initialize whole map
		//Node allMap[50][25];
		array<array < Node, 25>,50> allMap;
		for (int x = 0; x < 50; x++) {
			for (int y = 0; y < 25; y++) {
				allMap[x][y].fCost = FLT_MAX;
				allMap[x][y].gCost = FLT_MAX;
				allMap[x][y].hCost = FLT_MAX;
				allMap[x][y].parentX = -1;
				allMap[x][y].parentY = -1;
				allMap[x][y].x = x;
				allMap[x][y].y = y;

				closedList[x][y] = false;
			}
		}

		//Initialize our starting list
		int x = player.x;
		int y = player.y;
		allMap[x][y].fCost = 0.0;
		allMap[x][y].gCost = 0.0;
		allMap[x][y].hCost = 0.0;
		allMap[x][y].parentX = x;
		allMap[x][y].parentY = y;

		vector<Node> openList;
		
		openList.emplace_back(allMap[x][y]);
		bool destinationFound = false;

		while (!openList.empty()) {
			Node node;
			do {
				if (openList.empty()) {
					break;
				}
				float temp = FLT_MAX;
				vector<Node>::iterator itNode;
				for (vector<Node>::iterator it = openList.begin(); it != openList.end(); it = next(it)) {
					Node n = *it;
					if (n.fCost < temp) {
						temp = n.fCost;
						itNode = it;
					}
				}
				node = *itNode;
				openList.erase(itNode);
			} while (isValid(node.x, node.y) == false);

			

			x = node.x;
			y = node.y;
			closedList[x][y] = true;


			for (int newX = -1; newX <= 1; newX++) {
				for (int newY = -1; newY <= 1; newY++) {

					double gNew, hNew, fNew;
					if (isValid(x + newX, y + newY)) {
						if (isDestination(x + newX, y + newY, dest))
						{
							allMap[x + newX][y + newY].parentX = x;
							allMap[x + newX][y + newY].parentY = y;

							destinationFound = true;
							return makePath(allMap, dest);

						}
						else if (closedList[x + newX][y + newY] == false)
						{
							gNew = node.gCost + 1.0;
							hNew = calculateH(x + newX, y + newY, dest);
							fNew = gNew + hNew;

							// Check if this path is better than the one already present
							if (allMap[x + newX][y + newY].fCost == FLT_MAX ||
								allMap[x + newX][y + newY].fCost > fNew)
							{
								// Update the details of this cell
								allMap[x + newX][y + newY].fCost = fNew;
								allMap[x + newX][y + newY].gCost = gNew;
								allMap[x + newX][y + newY].hCost = hNew;
								allMap[x + newX][y + newY].parentX = x;
								allMap[x + newX][y + newY].parentY = y;
								openList.emplace_back(allMap[x + newX][y + newY]);

							}
						}
					}
				}
			}



			}
			if (destinationFound == false) {
				cout << "Destination not found" << endl;
				return empty;

		}

	}
};
#endif