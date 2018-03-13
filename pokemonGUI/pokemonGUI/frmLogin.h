#pragma once
#include <msclr/marshal.h>
#include "Database\sqlite3.h"
#define DB "Pokemon.sqlite"
namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmLogin
	/// </summary>
	public ref class frmLogin : public System::Windows::Forms::Form
	{
	public:
		frmLogin(void)
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
		~frmLogin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtPass;
	protected:

	private: System::Windows::Forms::TextBox^  txtUser;
	protected:

	private: System::Windows::Forms::Label^  txtUserName;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnLogin;
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
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(145, 215);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(227, 22);
			this->txtPass->TabIndex = 0;
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(145, 167);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(227, 22);
			this->txtUser->TabIndex = 1;
			// 
			// txtUserName
			// 
			this->txtUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUserName->Location = System::Drawing::Point(19, 167);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(120, 22);
			this->txtUserName->TabIndex = 2;
			this->txtUserName->Text = L"User Name:";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(19, 215);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(120, 22);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Password:";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(468, 354);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(129, 59);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &frmLogin::btnLogin_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(603, 354);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(129, 59);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Create Account";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(744, 425);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->txtPass);
			this->Name = L"frmLogin";
			this->Text = L"frmLogin";
			this->Load += gcnew System::EventHandler(this, &frmLogin::frmLogin_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void frmLogin_Load(System::Object^  sender, System::EventArgs^  e) {


	}
private: System::Void btnLogin_Click(System::Object^  sender, System::EventArgs^  e) {

	String ^ userName;

	String ^ Password;
	msclr::interop::marshal_context ctx;

	//convert system string to std string for sql preparetion 
	const char * charUserName = ctx.marshal_as<const char*>(userName = txtUser->Text);
	const char * charPassword = ctx.marshal_as<const char*>(Password = txtPass->Text);





}
};
}