#include "Player.h"

using namespace std;


void Player::getPlayers(int& num) {
    // Game variables
    bool tryAgn = false;
    //prompts owner for the number of players playing the game
    cout << "How many players: ";
    cin >> num;
    //while loop that will keep running if condition is true
    while (tryAgn) {
        try {
            //if the owner/user enters a non negative value condition is set to false and breaks out of loop
            if (num > 0) {
                tryAgn = true;
            }
            //if condition is still true (user enter a negative number exception is thrown
            else {
                string excep = "Invalid input. Enter again: ";
                throw excep;
            }
        }
        //catch statement catch exception and used exception handles for re-entry
        catch (string excep) {
            cout << excep;
            cin >> num;
        }
    }
}
int *Player::plyNames(int& num) {
    int *temp = new int [num];
    cin.ignore();
    string n;

    //for loop for getting each players name
    for (int i = 0; i < num; i++) {
        cout << "Enter Player " << i + 1 << " Name: ";
        getline(cin, n);
        p.emplace(n);
        temp[i] = BKDRHash(n)%24;
    }
    return temp;
}
//prints the names of the players in ascending order
void Player::print() {
    //display names
    for (auto it = p.begin(); it != p.end(); it++) {
        cout << it->getName() << endl;
    }
    cout << endl;
}
//BKDRHash function to pass names and output a value/index
unsigned int Player::BKDRHash(const string& str)
{
    unsigned int seed = 131; 
    unsigned int hash = 0;

    for (size_t i = 0; i < str.length(); i++)
    {
        hash = (hash * seed) + str[i];
    }

    return hash;
}
