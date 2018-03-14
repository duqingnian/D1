#include "OurPokemons.h"
#include "protoGUI.h"
#include "pokeInfo.h"
#include "Game.h"
#include "frmAdventrureMap.h"
#include "frmShop.h"

using namespace System;
using namespace System::Windows::Forms;

void main() {
	


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	
	pokemonGUI::pokeInfo form;
	Application::Run(%form);


}

void pokemonGUI::pokeInfo::updateLabel() {
	if (cbPokemonSelect->SelectedIndex != -1) {
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

		pgBarPlayerHealth->Value = playerHealth;
		pgBarPlayerStamina->Value = playerStamina;
	}
}