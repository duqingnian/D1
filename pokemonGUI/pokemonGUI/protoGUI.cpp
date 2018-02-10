#include "protoGUI.h"

void pokemonGUI::protoGUI::updateLabels() { //Update current status labels
	labelPlayerStats->Text = game.getPlayer().getPokemon().labelStats();
	labelEnemyStats->Text = game.getFight().getEnemy().labelStats();
	btnHealthPotion->Text = "Use Health Potion (" + game.getPlayer().getHealthPotions() + ")";
	btnStaminaPotion->Text = "Use Stamina Potion (" + game.getPlayer().getStaminaPotions() + ")";

	if (game.getPlayer().getPokemon().getHP() == 0) {
		timerEnemyTurn->Stop();
		MessageBox::Show(this, "You've lost", "BG");

		this->Close();
	}
	else if (game.getFight().getEnemy().getHP() == 0) {
		game.getPlayer().addMoney(game.getFight().MONEY_FOR_WIN); //Updated in Fight.h
		game.getPlayer().getPokemon().gainExp(game.getFight().EXPERIENCE_FOR_WIN); //Updated in Fight.h
		timerEnemyTurn->Stop();
		MessageBox::Show(this, "You've won", "GG");
		this->Close();
	}
}

void pokemonGUI::protoGUI::initialize() { //Initializing button names
	//Adding Ability1 name to button
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

void pokemonGUI::protoGUI::enemyTurn() {
	btnAbility1->Enabled = false; //grey out buttons
	btnAbility2->Enabled = false;
	btnAbility3->Enabled = false;
	btnHealthPotion->Enabled = false;
	btnStaminaPotion->Enabled = false;
	timerEnemyTurn->Start();
}