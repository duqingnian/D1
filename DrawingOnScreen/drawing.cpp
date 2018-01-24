#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main() {
	int age;
	string leftLine;
	string rightLine;
	ifstream leftFile("cat.txt");
	ifstream rightFile("cat.txt");
	if (leftFile.is_open() && rightFile.is_open())
	{
		while (getline(leftFile, leftLine) && getline(rightFile, rightLine))
		{
			cout << leftLine << "\t \t \t \t \t \t \t \t " << rightLine << endl;
		}
		leftFile.close();
	}

	else cout << "Unable to open file";
	cin >> age;
	return 0;
}
