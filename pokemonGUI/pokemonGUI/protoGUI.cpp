#include "protoGUI.h"

void pokemonGUI::protoGUI::updateLabels() {
	labelPlayerStats->Text = game.getPlayer().getPokemon().labelStats();
	labelEnemyStats->Text = game.getFight().getEnemy().labelStats();
	btnHealthPotion->Text = "Use Health Potion (" + game.getPlayer().getHealthPotions() + ")";
	btnStaminaPotion->Text = "Use Stamina Potion (" + game.getPlayer().getStaminaPotions() + ")";
}
void pokemonGUI::protoGUI::initialize() {
	string ability1 = game.getPlayer().getPokemon().getAbility1().getName();
	System::String^ s = gcnew System::String(ability1.c_str());
	btnAbility1->Text = s;
	//Adding Ability2 name to button
	string ability2 = game.getPlayer().getPokemon().getAbility2().getName();
	s = gcnew System::String(ability2.c_str());
	btnAbility2->Text = s;
	//Adding Ability3 name to button
	string ability3 = game.getPlayer().getPokemon().getAbility3().getName();
	s = gcnew System::String(ability3.c_str());
	btnAbility3->Text = s;


	pictureBox1->ImageLocation = gcnew System::String(game.getPlayer().getPokemon().getPictureFileName().c_str());
	pictureBox2->ImageLocation = gcnew System::String(game.getFight().getEnemy().getPictureFileName().c_str());

}