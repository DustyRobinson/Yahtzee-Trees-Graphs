/* 
 * File:   Player.h
 * Author: Steven
 *
 * Created on May 24, 2023, 9:23 PM
 */

#ifndef PLAYER_H
#define PLAYER_H
#include <set>
#include<iostream>

using namespace std;

class Player {
    //Protected variables
protected:
    string name;
    set<Player> p;

public:
    //Constructor
    Player () { name = " ";}
    Player(string n) { name = n; }
    //Mutator member functions
    void setName(string n) { name = n; }
    //Accessor member functions
    string getName()const { return name; }
    //Overloaded < operator defined in player.cpp
    friend bool operator< (const Player& c1, const Player& c2) { return c1.name < c2.name; };
    void getPlayers(int&);
    int *plyNames(int&);
    void print();
    unsigned int BKDRHash(const string&);
};



#endif /* PLAYER_H */

