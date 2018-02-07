#pragma once
#include <string>
#include "Fight.h"
#include "protoGUI.h"
#include "Game.h"

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
		void updateLabel() {
			labelStats->Text = game.getPlayer().getPokemon().labelStats();
		}

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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  btnStartGame;

	protected:

	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ComboBox^  cbPokemonSelect;
	private: System::Windows::Forms::Label^  labelStats;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->btnStartGame = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->cbPokemonSelect = (gcnew System::Windows::Forms::ComboBox());
			this->labelStats = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(611, 477);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(179, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Refresh";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &pokeInfo::button1_Click);
			// 
			// btnStartGame
			// 
			this->btnStartGame->Location = System::Drawing::Point(426, 477);
			this->btnStartGame->Name = L"btnStartGame";
			this->btnStartGame->Size = System::Drawing::Size(179, 43);
			this->btnStartGame->TabIndex = 1;
			this->btnStartGame->Text = L"Start Game";
			this->btnStartGame->UseVisualStyleBackColor = true;
			this->btnStartGame->Click += gcnew System::EventHandler(this, &pokeInfo::btnStartGame_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(257, 384);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(70, 56);
			this->button4->TabIndex = 3;
			this->button4->Text = L"button4";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(146, 198);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(181, 384);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(70, 56);
			this->button3->TabIndex = 5;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// cbPokemonSelect
			// 
			this->cbPokemonSelect->FormattingEnabled = true;
			this->cbPokemonSelect->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Catter", L"Zizi", L"Pyro", L"Lemongrass",
					L"Thundershock"
			});
			this->cbPokemonSelect->Location = System::Drawing::Point(12, 240);
			this->cbPokemonSelect->Name = L"cbPokemonSelect";
			this->cbPokemonSelect->Size = System::Drawing::Size(146, 24);
			this->cbPokemonSelect->TabIndex = 6;
			this->cbPokemonSelect->Text= L"Select pokemon";
			this->cbPokemonSelect->SelectedIndexChanged += gcnew System::EventHandler(this, &pokeInfo::cbPokemonSelect_SelectedIndexChanged);
			// 
			// labelStats
			// 
			this->labelStats->Location = System::Drawing::Point(178, 12);
			this->labelStats->Name = L"labelStats";
			this->labelStats->Size = System::Drawing::Size(294, 252);
			this->labelStats->TabIndex = 7;
			this->labelStats->Click += gcnew System::EventHandler(this, &pokeInfo::label1_Click);
			// 
			// pokeInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(802, 532);
			this->Controls->Add(this->labelStats);
			this->Controls->Add(this->cbPokemonSelect);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->btnStartGame);
			this->Controls->Add(this->button1);
			this->Name = L"pokeInfo";
			this->Text = L"pokeInfo";
			this->Load += gcnew System::EventHandler(this, &pokeInfo::pokeInfo_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//--------------------------------------------------------------------------------------------------------------------------------
	private: System::Void btnStartGame_Click(System::Object^  sender, System::EventArgs^  e) { //Start Game button clicked

		if (game.getPlayer().getPokemon().getHP() > 0) {
			game.setNewFight(Fight(game.getPlayer(), Catter)); //Start a new fight
			pokemonGUI::protoGUI gui;
			gui.ShowDialog(); //Launch fight GUI
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
	}
}
		 //----------------------------------------------------------------------------------------------------------------------------
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	updateLabel();
}
private: System::Void pokeInfo_Load(System::Object^  sender, System::EventArgs^  e) {
}
};
}
