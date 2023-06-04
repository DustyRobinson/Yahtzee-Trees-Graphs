/* 
 * File:   ScoreCard.h
 * Author: Steven
 *
 * Created on May 24, 2023, 9:44 PM
 */

#ifndef SCORECARD_H
#define SCORECARD_H
#include<set>
#include<list>
#include<map>
#include <iomanip>
#include <stack>
#include "Dice.h"
#include "Player.h"

using namespace std;

class ScoreCard: public Dice, public Player  {
 //Protected member variables   
protected:
    struct sCard {
        int vertex, score;
        string section;
        sCard* edge;
    };
    sCard **head;
    int length, numSect;
    string sectAry[13];

public:
    ScoreCard();
    ~ScoreCard();
    void inVertex(int, int, int, string);
    void setCard();
    int traverse(int, int);
    void store(int, int, int);
    void printScore(int,int);
    void display (int,int);
    void getScores(int, set<Player>::iterator);
    //void calScore(stack<int>&, stack<string>&);
    void card(int i, set<Player>::iterator j);
    //void finalScore();
    //void winner(stack<int>&,stack<string> &);
};


#endif /* SCORECARD_H */

