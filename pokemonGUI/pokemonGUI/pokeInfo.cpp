#include "OurPokemons.h"
#include "protoGUI.h"
#include "pokeInfo.h"
#include "Game.h"
#include "frmAdventrureMap.h"
#include "frmShop.h"
#include "frmLogin.h"
#pragma comment(lib, "winmm.lib")
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#pragma comment(lib, "user32.lib")

using namespace System;
using namespace System::Windows::Forms;

void main() {
	//The MAIN function that get's executed first
	PlaySound(TEXT("Birds.wav"), NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);
	::ShowWindow(::GetConsoleWindow(), SW_HIDE); //Hide console window
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//Run Pokemon Info dialog
	pokemonGUI::frmLogin form;
	Application::Run(%form);


}

void pokemonGUI::pokeInfo::updateLabel() {
	//Updates labels, buttons, progress bars and every other piece of information
	//Displayed on this screen

	if (cbPokemonSelect->SelectedIndex != -1 && game.getPlayer().getPokemon().getName()!="") {
		//Pokemon stats
		labelStats->Text = game.getPlayer().getPokemon().labelStats();

		//Money
		labelMoney->Text = "" + game.getPlayer().getMoney();

		//Buttons
		btnHealthPotion->Text = "Use Health Potion (" + game.getPlayer().getHealthPotions() + ")";
		btnStaminaPotion->Text = "Use Stamina Potion (" + game.getPlayer().getStaminaPotions() + ")";
		btnLevelUp->Text = "Level Up (" + game.getPlayer().getPokemon().getExp() + "/100)";

		//Pokemons health
		int playerMaxHealth = game.getPlayer().getPokemon().getMaxHP();
		double playerHealth = game.getPlayer().getPokemon().getHP();
		playerHealth = playerHealth / playerMaxHealth * 100;

		//Pokemons stamina
		int playerMaxStamina = game.getPlayer().getPokemon().getMaxStamina();
		double playerStamina = game.getPlayer().getPokemon().getStamina();
		playerStamina = playerStamina / playerMaxStamina * 100;

		//Progress bars
		pgBarPlayerHealth->Value = playerHealth;
		pgBarPlayerStamina->Value = playerStamina;
	}
}