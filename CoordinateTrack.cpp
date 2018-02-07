#include <conio.h>
#include <iostream>
using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ENTER 13

int main()
{
    int c = 0;
    int xCord = 50;
    int yCord = 50;
    cout << "X=" << xCord << "   Y=" << yCord << '\r' ;

    while(1)
    {
        c = 0;


        switch((c=getch())) {
        case KEY_UP:
            if (yCord<99){
            yCord++;
            }
            cout << "X=" << xCord << "   Y=" << yCord << '\r' ;//key up
            break;
        case KEY_DOWN:
            if (yCord>10){
            yCord--;
            }
            cout << "X=" << xCord << "   Y=" << yCord << '\r';   // key down
            break;
        case KEY_LEFT:
            if (xCord>10){
            xCord--;
            }
            cout << "X=" << xCord << "   Y=" << yCord << '\r';  // key left
            break;
        case KEY_RIGHT:
            if (xCord<99){
            xCord++;
            }







            cout << "X=" << xCord << "   Y=" << yCord << '\r';  // key right
            break;
        //default:
            //cout << endl << "null" << endl;  // not arrow
            //break;
        case KEY_ENTER:
            cout<< endl << "You pressed enter. ok"; // exit
            break;
        }

    }

    return 0;
}
