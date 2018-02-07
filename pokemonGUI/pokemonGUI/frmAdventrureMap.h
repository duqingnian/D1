#pragma once

namespace pokemonGUI {

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
	public:
		frmAdventrureMap(void)
		{


			InitializeComponent();
			drawGrid();
			//
			//TODO: Add the constructor code here
			//
		}
		void drawGrid() {
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
	protected:

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->panel1->Location = System::Drawing::Point(233, 12);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1000, 500);
			this->panel1->TabIndex = 0;
			this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::panel1_MouseClick);
			// 
			// frmAdventrureMap
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1543, 594);
			this->Controls->Add(this->panel1);
			this->Name = L"frmAdventrureMap";
			this->Text = L"frmAdventrureMap";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

		Graphics ^ graphics = panel1->CreateGraphics();
		Pen^ penCurrent = gcnew Pen(Color::Gray);
		for (int i = 0; i < 500; i += 20) {
			Point p1(i, 0);
			Point p2(i, 500);
			graphics->DrawLine(penCurrent, p1, p2);
		}
		for (int i = 0; i < 500; i += 20) {
			Point p1(0, i);
			Point p2(1000, i);
			graphics->DrawLine(penCurrent, p1, p2);
		}
	}
	};
}
