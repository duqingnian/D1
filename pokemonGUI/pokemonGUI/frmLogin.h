#pragma once

#include <msclr/marshal.h>

#include "Database\sqlite3.h"

#define DB "Pokemon.sqlite"
#include "pokeInfo.h"
#include "frmAddUser.h"

#include "Player.h"

#include "Game.h"
#include <Windows.h>
#include <MMSystem.h>

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


		}

	protected:

		/// <summary>

		/// Clean up any resources being used.

		/// </summary>

		~frmLogin()

		{
			//PlaySound(TEXT("Birds.wav"));// , NULL, SND_SYNC);
			if (components)

			{

				delete components;

			}

		}

	private: System::Windows::Forms::TextBox^ txtPass;

	protected:

	private: System::Windows::Forms::TextBox^ txtUser;

	protected:

	private: System::Windows::Forms::Label^ txtUserName;

	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ btnLogin;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmLogin::typeid));
			this->txtPass = (gcnew System::Windows::Forms::TextBox());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtPass
			// 
			this->txtPass->Location = System::Drawing::Point(513, 379);
			this->txtPass->Margin = System::Windows::Forms::Padding(2);
			this->txtPass->Name = L"txtPass";
			this->txtPass->Size = System::Drawing::Size(171, 20);
			this->txtPass->TabIndex = 0;
			this->txtPass->UseSystemPasswordChar = true;
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(513, 318);
			this->txtUser->Margin = System::Windows::Forms::Padding(2);
			this->txtUser->Name = L"txtUser";
			this->txtUser->Size = System::Drawing::Size(171, 20);
			this->txtUser->TabIndex = 1;
			// 
			// txtUserName
			// 
			this->txtUserName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUserName->Location = System::Drawing::Point(15, 138);
			this->txtUserName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(90, 18);
			this->txtUserName->TabIndex = 2;
			this->txtUserName->Text = L"User Name:";
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(14, 175);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(90, 18);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Password:";
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(377, 423);
			this->btnLogin->Margin = System::Windows::Forms::Padding(2);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(97, 48);
			this->btnLogin->TabIndex = 4;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &frmLogin::btnLogin_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(504, 423);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 48);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Create Account";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &frmLogin::button2_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(-3, -6);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(1002, 502);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &frmLogin::pictureBox1_Click);
			// 
			// frmLogin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(999, 495);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->txtPass);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->label1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"frmLogin";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Login";
			this->Load += gcnew System::EventHandler(this, &frmLogin::frmLogin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion

	private: System::Void frmLogin_Load(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {

		sqlite3 *dbFile;

		String ^ userName;

		String ^ Password;

		msclr::interop::marshal_context ctx;

		//convert system string to std string for sql preparetion

		const char * charUserName = ctx.marshal_as<const char*>(userName = txtUser->Text);

		const char * charPassword = ctx.marshal_as<const char*>(Password = txtPass->Text);

		if (userAccept(dbFile, charUserName, charPassword) == true)

		{
			game.getPlayer().setName(charUserName);
			Player::loadPlayer();
			pokemonGUI::pokeInfo info;
			info.ShowDialog();
			
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		pokemonGUI::frmAddUser frmAddUser;
		frmAddUser.ShowDialog();
	}

			 bool userAccept(sqlite3 *dbFile, const char * userName, const char * password)
			 {
				 // prevent dulicate user names to be created in the database
				 sqlite3_open(DB, &dbFile);
				 char *zErrMsg = 0;

				 sqlite3_stmt *stmt;

				 const char *pzTest;

				 char * sql;

				 sql = "select count(UserName) from Player where UserName = ? and password = ? ;";

	

				 int rc = sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr);
				 if (rc != SQLITE_OK)
				 {

					 cout << "Database could not prepeare the statement" << endl;
				 }

				 rc = sqlite3_bind_text(stmt, 1, userName, strlen(userName), 0);

				 if (rc != SQLITE_OK)
				 {
					 cout << "Database could not bind username to sql" << endl;
				 }

				 rc = sqlite3_bind_text(stmt, 2, password, strlen(password), 0);
				 if (rc != SQLITE_OK)
				 {
					 cout << "Database could not bind password to sql" << endl;
				 }
				 rc = sqlite3_step(stmt);

				 int countCheck = sqlite3_column_int(stmt, 0);

				 if (countCheck >= 1)
				 {
					 cout << "found user" << endl;
					 return true;
				 }

				 rc = sqlite3_finalize(stmt);

				 if (rc != SQLITE_OK)
				 {
					 cout << "Database could not clear statement";
				 }

				 return false;

			 }

	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
};

}



