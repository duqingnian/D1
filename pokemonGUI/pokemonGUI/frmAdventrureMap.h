#pragma once
#include <iostream>
#include "World.h"
#include <msclr\marshal_cppstd.h>
#include <vector>
#include "Cordinate.h"
#include <set>
#include <algorithm>
#include "Game.h"
#include "protoGUI.h"
#include "OurWorlds.h"
#include "frmMainMenu.h"







namespace pokemonGUI {

	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
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
		Color color = Color::Black;
		int characterX = game.getPlayer().getX();
		int characterY = game.getPlayer().getY();
		List<double> listOfMoves;
		int timerIterator;
		int timerEnd;
		bool automatic = true;
		System::Windows::Forms::Button^  btnStopMapMaking;
	private: System::Windows::Forms::Button^  btnBack;

			 Dictionary<String^, PictureBox^>^ enemiesPictureBox = gcnew Dictionary<String^, PictureBox^>();
		void loadEnemies(World* w);
		void loadMap(World* w);
		void removeEnemies();
		void drawGrid();


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
	private: System::Windows::Forms::Timer^  timerMoveCharacter;
	private: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::PictureBox^  pbMap;

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
			this->pbMap = (gcnew System::Windows::Forms::PictureBox());
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
			this->timerMoveCharacter = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnStopMapMaking = (gcnew System::Windows::Forms::Button());
			this->btnBack = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCharacter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMap))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Transparent;
			this->panel1->Controls->Add(this->pictureCharacter);
			this->panel1->Controls->Add(this->pbMap);
			this->panel1->ForeColor = System::Drawing::Color::Transparent;
			this->panel1->Location = System::Drawing::Point(9, 9);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1331, 610);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &frmAdventrureMap::panel1_Paint);
			this->panel1->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::aStar_MouseDoubleClick);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseUp);
			// 
			// pictureCharacter
			// 
			this->pictureCharacter->BackColor = System::Drawing::Color::Transparent;
			this->pictureCharacter->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureCharacter->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureCharacter.Image")));
			this->pictureCharacter->Location = System::Drawing::Point(85, 95);
			this->pictureCharacter->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureCharacter->Name = L"pictureCharacter";
			this->pictureCharacter->Size = System::Drawing::Size(25, 25);
			this->pictureCharacter->TabIndex = 0;
			this->pictureCharacter->TabStop = false;
			// 
			// pbMap
			// 
			this->pbMap->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pbMap->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbMap.Image")));
			this->pbMap->Location = System::Drawing::Point(0, 0);
			this->pbMap->Name = L"pbMap";
			this->pbMap->Size = System::Drawing::Size(1328, 607);
			this->pbMap->TabIndex = 1;
			this->pbMap->TabStop = false;
			this->pbMap->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::aStar_MouseDoubleClick);
			this->pbMap->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseDown);
			this->pbMap->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseMove);
			this->pbMap->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseUp);
			// 
			// btnMapMaker
			// 
			this->btnMapMaker->Location = System::Drawing::Point(1376, 12);
			this->btnMapMaker->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnMapMaker->Name = L"btnMapMaker";
			this->btnMapMaker->Size = System::Drawing::Size(135, 48);
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
			this->btnSaveMap->Location = System::Drawing::Point(1376, 66);
			this->btnSaveMap->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnSaveMap->Name = L"btnSaveMap";
			this->btnSaveMap->Size = System::Drawing::Size(135, 48);
			this->btnSaveMap->TabIndex = 0;
			this->btnSaveMap->Text = L"Save map";
			this->btnSaveMap->UseVisualStyleBackColor = true;
			this->btnSaveMap->Visible = false;
			this->btnSaveMap->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnSaveMap_Click);
			// 
			// btnLoadMap
			// 
			this->btnLoadMap->Location = System::Drawing::Point(1376, 121);
			this->btnLoadMap->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnLoadMap->Name = L"btnLoadMap";
			this->btnLoadMap->Size = System::Drawing::Size(135, 48);
			this->btnLoadMap->TabIndex = 0;
			this->btnLoadMap->Text = L"Load map";
			this->btnLoadMap->UseVisualStyleBackColor = true;
			this->btnLoadMap->Visible = false;
			this->btnLoadMap->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnLoadMap_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(1373, 196);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"World name";
			this->label1->Visible = false;
			// 
			// textBoxWorldName
			// 
			this->textBoxWorldName->Location = System::Drawing::Point(1376, 217);
			this->textBoxWorldName->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textBoxWorldName->Name = L"textBoxWorldName";
			this->textBoxWorldName->Size = System::Drawing::Size(121, 22);
			this->textBoxWorldName->TabIndex = 3;
			this->textBoxWorldName->Visible = false;
			this->textBoxWorldName->TextChanged += gcnew System::EventHandler(this, &frmAdventrureMap::textBoxWorldName_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1373, 267);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 17);
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
			this->panelWall->Location = System::Drawing::Point(1376, 295);
			this->panelWall->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelWall->Name = L"panelWall";
			this->panelWall->Size = System::Drawing::Size(65, 65);
			this->panelWall->TabIndex = 5;
			this->panelWall->Tag = L"";
			this->panelWall->Visible = false;
			this->panelWall->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelWall_MouseClick);
			// 
			// panelWater
			// 
			this->panelWater->BackColor = System::Drawing::SystemColors::Highlight;
			this->panelWater->Location = System::Drawing::Point(1376, 367);
			this->panelWater->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelWater->Name = L"panelWater";
			this->panelWater->Size = System::Drawing::Size(65, 65);
			this->panelWater->TabIndex = 5;
			this->panelWater->Visible = false;
			this->panelWater->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelWater_MouseClick);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(1447, 318);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(35, 17);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Wall";
			this->label3->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(1447, 391);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(46, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Water";
			this->label4->Visible = false;
			// 
			// panelMoney
			// 
			this->panelMoney->BackColor = System::Drawing::SystemColors::ActiveBorder;
			this->panelMoney->Location = System::Drawing::Point(1376, 438);
			this->panelMoney->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelMoney->Name = L"panelMoney";
			this->panelMoney->Size = System::Drawing::Size(65, 65);
			this->panelMoney->TabIndex = 5;
			this->panelMoney->Visible = false;
			this->panelMoney->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panelMoney_MouseClick);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(1447, 463);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 17);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Money";
			this->label5->Visible = false;
			// 
			// timerMoveCharacter
			// 
			this->timerMoveCharacter->Tick += gcnew System::EventHandler(this, &frmAdventrureMap::timerMoveCharacter_Tick);
			// 
			// btnStopMapMaking
			// 
			this->btnStopMapMaking->Location = System::Drawing::Point(1376, 568);
			this->btnStopMapMaking->Name = L"btnStopMapMaking";
			this->btnStopMapMaking->Size = System::Drawing::Size(135, 48);
			this->btnStopMapMaking->TabIndex = 7;
			this->btnStopMapMaking->Text = L"Stop map making";
			this->btnStopMapMaking->UseVisualStyleBackColor = true;
			this->btnStopMapMaking->Visible = false;
			this->btnStopMapMaking->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnStopMapMaking_Click);
			// 
			// btnBack
			// 
			this->btnBack->Location = System::Drawing::Point(1376, 66);
			this->btnBack->Name = L"btnBack";
			this->btnBack->Size = System::Drawing::Size(135, 496);
			this->btnBack->TabIndex = 8;
			this->btnBack->Text = L"Back to Pokemon Menu";
			this->btnBack->UseVisualStyleBackColor = true;
			this->btnBack->Click += gcnew System::EventHandler(this, &frmAdventrureMap::button1_Click);
			// 
			// frmAdventrureMap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1908, 652);
			this->Controls->Add(this->btnBack);
			this->Controls->Add(this->btnStopMapMaking);
			this->Controls->Add(this->panel1);
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
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->Name = L"frmAdventrureMap";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Adventure Map";
			this->Load += gcnew System::EventHandler(this, &frmAdventrureMap::frmAdventrureMap_Load);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &frmAdventrureMap::frmAdventrureMap_KeyDown);
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureCharacter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbMap))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnMapMaker_Click(System::Object^  sender, System::EventArgs^  e) { 
		//Button Start Map Maker
		//Draws grid if picture map is invisible and lets you start drawing obstacles like walls or water
		//And add gold coins
		//Also Enables new buttons specifically made for world design
		//After the first press, works as a "New Map" button
		
		if (mapMaking) {
			world.blocks.clear();
			removeEnemies();
			graphics->Clear(Color::White);
			drawGrid();
		}
		else {

			mapMaking = true;
			btnLoadMap->Visible = true;
			btnSaveMap->Visible = true;
			if (textBoxWorldName->Text == "") {
				//Do not enable Load and Save buttons if world name is not specified
				btnLoadMap->Enabled = false;
				btnSaveMap->Enabled = false;
			}
			btnStopMapMaking->Visible = true;
			textBoxWorldName->Visible = true;
			btnBack->Visible = false;
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
	}


	private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Mouse down. Start timer to draw with mouse drag
		//Based on which mouse button is pressed either start drawing or start erasing
		//Also if an enemy object is toggled, move the object to a new clicked place
		if (mapMaking) {
			if (e->Button.ToString() == "Left") {
				timerMouseDrag->Start();
			}
			else if (e->Button.ToString() == "Right") {
				timerEraser->Start();
			}
			//If an enemy object has dragging=true, move it to the newly clicked position
			//And display it's new X and Y position
			for (Enemy *en : world.enemies) {
				if (en->isDragging()) {
					for each(KeyValuePair<String^, PictureBox^>^ pair in enemiesPictureBox) {
						if (game.systemString(en->getName())==pair->Key) {
							en->setDragging(false);
							int tempX = e->X / 20;
							int tempY = e->Y / 20;
							pair->Value->BorderStyle = BorderStyle::None;
							pair->Value->Location = Point(tempX * 20 + 7, tempY * 20 + 7);
							en->setX(tempX * 20);
							en->setY(tempY * 20);
							cout << "X: " << tempX * 20;
							cout << "Y: " << tempY * 20;
							break;
						}
					}
					break;
				}
			}
		}
	}

	private: System::Void timerMouseDrag_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Every 10 ms get the current mouse positon on the map and draw a square on that position
		//Transform the X and Y coordinates into a single number 0-1249
		//Store this number into a set because if we were to store the same number twice,
		//Set will not add the duplicate and only keep one so it will not get over filled

		if (mouse->X < X_MAX && mouse->Y < Y_MAX) {
			int block = mouse->X / X_STEP + mouse->Y / Y_STEP * (X_MAX / X_STEP); // Coordinates 0-1249
			int x = block % (X_MAX / X_STEP) * X_STEP;// From the block number get the X cord
			int y = block / (X_MAX / X_STEP) * Y_STEP;// From the block number get the Y cord
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
			pbMap->Refresh();
			world.blocks.insert(b);
		}
	}
	private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Update mouse coordinates as a local object to keep track of where the mouse pointer is
		//When calling other funtions, that do not have MouseEvent as a parameter
		if (mapMaking) {
			mouse = e;
		}
	}
	private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//When mouse is released it stops drawing/erasing new obstacles
		if (mapMaking) {
			timerMouseDrag->Stop();
			timerEraser->Stop();
		}
	}
	private: System::Void btnSaveMap_Click(System::Object^  sender, System::EventArgs^  e) {
		//Saves world with the world name currently in World Name text box

		//Converts from System::String^ to std::string
		//String^ is a managed object, while string is non-managed
		msclr::interop::marshal_context context;
		std::string worldName = context.marshal_as<std::string>(textBoxWorldName->Text); 
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
		//Since we are manually loading map we disable the automatic map update
		automatic = false; 
		removeEnemies();
		//loadEnemies(&world);
		loadMap(&world);
		automatic = true;
	}

	private: System::Void timerEraser_Tick(System::Object^  sender, System::EventArgs^  e) {
		//Timer for erasing what has been drawn while holding down mouse right click
		//And taking the block number out of set containing them
		//Also turns the block color back to white
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
		if (e->KeyCode == Keys::Escape) {
			pokemonGUI::frmMainMenu mainMenu;
			mainMenu.ShowDialog(); //Launch Main Menu
		}
		int X = characterX;
		int Y = characterY;
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
		if (e->KeyCode == Keys::ShiftKey) {
			//Toggle map visibility
			if (pbMap->Visible) {
				pbMap->Visible = false;
				drawGrid();
				loadMap(&world);
			}
			else {
				pbMap->Visible = true;
			}
		}
		int block = X / X_STEP + Y / Y_STEP * (X_MAX / X_STEP);
		if (world.obstacles.count(block) == 0) { //If new position is not an obstacle
			characterX = X;
			characterY = Y;
			pictureCharacter->Location = Point(characterX, characterY); //Move character
			game.getPlayer().setX(characterX);
			game.getPlayer().setY(characterY);
		}

	}

	private: System::Void aStar_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		// Use A* alghorithm to figure out the best path from yourself to the double click position
		// Then start timer to gradually move our charactor step by step
		try {
			Node player;
			player.x = characterX / 20;
			player.y = characterY / 20;

			Node destination;
			destination.x = e->X / 20;
			destination.y = e->Y / 20;

			listOfMoves.Clear();
			timerEnd = 0;
			timerIterator = 0;
			

			for (Node node : Cordinate::aStar(player, destination)) {
				listOfMoves.Add(node.x);
				listOfMoves.Add(node.y);
				timerEnd++;

			}
			if (timerEnd != 0) {
				timerMoveCharacter->Start();
			}
			
		}
		catch (const exception& e) {
			cout << "aStarAdventureMap - Error " << e.what();
		}
		
	}


