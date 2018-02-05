#pragma once
#include "Game.h"

namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
		void updateLabels() {
			labelPlayerStats->Text = game.getPlayer().getPokemon().labelStats();
			labelEnemyStats->Text = game.getFight().getEnemy().labelStats();
		}
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
	protected:

	protected:


	private: System::Windows::Forms::Button^  btnAttack4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  progressBar2;
	private: System::Windows::Forms::Label^  labelPlayerStats;
	private: System::Windows::Forms::Label^  labelEnemyStats;

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
			this->btnAbility1 = (gcnew System::Windows::Forms::Button());
			this->btnAbility2 = (gcnew System::Windows::Forms::Button());
			this->btnAbility3 = (gcnew System::Windows::Forms::Button());
			this->btnAttack4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			this->labelPlayerStats = (gcnew System::Windows::Forms::Label());
			this->labelEnemyStats = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAbility1
			// 
			this->btnAbility1->Location = System::Drawing::Point(482, 313);
			this->btnAbility1->Margin = System::Windows::Forms::Padding(2);
			this->btnAbility1->Name = L"btnAbility1";
			this->btnAbility1->Size = System::Drawing::Size(158, 50);
			this->btnAbility1->TabIndex = 0;
			this->btnAbility1->Text = L"button1";
			this->btnAbility1->UseVisualStyleBackColor = true;
			this->btnAbility1->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility1_Click);
			// 
			// btnAbility2
			// 
			this->btnAbility2->Location = System::Drawing::Point(644, 313);
			this->btnAbility2->Margin = System::Windows::Forms::Padding(2);
			this->btnAbility2->Name = L"btnAbility2";
			this->btnAbility2->Size = System::Drawing::Size(158, 50);
			this->btnAbility2->TabIndex = 1;
			this->btnAbility2->Text = L"button2";
			this->btnAbility2->UseVisualStyleBackColor = true;
			this->btnAbility2->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility2_Click);
			// 
			// btnAbility3
			// 
			this->btnAbility3->Location = System::Drawing::Point(644, 370);
			this->btnAbility3->Margin = System::Windows::Forms::Padding(2);
			this->btnAbility3->Name = L"btnAbility3";
			this->btnAbility3->Size = System::Drawing::Size(158, 50);
			this->btnAbility3->TabIndex = 2;
			this->btnAbility3->Text = L"button3";
			this->btnAbility3->UseVisualStyleBackColor = true;
			this->btnAbility3->Click += gcnew System::EventHandler(this, &protoGUI::btnAbility3_Click);
			// 
			// btnAttack4
			// 
			this->btnAttack4->Location = System::Drawing::Point(482, 370);
			this->btnAttack4->Margin = System::Windows::Forms::Padding(2);
			this->btnAttack4->Name = L"btnAttack4";
			this->btnAttack4->Size = System::Drawing::Size(158, 50);
			this->btnAttack4->TabIndex = 3;
			this->btnAttack4->Text = L"button4";
			this->btnAttack4->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(9, 313);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(327, 108);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(482, 10);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(346, 102);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(9, 289);
			this->progressBar1->Margin = System::Windows::Forms::Padding(2);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(327, 19);
			this->progressBar1->TabIndex = 6;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(482, 116);
			this->progressBar2->Margin = System::Windows::Forms::Padding(2);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(346, 19);
			this->progressBar2->TabIndex = 7;
			// 
			// labelPlayerStats
			// 
			this->labelPlayerStats->AutoSize = true;
			this->labelPlayerStats->Location = System::Drawing::Point(16, 158);
			this->labelPlayerStats->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelPlayerStats->Name = L"labelPlayerStats";
			this->labelPlayerStats->Size = System::Drawing::Size(35, 13);
			this->labelPlayerStats->TabIndex = 8;
			this->labelPlayerStats->Text = L"label1";
			// 
			// labelEnemyStats
			// 
			this->labelEnemyStats->AutoSize = true;
			this->labelEnemyStats->Location = System::Drawing::Point(721, 137);
			this->labelEnemyStats->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->labelEnemyStats->Name = L"labelEnemyStats";
			this->labelEnemyStats->Size = System::Drawing::Size(35, 13);
			this->labelEnemyStats->TabIndex = 9;
			this->labelEnemyStats->Text = L"label1";
			this->labelEnemyStats->TextAlign = System::Drawing::ContentAlignment::TopRight;
			// 
			// protoGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(837, 431);
			this->Controls->Add(this->labelEnemyStats);
			this->Controls->Add(this->labelPlayerStats);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAttack4);
			this->Controls->Add(this->btnAbility3);
			this->Controls->Add(this->btnAbility2);
			this->Controls->Add(this->btnAbility1);
			this->Margin = System::Windows::Forms::Padding(2);
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
	updateLabels();
}
private: System::Void btnAbility2_Click(System::Object^  sender, System::EventArgs^  e) {
	game.getFight().useAbility2(game.getPlayer().getPokemon(), game.getFight().getEnemy());
	updateLabels();
}
private: System::Void btnAbility3_Click(System::Object^  sender, System::EventArgs^  e) {
	game.getFight().useAbility3(game.getPlayer().getPokemon(), game.getFight().getEnemy());
	updateLabels();
}
			//-----------------------------------------------------------------------------------------------------------
};
}
