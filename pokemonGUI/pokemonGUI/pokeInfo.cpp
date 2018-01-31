#include "protoGUI.h"
#include "pokeInfo.h"
#include "Game.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	pokemonGUI::pokeInfo form;
	Application::Run(%form);
}