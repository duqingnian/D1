// FOR THIS TO WORK, YOU'LL NEED TO RUN THE SQL FILES IN THE TERMINAL (APPS ANYWHERE) FIRST AND THEN COMMIT.
// SO TYPE: connect/@acal
//          THEN COPY AND PASTE ALL THE SQL STATEMENTS INTO THE TERMINAL
//          THEN TYPE: commit
//          AND DO THAT FOR EACH FILE

#include <iostream>
#include <fstream>
#include <string>
//  using namespace std;

int main(int dbtask)
{
	// need to initialise any variables here 

	//  dbtask; // passed in as 1, 2, 3, 4, 5.....

	switch (dbtask) {
  case 1:
		int newuser(char name);   // Creates new user. Returns userid as integer and reads in username as character 
		break;
	case 2:
		int getuserid(char name); //Gets existing userid. Returns userid as integer and reads in username as character 
		break;
	case 3:
		int getuserpoints(int userid); //Gets existing userid.s Returns totalpoints as integer. int newuser(char name)
		break;
	case 4:
	int getpower(int userid); // gets existing user's power using the userid
		break;
	case 5:
		int getability(int userid); // gets the ability for the user
		break;
	case 6:
		int gettype(int userid);  // gets the type for the user. 
		break;
	}

	int newuser(char name)
	{
		cmd.setCommandText("insert into username(userid, username, totalpoints) values (user_seq.nextval, &name, 0");
		cmd.Execute();
		con.Commit();   //commits the insert to the database
		cmd.setCommandText("select userid from username where name = '&name'"); // returns the user_id back for new user.
		return cmd.Execute(); // executes the select command and returns the value of user_id              
	}

	int getuserid(char name)
	{
		cmd.setCommandText("select userid from username where name = '&name'"); // returns the user_id back for user.
		return cmd.Execute();
	}

	int getuserpoints(int userid)
	{
		cmd.setCommandText("select total_points from username where userid = '&userid'"); // returns the total_points back for user_id.
		return cmd.Execute();
	}

	int getpower(int userid)
	{
		cmd.setCommandText("select power from pokemon, power where pokemon.userid = '&userid' and power.pokemonid = pokemon.pokemonid"); // returns the power back for user.
		return cmd.Execute();
	}

	int getability(int userid)
	{
		cmd.setCommandText("select abilityident from ability, pokemon where pokemon.userid = '&userid' and ability.pokemonid = pokemon.pokemonid"); // returns the ability back for user.
		return cmd.Execute();
	}

	int gettype(int userid)
	{
		cmd.setCommandText("select type from type, pokemon where pokemon.userid = '&userid' and type.pokemonid = pokemon.pokemonid"); // returns the power back for user.
		return cmd.Execute();
	}


} // end main
