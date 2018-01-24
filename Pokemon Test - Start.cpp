//I've added this stuff in only to test if the mouse handling and keyboard functions work (which I will upload soon)

#include <iostream>
#include <chrono> //name of a header and a sub-namespace. It's used in all things related to time (clocks, time spans and references to specific time points)
#include <thread>
using namespace std;

int main()
{
    
    cout <<"\n...Hello? Is someone there? "<< endl;
    using namespace std::this_thread;      // <thread> refers to the sleep_until
    using namespace std::chrono_literals;  // choose either h = hours, s = seconds, ms = miliseconds (etc)
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 2s); // uses the time from when the last line is executed (eg: wait 2 seconds since the last line has been executed)
    
    cout <<"Ah, there you are.\n"<< endl; // the \n adds a new line before it.. I only added them because I thought it looked neater (but you can remove them if you want to)
    using namespace std::this_thread; // the this_thread finds the name for the function it's working with 
    using namespace std::chrono_literals; // the chrono_literals accesses the class duration, and makes the literal values become visible (the h = hours, s = seconds etc are the literals)
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 1s);
    
    char userName[20]; // length of userName cannot be greater than (eg) 20 characters
   
    std::cout << "What is your name? \n";
    std::cin.getline(userName, 20); // gets the line for the userName...

    userName[0] = toupper(userName[0]); // ... and converts it to sentence/title case (so the first character is capitalised and the rest is ignored).
    for (int i = 1; i < 20; i++) // means that for every letter in userName, that's less than 20 characters...
    {
         if ( userName[i - 1] == ' ' ) // ... it checks to see if the first letter is present...
             userName[i] = toupper( userName[i] ); // ... and then converts only this letter to uppercase.
    }
    
    cout << "\nHello, " <<userName<< "!" << endl;
    cout << "\nMy name is Professor Oak! Welcome to the world of Pokemon!" << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 2s);
    cout << "\nPokemon are small creatures that inhabit this world..." << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 2s);
    cout << "Some people like to keep them as pets, but others like to use them in battle." << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 2s);
    cout << "\nOh, me? I like to study them as a profession." << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 2s);
    cout << "I guess that's all I have to say for now." << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 4s);
    cout << "\nWell? Don't just stand there! Go on, a world of adventure with Pokemon awaits!" << endl;
    
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    sleep_until(system_clock::now() + 3s);
    
    cout << "\nSo, what do you want to do first? \n" ;
    cout << "1 -- \n" ;
    cout << "2 -- \n" ;
    int pickChoice;
    cin >>pickChoice;

    switch (pickChoice)
    {
           case 1:
                cout <<"You chose to -- \n";
                break;
           case 2:
                cout <<"You chose to -- .\n";
                break;
           default:
                   cout <<"Sorry, what? I didn't quite understand that...";
    }

}

// it's not yet completed, but I was also thinking that we could add a difficulty setting?
// I also need to fix up some of the errors (the code right now accepts numbers as input) and that needs to be changed still...
// also, the bit that ends (above) needs to be changed (if you're all happy with keeping it)
