#pragma once
#include <string>
#include "Fight.h"
#include "protoGUI.h"
#include "Game.h"
#include "frmAddUser.h"
#include "frmMainMenu.h"
#include "frmShop.h"
#include "frmAdventrureMap.h"

namespace pokemonGUI {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for pokeInfo
	/// </summary>
	public ref class pokeInfo : public System::Windows::Forms::Form
	{

	public:
		pokeInfo(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: void updateLabel();

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~pokeInfo()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnSaveGame;
	protected:

	private: System::Windows::Forms::Button^  btnStartGame;

	protected:


	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btnShop;

	private: System::Windows::Forms::ComboBox^  cbPokemonSelect;
	private: System::Windows::Forms::Label^  labelStats;
	private: System::Windows::Forms::Timer^  timerRefresh;
	private: System::Windows::Forms::ProgressBar^  pgBarPlayerHealth;
	private: System::Windows::Forms::ProgressBar^  pgBarPlayerStamina;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnHealthPotion;
	private: System::Windows::Forms::Button^  btnStaminaPotion;
	private: System::Windows::Forms::Button^  btnLoadGame;
	private: System::Windows::Forms::Label^  labelMoney;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  btnLevelUp;

	private: System::ComponentModel::IContainer^  components;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->btnSaveGame = (gcnew System::Windows::Forms::Button());
			this->btnStartGame = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnShop = (gcnew System::Windows::Forms::Button());
			this->cbPokemonSelect = (gcnew System::Windows::Forms::ComboBox());
			this->labelStats = (gcnew System::Windows::Forms::Label());
			this->timerRefresh = (gcnew System::Windows::Forms::Timer(this->components));
			this->pgBarPlayerHealth = (gcnew System::Windows::Forms::ProgressBar());
			this->pgBarPlayerStamina = (gcnew System::Windows::Forms::ProgressBar());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnHealthPotion = (gcnew System::Windows::Forms::Button());
			this->btnStaminaPotion = (gcnew System::Windows::Forms::Button());
			this->btnLoadGame = (gcnew System::Windows::Forms::Button());
			this->labelMoney = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->btnLevelUp = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// btnSaveGame
			// 
			this->btnSaveGame->Location = System::Drawing::Point(12, 367);
			this->btnSaveGame->Name = L"btnSaveGame";
			this->btnSaveGame->Size = System::Drawing::Size(146, 43);
			this->btnSaveGame->TabIndex = 0;
			this->btnSaveGame->Text = L"Save Game";
			this->btnSaveGame->UseVisualStyleBackColor = true;
			this->btnSaveGame->Click += gcnew System::EventHandler(this, &pokeInfo::button1_Click);
			// 
			// btnStartGame
			// 
			this->btnStartGame->Location = System::Drawing::Point(566, 377);
			this->btnStartGame->Name = L"btnStartGame";
			this->btnStartGame->Size = System::Drawing::Size(224, 82);
			this->btnStartGame->TabIndex = 1;
			this->btnStartGame->Text = L"Start Game";
			this->btnStartGame->UseVisualStyleBackColor = true;
			this->btnStartGame->Click += gcnew System::EventHandler(this, &pokeInfo::btnStartGame_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(201, 147);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(359, 242);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// btnShop
			// 
			this->btnShop->Location = System::Drawing::Point(12, 295);
			this->btnShop->Name = L"btnShop";
			this->btnShop->Size = System::Drawing::Size(146, 56);
			this->btnShop->TabIndex = 5;
			this->btnShop->Text = L"Shop";
			this->btnShop->UseVisualStyleBackColor = true;
			this->btnShop->Click += gcnew System::EventHandler(this, &pokeInfo::btnShop_Click);
			// 
			// cbPokemonSelect
			// 
			this->cbPokemonSelect->FormattingEnabled = true;
			this->cbPokemonSelect->Items->AddRange(gcnew cli::array< System::Object^  >(13) {
				L"Catter", L"Zizi", L"Pyro", L"Lemongrass",
					L"Thundershock", L"Wail", L"Blaze", L"Flyff", L"Jolt", L"Treehouse", L"Deeria", L"Hydros", L"Flop"
			});
			this->cbPokemonSelect->Location = System::Drawing::Point(12, 240);
			this->cbPokemonSelect->Name = L"cbPokemonSelect";
			this->cbPokemonSelect->Size = System::Drawing::Size(146, 24);
			this->cbPokemonSelect->TabIndex = 6;
			this->cbPokemonSelect->Text = L"Select pokemon";
			this->cbPokemonSelect->SelectedIndexChanged += gcnew System::EventHandler(this, &pokeInfo::cbPokemonSelect_SelectedIndexChanged);
			// 
			// labelStats
			// 
			this->labelStats->Location = System::Drawing::Point(36, 28);
			this->labelStats->Name = L"labelStats";
			this->labelStats->Size = System::Drawing::Size(183, 194);
			this->labelStats->TabIndex = 7;
			this->labelStats->Click += gcnew System::EventHandler(this, &pokeInfo::label1_Click);
			// 
			// timerRefresh
			// 
			this->timerRefresh->Interval = 1500;
			this->timerRefresh->Tick += gcnew System::EventHandler(this, &pokeInfo::timerRefresh_Tick);
			// 
			// pgBarPlayerHealth
			// 
			this->pgBarPlayerHealth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pgBarPlayerHealth->Location = System::Drawing::Point(399, 37);
			this->pgBarPlayerHealth->Name = L"pgBarPlayerHealth";
			this->pgBarPlayerHealth->Size = System::Drawing::Size(371, 23);
			this->pgBarPlayerHealth->TabIndex = 8;
			// 
			// pgBarPlayerStamina
			// 
			this->pgBarPlayerStamina->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pgBarPlayerStamina->Location = System::Drawing::Point(399, 66);
			this->pgBarPlayerStamina->Name = L"pgBarPlayerStamina";
			this->pgBarPlayerStamina->Size = System::Drawing::Size(371, 23);
			this->pgBarPlayerStamina->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(366, 43);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(27, 17);
			this->label1->TabIndex = 16;
			this->label1->Text = L"HP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(334, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Stamina";
			// 
			// btnHealthPotion
			// 
			this->btnHealthPotion->Location = System::Drawing::Point(399, 97);
			this->btnHealthPotion->Name = L"btnHealthPotion";
			this->btnHealthPotion->Size = System::Drawing::Size(188, 44);
			this->btnHealthPotion->TabIndex = 17;
			this->btnHealthPotion->Text = L"Use Health potion";
			this->btnHealthPotion->UseVisualStyleBackColor = true;
			this->btnHealthPotion->Click += gcnew System::EventHandler(this, &pokeInfo::btnHealthPotion_Click);
			// 
			// btnStaminaPotion
			// 
			this->btnStaminaPotion->Location = System::Drawing::Point(593, 97);
			this->btnStaminaPotion->Name = L"btnStaminaPotion";
			this->btnStaminaPotion->Size = System::Drawing::Size(177, 44);
			this->btnStaminaPotion->TabIndex = 18;
			this->btnStaminaPotion->Text = L"Use Stamina potion";
			this->btnStaminaPotion->UseVisualStyleBackColor = true;
			this->btnStaminaPotion->Click += gcnew System::EventHandler(this, &pokeInfo::btnStaminaPotion_Click);
			// 
			// btnLoadGame
			// 
			this->btnLoadGame->Location = System::Drawing::Point(12, 416);
			this->btnLoadGame->Name = L"btnLoadGame";
			this->btnLoadGame->Size = System::Drawing::Size(146, 43);
			this->btnLoadGame->TabIndex = 5;
			this->btnLoadGame->Text = L"Load Game";
			this->btnLoadGame->UseVisualStyleBackColor = true;
			// 
			// labelMoney
			// 
			this->labelMoney->AutoSize = true;
			this->labelMoney->Location = System::Drawing::Point(652, 243);
			this->labelMoney->Name = L"labelMoney";
			this->labelMoney->Size = System::Drawing::Size(32, 17);
			this->labelMoney->TabIndex = 16;
			this->labelMoney->Text = L"000";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(590, 243);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 17);
			this->label4->TabIndex = 16;
			this->label4->Text = L"Money: £";
			// 
			// btnLevelUp
			// 
			this->btnLevelUp->Location = System::Drawing::Point(201, 416);
			this->btnLevelUp->Name = L"btnLevelUp";
			this->btnLevelUp->Size = System::Drawing::Size(143, 44);
			this->btnLevelUp->TabIndex = 19;
			this->btnLevelUp->Text = L"Level Up (0/100)";
			this->btnLevelUp->UseVisualStyleBackColor = true;
			this->btnLevelUp->Click += gcnew System::EventHandler(this, &pokeInfo::btnLevelUp_Click);
			// 
			// pokeInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 472);
			this->Controls->Add(this->btnLevelUp);
			this->Controls->Add(this->btnStaminaPotion);
			this->Controls->Add(this->btnHealthPotion);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->labelMoney);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pgBarPlayerStamina);
			this->Controls->Add(this->pgBarPlayerHealth);
			this->Controls->Add(this->labelStats);
			this->Controls->Add(this->cbPokemonSelect);
			this->Controls->Add(this->btnLoadGame);
			this->Controls->Add(this->btnShop);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnStartGame);
			this->Controls->Add(this->btnSaveGame);
			this->Name = L"pokeInfo";
			this->Text = L"pokeInfo";
			this->Load += gcnew System::EventHandler(this, &pokeInfo::pokeInfo_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &pokeInfo::pokeInfo_KeyDown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//--------------------------------------------------------------------------------------------------------------------------------
	private: System::Void btnStartGame_Click(System::Object^  sender, System::EventArgs^  e) { //Start Game button clicked

		timerRefresh->Start();

		if (cbPokemonSelect->SelectedIndex == -1)
		{
			MessageBox::Show("Select a Pokemon", "Alert");
		}
		else
		{
			cbPokemonSelect->Enabled = false;
			btnStartGame->Text = "Continue";
			pokemonGUI::frmAdventrureMap mapGui;
			mapGui.ShowDialog(); //Launch fight GUI
		}
		
	}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void cbPokemonSelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) { //Pokemon selection made
	if (cbPokemonSelect->Text == "Catter") {
		labelStats->Text = Catter.labelStats();
		game.getPlayer().setPokemon(Catter);
	} else 	if (cbPokemonSelect->Text == "Zizi") {
		labelStats->Text = Zizi.labelStats();
		game.getPlayer().setPokemon(Zizi);
	} else 	if (cbPokemonSelect->Text == "Pyro") {
		labelStats->Text = Pyro.labelStats();
		game.getPlayer().setPokemon(Pyro);
	} else 	if (cbPokemonSelect->Text == "Lemongrass") {
		labelStats->Text = Lemongrass.labelStats();
		game.getPlayer().setPokemon(Lemongrass);
	} else 	if (cbPokemonSelect->Text == "Thundershock") {
		labelStats->Text = Thundershock.labelStats();
		game.getPlayer().setPokemon(Thundershock);
	} else if (cbPokemonSelect->Text == "Wail") {
		labelStats->Text = Wail.labelStats();
		game.getPlayer().setPokemon(Wail);
	} else if (cbPokemonSelect->Text == "Blaze") {
		labelStats->Text = Blaze.labelStats();
		game.getPlayer().setPokemon(Blaze);
	}
	else if (cbPokemonSelect->Text == "Flyff") {
		labelStats->Text = Flyff.labelStats();
		game.getPlayer().setPokemon(Flyff);
	}
	else if (cbPokemonSelect->Text == "Jolt") {
		labelStats->Text = Jolt.labelStats();
		game.getPlayer().setPokemon(Jolt);
	}
	else if (cbPokemonSelect->Text == "Treehouse") {
		labelStats->Text = Treehouse.labelStats();
		game.getPlayer().setPokemon(Treehouse);
	}
	else if (cbPokemonSelect->Text == "Deeria") {
		labelStats->Text = Deeria.labelStats();
		game.getPlayer().setPokemon(Deeria);
	}
	else if (cbPokemonSelect->Text == "Hydros") {
		labelStats->Text = Hydros.labelStats();
		game.getPlayer().setPokemon(Hydros);
	}
	else if (cbPokemonSelect->Text == "Flop") {
		labelStats->Text = Flop.labelStats();
		game.getPlayer().setPokemon(Flop);
	}
	updateLabel();
	pictureBox1->ImageLocation = gcnew System::String(game.getPlayer().getPokemon().getPictureFileName().c_str());
}
		 //----------------------------------------------------------------------------------------------------------------------------
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	pokemonGUI::frmAddUser frmAddUser;
	frmAddUser.ShowDialog(); //Launch fight GUI
}
private: System::Void pokeInfo_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pokeInfo_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	if (e->KeyCode == Keys::Escape) {
		pokemonGUI::frmMainMenu mainMenu;
		mainMenu.ShowDialog(); //Launch Main Menu
	}
}
private: System::Void timerRefresh_Tick(System::Object^  sender, System::EventArgs^  e) {
	updateLabel();
}
private: System::Void btnShop_Click(System::Object^  sender, System::EventArgs^  e) {
	pokemonGUI::frmShop shop;
	shop.ShowDialog(); //Launch Shop
	updateLabel();
}
private: System::Void btnHealthPotion_Click(System::Object^  sender, System::EventArgs^  e) {
	if (cbPokemonSelect->SelectedIndex != -1) { //Use health potion
		if (game.getPlayer().getHealthPotions() > 0) {
			game.getPlayer().getPokemon().heal(50);
			game.getPlayer().removeHealthPotion();
			updateLabel();
		}
	}
}
private: System::Void btnStaminaPotion_Click(System::Object^  sender, System::EventArgs^  e) {
	if (cbPokemonSelect->SelectedIndex != -1) { //Use stamina potion
		if (game.getPlayer().getStaminaPotions() > 0) {
			game.getPlayer().getPokemon().addStamina(50);
			game.getPlayer().removeStaminaPotion();
			updateLabel();
		}
	}
}
private: System::Void btnLevelUp_Click(System::Object^  sender, System::EventArgs^  e) {
	game.getPlayer().getPokemon().levelUp();
	updateLabel();
}
};
}
