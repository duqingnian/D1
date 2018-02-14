#pragma once
#include "OurPokemons.h"


namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmHelpFacility
	/// </summary>
	public ref class frmHelpFacility : public System::Windows::Forms::Form
	{
	public:
		frmHelpFacility(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmHelpFacility()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::ComboBox^  cbPokemonSelect;
	private: System::Windows::Forms::ComboBox^  cbPokemonLvl;
	protected:


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnBack;

	private: System::Windows::Forms::Button^  button2;

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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cbPokemonSelect = (gcnew System::Windows::Forms::ComboBox());
			this->cbPokemonLvl = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(246, 241);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// cbPokemonSelect
			// 
			this->cbPokemonSelect->FormattingEnabled = true;
			this->cbPokemonSelect->Location = System::Drawing::Point(12, 259);
			this->cbPokemonSelect->Name = L"cbPokemonSelect";
			this->cbPokemonSelect->Size = System::Drawing::Size(193, 21);
			this->cbPokemonSelect->TabIndex = 1;
			this->cbPokemonSelect->SelectedIndexChanged += gcnew System::EventHandler(this, &frmHelpFacility::cbPokemonSelect_SelectedIndexChanged);
			// 
			// cbPokemonLvl
			// 
			this->cbPokemonLvl->FormattingEnabled = true;
			this->cbPokemonLvl->Location = System::Drawing::Point(211, 259);
			this->cbPokemonLvl->Name = L"cbPokemonLvl";
			this->cbPokemonLvl->Size = System::Drawing::Size(47, 21);
			this->cbPokemonLvl->TabIndex = 2;
			this->cbPokemonLvl->SelectedIndexChanged += gcnew System::EventHandler(this, &frmHelpFacility::cbPokemonLvl_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->Location = System::Drawing::Point(264, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(240, 268);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(372, 503);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(132, 36);
			this->btnBack->TabIndex = 4;
			this->btnBack->Text = L"Back";
			this->btnBack->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(12, 335);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(193, 45);
			this->button2->TabIndex = 5;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmHelpFacility::button2_Click);
			// 
			// frmHelpFacility
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 551);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbPokemonLvl);
			this->Controls->Add(this->cbPokemonSelect);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"frmHelpFacility";
			this->Text = L"frmHelpFacility";
			this->Load += gcnew System::EventHandler(this, &frmHelpFacility::frmHelpFacility_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {


		/*ourpokemon[0].levelUp()

		for (Pokemon p : ourPokemons) {
			ourPokemon[0].labelStats
			cbPokemonSelect->Items->Add();
		}
	*/


	}
private: System::Void cbPokemonLvl_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}



private: System::Void frmHelpFacility_Load(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void cbPokemonSelect_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}
