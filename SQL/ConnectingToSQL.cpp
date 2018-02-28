// FOR THIS TO WORK, YOU'LL NEED TO RUN THE SQL FILES IN THE TERMINAL (APPS ANYWHERE) FIRST AND THEN CONNECT TO THE SERVER.
// SO TYPE: connect/@acal
//          THEN COPY AND PASTE ALL THE SQL STATEMENTS INTO THE TERMINAL FROM THE FILE POKEMONDATABASEWITHJOINING.SQL
//          THEN TYPE: commit
//          AND DO THAT FOR EACH FILE
// AND THEN RUN THE FILE CONNECTINGTOSQL.CPP BEFORE RUNNING RETRIEVINGINFO.CPP

#include <SQLAPI\include\SQLAPI.h>
#include <iostream>

using namespace std;

int main()
{
	sqlplus::sqlplus db("acal"); // opens database
	cur->set - sql("SELECT P.PokemonID, P.Name, A.AbilityID, A.Damage, A.Mana, T.Type, T.Weakness, W.PowerID, W.Lvl FROM PokemonTable P, Ability A, AbilityIDENT AI, Type T, Power W where P.PokemonID = AI.PokemonID and A.AbilityID = AI.AbilityID and P.TypeID = T.TypeID and P.PowerID = W.PowerID; ")
		cur->prepare();

	while (cur->step())
		cout << cur->get_int(0) << cur->get_text(1) << endl;
}
