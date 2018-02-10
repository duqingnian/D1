#pragma once

namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmAddUser
	/// </summary>
	public ref class frmAddUser : public System::Windows::Forms::Form
	{
	public:
		frmAddUser(void)
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
		~frmAddUser()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtFirstName;
	protected:
	private: System::Windows::Forms::TextBox^  txtEmailAddress;
	private: System::Windows::Forms::TextBox^  txtUserName;
	private: System::Windows::Forms::TextBox^  txtLastName;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::TextBox^  txtPasswordConf;
	private: System::Windows::Forms::Label^  lblFirstName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  lblReenterPass;

	private: System::Windows::Forms::Label^  lblPassword;

	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  lblEmailAddress;

	private: System::Windows::Forms::Label^  lblUserName;

	private: System::Windows::Forms::Button^  btnConfirm;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::Label^  lblPassNotCorrect;

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
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->txtEmailAddress = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtPasswordConf = (gcnew System::Windows::Forms::TextBox());
			this->lblFirstName = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->lblReenterPass = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->lblEmailAddress = (gcnew System::Windows::Forms::Label());
			this->lblUserName = (gcnew System::Windows::Forms::Label());
			this->btnConfirm = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->lblPassNotCorrect = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(197, 130);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(180, 22);
			this->txtFirstName->TabIndex = 0;
			// 
			// txtEmailAddress
			// 
			this->txtEmailAddress->Location = System::Drawing::Point(198, 215);
			this->txtEmailAddress->Name = L"txtEmailAddress";
			this->txtEmailAddress->Size = System::Drawing::Size(180, 22);
			this->txtEmailAddress->TabIndex = 1;
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(198, 187);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(180, 22);
			this->txtUserName->TabIndex = 2;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(197, 158);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(180, 22);
			this->txtLastName->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(198, 242);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(180, 22);
			this->txtPassword->TabIndex = 4;
			// 
			// txtPasswordConf
			// 
			this->txtPasswordConf->Location = System::Drawing::Point(197, 270);
			this->txtPasswordConf->Name = L"txtPasswordConf";
			this->txtPasswordConf->Size = System::Drawing::Size(180, 22);
			this->txtPasswordConf->TabIndex = 5;
			// 
			// lblFirstName
			// 
			this->lblFirstName->AutoSize = true;
			this->lblFirstName->Location = System::Drawing::Point(108, 130);
			this->lblFirstName->Name = L"lblFirstName";
			this->lblFirstName->Size = System::Drawing::Size(84, 17);
			this->lblFirstName->TabIndex = 6;
			this->lblFirstName->Text = L"First Name: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(108, 158);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(84, 17);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Last Name: ";
			// 
			// lblReenterPass
			// 
			this->lblReenterPass->AutoSize = true;
			this->lblReenterPass->Location = System::Drawing::Point(58, 270);
			this->lblReenterPass->Name = L"lblReenterPass";
			this->lblReenterPass->Size = System::Drawing::Size(133, 17);
			this->lblReenterPass->TabIndex = 9;
			this->lblReenterPass->Text = L"Re-enter Password:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(118, 243);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(73, 17);
			this->lblPassword->TabIndex = 8;
			this->lblPassword->Text = L"Password:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(146, 187);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 17);
			this->label5->TabIndex = 11;
			// 
			// lblEmailAddress
			// 
			this->lblEmailAddress->AutoSize = true;
			this->lblEmailAddress->Location = System::Drawing::Point(86, 215);
			this->lblEmailAddress->Name = L"lblEmailAddress";
			this->lblEmailAddress->Size = System::Drawing::Size(106, 17);
			this->lblEmailAddress->TabIndex = 10;
			this->lblEmailAddress->Text = L"Email Address: ";
			// 
			// lblUserName
			// 
			this->lblUserName->AutoSize = true;
			this->lblUserName->Location = System::Drawing::Point(108, 187);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(87, 17);
			this->lblUserName->TabIndex = 12;
			this->lblUserName->Text = L"User Name: ";
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(213, 462);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(167, 38);
			this->btnConfirm->TabIndex = 13;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &frmAddUser::btnConfirm_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(386, 462);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(167, 38);
			this->btnCancel->TabIndex = 14;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// lblPassNotCorrect
			// 
			this->lblPassNotCorrect->AutoSize = true;
			this->lblPassNotCorrect->ForeColor = System::Drawing::Color::Red;
			this->lblPassNotCorrect->Location = System::Drawing::Point(384, 274);
			this->lblPassNotCorrect->Name = L"lblPassNotCorrect";
			this->lblPassNotCorrect->Size = System::Drawing::Size(169, 17);
			this->lblPassNotCorrect->TabIndex = 15;
			this->lblPassNotCorrect->Text = L"Password is not the same";
			this->lblPassNotCorrect->Visible = false;
			// 
			// frmAddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(565, 512);
			this->Controls->Add(this->lblPassNotCorrect);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnConfirm);
			this->Controls->Add(this->lblUserName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->lblEmailAddress);
			this->Controls->Add(this->lblReenterPass);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->lblFirstName);
			this->Controls->Add(this->txtPasswordConf);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->txtEmailAddress);
			this->Controls->Add(this->txtFirstName);
			this->ForeColor = System::Drawing::Color::Black;
			this->Name = L"frmAddUser";
			this->Text = L"frmAddUser";
			this->Load += gcnew System::EventHandler(this, &frmAddUser::frmAddUser_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmAddUser_Load(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void btnConfirm_Click(System::Object^  sender, System::EventArgs^  e) {

	if (txtPassword->Text != txtPasswordConf->Text)
	{

		lblPassNotCorrect->Visible = true;

	}

		
	




			
}
};
}
