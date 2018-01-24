// pokemonProtoMusic.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "stdafx.h"
using namespace std;
#include <Windows.h> //windows header file
#include <mmstream.h> // multimedia header file

int main()
{

	PlaySound(TEXT("poke-caterpie.wav"), NULL, SND_SYNC);
	system("pause");

    return 0;
}

