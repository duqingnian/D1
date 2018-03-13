#include <iostream>
#include <fstream>
#include <string>
 
int main(int dbtask)
{
       // need to initialise any variables here 
 
      // passed in as 1, 2, 3, 4, 5.....
 
       switch (dbtask) {
       case 1:
              int newuser(char name);   // Creates new user. Returns user_id as integer and reads in username as character 
              break;
       case 2:
              int getuserid(char name); //Gets existing user_id. Returns user_id as integer and reads in username as character 
              break;
       case 3:
              int getuserpoints(int user_id); //Gets existing user_id. Returns user_points as integer. int newuser(char name)
              break;
       case 4:
              int getpower(int user_id); // gets existing user's power using the user_id
              break;
       case 5:
              int getability(int user_id); // gets the ability for the user
              break;
       case 6:
              int gettype(int user_id);  // gets the type for the user. 
              break;
       }
 
       int newuser(char name)
       {
              cmd.setCommandText("insert into username(user_id, user_name, total_points) values (user_seq.nextval, &name, 0");
              cmd.Execute();
              con.Commit();   //commits the insert to the database
              cmd.setCommandText("select user_id from username where name = '&name'"); // returns the user_id back for new user.
              return cmd.Execute(); // executes the select command and returns the value of user_id              
       }
 
       int getuserid(char name)
       {
              cmd.setCommandText("select user_id from username where name = '&name'"); // returns the user_id back for user.
              return cmd.Execute();
       }
 
       int getuserpoints(int user_id)
       {
              cmd.setCommandText("select total_points from username where user_id = '&user_id'"); // returns the total_points back for user_id.
              return cmd.Execute();
       }
 
       int getpower(int user_id)
       {
              cmd.setCommandText("select power??_value from pokemon, power where pokemon.user_id = '&user_id' and power.pokemon_id = pokemon.pokemon_id"); // returns the power back for user.
              return cmd.Execute();
       }
 
       int getability(int user_id)
       {
              cmd.setCommandText("select ability??_value from ability, pokemon where pokemon.user_id = '&user_id' and ability.pokemon_id = pokemon.pokemon_id"); // returns the ability back for user.
              return cmd.Execute();
       }
 
       int gettype(int user_id)
       {
              cmd.setCommandText("select type??_value from type, pokemon where pokemon.user_id = '&user_id' and type.pokemon_id = pokemon.pokemon_id"); // returns the power back for user.
              return cmd.Execute();
       }
 
 
} // end main

