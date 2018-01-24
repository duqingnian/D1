#include <iostream>
using namespace std;

int main()
{
    cout <<"\tWelcome to my text based game!\n";
    char userName[100];
    cout <<"\nPlease enter your username: ";
    cin >>userName;
    cout <<"Hello, "<<userName<<"!\n\n";

    cout <<"Please pick your race: \n";
    cout <<"1 - Human\n";
    cout <<"2 - Orc\n";
    int pickRace;
    cout <<"Pick your race: ";
    cin >>pickRace;

    switch (pickRace)
    {
           case 1:
                cout <<"You picked the Human race.\n";
                break;
           case 2:
                cout <<"You picked the Orc race.\n";
                break;
           default:
                   cout <<"Error - Invalid input; only 1 or 2 allowed.\n";
    }


    int difficulty;
    cout <<"\nPick your level difficulty: \n";
    cout <<"1 - Easy\n";
    cout <<"2 - Medium\n";
    cout <<"3 - Hard\n";

    cout <<"Pick your level difficulty: ";
    cin >>difficulty;

    switch (difficulty)
    {
           case 1:
                cout <<"You picked Easy.\n\n";
                break;
           case 2:
                cout <<"You picked Medium.\n\n";
                break;
           case 3:
                cout <<"You picked Hard.\n\n";
                break;
           default:
                   cout <<"Error - Invalid input; only 1,2 or 3 allowed.\n";
    }

    system("PAUSE");
    return 1;
}
