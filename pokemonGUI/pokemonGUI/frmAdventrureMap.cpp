#include "stdafx.h"
#include "frmAdventrureMap.h"

void pokemonGUI::frmAdventrureMap::loadEnemies(World* w) {
	try {
		for (Enemy* enemy : w->enemies) {
			if (enemy->isAlive()) {
				String^ name = gcnew System::String(enemy->getName().c_str());
				PictureBox^ pb = gcnew PictureBox();
				pb->BackColor = System::Drawing::Color::Transparent;
				pb->Load("./Pictures/enemy.png");
				pb->Location = System::Drawing::Point(enemy->getX() + 7, enemy->getY() + 7); //+7 because that is where our panel is on window
				pb->Name = name;
				pb->Size = System::Drawing::Size(20, 20);
				pb->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::pbEnemy_MouseDown);
				pb->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &frmAdventrureMap::pbEnemy_MouseDoubleClick);
				Controls->Add(pb);
				pb->BringToFront();

				if (!enemiesPictureBox->ContainsKey(name)) {
					enemiesPictureBox->Add(name, pb);//Add to list for easier access
				}
				else {
					cout << "enemiesPictureBox contains item with that name" << endl;
				}

				int block = enemy->getX() / X_STEP + enemy->getY() / Y_STEP * (X_MAX / X_STEP);
				world.obstacles.insert(block);
			}
		}
	}
	catch (const exception& e) {
		cout << "Load Enemies: " << e.what() << endl;
	}
}

void pokemonGUI::frmAdventrureMap::loadMap(World * w)
{
	//Load world from a file
	msclr::interop::marshal_context context;
	std::string worldName = context.marshal_as<std::string>(textBoxWorldName->Text); //Convert from String^ to std::string
	world.loadWorld(worldName); //Loads set with the new world
	pbMap->Load(game.systemString(world.pictureLocation));

								//Display the new world
	if (graphics == nullptr) {
		graphics = panel1->CreateGraphics();
	}
	graphics->Clear(Color::White);
	drawGrid();
	for (Block b : w->blocks) {
		int x = b.id % (X_MAX / X_STEP) * X_STEP;
		int y = b.id / (X_MAX / X_STEP) * Y_STEP;
		w->obstacles.insert(b.id); // Insert blocks id into obstacles to prevent player movement over them

		if (b.color == "blue") {
			color = Color::Blue;
		}
		else {
			color = Color::Black;
		}
		SolidBrush^ brush = gcnew SolidBrush(color);
		graphics->FillRectangle(brush, x, y, X_STEP, Y_STEP);
	}

	//Add enemies as obstacles
	for (Enemy* en : w->enemies) {
		if (en->isAlive()) {
			int id = en->getX() / X_STEP + en->getY() / Y_STEP * X_MAX / X_STEP;
			w->obstacles.insert(id);
		}
	}
}

void pokemonGUI::frmAdventrureMap::drawGrid() { //Draw grid
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
