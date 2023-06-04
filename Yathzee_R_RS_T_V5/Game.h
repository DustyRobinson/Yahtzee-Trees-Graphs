/* 
 * File:   PlayGame.h
 * Author: Steven
 *
 * Created on May 24, 2023, 10:16 PM
 */

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <iostream> 
#include <stack>
#include "Dice.h"
#include "Player.h"
#include "Scorecard.h"
#include "RuleBook.h"

class Game: public ScoreCard, public RuleBook {

public:
    Game(): ScoreCard(), RuleBook(){};
    //Function the runs the Yahtzee game
    void playGame();
    void start(int, int);
    void menu();
    void winner(stack<int>&,stack<string> &);
};


#endif /* PLAYGAME_H */

