#pragma once
#include "Game.h"


namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary for protoGUI
	/// </summary>
	public ref class protoGUI : public System::Windows::Forms::Form
	{
	public:
		protoGUI(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//---------------------------------------------------------------------------------------------------------
			updateLabels();
			//Adding Ability1 name to button
			initialize();
			
		}
		void initialize();
		void updateLabels();
		//--------------------------------------------------------------------------------------------------------------

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~protoGUI()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnAbility1;
	private: System::Windows::Forms::Button^  btnAbility2;
	private: System::Windows::Forms::Button^  btnAbility3;
	private: System::Windows::Forms::Button^  btnStaminaPotion;
	protected:

	protected:



	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ProgressBar^  pgBarPlayerHealth;
	private: System::Windows::Forms::ProgressBar^  pgBarEnemyHealth;




	private: System::Windows::Forms::Label^  labelPlayerStats;
	private: System::Windows::Forms::Label^  labelEnemyStats;
	private: System::Windows::Forms::Timer^  timerHealth;
	private: System::Windows::Forms::Button^  btnStartBattle;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnHealthPotion;

	private: System::Windows::Forms::Label^  labelHP;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ProgressBar^  pgBarPlayerStamina;

	private: System::Windows::Forms::Label^  label3;
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
			this->btnAbility1 = (gcnew System::Windows::Forms::Button());
			this->btnAbility2 = (gcnew System::Windows::Forms::Button());
			this->btnAbility3 = (gcnew System::Windows::Forms::Button());
			this->btnStaminaPotion = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pgBarPlayerHealth = (gcnew System::Windows::Forms::ProgressBar());
			this->pgBarEnemyHealth = (gcnew System::Windows::Forms::ProgressBar());
			this->labelPlayerStats = (gcnew System::Windows::Forms::Label());
			this->labelEnemyStats = (gcnew System::Windows::Forms::Label());
			this->timerHealth = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStartBattle = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnHealthPotion = (gcnew System::Windows::Forms::Button());
			this->labelHP = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pgBarPlayerStamina = (gcnew System::Windows::Forms::ProgressBar());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAbility1
			// 
			this->btnAbility1->Location = System::Drawing::Point(473, 376);
			this->btnAbility1->Name = L"btnAbility1";
			this->btnAbility1->Size = System::Drawing::Size(210, 62);
			this->btnAbility1->TabIndex = 0;
			this->btnAbility1->Text = L"button1";
			this->btnAbility1->UseVisualStyleBackColor = true;
			this->btnAbility1->Visible = false;
			this->btnAbility1->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility1_Click);
			// 
			// btnAbility2
			// 
			this->btnAbility2->Location = System::Drawing::Point(473, 448);
			this->btnAbility2->Name = L"btnAbility2";
			this->btnAbility2->Size = System::Drawing::Size(210, 62);
			this->btnAbility2->TabIndex = 1;
			this->btnAbility2->Text = L"button2";
			this->btnAbility2->UseVisualStyleBackColor = true;
			this->btnAbility2->Visible = false;
			this->btnAbility2->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility2_Click);
			// 
			// btnAbility3
			// 
			this->btnAbility3->Location = System::Drawing::Point(473, 516);
			this->btnAbility3->Name = L"btnAbility3";
			this->btnAbility3->Size = System::Drawing::Size(210, 62);
			this->btnAbility3->TabIndex = 2;
			this->btnAbility3->Text = L"button3";
			this->btnAbility3->UseVisualStyleBackColor = true;
			this->btnAbility3->Visible = false;
			this->btnAbility3->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility3_Click);
			// 
			// btnStaminaPotion
			// 
			this->btnStaminaPotion->Location = System::Drawing::Point(730, 444);
			this->btnStaminaPotion->Name = L"btnStaminaPotion";
			this->btnStaminaPotion->Size = System::Drawing::Size(192, 62);
			this->btnStaminaPotion->TabIndex = 3;
			this->btnStaminaPotion->Text = L"Use Stamina potion";
			this->btnStaminaPotion->UseVisualStyleBackColor = true;
			this->btnStaminaPotion->Visible = false;
			this->btnStaminaPotion->Click += gcnew System::EventHandler(this, &protoGUI::btnStaminaPotion_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 405);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(436, 173);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(643, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(461, 125);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// pgBarPlayerHealth
			// 
			this->pgBarPlayerHealth->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pgBarPlayerHealth->Location = System::Drawing::Point(77, 347);
			this->pgBarPlayerHealth->Name = L"pgBarPlayerHealth";
			this->pgBarPlayerHealth->Size = System::Drawing::Size(371, 23);
			this->pgBarPlayerHealth->TabIndex = 6;
			// 
			// pgBarEnemyHealth
			// 
			this->pgBarEnemyHealth->Location = System::Drawing::Point(691, 143);
			this->pgBarEnemyHealth->Name = L"pgBarEnemyHealth";
			this->pgBarEnemyHealth->Size = System::Drawing::Size(413, 23);
			this->pgBarEnemyHealth->TabIndex = 7;
			// 
			// labelPlayerStats
			// 
			this->labelPlayerStats->AutoSize = true;
			this->labelPlayerStats->Location = System::Drawing::Point(12, 169);
			this->labelPlayerStats->Name = L"labelPlayerStats";
			this->labelPlayerStats->Size = System::Drawing::Size(46, 17);
			this->labelPlayerStats->TabIndex = 8;
			this->labelPlayerStats->Text = L"label1";
			// 
			// labelEnemyStats
			// 
			this->labelEnemyStats->AutoSize = true;
			this->labelEnemyStats->Location = System::Drawing::Point(961, 169);
			this->labelEnemyStats->Name = L"labelEnemyStats";
			this->labelEnemyStats->Size = System::Drawing::Size(46, 17);
			this->labelEnemyStats->TabIndex = 9;
			this->labelEnemyStats->Text = L"label1";
			this->labelEnemyStats->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// timerHealth
			// 
			this->timerHealth->Enabled = true;
			this->timerHealth->Tick += gcnew System::EventHandler(this, &protoGUI::timerHealth_Tick);
			// 
			// btnStartBattle
			// 
			this->btnStartBattle->Location = System::Drawing::Point(473, 223);
			this->btnStartBattle->Name = L"btnStartBattle";
			this->btnStartBattle->Size = System::Drawing::Size(159, 75);
			this->btnStartBattle->TabIndex = 10;
			this->btnStartBattle->Text = L"Start Battle";
			this->btnStartBattle->UseVisualStyleBackColor = true;
			this->btnStartBattle->Click += gcnew System::EventHandler(this, &protoGUI::btnStartBattle_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(184, 119);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 11;
			this->label1->Text = L"label1";
			// 
			// btnHealthPotion
			// 
			this->btnHealthPotion->Location = System::Drawing::Point(730, 376);
			this->btnHealthPotion->Name = L"btnHealthPotion";
			this->btnHealthPotion->Size = System::Drawing::Size(192, 62);
			this->btnHealthPotion->TabIndex = 12;
			this->btnHealthPotion->Text = L"Use Health potion";
			this->btnHealthPotion->UseVisualStyleBackColor = true;
			this->btnHealthPotion->Visible = false;
			this->btnHealthPotion->Click += gcnew System::EventHandler(this, &protoGUI::btnHealthPotion_Click);
			// 
			// labelHP
			// 
			this->labelHP->AutoSize = true;
			this->labelHP->Location = System::Drawing::Point(31, 347);
			this->labelHP->Name = L"labelHP";
			this->labelHP->Size = System::Drawing::Size(27, 17);
			this->labelHP->TabIndex = 13;
			this->labelHP->Text = L"HP";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(12, 376);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(59, 17);
			this->label2->TabIndex = 15;
			this->label2->Text = L"Stamina";
			// 
			// pgBarPlayerStamina
			// 
			this->pgBarPlayerStamina->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->pgBarPlayerStamina->Location = System::Drawing::Point(77, 376);
			this->pgBarPlayerStamina->Name = L"pgBarPlayerStamina";
			this->pgBarPlayerStamina->Size = System::Drawing::Size(371, 23);
			this->pgBarPlayerStamina->TabIndex = 14;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(656, 149);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(27, 17);
			this->label3->TabIndex = 16;
			this->label3->Text = L"HP";
			// 
			// protoGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 590);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->pgBarPlayerStamina);
			this->Controls->Add(this->labelHP);
			this->Controls->Add(this->btnHealthPotion);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnStartBattle);
			this->Controls->Add(this->labelEnemyStats);
			this->Controls->Add(this->labelPlayerStats);
			this->Controls->Add(this->pgBarEnemyHealth);
			this->Controls->Add(this->pgBarPlayerHealth);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnStaminaPotion);
			this->Controls->Add(this->btnAbility3);
			this->Controls->Add(this->btnAbility2);
			this->Controls->Add(this->btnAbility1);
			this->Name = L"protoGUI";
			this->Text = L"protoGUI";
			this->Load += gcnew System::EventHandler(this, &protoGUI::protoGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void protoGUI_Load(System::Object^  sender, System::EventArgs^  e) {
		//things to happen when the program loads.



	}
			 //-----------------------------------------------------------------------------------------------------------
private: System::Void btnAbility1_Click(System::Object^  sender, System::EventArgs^  e) {
	game.getFight().useAbility1(game.getPlayer().getPokemon(), game.getFight().getEnemy());
	game.enemyAttack(); //Enemy's attack
	updateLabels();
	updatePgbar();
	
}
private: System::Void btnAbility2_Click(System::Object^  sender, System::EventArgs^  e) {
	updatePgbar();
	game.getFight().useAbility2(game.getPlayer().getPokemon(), game.getFight().getEnemy());
	game.enemyAttack(); //Enemy's attack
	updateLabels();
	updatePgbar();
}
private: System::Void btnAbility3_Click(System::Object^  sender, System::EventArgs^  e) {
	

	game.getFight().useAbility3(game.getPlayer().getPokemon(), game.getFight().getEnemy());
	game.enemyAttack(); //Enemy's attack
	updateLabels();
	updatePgbar();
}
			//-----------------------------------------------------------------------------------------------------------
private: System::Void btnStartBattle_Click(System::Object^  sender, System::EventArgs^  e) {
	this->timerHealth->Start();
	btnAbility1->Visible = true;
	btnAbility2->Visible = true;
	btnAbility3->Visible = true;
	btnHealthPotion->Visible = true;
	btnStaminaPotion->Visible = true;
	btnStartBattle->Visible = false;

}
private: System::Void timerHealth_Tick(System::Object^  sender, System::EventArgs^  e) {
	updatePgbar();
	
}
		 void updatePgbar()
		 {
			 //Pokemons health and Stamina
			 int playerMaxHealth = game.getPlayer().getPokemon().getMaxHP();
			 double playerHealth = game.getPlayer().getPokemon().getHP();
			 playerHealth = playerHealth / playerMaxHealth * 100;

			 int enemyMaxHealth = game.getFight().getEnemy().getMaxHP();
			 double enemyHealth = game.getFight().getEnemy().getHP();
			 enemyHealth = enemyHealth / enemyMaxHealth * 100;

			 //Pokemons stamina
			 int playerMaxStamina = game.getPlayer().getPokemon().getMaxStamina();
			 double playerStamina = game.getPlayer().getPokemon().getStamina();
			 playerStamina = playerStamina / playerMaxStamina * 100;



			label1->Text = Convert::ToString(playerHealth);
			pgBarEnemyHealth->Value = enemyHealth;
			pgBarPlayerHealth->Value = playerHealth;
			pgBarPlayerStamina->Value = playerStamina;


		 }

private: System::Void btnHealthPotion_Click(System::Object^  sender, System::EventArgs^  e) { //Health potion button click
	game.getFight().useHealthPotion();
	game.enemyAttack(); //Enemy's turn
	updateLabels();
	updatePgbar();
}
private: System::Void btnStaminaPotion_Click(System::Object^  sender, System::EventArgs^  e) { //Stamina potion button click
	game.getFight().useStaminaPotion();
	game.enemyAttack(); //Enemy's turn
	updateLabels();
	updatePgbar();
}
};
}
