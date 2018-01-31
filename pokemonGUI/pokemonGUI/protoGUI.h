#pragma once

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
			//
		}

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
	private: System::Windows::Forms::Button^  btnAttack1;
	protected:
	private: System::Windows::Forms::Button^  btnAttack2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  btnAttack4;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::ProgressBar^  progressBar2;

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
			this->btnAttack1 = (gcnew System::Windows::Forms::Button());
			this->btnAttack2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->btnAttack4 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->progressBar2 = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// btnAttack1
			// 
			this->btnAttack1->Location = System::Drawing::Point(643, 385);
			this->btnAttack1->Name = L"btnAttack1";
			this->btnAttack1->Size = System::Drawing::Size(210, 62);
			this->btnAttack1->TabIndex = 0;
			this->btnAttack1->Text = L"button1";
			this->btnAttack1->UseVisualStyleBackColor = true;
			// 
			// btnAttack2
			// 
			this->btnAttack2->Location = System::Drawing::Point(859, 385);
			this->btnAttack2->Name = L"btnAttack2";
			this->btnAttack2->Size = System::Drawing::Size(210, 62);
			this->btnAttack2->TabIndex = 1;
			this->btnAttack2->Text = L"button2";
			this->btnAttack2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(859, 456);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(210, 62);
			this->button3->TabIndex = 2;
			this->button3->Text = L"button3";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// btnAttack4
			// 
			this->btnAttack4->Location = System::Drawing::Point(643, 456);
			this->btnAttack4->Name = L"btnAttack4";
			this->btnAttack4->Size = System::Drawing::Size(210, 62);
			this->btnAttack4->TabIndex = 3;
			this->btnAttack4->Text = L"button4";
			this->btnAttack4->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 385);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(436, 133);
			this->pictureBox1->TabIndex = 4;
			this->pictureBox1->TabStop = false;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Location = System::Drawing::Point(643, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(461, 125);
			this->pictureBox2->TabIndex = 5;
			this->pictureBox2->TabStop = false;
			// 
			// progressBar1
			// 
			this->progressBar1->Location = System::Drawing::Point(12, 356);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(436, 23);
			this->progressBar1->TabIndex = 6;
			// 
			// progressBar2
			// 
			this->progressBar2->Location = System::Drawing::Point(643, 143);
			this->progressBar2->Name = L"progressBar2";
			this->progressBar2->Size = System::Drawing::Size(461, 23);
			this->progressBar2->TabIndex = 7;
			// 
			// protoGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1116, 530);
			this->Controls->Add(this->progressBar2);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnAttack4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->btnAttack2);
			this->Controls->Add(this->btnAttack1);
			this->Name = L"protoGUI";
			this->Text = L"protoGUI";
			this->Load += gcnew System::EventHandler(this, &protoGUI::protoGUI_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void protoGUI_Load(System::Object^  sender, System::EventArgs^  e) {
		//things to happen when the program loads.



	}
	};
}
