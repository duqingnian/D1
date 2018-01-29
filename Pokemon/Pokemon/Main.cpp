#include "stdafx.h"
#include "Fight.h"
#include <fstream>


int main()
{
	int i;
	Pokemon Player;
	Player = Catter; //Assign player a pokemon


					 //Bits that draw images
	string leftLine;
	string rightLine;
	ifstream leftFile(Player.getPictureFileName());
	ifstream rightFile("Pictures/zizi.txt");
	if (leftFile.is_open() && rightFile.is_open())
	{
		while (getline(leftFile, leftLine) && getline(rightFile, rightLine))
		{
			cout << leftLine << "\t \t \t \t \t \t \t \t " << rightLine << endl;
		}
		leftFile.close();
	}

	else cout << "Unable to open file";



	Fight fight(Catter, Zizi);
	cout << fight.useAbility3(fight.getPlayer(), fight.getEnemy()) << endl;
	cout << fight.useAbility2(fight.getPlayer(), fight.getEnemy()) << endl;
	fight.getEnemy().printStats();
	cout << endl;
	fight.getPlayer().printStats();

	cin >> i;
	return 0;
}

