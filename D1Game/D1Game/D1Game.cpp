// D1Game.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fight.h"
#include <fstream>
#include <Windows.h>
#include "protoGUI.h"
#include "pokeInfo.h"



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

	

	cin >> i;
	return 0;
}

