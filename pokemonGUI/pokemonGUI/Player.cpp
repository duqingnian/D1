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

	int pokemonID = this->pokemon.savePokemon(); //Saves players pokemon and returns that saves ID to use as foreign key

	sqlite3 *db; //A pointer to the database
	bool connected = false; //To check if we have made a connection
	if (sqlite3_open(DB, &db) == SQLITE_OK) { //Make a connection
		connected = true;
	}
	else {
		cout << "Can't connect to database" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}

	int ok; //For testing functions
	sqlite3_stmt * statement = nullptr;
	string querry;


	//To connect PlayerStats table with Player table
	string name = this->name;
	querry = "SELECT playerID FROM Player WHERE UserName = ?";
	sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
	sqlite3_bind_text(statement, 1, name.c_str(), name.size(), NULL);
	sqlite3_step(statement);
	int PlayerFK = sqlite3_column_int(statement, 0);
	sqlite3_finalize(statement);


	querry = "INSERT INTO PlayerStats(PokemonID, PosX, PosY, Money, HealthPotions, StaminaPotions, Score, PlayerFK) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
	ok = sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr); //We prepare our statement
	if (ok != SQLITE_OK) {
		cout << "Problems preparing SQLite3 statement in Player Save" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}

	//ID is set to Auto increment so no need to worry about that 
	ok = sqlite3_bind_int(statement, 1, pokemonID);
		if (ok != SQLITE_OK) {
			cout << "Problems binding pokemon name in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 2, this->x);
		if (ok != SQLITE_OK) {
			cout << "Problems binding posX in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 3, this->y);
		if (ok != SQLITE_OK) {
			cout << "Problems binding posY in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 4, this->money);
		if (ok != SQLITE_OK) {
			cout << "Problems binding money in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 5, this->healthPotions);
		if (ok != SQLITE_OK) {
			cout << "Problems binding healthPotions in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 6, this->staminaPotions);
		if (ok != SQLITE_OK) {
			cout << "Problems binding staminaPotions in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 7, this->score);
		if (ok != SQLITE_OK) {
			cout << "Problems binding score in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}
	ok = sqlite3_bind_int(statement, 8, PlayerFK);
		if (ok != SQLITE_OK) {
			cout << "Problems binding Player Foreign Key in Player Save" << endl;
			cout << sqlite3_errmsg(db) << endl;
		}

	
	ok = sqlite3_step(statement); //Execute statement
	if (ok != SQLITE_DONE) {
		cout << "Problems executing SQLite3 statement in Player Save" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}

	ok = sqlite3_finalize(statement); //Deletes statement and cleans everything up
	if (ok != SQLITE_OK) {
		cout << "Problems finalizing SQLite3 statement in Player Save" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}

	int ID = sqlite3_last_insert_rowid(db); //We can get our auto incremented ID with this method without making extra SQL querries.

	ok = sqlite3_close(db); //Closes connection
	if (ok != SQLITE_OK) {
		cout << "Problems closing Database connection in Player Save" << endl;
		cout << sqlite3_errmsg(db) << endl;
	}

	return ID; //The ID for the row we saved data in
}

void Player::loadPlayer(int PlayerID) {
	


	sqlite3 *db;
	sqlite3_stmt *statement;


	if (sqlite3_open(DB, &db) == SQLITE_OK) {
		string querry;
		if (PlayerID == -1) {
			string name = game.getPlayer().getName();
			querry = "SELECT playerID FROM Player WHERE UserName = ?";
			sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
			sqlite3_bind_text(statement, 1, name.c_str(), name.size(), NULL);
			sqlite3_step(statement);
			PlayerID = sqlite3_column_int(statement, 0);
			sqlite3_finalize(statement);
		}

		querry = "SELECT * FROM PlayerStats WHERE PlayerFK = ?";
		sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
		sqlite3_bind_int(statement, 1, PlayerID);
		sqlite3_step(statement);
		int pokemonID = sqlite3_column_int(statement, 2); //Get PokemonID

		int x = sqlite3_column_int(statement, 3);
		int y = sqlite3_column_int(statement, 4);
		int money = sqlite3_column_int(statement, 5);
		int healthPotions = sqlite3_column_int(statement, 6);
		int staminaPotions = sqlite3_column_int(statement, 7);
		int score = sqlite3_column_int(statement, 8);

		sqlite3_finalize(statement);
		sqlite3_close(db);

		Pokemon pokemon = Pokemon::loadPokemon(pokemonID); //SQL querry that gets pokemon from database
		
		string name = (string)"Player:" + to_string(PlayerID);

		Player player(name, pokemon, money, healthPotions, staminaPotions, score, x, y);
		game.setPlayer(player);
 	}
	
}
