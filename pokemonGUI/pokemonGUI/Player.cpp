#include "Player.h"
#include "Game.h"


Player::Player()
{
	this->name = "";
	this->money = 0;
	this->pokemon = Pokemon();
	this->healthPotions = 0;
	this->staminaPotions = 0;
	this->score = 0;
}


Player::~Player()
{
}
Player::Player(string name) {
	this->name = name;
	this->money = 100;
	this->pokemon = Pokemon();
	this->healthPotions = 3;
	this->staminaPotions = 3;
	this->score = 0;
	this->x = 100;
	this->y = 100;
}
Player::Player(string name, Pokemon pokemon, int money, int healthPotions, int staminaPotions, int score, int x, int y) {
	this->name = name;
	this->money = money;
	this->pokemon = pokemon;
	this->healthPotions = healthPotions;
	this->staminaPotions = staminaPotions;
	this->score = score;
	this->x = x;
	this->y = y;
}

int Player::savePlayer() {
	//Returns ID for the save

	sqlite3 *db; //A pointer to the database
	bool connected = false; //To check if we have made a connection
	if (sqlite3_open(DB, &db) == SQLITE_OK) { //Make a connection
		connected = true;
	}
	else {
		cout << "Can't connect to database" << endl;
	}
	int ok; //For testing functions
	sqlite3_stmt * statement = nullptr;
	string querry = "INSERT INTO PlayerStats(ID, Pokemon, PosX, PosY, Money, HealthPotions, StaminaPotions, Score) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	ok = sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr); //We prepare our statement
	if (ok != SQLITE_OK) {
		cout << "Problems preparing SQLite3 statement in Player Save" << endl;
	}

	//----------------------------
	//For our ID let's use the number of seconds since January 1, 2000
	time_t timer;
	struct tm y2k = { 0 };
	int seconds;

	y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
	y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

	time(&timer); 

	seconds = difftime(timer, mktime(&y2k));
	//------------------------------

	//Time for database sanitization
	ok = sqlite3_bind_int(statement, 1, seconds);
		if (ok != SQLITE_OK) {
			cout << "Problems binding ID in Player Save" << endl;
		}
	//The fourth argument is position of \0
	ok = sqlite3_bind_text(statement, 2, this->pokemon.getName().c_str(), this->pokemon.getName().size(), NULL);
		if (ok != SQLITE_OK) {
			cout << "Problems binding pokemon name in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 3, this->x);
		if (ok != SQLITE_OK) {
			cout << "Problems binding posX in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 4, this->y);
		if (ok != SQLITE_OK) {
			cout << "Problems binding posY in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 5, this->money);
		if (ok != SQLITE_OK) {
			cout << "Problems binding money in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 6, this->healthPotions);
		if (ok != SQLITE_OK) {
			cout << "Problems binding healthPotions in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 7, this->staminaPotions);
		if (ok != SQLITE_OK) {
			cout << "Problems binding staminaPotions in Player Save" << endl;
		}
	ok = sqlite3_bind_int(statement, 8, this->score);
		if (ok != SQLITE_OK) {
			cout << "Problems binding score in Player Save" << endl;
		}

	
	ok = sqlite3_step(statement); //Execute statement
	if (ok != SQLITE_DONE) {
		cout << "Problems executing SQLite3 statement in Player Save" << endl;
	}

	ok = sqlite3_finalize(statement); //Deletes statement and cleans everything up
	if (ok != SQLITE_OK) {
		cout << "Problems finalizing SQLite3 statement in Player Save" << endl;
	}

	ok = sqlite3_close(db); //Closes connection
	if (ok != SQLITE_OK) {
		cout << "Problems preparing SQLite3 statement in Player Save" << endl;
	}

	return seconds;
}

void Player::loadPlayer(int PlayerID) {
	sqlite3 *db;
	sqlite3_stmt *statement;


	if (sqlite3_open(DB, &db) == SQLITE_OK) {
		string querry = "SELECT * FROM PlayerStats WHERE ID = ?";
		sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
		sqlite3_bind_int(statement, 1, PlayerID);
		sqlite3_step(statement);
		string pokemonName = (char*) sqlite3_column_text(statement, 1); //Get Pokemon name
		Pokemon pokemon;
		for (Pokemon *p : pokemonArray) { //Based on pokemon name, get pokemon object
			if (p->getName() == pokemonName) {
				pokemon = *p;
			}
		}
		int x = sqlite3_column_int(statement, 2);
		int y = sqlite3_column_int(statement, 3);
		int money = sqlite3_column_int(statement, 4);
		int healthPotions = sqlite3_column_int(statement, 5);
		int staminaPotions = sqlite3_column_int(statement, 6);
		int score = sqlite3_column_int(statement, 7);
		
		string name = (string)"Player:" + to_string(PlayerID);

		Player player(name, pokemon, money, healthPotions, staminaPotions, score, x, y);
		game.setPlayer(player);
 	}
	
}
