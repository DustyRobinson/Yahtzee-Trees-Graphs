/* 
 * File:   PlayGame.h
 * Author: Steven
 *
 * Created on June, 4 2023, 11:53 AM
 */

#ifndef PLAYGAME_H
#define PLAYGAME_H

#include <iostream> 
#include "Dice.h"
#include "Player.h"
#include "Scorecard.h"
#include "RuleBook.h"

class Game: public ScoreCard, public RuleBook {

public:
     //Constructor
    Game(): ScoreCard(), RuleBook(){};
    //Function the runs the Yahtzee game
    void playGame();
    void start(int *,int, int);
    void menu();
};


#endif /* PLAYGAME_H */

