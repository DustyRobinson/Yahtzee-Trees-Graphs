/* 
 * File:   ScoreCard.h
 * Author: Steven
 *
 * Created on June, 4 2023, 11:53 AM
 */

#ifndef SCORECARD_H
#define SCORECARD_H
#include<set>
#include <iomanip>
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
    string sectAry[18];

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
    int addScores(int, int);
    void calScore(int*, int n, int *, string *);
    void card(int i, set<Player>::iterator j);
    void finalScore(int*,int);
    void winner(int *, string *, int);
};


#endif /* SCORECARD_H */

