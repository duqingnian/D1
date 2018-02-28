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