private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}

		 
private: System::Void frmAdventrureMap_Load(System::Object^  sender, System::EventArgs^  e) {
	//When first launching Map 
	pictureCharacter->Location = Point(game.getPlayer().getX(), game.getPlayer().getY());
	loadMap(&world);
	loadEnemies(&world);
	
}
private: System::Void timerMoveCharacter_Tick(System::Object^  sender, System::EventArgs^  e) {
	//Based on A* algorithm move players character step by step to the desired location
	//At the end of the path check if that is a place to make a map transition
	//And if so, then transition to the next map

	try {
		if (timerIterator / 2 == timerEnd) {
			if (timerIterator != 0) {
				for (World* w : world.exits) {
					switch (w->entrance) {
					case 'l': //Left
						if (listOfMoves[timerIterator - 2] * 20 >= 960) {
							removeEnemies();
							world = *w;
							int block = w->spawnPoint;
							characterX = block % (X_MAX / X_STEP) * X_STEP;
							characterY = block / (X_MAX / X_STEP) * Y_STEP;
							game.getPlayer().setX(characterX);
							game.getPlayer().setY(characterY);
							pictureCharacter->Location = Point(characterX, characterY);
							loadMap(w);
							loadEnemies(w);
						}
						break;
					case 'r'://Right
						if (listOfMoves[timerIterator - 2] * 20 <= 20) {
							removeEnemies();
							world = *w;
							int block = w->spawnPoint;
							characterX = block % (X_MAX / X_STEP) * X_STEP;
							characterY = block / (X_MAX / X_STEP) * Y_STEP;
							game.getPlayer().setX(characterX);
							game.getPlayer().setY(characterY);
							pictureCharacter->Location = Point(characterX, characterY);
							loadMap(w);
							loadEnemies(w);
						}
						break;
					case 't'://Top
						if (listOfMoves[timerIterator - 2] * 20 <= 20) {
							removeEnemies();
							world = *w;
							int block = w->spawnPoint;
							characterX = block % (X_MAX / X_STEP) * X_STEP;
							characterY = block / (X_MAX / X_STEP) * Y_STEP;
							game.getPlayer().setX(characterX);
							game.getPlayer().setY(characterY);
							pictureCharacter->Location = Point(characterX, characterY);
							loadMap(w);
							loadEnemies(w);
						}
						break;
					case 'b'://Bottom
						if (listOfMoves[timerIterator - 1] * 20 >= 960) {
							removeEnemies();
							world = *w;
							int block = w->spawnPoint;
							characterX = block % (X_MAX / X_STEP) * X_STEP;
							characterY = block / (X_MAX / X_STEP) * Y_STEP;
							game.getPlayer().setX(characterX);
							game.getPlayer().setY(characterY);
							pictureCharacter->Location = Point(characterX, characterY);
							loadMap(w);
							loadEnemies(w);
						}
						break;
					}
				}
			}
			listOfMoves.Clear();
			timerEnd = 0;
			timerIterator = 0;
			timerMoveCharacter->Stop();
		}
		else {
			//Move charactor by one step
			int x = listOfMoves[timerIterator];
			int y = listOfMoves[timerIterator + 1];
			characterX = x * 20;
			characterY = y * 20;
			pictureCharacter->Location = (Point(characterX, characterY));
			timerIterator += 2;
			game.getPlayer().setX(characterX);
			game.getPlayer().setY(characterY);
		}
	}
	catch (const exception& e) {
		cout << "TimerMoveCharacter - Error " << e.what() << endl;
	}
}
	
	private: System::Void pbEnemy_MouseDoubleClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		//Double click enemy character to open up fight window
		//If enemy loses the fight - he is removed from the map
		if (!mapMaking) {
			if (game.getPlayer().getPokemon().getHP() != 0) {
				for each(KeyValuePair<String^, PictureBox^>^ pair in enemiesPictureBox) {
					PictureBox^ thisBox = safe_cast<PictureBox^>(sender);
					if (thisBox->Location == pair->Value->Location) {
						if (!sender->Equals(pair->Value)) {
							thisBox->Visible = false;
						}
						for (Enemy* en : world.enemies) {
							if (game.systemString(en->getName()) == pair->Key) {
								for (Pokemon* pk : pokemonArray) {
									if (en->getPokemonName() == pk->getName()) {
										en->setPokemon(*pk); //Assign pokemon to enemy
										break;
									}
								}
								const Fight fight(&game.getPlayer(), en);
								game.setNewFight(fight);
								pokemonGUI::protoGUI fightGui;
								fightGui.ShowDialog(); //Launch fight gui
								if (en->isAlive() == false) {

								 //Remove enemy from the screen
									pair->Value->Visible = false;
									int block = en->getX() / X_STEP + en->getY() / Y_STEP * (X_MAX / X_STEP);
									world.obstacles.erase(block);
								}
								break;
							}
						}

						break;
					}
				}
			}
		}
	}
		 
