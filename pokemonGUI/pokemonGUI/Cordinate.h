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

		int x = dest.x;
		int y = dest.y;
		stack<Node> path;
		vector<Node> usablePath;
		int i;
		cout << x << " " << y << endl;
		while (!(map[x][y].parentX == x && map[x][y].parentY == y)&&map[x][y].x!=-1&&map[x][y].y!=-1) {
			i++;
			path.push(map[x][y]);
			int tempX = map[x][y].parentX;
			int tempY = map[x][y].parentY;
			x = tempX;
			y = tempY;
			cout << x << " " << y << endl;
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


			/*
			double gNew, hNew, fNew;

			//----------- (West) ------------

			// Check if it is not an obstacle
			if (isValid(x - 1, y) == true)
			{
				//If this node is our destination
				if (isDestination(x - 1, y, dest) == true)
				{
					allMap[x - 1][y].parentX = x;
					allMap[x - 1][y].parentY = y;
					cout << allMap[x - 1][y].parentX << "--" << allMap[x - 1][y].parentY << endl;
					destinationFound = true;
					return makePath(allMap, dest);
				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x - 1][y] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x - 1, y, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x - 1][y].fCost == FLT_MAX ||
						allMap[x - 1][y].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x - 1][y].fCost = fNew;
						allMap[x - 1][y].gCost = gNew;
						allMap[x - 1][y].hCost = hNew;
						allMap[x - 1][y].parentX = x;
						allMap[x - 1][y].parentY = y;
						openList.insert(allMap[x - 1][y]);
						cout << "W ";
					}
				}
			}

			//----------- (East) ------------

			// Check if it is not an obstacle
			if (isValid(x + 1, y) == true)
			{
				//If this node is our destination
				if (isDestination(x + 1, y, dest) == true)
				{
					allMap[x + 1][y].parentX = x;
					allMap[x + 1][y].parentY = y;
					cout << allMap[x + 1][y].parentX << "--" << allMap[x + 1][y].parentY << endl;
					destinationFound = true;
					return makePath(allMap, dest);

					
				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x + 1][y] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x + 1, y, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x + 1][y].fCost == FLT_MAX ||
						allMap[x + 1][y].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x + 1][y].fCost = fNew;
						allMap[x + 1][y].gCost = gNew;
						allMap[x + 1][y].hCost = hNew;
						allMap[x + 1][y].parentX = x;
						allMap[x + 1][y].parentY = y;
						openList.insert(allMap[x + 1][y]);
						cout << "E ";
					}
				}
			}

			//----------- (South) ------------

			// Check if it is not an obstacle
			if (isValid(x, y + 1) == true)
			{
				//If this node is our destination
				if (isDestination(x, y + 1, dest) == true)
				{
					allMap[x][y + 1].parentX = x;
					allMap[x][y + 1].parentY = y;
					cout << allMap[x][y+1].parentX << "--" << allMap[x][y+1].parentY << endl;
					destinationFound = true;
					return makePath(allMap, dest);

				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x][y + 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x, y + 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x][y + 1].fCost == FLT_MAX ||
						allMap[x][y + 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x][y + 1].fCost = fNew;
						allMap[x][y + 1].gCost = gNew;
						allMap[x][y + 1].hCost = hNew;
						allMap[x][y + 1].parentX = x;
						allMap[x][y + 1].parentY = y;
						openList.insert(allMap[x][y + 1]);
						cout << "S ";
					}
				}
			}

			//----------- (North) ------------

			// Check if it is not an obstacle
			if (isValid(x, y - 1) == true)
			{
				//If this node is our destination
				if (isDestination(x, y - 1, dest) == true)
				{

					allMap[x][y - 1].parentX = x;
					allMap[x][y - 1].parentY = y;
					cout << allMap[x][y - 1].parentX << "--" << allMap[x][y - 1].parentY << endl;
					destinationFound = true;
					return makePath(allMap, dest);

				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x][y - 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x, y - 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x][y - 1].fCost == FLT_MAX ||
						allMap[x][y - 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x][y - 1].fCost = fNew;
						allMap[x][y - 1].gCost = gNew;
						allMap[x][y - 1].hCost = hNew;
						allMap[x][y - 1].parentX = x;
						allMap[x][y - 1].parentY = y;
						openList.insert(allMap[x][y - 1]);
						cout << "N ";
					}
				}
			}
			//----------- (North-West) ------------

			// Check if it is not an obstacle
			if (isValid(x - 1, y - 1) == true)
			{
				//If this node is our destination
				if (isDestination(x - 1, y - 1, dest) == true)
				{
					allMap[x - 1][y - 1].parentX = x;
					allMap[x - 1][y - 1].parentY = y;

					return makePath(allMap, dest);
				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x - 1][y - 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x - 1, y - 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x - 1][y - 1].fCost == FLT_MAX ||
						allMap[x - 1][y - 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x - 1][y - 1].fCost = fNew;
						allMap[x - 1][y - 1].gCost = gNew;
						allMap[x - 1][y - 1].hCost = hNew;
						allMap[x - 1][y - 1].parentX = x;
						allMap[x - 1][y - 1].parentY = y;
						openList.insert(allMap[x - 1][y - 1]);
						cout << "NW ";
					}
				}
			}

			//----------- (South-West) ------------

			// Check if it is not an obstacle
			if (isValid(x - 1, y + 1) == true)
			{
				//If this node is our destination
				if (isDestination(x - 1, y + 1, dest) == true)
				{
					allMap[x - 1][y + 1].parentX = x;
					allMap[x - 1][y + 1].parentY = y;

					return makePath(allMap, dest);
				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x - 1][y + 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x - 1, y + 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x - 1][y + 1].fCost == FLT_MAX ||
						allMap[x - 1][y + 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x - 1][y + 1].fCost = fNew;
						allMap[x - 1][y + 1].gCost = gNew;
						allMap[x - 1][y + 1].hCost = hNew;
						allMap[x - 1][y + 1].parentX = x;
						allMap[x - 1][y + 1].parentY = y;
						openList.insert(allMap[x - 1][y + 1]);
						cout << "SW ";
					}
				}
			}

			//----------- (North-East) ------------

			// Check if it is not an obstacle
			if (isValid(x + 1, y - 1) == true)
			{
				//If this node is our destination
				if (isDestination(x + 1, y - 1, dest) == true)
				{
					allMap[x + 1][y - 1].parentX = x;
					allMap[x + 1][y - 1].parentY = y;

					destinationFound = true;
					return makePath(allMap, dest);


				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x + 1][y - 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x + 1, y - 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x + 1][y - 1].fCost == FLT_MAX ||
						allMap[x + 1][y - 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x + 1][y - 1].fCost = fNew;
						allMap[x + 1][y - 1].gCost = gNew;
						allMap[x + 1][y - 1].hCost = hNew;
						allMap[x + 1][y - 1].parentX = x;
						allMap[x + 1][y - 1].parentY = y;
						openList.insert(allMap[x + 1][y - 1]);
						cout << "NE ";
					}
				}
			}

			//----------- (South-East) ------------

			// Check if it is not an obstacle
			if (isValid(x + 1, y + 1) == true)
			{
				//If this node is our destination
				if (isDestination(x + 1, y + 1, dest) == true)
				{
					allMap[x + 1][y + 1].parentX = x;
					allMap[x + 1][y + 1].parentY = y;

					destinationFound = true;
					return makePath(allMap, dest);


				}

				// If it is not on the closedList, so it is not in our path already
				else if (closedList[x + 1][y + 1] == false)
				{
					gNew = allMap[x][y].gCost + 1.0;
					hNew = calculateH(x + 1, y + 1, dest);
					fNew = gNew + hNew;

					// Check if this path is better than the one already present
					if (allMap[x + 1][y + 1].fCost == FLT_MAX ||
						allMap[x + 1][y + 1].fCost > fNew)
					{
						// Update the details of this cell
						allMap[x + 1][y + 1].fCost = fNew;
						allMap[x + 1][y + 1].gCost = gNew;
						allMap[x + 1][y + 1].hCost = hNew;
						allMap[x + 1][y + 1].parentX = x;
						allMap[x + 1][y + 1].parentY = y;
						openList.insert(allMap[x + 1][y]);
						cout << "SE ";
					}
				}
			} 
			*/

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