#include "Pokemon.h"
#include <sstream>
#include "OurPokemons.h"

//Initialising a pokemon
Pokemon::Pokemon() {
	this->name = "";
	this->level = 0;
	this->exp = 0;
	this->strength = 0;
	this->agility = 0;
	this->HP = 0;
	this->maxHP = 0;
	this->stamina = 0;
	this->maxStamina = 0;
	this->weakness = "";
	this->type = "";
	this->pictureFileName = "";
	this->ability1 = Ability();
	this->ability2 = Ability();
	this->ability3 = Ability();
}

Pokemon::Pokemon(string name, int level,
	int exp, int strength, int agility,
	int hp, int maxHP, int maxStamina,
	string weakness, string type,
	string pictureFileName,
	Ability ability1,
	Ability ability2,
	Ability ability3) {
	this->name = name;
	this->level = level;
	this->exp = exp;
	this->strength = strength;
	this->agility = agility;
	this->HP = maxHP;
	this->maxHP = maxHP;
	this->stamina = maxStamina;
	this->maxStamina = maxStamina;
	this->weakness = weakness;
	this->type = type;
	this->pictureFileName = pictureFileName;
	this->ability1 = ability1;
	this->ability2 = ability2;
	this->ability3 = ability3;
}
Pokemon::~Pokemon() {

}

void Pokemon::heal(int healAmount) { //Heal back HP
	int newHP = this->HP + healAmount;
	if (newHP > maxHP) {
		this->HP = maxHP;
	}
	else {
		this->HP = newHP;
	}
}
void Pokemon::addStamina(int staminaAmount) { //Heal back HP
	int newStamina = this->stamina + staminaAmount;
	if (newStamina > maxStamina) {
		this->stamina = maxStamina;
	}
	else {
		this->stamina = newStamina;
	}
}
void Pokemon::levelUp() { //level Up
	if (this->exp >= 100) {
		//If enough xp
		this->level += 1;
		this->exp -= 100;
		this->strength += 5;
		this->agility += 5;
		this->maxHP += 10;
		this->HP = this->maxHP;
		this->maxStamina += 10;
		this->stamina = this->maxStamina;

		cout << this->name << " leveled up to level: " << this->level << endl;
	}
	else {
		cout << "Not enough XP to level up" << endl;
	}

}
void Pokemon::receiveDmg(const int dmg) { //Subtract HP
	int newHP = this->HP - dmg;
	if (newHP < 0) {
		this->HP = 0;
	}
	else {
		this->HP = newHP;
	}
}
void Pokemon::printStats() {
	//For displaying stats in the terminal window
	cout << "Name:" << this->name << endl;
	cout << "Level:" << this->level << endl;
	cout << "Experience:" << this->exp << endl;
	cout << "Strength:" << this->strength << endl;
	cout << "Agility:" << this->agility << endl;
	cout << "HP:" << this->HP << "/" << this->maxHP << endl;
	cout << "Stamina:" << this->stamina << "/" << this->maxStamina << endl;
	cout << "Weakness:" << this->weakness << endl;
	cout << "Type:" << this->type << endl;
}
System::String^ Pokemon::labelStats() {
	//For displaying stats in a graphical user interface
	stringstream ss;
	ss << "Name: " << this->name << endl;
	ss << "Level: " << this->level << endl;
	ss << "Experience: " << this->exp << endl;
	ss << "Strength: " << this->strength << endl;
	ss << "Agility: " << this->agility << endl;
	ss << "HP: " << this->HP << "/" << this->maxHP << endl;
	ss << "Stamina: " << this->stamina << "/" << this->maxStamina << endl;
	ss << "Weakness: " << this->weakness << endl;
	ss << "Type: " << this->type << endl;
	return gcnew System::String(ss.str().c_str());
}
int Pokemon::savePokemon() {
	//Saves this pokemons current stats into database

	sqlite3 *dbp;
	sqlite3_open(DB, &dbp);
	

	sqlite3_stmt * saving = nullptr;
	string command = "SELECT MAX(PowerID) FROM Power";
	sqlite3_prepare(dbp, command.c_str(), command.size() + 1, &saving, nullptr);
	sqlite3_step(saving);
	int maxID = sqlite3_column_int(saving, 0);

	sqlite3_finalize(saving);

	int check;

	command = "INSERT INTO Power VALUES(?, ?, ?, ?, ?, ?, ?, ?, ?)";
	check = sqlite3_prepare(dbp, command.c_str(), command.size() + 1, &saving, nullptr);

	check = sqlite3_bind_int(saving, 1, maxID + 1);
	check = sqlite3_bind_int(saving, 2, this->level);
	check = sqlite3_bind_int(saving, 3, this->HP);
	check = sqlite3_bind_int(saving, 4, this->maxHP);
	check = sqlite3_bind_int(saving, 5, this->exp);
	check = sqlite3_bind_int(saving, 6, this->agility);
	check = sqlite3_bind_int(saving, 7, this->strength);
	check = sqlite3_bind_int(saving, 8, this->maxStamina);
	check = sqlite3_bind_int(saving, 9, 0);

	check = sqlite3_step(saving);
	check = sqlite3_finalize(saving);

	command = "INSERT INTO PokemonTable(PokemonID, TypeID, Name, PowerID) VALUES(?, 0, ?, ?)";
	check = sqlite3_prepare(dbp, command.c_str(), command.size() + 1, &saving, nullptr);
	check = sqlite3_bind_int(saving, 1, maxID + 1);
	check = sqlite3_bind_text(saving, 2, this->name.c_str(), this->name.size(), NULL);
	check = sqlite3_bind_int(saving, 3, maxID + 1);
	check = sqlite3_step(saving);
	check = sqlite3_finalize(saving);
	check = sqlite3_close(dbp);

	return maxID + 1; //Returns the ID for this save
}


Pokemon Pokemon::loadPokemon(int pokemonID) {
	//Loads pokemon based on unique ID
	//And returns that pokemons object

	sqlite3 *db;
	sqlite3_stmt *statement = nullptr;

	if (sqlite3_open(DB, &db) == SQLITE_OK) {
		string querry;
		
		querry = "SELECT * FROM PokemonTable WHERE PokemonID = ?";
		sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_bind_int(statement, 1, pokemonID);
		cout << sqlite3_errmsg(db) << endl;
		sqlite3_step(statement);
		cout << sqlite3_errmsg(db) << endl;
		const unsigned char * pokemonName1 = sqlite3_column_text(statement, 2);
		string pokemonName = (char*)pokemonName1;

		sqlite3_finalize(statement);
		Pokemon pokemon;
		for (Pokemon *p : pokemonArray) { //Based on pokemon name, get pokemon object
			if (p->getName() == pokemonName) {
				pokemon = *p;
			}
		}
		

		querry = "SELECT * FROM Power WHERE PowerID = ?";
		sqlite3_prepare(db, querry.c_str(), querry.size() + 1, &statement, nullptr);
		sqlite3_bind_int(statement, 1, pokemonID);
		sqlite3_step(statement);
		
		pokemon.level = sqlite3_column_int(statement, 1);
		pokemon.HP = sqlite3_column_int(statement, 2);
		pokemon.maxHP = sqlite3_column_int(statement, 3);
		pokemon.exp = sqlite3_column_int(statement, 4);
		pokemon.agility = sqlite3_column_int(statement, 5);
		pokemon.strength = sqlite3_column_int(statement, 6);
		pokemon.stamina = sqlite3_column_int(statement, 7);
		pokemon.maxStamina = pokemon.stamina;

		sqlite3_finalize(statement);
		sqlite3_close(db);


		return pokemon;
	}
}