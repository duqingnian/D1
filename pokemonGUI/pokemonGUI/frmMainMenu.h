#pragma once

namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmMainMenu
	/// </summary>
	public ref class frmMainMenu : public System::Windows::Forms::Form
	{
	public:
		frmMainMenu(void)
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
		~frmMainMenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnResume;
	protected:
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::Button^  btnLoad;

	private: System::Windows::Forms::Label^  label1;

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
			this->btnResume = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->btnLoad = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// btnResume
			// 
			this->btnResume->Location = System::Drawing::Point(55, 68);
			this->btnResume->Name = L"btnResume";
			this->btnResume->Size = System::Drawing::Size(134, 39);
			this->btnResume->TabIndex = 0;
			this->btnResume->Text = L"Resume";
			this->btnResume->UseVisualStyleBackColor = true;
			this->btnResume->Click += gcnew System::EventHandler(this, &frmMainMenu::btnResume_Click);
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(55, 113);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(134, 39);
			this->btnSave->TabIndex = 0;
			this->btnSave->Text = L"Save Game";
			this->btnSave->UseVisualStyleBackColor = true;
			// 
			// btnLoad
			// 
			this->btnLoad->Location = System::Drawing::Point(55, 158);
			this->btnLoad->Name = L"btnLoad";
			this->btnLoad->Size = System::Drawing::Size(134, 39);
			this->btnLoad->TabIndex = 0;
			this->btnLoad->Text = L"Load Game";
			this->btnLoad->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(74, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(98, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Game Paused";
			// 
			// frmMainMenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(240, 243);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnLoad);
			this->Controls->Add(this->btnSave);
			this->Controls->Add(this->btnResume);
			this->Name = L"frmMainMenu";
			this->ShowIcon = false;
			this->Text = L"Main Menu";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnResume_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
};
}
