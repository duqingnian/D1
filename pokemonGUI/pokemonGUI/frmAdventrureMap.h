#pragma once
#include <iostream>
#include "World.h"
#include <msclr\marshal_cppstd.h>

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
	private: System::Windows::Forms::Button^  btnSaveMap;
	private: System::Windows::Forms::Button^  btnLoadMap;
	private: System::Windows::Forms::ComboBox^  cbBrush;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxWorldName;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Timer^  timerMouseDrag;


		
	public:
		frmAdventrureMap(void)
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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnMapMaker = (gcnew System::Windows::Forms::Button());
			this->timerMouseDrag = (gcnew System::Windows::Forms::Timer(this->components));
			this->btnSaveMap = (gcnew System::Windows::Forms::Button());
			this->btnLoadMap = (gcnew System::Windows::Forms::Button());
			this->cbBrush = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxWorldName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(9, 9);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1330, 610);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseClick);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseUp);
			// 
			// btnMapMaker
			// 
			this->btnMapMaker->Location = System::Drawing::Point(1376, 12);
			this->btnMapMaker->Name = L"btnMapMaker";
			this->btnMapMaker->Size = System::Drawing::Size(135, 48);
			this->btnMapMaker->TabIndex = 0;
			this->btnMapMaker->Text = L"Start map making";
			this->btnMapMaker->UseVisualStyleBackColor = true;
			this->btnMapMaker->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnMapMaker_Click);
			// 
			// timerMouseDrag
			// 
			this->timerMouseDrag->Interval = 50;
			this->timerMouseDrag->Tick += gcnew System::EventHandler(this, &frmAdventrureMap::timerMouseDrag_Tick);
			// 
			// btnSaveMap
			// 
			this->btnSaveMap->Location = System::Drawing::Point(1376, 66);
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
			this->btnLoadMap->Location = System::Drawing::Point(1376, 120);
			this->btnLoadMap->Name = L"btnLoadMap";
			this->btnLoadMap->Size = System::Drawing::Size(135, 48);
			this->btnLoadMap->TabIndex = 0;
			this->btnLoadMap->Text = L"Load map";
			this->btnLoadMap->UseVisualStyleBackColor = true;
			this->btnLoadMap->Visible = false;
			this->btnLoadMap->Click += gcnew System::EventHandler(this, &frmAdventrureMap::btnLoadMap_Click);
			// 
			// cbBrush
			// 
			this->cbBrush->FormattingEnabled = true;
			this->cbBrush->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Eraser", L"Water", L"Wall" });
			this->cbBrush->Location = System::Drawing::Point(1376, 275);
			this->cbBrush->Name = L"cbBrush";
			this->cbBrush->Size = System::Drawing::Size(121, 24);
			this->cbBrush->TabIndex = 1;
			this->cbBrush->Text = L"Wall";
			this->cbBrush->Visible = false;
			this->cbBrush->SelectedIndexChanged += gcnew System::EventHandler(this, &frmAdventrureMap::cbBrush_SelectedIndexChanged);
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
			this->textBoxWorldName->Location = System::Drawing::Point(1376, 216);
			this->textBoxWorldName->Name = L"textBoxWorldName";
			this->textBoxWorldName->Size = System::Drawing::Size(121, 22);
			this->textBoxWorldName->TabIndex = 3;
			this->textBoxWorldName->Visible = false;
			this->textBoxWorldName->TextChanged += gcnew System::EventHandler(this, &frmAdventrureMap::textBoxWorldName_TextChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1373, 255);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 17);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Choose brush";
			this->label2->Visible = false;
			// 
			// frmAdventrureMap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1924, 652);
			this->Controls->Add(this->textBoxWorldName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cbBrush);
			this->Controls->Add(this->btnLoadMap);
			this->Controls->Add(this->btnSaveMap);
			this->Controls->Add(this->btnMapMaker);
			this->Controls->Add(this->panel1);
			this->MaximizeBox = false;
			this->Name = L"frmAdventrureMap";
			this->ShowIcon = false;
			this->Text = L"Adventure Map";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (mapMaking) {

		}

	}
	private: System::Void btnMapMaker_Click(System::Object^  sender, System::EventArgs^  e) { //Button Start Map Maker
		//Draws grid
		drawGrid();
		mapMaking = true;
		btnLoadMap->Visible = true;
		btnSaveMap->Visible = true;
		btnLoadMap->Enabled = false;
		btnSaveMap->Enabled = false;
		textBoxWorldName->Visible = true;
		label1->Visible = true;
		label2->Visible = true;
		cbBrush->Visible = true;
	}


private: System::Void panel1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Mouse down. Start timer to draw with mouse drag
	if (mapMaking) {
		timerMouseDrag->Start();
	}
}

private: System::Void timerMouseDrag_Tick(System::Object^  sender, System::EventArgs^  e) {
	//Every 50 ms captures block and draws
	if (mouse->X < X_MAX && mouse->Y < Y_MAX) {
		int block = mouse->X / X_STEP + mouse->Y / Y_STEP * (X_MAX / X_STEP);
		int x = block % (X_MAX / X_STEP) * X_STEP;
		int y = block / (X_MAX / X_STEP) * Y_STEP;
		//cout << block << " x:" << x << " y:" << y << endl;
		Block b;
		b.id = block;
		b.color = world.colorName;
		if (world.colorName=="white") { //If our selected brush is eraser
			world.blocks.erase(b);
		}
		else {
			world.blocks.insert(b);
		}
		SolidBrush^ brush = gcnew SolidBrush(color);
		graphics->FillRectangle(brush, x, y, X_STEP, Y_STEP);


	}
}
private: System::Void panel1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Update mouse coordinates
	mouse = e;
}
private: System::Void panel1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
	//Release mouse and stop drawing and capturing blocks
	timerMouseDrag->Stop();
}
private: System::Void cbBrush_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	if (cbBrush->Text == "Wall") {
		color = Color::Black;
		world.colorName = "black";
	}
	else if (cbBrush->Text == "Water") {
		color = Color::Blue;
		world.colorName = "blue";
	}
	else {
		color = Color::White;
		world.colorName = "white";
	}

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
};
}
