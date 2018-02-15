#include "protoGUI.h"
#include "pokeInfo.h"
#include "Game.h"
#include "frmAdventrureMap.h"
#include "frmShop.h"
#include "frmHelpFacility.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	pokemonGUI::pokeInfo form;
	Application::Run(%form);
	pokemonGUI::frmAdventrureMap map;
	Application::Run(%map);
	pokemonGUI::frmShop shop;
	Application::Run(%shop);

	pokemonGUI::frmHelpFacility help;
	Application::Run(%help);
}