#pragma once
#include <msclr/marshal.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Game.h"
#include <sstream>
#include "pokeInfo.h"
#define DB "Pokemon.sqlite"
#include "Database\sqlite3.h"

namespace pokemonGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	using namespace std;
	static int callback(void *data, int argc, char **argv, char **azColName) {
		int i;
		fprintf(stderr, "%s: ", (const char*)data);

		for (i = 0; i<argc; i++) {
			printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
		}

		printf("\n");
		return 0;
	}

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

	protected:





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
	private: System::Windows::Forms::TextBox^  txtFirstName;
	private: System::Windows::Forms::TextBox^  txtLastName;
	private: System::Windows::Forms::TextBox^  txtUserName;
	private: System::Windows::Forms::TextBox^  txtEmailAddress;
	private: System::Windows::Forms::TextBox^  txtPassword;
	private: System::Windows::Forms::TextBox^  txtPasswordConf;






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
			this->txtFirstName = (gcnew System::Windows::Forms::TextBox());
			this->txtLastName = (gcnew System::Windows::Forms::TextBox());
			this->txtUserName = (gcnew System::Windows::Forms::TextBox());
			this->txtEmailAddress = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtPasswordConf = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
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
			this->lblReenterPass->Location = System::Drawing::Point(59, 270);
			this->lblReenterPass->Name = L"lblReenterPass";
			this->lblReenterPass->Size = System::Drawing::Size(133, 17);
			this->lblReenterPass->TabIndex = 9;
			this->lblReenterPass->Text = L"Re-enter Password:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(117, 242);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(73, 17);
			this->lblPassword->TabIndex = 8;
			this->lblPassword->Text = L"Password:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(147, 187);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 17);
			this->label5->TabIndex = 11;
			// 
			// lblEmailAddress
			// 
			this->lblEmailAddress->AutoSize = true;
			this->lblEmailAddress->Location = System::Drawing::Point(85, 215);
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
			this->btnConfirm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(167, 38);
			this->btnConfirm->TabIndex = 13;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &frmAddUser::btnConfirm_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(387, 462);
			this->btnCancel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(167, 38);
			this->btnCancel->TabIndex = 14;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			this->btnCancel->Click += gcnew System::EventHandler(this, &frmAddUser::btnCancel_Click);
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
			// txtFirstName
			// 
			this->txtFirstName->Location = System::Drawing::Point(199, 130);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(181, 22);
			this->txtFirstName->TabIndex = 16;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(198, 158);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(181, 22);
			this->txtLastName->TabIndex = 17;
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(198, 187);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(181, 22);
			this->txtUserName->TabIndex = 18;
			// 
			// txtEmailAddress
			// 
			this->txtEmailAddress->Location = System::Drawing::Point(199, 215);
			this->txtEmailAddress->Name = L"txtEmailAddress";
			this->txtEmailAddress->Size = System::Drawing::Size(181, 22);
			this->txtEmailAddress->TabIndex = 19;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(199, 243);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(181, 22);
			this->txtPassword->TabIndex = 20;
			// 
			// txtPasswordConf
			// 
			this->txtPasswordConf->Location = System::Drawing::Point(199, 270);
			this->txtPasswordConf->Name = L"txtPasswordConf";
			this->txtPasswordConf->Size = System::Drawing::Size(181, 22);
			this->txtPasswordConf->TabIndex = 21;
			// 
			// frmAddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(681, 577);
			this->Controls->Add(this->txtPasswordConf);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtEmailAddress);
			this->Controls->Add(this->txtUserName);
			this->Controls->Add(this->txtLastName);
			this->Controls->Add(this->txtFirstName);
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
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
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
	String ^ fName;
	String ^ lName;
	String ^ userName;
	String ^ EmailAdd;
	String ^ Password;

	msclr::interop::marshal_context ctx;

	// converts system string to char
		const char * charFName = ctx.marshal_as<const char*>(fName = txtFirstName->Text);
		const char * charLName = ctx.marshal_as<const char*>(lName = txtLastName->Text);
		const char * charEmailAdd = ctx.marshal_as<const char*>(EmailAdd = txtEmailAddress->Text);
		const char * charUserName = ctx.marshal_as<const char*>(userName = txtUserName->Text);
		const char * charPassword = ctx.marshal_as<const char*>(Password = txtPassword->Text);

		sqlite3 *dbFile;
		cout <<charUserName << endl;

		 if (!(userNameDup(dbFile, charUserName) != false || passwordPass() != true|| emptyTxt()== true)){
			 runParamSQL(dbFile, charFName, charLName, charEmailAdd, charPassword, charUserName);
			 Player p{ charUserName };
			 game.setPlayer(p);
			 pokemonGUI::pokeInfo form;
			 this->Visible = false;
			 form.ShowDialog();
		  }
}
		 bool passwordPass()
		 {
			 // checks whether database is compared 
			 if (txtPassword->Text != txtPasswordConf->Text)
			 {
				 lblPassNotCorrect->Visible = true;
				 return false;
			 }
			 return true;
		 }
		 bool connectDB(sqlite3 *dbFile, bool isOpenDB)
		 {
			 if (sqlite3_open(DB, &dbFile) == SQLITE_OK)
			 {
				 isOpenDB = true;
				 return true;
			 }
			 return false;
		 }
		 //Disconnect Database
		 void DisonnectDB(sqlite3 *dbFile, bool isOpenDB)
		 {
			 if (isOpenDB == true)
			 {
				 sqlite3_close(dbFile);
			 }
		 }
		 // Checking whether there is a database connection
		 void CheckConn(sqlite3 *dbFile, bool isOpenDB)
		 {
			 isOpenDB = false;
			 isOpenDB = connectDB(dbFile, isOpenDB);
			 if (isOpenDB)
				 cout << "Connected Successful" << endl;
			 else cout << "connection failed " << endl;
		 }
		 // A function to run parameterize query
		 void runParamSQL(sqlite3 *db, const char *fn, const char *ln, const char *emailAdd, const char * pass, const char * userName)
		 {
			 sqlite3_open(DB, &db);
			 char *zErrMsg = 0;
			 sqlite3_stmt *stmt;
			 const char *pzTest;
			 char *SQL;

			 // Insert data item into myTable
			 SQL = "insert into Player (FirstName, LastName, EmailAddress, Password, UserName) values (?,?,?,?,?)";
			
			 int rc = sqlite3_prepare(db, SQL, strlen(SQL), &stmt, &pzTest);

			 if (rc == SQLITE_OK) {
				
				 // bind the value to prevent sql injection
				 sqlite3_bind_text(stmt, 1, fn, strlen(fn), 0);
				 sqlite3_bind_text(stmt, 2, ln, strlen(ln), 0);
				 sqlite3_bind_text(stmt, 3, emailAdd, strlen(emailAdd), 0);
				 sqlite3_bind_text(stmt, 4, pass, strlen(pass), 0);
				 sqlite3_bind_text(stmt, 5, pass, strlen(pass), 0);
		
				 // commit 
				 sqlite3_step(stmt);
				 sqlite3_finalize(stmt);
			 }
		 }
		 bool emptyTxt() {
			 if (txtEmailAddress->Text == "")
			 {
				 MessageBox::Show("Email address is left blank", "Alert");
				 return true;
			 }
			 if (txtFirstName->Text == "")
			 {
				 MessageBox::Show("first name is left blank", "Alert");
				 return true;
			 }
			 if (txtLastName->Text == "")
			 {
				 MessageBox::Show("Last name is left blank", "Alert");
				 return true;
			 }
			 if (txtPassword->Text == "")
			 {
				 MessageBox::Show("Password is left blank", "Alert");
				 return true;
			 }
			 if (txtPasswordConf->Text == "")
			 {
				 MessageBox::Show("Password Confirmation is left blank", "Alert");
				 return true;
			 }
			 if (txtUserName->Text == "")
			 {
				 MessageBox::Show("User Name is left blank", "Alert");
				 return true;
			 }
			 return false;
		 }
		 bool userNameDup(sqlite3 *dbFile, const char * userName)
		 {
			 // prevent dulicate user names to be created in the database
			 sqlite3_open(DB, &dbFile);

			 char *zErrMsg = 0;
			 sqlite3_stmt *stmt;
			 const char *pzTest;
			 char * sql;

			 sql = "select count(UserName) from Player where UserName = ? ";

			cout<<  sqlite3_errmsg(dbFile);

			int rc = sqlite3_prepare(dbFile, sql, strlen(sql), &stmt, nullptr);

			 if (rc != SQLITE_OK)
			 {
				 cout << "Database could not prepeare the statement" << endl;
				 cout << sqlite3_errmsg(dbFile);
			 }

			 rc = sqlite3_bind_text(stmt, 1, userName, strlen(userName), 0);

			 if (rc != SQLITE_OK)
			 {
				 cout << "Database could not bind text to sql" << endl;
				 cout << sqlite3_errmsg(dbFile);
			 }

			 rc = sqlite3_step(stmt);

			 if (rc != SQLITE_OK)
			 {
				 cout << "Database could not execute it" << endl;
				 cout << sqlite3_errmsg(dbFile);
			 }
			 int countCheck = sqlite3_column_int(stmt, 0);

			 if (countCheck >= 1)
			 {
				 MessageBox::Show("user name has been taken", "Alert");
				 return true;
			 }
			 rc = sqlite3_finalize(stmt);

			 if (rc != SQLITE_OK)
			 {
				 cout << "Database could not clear statement";
			 }
			 return false;
		 }
private: System::Void btnCancel_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}
