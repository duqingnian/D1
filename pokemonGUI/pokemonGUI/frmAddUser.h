#pragma once
//#include "Database.h"
//#include "Database\sqlite3.h"
#include <msclr/marshal.h>
#include <iostream>
//#include"pokeInfo.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
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
	//void sqlExecute(const char *sql)
	//{
	//	bool isOpenDB = false;
	//	sqlite3 *dbFile;
	//	char *zErrMsg = 0;
	//	int rc;

	//	//sql = "SELECT * from ability";
	//	const char* data = "Callback function called";

	//	if (sqlite3_open(DB, &dbFile) == SQLITE_OK)
	//	{

	//		rc = sqlite3_exec(dbFile, sql, callback, (void*)data, &zErrMsg);

	//	}
	//	else
	//	{
	//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
	//		sqlite3_free(zErrMsg);
	//	}
	//	sqlite3_close(dbFile);

	//}

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
			this->txtFirstName->Location = System::Drawing::Point(148, 106);
			this->txtFirstName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtFirstName->Name = L"txtFirstName";
			this->txtFirstName->Size = System::Drawing::Size(136, 20);
			this->txtFirstName->TabIndex = 0;
			// 
			// txtEmailAddress
			// 
			this->txtEmailAddress->Location = System::Drawing::Point(148, 175);
			this->txtEmailAddress->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtEmailAddress->Name = L"txtEmailAddress";
			this->txtEmailAddress->Size = System::Drawing::Size(136, 20);
			this->txtEmailAddress->TabIndex = 1;
			// 
			// txtUserName
			// 
			this->txtUserName->Location = System::Drawing::Point(148, 152);
			this->txtUserName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtUserName->Name = L"txtUserName";
			this->txtUserName->Size = System::Drawing::Size(136, 20);
			this->txtUserName->TabIndex = 2;
			// 
			// txtLastName
			// 
			this->txtLastName->Location = System::Drawing::Point(148, 128);
			this->txtLastName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtLastName->Name = L"txtLastName";
			this->txtLastName->Size = System::Drawing::Size(136, 20);
			this->txtLastName->TabIndex = 3;
			// 
			// txtPassword
			// 
			this->txtPassword->Location = System::Drawing::Point(148, 197);
			this->txtPassword->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(136, 20);
			this->txtPassword->TabIndex = 4;
			this->txtPassword->UseSystemPasswordChar = true;
			// 
			// txtPasswordConf
			// 
			this->txtPasswordConf->Location = System::Drawing::Point(148, 219);
			this->txtPasswordConf->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->txtPasswordConf->Name = L"txtPasswordConf";
			this->txtPasswordConf->PasswordChar = '*';
			this->txtPasswordConf->Size = System::Drawing::Size(136, 20);
			this->txtPasswordConf->TabIndex = 5;
			this->txtPasswordConf->UseSystemPasswordChar = true;
			// 
			// lblFirstName
			// 
			this->lblFirstName->AutoSize = true;
			this->lblFirstName->Location = System::Drawing::Point(81, 106);
			this->lblFirstName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblFirstName->Name = L"lblFirstName";
			this->lblFirstName->Size = System::Drawing::Size(63, 13);
			this->lblFirstName->TabIndex = 6;
			this->lblFirstName->Text = L"First Name: ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(81, 128);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(64, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Last Name: ";
			// 
			// lblReenterPass
			// 
			this->lblReenterPass->AutoSize = true;
			this->lblReenterPass->Location = System::Drawing::Point(44, 219);
			this->lblReenterPass->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblReenterPass->Name = L"lblReenterPass";
			this->lblReenterPass->Size = System::Drawing::Size(100, 13);
			this->lblReenterPass->TabIndex = 9;
			this->lblReenterPass->Text = L"Re-enter Password:";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Location = System::Drawing::Point(88, 197);
			this->lblPassword->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(56, 13);
			this->lblPassword->TabIndex = 8;
			this->lblPassword->Text = L"Password:";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(110, 152);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 13);
			this->label5->TabIndex = 11;
			// 
			// lblEmailAddress
			// 
			this->lblEmailAddress->AutoSize = true;
			this->lblEmailAddress->Location = System::Drawing::Point(64, 175);
			this->lblEmailAddress->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblEmailAddress->Name = L"lblEmailAddress";
			this->lblEmailAddress->Size = System::Drawing::Size(79, 13);
			this->lblEmailAddress->TabIndex = 10;
			this->lblEmailAddress->Text = L"Email Address: ";
			// 
			// lblUserName
			// 
			this->lblUserName->AutoSize = true;
			this->lblUserName->Location = System::Drawing::Point(81, 152);
			this->lblUserName->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblUserName->Name = L"lblUserName";
			this->lblUserName->Size = System::Drawing::Size(66, 13);
			this->lblUserName->TabIndex = 12;
			this->lblUserName->Text = L"User Name: ";
			// 
			// btnConfirm
			// 
			this->btnConfirm->Location = System::Drawing::Point(160, 375);
			this->btnConfirm->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnConfirm->Name = L"btnConfirm";
			this->btnConfirm->Size = System::Drawing::Size(125, 31);
			this->btnConfirm->TabIndex = 13;
			this->btnConfirm->Text = L"Confirm";
			this->btnConfirm->UseVisualStyleBackColor = true;
			this->btnConfirm->Click += gcnew System::EventHandler(this, &frmAddUser::btnConfirm_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(290, 375);
			this->btnCancel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(125, 31);
			this->btnCancel->TabIndex = 14;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// lblPassNotCorrect
			// 
			this->lblPassNotCorrect->AutoSize = true;
			this->lblPassNotCorrect->ForeColor = System::Drawing::Color::Red;
			this->lblPassNotCorrect->Location = System::Drawing::Point(288, 223);
			this->lblPassNotCorrect->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->lblPassNotCorrect->Name = L"lblPassNotCorrect";
			this->lblPassNotCorrect->Size = System::Drawing::Size(127, 13);
			this->lblPassNotCorrect->TabIndex = 15;
			this->lblPassNotCorrect->Text = L"Password is not the same";
			this->lblPassNotCorrect->Visible = false;
			// 
			// frmAddUser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(511, 469);
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
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
		const char * charFName = ctx.marshal_as<const char*>(fName = txtFirstName->Text);
		const char * charLName = ctx.marshal_as<const char*>(lName = txtLastName->Text);
		const char * charEmailAdd = ctx.marshal_as<const char*>(EmailAdd = txtEmailAddress->Text);
		const char * charUserName = ctx.marshal_as<const char*>(userName = txtUserName->Text);
		const char * charPassword = ctx.marshal_as<const char*>(Password = txtPassword->Text);

		sqlite3 *dbFile;

		string str;
		char *zErrMsg = 0;
		sqlite3_stmt *stmt;
		const char *pzTest;
		char *szSQL;
		char *fn = "power";

		sqlite3_open(DB, &dbFile);
		//runParamSQL(dbFile, strFName, strlen, strEmailAdd, strPass);
		runParamSQL(dbFile,charFName,charLName, charEmailAdd, charPassword);
		
	
			
}
		 bool passwordPass()
		 {
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

		 void DisonnectDB(sqlite3 *dbFile, bool isOpenDB)
		 {
			 if (isOpenDB == true)
			 {
				 sqlite3_close(dbFile);
			 }
		 }

		 void CheckConn(sqlite3 *dbFile, bool isOpenDB)
		 {
			 isOpenDB = false;
			 isOpenDB = connectDB(dbFile, isOpenDB);
			 if (isOpenDB)
				 cout << "Connected Successful" << endl;
			 else cout << "connection failed " << endl;
		 }
		 // A function to run parameterize query
		 void runParamSQL(sqlite3 *db, const char *fn, const char *ln, const char *emailAdd, const char * pass)
		 {
			 

			 char *zErrMsg = 0;
			 sqlite3_stmt *stmt;
			 const char *pzTest;
			 char *szSQL;

			 // Insert data item into myTable
			 szSQL = "insert into Player (FirstName, LastName, EmailAddress, Password) values (?,?,?,?)";
			
			 int rc = sqlite3_prepare(db, szSQL, strlen(szSQL), &stmt, &pzTest);

			 if (rc == SQLITE_OK) {
				
				 // bind the value 
				 sqlite3_bind_text(stmt, 1, fn, strlen(fn), 0);
				 sqlite3_bind_text(stmt, 2, ln, strlen(ln), 0);
				 sqlite3_bind_text(stmt, 3, emailAdd, strlen(emailAdd), 0);
				 sqlite3_bind_text(stmt, 4, pass, strlen(pass), 0);
		

				 // commit 
				 sqlite3_step(stmt);
				 sqlite3_finalize(stmt);

				 sqlite3_close(db);

			 }
		 }
};
}