private: System::Void pbEnemy_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Clicked on enemy character to start moving it
	//Can only happen if the map is in map making mode
	//Meant for easier level design
	if (mapMaking) {
		for each(KeyValuePair<String^, PictureBox^>^ pair in enemiesPictureBox) {
			PictureBox^ thisBox = safe_cast<PictureBox^>(sender);
			if (thisBox->Location == pair->Value->Location) {
				if (!sender->Equals(pair->Value)) {
					thisBox->Visible = false;
				}
				for (Enemy *en : world.enemies) {
					if (game.systemString(en->getName()) == pair->Key) {
						if (en->isDragging()) {
							en->setDragging(false);
							pair->Value->BorderStyle = BorderStyle::None;
						} //Toggles selected border and let's you move the enemy
						en->setDragging(true);
						pair->Value->BorderStyle = BorderStyle::Fixed3D;
						break;
					}
				}
				break;
			}
		}
	}
}
		 
private: System::Void btnStopMapMaking_Click(System::Object^  sender, System::EventArgs^  e) {
	//Button stop map making
	//Hides everything connected to map making and lets the player move his character
	mapMaking = false;
	btnLoadMap->Visible =false;
	btnSaveMap->Visible = false;
	btnStopMapMaking->Visible = false;
	textBoxWorldName->Visible = false;
	label1->Visible = false;
	label2->Visible = false;
	label3->Visible = false;
	label4->Visible = false;
	label5->Visible = false;
	panelWall->Visible = false;
	panelWater->Visible = false;
	panelMoney->Visible = false;
	btnBack->Visible = true;
	btnMapMaker->Text = "Start map making";
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}
};
}