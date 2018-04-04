#include <iostream>
#include <fstream>
#include <string>
#include "libsqlite.hpp"
using namespace std;

////////////////////////////////////////////GETS WEAKNESS////////////////////////////////////////////

       char getWeakness (char namex[])
         try
       {
             //char x;
             cout << "Function - getWeakness for type " << namex <<  ".  Connecting to database..." << endl; 
         
             sqlite::sqlite db( "PokemonNew.sqlite" );
             auto cur = db.get_statement();
             cur->set_sql( "SELECT * from Type where Type = '&namex' ; " ); // pass parameter namex to select
             cur->set_sql( "SELECT * from Type where Type = 'FIRE' ; " );
             cur->prepare();  
         
             while( cur->step() )  {                  // loop over results and display them 
                    cout << cur->get_int(0) << " " << cur->get_text(1) << " " << cur->get_text(2) << " " << endl;
                    cout <<  "Weakness for " << cur->get_text(1) << " is " << cur->get_text(2) << " " << endl;
             }
       }
       catch( sqlite::exception e )      // catch any sql errors
       {
           std::cerr << e.what() << std::endl;
           cout << "Error: " << e.what() << endl;
           return 1;
       };

////////////////////////////////////////////GETS POKEMON ID////////////////////////////////////////////

       char getPokemon (char namey[])
         try
       {
             //char x;
             cout << "Function - getPokemon for type " << namey <<  ".  Connecting to database..." << endl; 
         
             sqlite::sqlite db( "PokemonNew.sqlite" );
             auto cur = db.get_statement();
             cur->set_sql( "SELECT * from PokemonTable where Name = '&namey' ; " ); // pass parameter name to select
             cur->set_sql( "SELECT * from PokemonTable where Name = 'CATTER' ; " );
             cur->prepare();  
         
             while( cur->step() )  {                  // loop over results and display them 
                    cout << cur->get_int(0) << " " << cur->get_int(1) << " " << cur->get_text(2) << " " << cur->get_int(3) << " " << endl;
                    cout <<  "ID for Pokemon " << cur->get_text(2) << " is " << cur->get_int(0) << " " << endl;
             }
       }
       catch( sqlite::exception e )
       {
           std::cerr << e.what() << std::endl;
           cout << "Error: " << e.what() << endl;
           return 1;
       };

////////////////////////////////////////////GETS POKEMON NAME////////////////////////////////////////////


       char getPokemonId (char id[])
         try
       {
             //char x;
             cout << "Function - getPokemon for type " << id <<  ".  Connecting to database..." << endl; 
         
             sqlite::sqlite db( "PokemonNew.sqlite" );
             auto cur = db.get_statement();
             cur->set_sql( "SELECT * from PokemonTable where PokemonID = '&id' ; " ); // pass parameter id to select
             cur->set_sql( "SELECT * from PokemonTable where PokemonID = '4' ; " );
             cur->prepare();  
         
             while( cur->step() )  {
                    cout << cur->get_int(0) << " " << cur->get_int(1) << " " << cur->get_text(2) << " " << cur->get_int(3) << " " << endl;
                    cout <<  "Pokemon Name for id " << cur->get_text(1) << " is " << cur->get_text(2) << " " << endl;
             }
       }
       catch( sqlite::exception e )
       {
           std::cerr << e.what() << std::endl;
           cout << "Error: " << e.what() << endl;
           return 1;
       };

////////////////////////////////////////////GETS ABILITY NAME////////////////////////////////////////////

       char getAbility (char id[])
         try
       {
             //char x;
             cout << "Function - getAbility for type " << id <<  ".  Connecting to database..." << endl; 
         
             sqlite::sqlite db( "PokemonNew.sqlite" );
             auto cur = db.get_statement();
             cur->set_sql( "SELECT * from Ability where Damage >= '&id' ; " ); // pass parameter name to select
             cur->set_sql( "SELECT * from Ability where Damage >= 10 ; " );
             cur->prepare();  
         
             while( cur->step() )  {                  // loop over results and display them 
                    cout << cur->get_int(0) << " " << cur->get_text(1) << " " << cur->get_int(2) << " " << cur->get_int(3) << " " << endl;
                    cout <<  "Ability for Damage " << cur->get_int(2) << " is " << cur->get_text(1) << " " << endl;
             }
       }
       catch( sqlite::exception e )      // catch any sql errors
       {
           std::cerr << e.what() << std::endl;
           cout << "Error: " << e.what() << endl;
           return 1;
       };
 
/////////////////////////////////////////////////////////////////////////////////////////////////////////

 int main (int argc, char *argv[])   
 {
       char* dbtask = argv[1];
       char* namex  = argv[2];
       char* id = argv[3];
       //char weakness;
   
       cout << "Hello in main      - dbtask=" << *dbtask << " namex=" << namex << " user_id =" << id << endl;
       //cout << "In main argv - dbtask=" << argv[1] << " namex=" << argv[2] << " user_id =" << argv[3] << endl;
	 
       switch (*dbtask)
       {
       case '1': // dbtask 1 - gets the Weakness from the type table
              cout << "call function getWeakness parameter type " << namex << endl; 
              getWeakness(namex);              
              break;
           
       case '2': // dbtask 2 – gets pokemon id details for pokemon name
              cout << "call function getPokemon parameter name " << namex << endl; 
              getPokemon(namex);             
              break;
              
       case '3': // dbtask 3 – gets pokemon details for pokemon_id 
              cout << "call function getPokemon parameter id " << id << endl; 
              getPokemonId(id);              
              break;
           
       case '4': // dbtask 4 – gets ability details for damage 
              cout << "call function getAbility parameter id " << id << endl; 
              getAbility(id);             
              break;
          
       } 
       
       return 0;
   
};
