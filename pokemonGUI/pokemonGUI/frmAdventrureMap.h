#pragma once
#include <iostream>
#include "World.h"
#include <msclr\marshal_cppstd.h>
#include "frmMainMenu.h"

namespace pokemonGUI {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmAdventrureMap
	/// </summary>
	public ref class frmAdventrureMap : public System::Windows::Forms::Form
	{
	private:
		bool mapMaking = false;
		Graphics ^ graphics; //Using these to draw on our panel
		System::Windows::Forms::MouseEventArgs^ mouse;
		int X_MAX = 1000;
		int X_STEP = 20;
		int Y_MAX = 500;
		int Y_STEP = 20;
		Color color = Color::Black;
		int characterX = 100;
		int characterY = 100;
	private: System::Windows::Forms::Button^  btnSaveMap;
	private: System::Windows::Forms::Button^  btnLoadMap;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxWorldName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timerEraser;
	private: System::Windows::Forms::Panel^  panelWall;
	private: System::Windows::Forms::Panel^  panelWater;






	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Panel^  panelMoney;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::PictureBox^  pictureCharacter;
	private: System::Windows::Forms::Timer^  timerMouseDrag;



	public:
		frmAdventrureMap(void)
		{


			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			frmAdventrureMap::KeyPreview = true;

		}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmAdventrureMap()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnMapMaker;
	private: System::ComponentModel::IContainer^  components;
	protected:

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(frmAdventrureMap::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureCharacter = (gcnew System::Windows::Forms::PictureBox());
			this->btnMapMaker = (gcnew System::Windows::Forms::Button());
			this->timerMouseDrag = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnSaveMap = (gcnew System::Windows::Forms::Button());
			this->btnLoadMap = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxWorldName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timerEraser = (gcnew System::Windows::Forms::Timer(this->components));
			this->panelWall = (gcnew System::Windows::Forms::Panel());
			this->panelWater = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panelMoney = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCharacter))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Controls->Add(this->pictureCharacter);
			this->panel1->Location = System::Drawing::Point(7, 7);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(998, 496);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmAdventrureMap::panel1_Paint);
			this->panel1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseDoubleClick);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseUp);
			// 
			// pictureCharacter
			// 
			this->pictureCharacter->BackColor = System::Drawing::Color::Transparent;
			this->pictureCharacter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureCharacter.Image")));
			this->pictureCharacter->Location = System::Drawing::Point(64, 77);
			this->pictureCharacter->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->pictureCharacter->Name = L"pictureCharacter";
			this->pictureCharacter->Size = System::Drawing::Size(19, 20);
			this->pictureCharacter->TabIndex = 0;
			this->pictureCharacter->TabStop = false;
			// 
			// btnMapMaker
			// 
			this->btnMapMaker->Location = System::Drawing::Point(1032, 10);
			this->btnMapMaker->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnMapMaker->Name = L"btnMapMaker";
			this->btnMapMaker->Size = System::Drawing::Size(101, 39);
			this->btnMapMaker->TabIndex = 0;
			this->btnMapMaker->Text = L"Start map making";
			this->btnMapMaker->UseVisualStyleBackColor = true;
			this->btnMapMaker->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnMapMaker_Click);
			// 
			// timerMouseDrag
			// 
			this->timerMouseDrag->Interval = 10;
			this->timerMouseDrag->Tick += gcnew System::EventHandler(this, &frmAdventrureMap::timerMouseDrag_Tick);
			// 
			// btnSaveMap
			// 
			this->btnSaveMap->Location = System::Drawing::Point(1032, 54);
			this->btnSaveMap->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnSaveMap->Name = L"btnSaveMap";
			this->btnSaveMap->Size = System::Drawing::Size(101, 39);
			this->btnSaveMap->TabIndex = 0;
			this->btnSaveMap->Text = L"Save map";
			this->btnSaveMap->UseVisualStyleBackColor = true;
			this->btnSaveMap->Visible = false;
			this->btnSaveMap->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnSaveMap_Click);
			// 
			// btnLoadMap
			// 
			this->btnLoadMap->Location = System::Drawing::Point(1032, 98);
			this->btnLoadMap->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->btnLoadMap->Name = L"btnLoadMap";
			this->btnLoadMap->Size = System::Drawing::Size(101, 39);
			this->btnLoadMap->TabIndex = 0;
			this->btnLoadMap->Text = L"Load map";
			this->btnLoadMap->UseVisualStyleBackColor = true;
			this->btnLoadMap->Visible = false;
			this->btnLoadMap->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnLoadMap_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1030, 159);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(64, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"World name";
			this->label1->Visible = false;
			// 
			// textBoxWorldName
			// 
			this->textBoxWorldName->Location = System::Drawing::Point(1032, 176);
			this->textBoxWorldName->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBoxWorldName->Name = L"textBoxWorldName";
			this->textBoxWorldName->Size = System::Drawing::Size(92, 20);
			this->textBoxWorldName->TabIndex = 3;
			this->textBoxWorldName->Visible = false;
			this->textBoxWorldName->TextChanged += gcnew System::EventHandler(this, &frmAdventrureMap::textBoxWorldName_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1030, 217);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Choose brush:";
			this->label2->Visible = false;
			// 
			// timerEraser
			// 
			this->timerEraser->Interval = 10;
			this->timerEraser->Tick += gcnew System::EventHandler(this, &frmAdventrureMap::timerEraser_Tick);
			// 
			// panelWall
			// 
			this->panelWall->BackColor = System::Drawing::SystemColors::InfoText;
			this->panelWall->Location = System::Drawing::Point(1032, 240);
			this->panelWall->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelWall->Name = L"panelWall";
			this->panelWall->Size = System::Drawing::Size(49, 53);
			this->panelWall->TabIndex = 5;
			this->panelWall->Tag = L"";
			this->panelWall->Visible = false;
			this->panelWall->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelWall_MouseClick);
			// 
			// panelWater
			// 
			this->panelWater->BackColor = System::Drawing::SystemColors::Highlight;
			this->panelWater->Location = System::Drawing::Point(1032, 298);
			this->panelWater->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelWater->Name = L"panelWater";
			this->panelWater->Size = System::Drawing::Size(49, 53);
			this->panelWater->TabIndex = 5;
			this->panelWater->Visible = false;
			this->panelWater->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelWater_MouseClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1085, 258);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(28, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Wall";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1085, 318);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(36, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Water";
			this->label4->Visible = false;
			// 
			// panelMoney
			// 
			this->panelMoney->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panelMoney->Location = System::Drawing::Point(1032, 356);
			this->panelMoney->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panelMoney->Name = L"panelMoney";
			this->panelMoney->Size = System::Drawing::Size(49, 53);
			this->panelMoney->TabIndex = 5;
			this->panelMoney->Visible = false;
			this->panelMoney->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelMoney_MouseClick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1085, 376);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Money";
			this->label5->Visible = false;
			// 
			// frmAdventrureMap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1431, 530);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panelMoney);
			this->Controls->Add(this->panelWater);
			this->Controls->Add(this->panelWall);
			this->Controls->Add(this->textBoxWorldName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnLoadMap);
			this->Controls->Add(this->btnSaveMap);
			this->Controls->Add(this->btnMapMaker);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->MaximizeBox = false;
			this->Name = L"frmAdventrureMap";
			this->ShowIcon = false;
			this->Text = L"Adventure Map";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmAdventrureMap::frmAdventrureMap_KeyDown);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCharacter))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnMapMaker_Click(System::Object^  sender, System::EventArgs^  e) { //Button Start Map Maker
																							  //Draws grid
		pictureCharacter->Location = Point(characterX, characterY);
		world.blocks.clear();
		graphics = panel1->CreateGraphics();
		graphics->Clear(Color::White);
		drawGrid();
		mapMaking = true;
		btnLoadMap->Visible = true;
		btnSaveMap->Visible = true;
		btnLoadMap->Enabled = false;
		btnSaveMap->Enabled = false;
		textBoxWorldName->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		label3->Visible = true;
		label4->Visible = true;
		label5->Visible = true;
		panelWall->Visible = true;
		panelWater->Visible = true;
		panelMoney->Visible = true;
		panelMoney->BackColor = Color::Gold;
		btnMapMaker->Text = "New Map";
	}


	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Mouse down. Start timer to draw with mouse drag
		if (mapMaking) {
			if (e->Button.ToString() == "Left") {
				timerMouseDrag->Start();
			}
			else if (e->Button.ToString() == "Right") {
				timerEraser->Start();
			}

		}
	}

	private: System::Void timerMouseDrag_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Every 10 ms captures block and draws on it
		if (mouse->X < X_MAX && mouse->Y < Y_MAX) {
			int block = mouse->X / X_STEP + mouse->Y / Y_STEP * (X_MAX / X_STEP); // Coordinates 0-1249
			int x = block % (X_MAX / X_STEP) * X_STEP;// From 0-1249 get X cord
			int y = block / (X_MAX / X_STEP) * Y_STEP;// From the weird one number get the Y cord
			Block b;
			b.id = block;
			b.color = world.colorName;
			SolidBrush^ brush = gcnew SolidBrush(color);
			if (world.colorName == "gold") { //If our selected brush is money
				graphics->FillEllipse(brush, x, y, X_STEP, Y_STEP);
			}
			else {
				graphics->FillRectangle(brush, x, y, X_STEP, Y_STEP);
			}
			world.blocks.insert(b);
		}
	}
	private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Update mouse coordinates
		mouse = e;
	}
	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Release mouse and stop drawing and capturing blocks
		timerMouseDrag->Stop();
		timerEraser->Stop();
	}
	private: System::Void btnSaveMap_Click(System::Object^  sender, System::EventArgs^  e) {
		//Save world
		msclr::interop::marshal_context context;
		std::string worldName = context.marshal_as<std::string>(textBoxWorldName->Text); //Convert from String^ to std::string
		world.saveWorld(worldName);
	}
	private: System::Void textBoxWorldName_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		//If World name box is empty, grey out Save and Load buttons
		if (textBoxWorldName->Text == "") {
			btnSaveMap->Enabled = false;
			btnLoadMap->Enabled = false;
		}
		else {
			btnSaveMap->Enabled = true;
			btnLoadMap->Enabled = true;
		}
	}
	private: System::Void btnLoadMap_Click(System::Object^  sender, System::EventArgs^  e) {
		//Load world from a file
		msclr::interop::marshal_context context;
		std::string worldName = context.marshal_as<std::string>(textBoxWorldName->Text); //Convert from String^ to std::string
		world.loadWorld(worldName); //Loads set with the new world

									//Display the new world
		graphics->Clear(Color::White);
		drawGrid();
		for (Block b : world.blocks) {
			int x = b.id % (X_MAX / X_STEP) * X_STEP;
			int y = b.id / (X_MAX / X_STEP) * Y_STEP;
			world.obstacles.insert(b.id); // Insert blocks id into obstacles to prevent player movement over them

			if (b.color == "blue") {
				color = Color::Blue;
			}
			else {
				color = Color::Black;
			}
			SolidBrush^ brush = gcnew SolidBrush(color);
			graphics->FillRectangle(brush, x, y, X_STEP, Y_STEP);
		}
	}
	private: void drawGrid() { //Draw grid
		graphics = panel1->CreateGraphics();
		Pen^ pen = gcnew Pen(Color::LightGray);
		for (int i = 0; i <= X_MAX; i += X_STEP) {
			Point p1(i, 0);
			Point p2(i, 500);
			graphics->DrawLine(pen, p1, p2);
		}
		for (int i = 0; i <= Y_MAX; i += Y_STEP) {
			Point p1(0, i);
			Point p2(1000, i);
			graphics->DrawLine(pen, p1, p2);
		}
	}
	private: System::Void timerEraser_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Timer for erasing what has been drawn with holding right click
		if (mouse->X < X_MAX && mouse->Y < Y_MAX) {
			int block = mouse->X / X_STEP + mouse->Y / Y_STEP * (X_MAX / X_STEP);
			int x = block % (X_MAX / X_STEP) * X_STEP;
			int y = block / (X_MAX / X_STEP) * Y_STEP;
			Block b;
			b.id = block;
			b.color = world.colorName;
			world.blocks.erase(b);

			SolidBrush^ brush = gcnew SolidBrush(Color::White);
			graphics->FillRectangle(brush, x, y, X_STEP, Y_STEP);


		}
	}

	private: System::Void panelWall_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Chosen Wall brush
		color = Color::Black;
		world.colorName = "black";
	}
	private: System::Void panelWater_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Chosen Water brush
		color = Color::Blue;
		world.colorName = "blue";
	}
	private: System::Void panelMoney_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Chosen Money brush
		color = Color::Gold;
		world.colorName = "gold";
	}

	private: System::Void frmAdventrureMap_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		//Character move keys pressed
		int X = characterX;
		int Y = characterY;
		if (e->KeyCode == Keys::Escape) {
			pokemonGUI::frmMainMenu mainMenu;
			mainMenu.ShowDialog(); //Launch Main Menu
		}
		if (e->KeyCode == Keys::Right) {
			X += 20;
		}
		if (e->KeyCode == Keys::Left) {
			X -= 20;
		}
		if (e->KeyCode == Keys::Up) {
			Y -= 20;
		}
		if (e->KeyCode == Keys::Down) {
			Y += 20;
		}
		int block = X / X_STEP + Y / Y_STEP * (X_MAX / X_STEP);
		if (world.obstacles.count(block) == 0) { //If new position is not an obstacle
			characterX = X;
			characterY = Y;
			pictureCharacter->Location = Point(characterX, characterY); //Move character
		}

	}
	private: System::Void panel1_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		Point p1(0, 0);
		Point p2(e->X, e->Y);
		Pen^ brush = gcnew Pen(Color::Olive);
		graphics->DrawLine(brush, p1, p2);
	}
private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
};
}
