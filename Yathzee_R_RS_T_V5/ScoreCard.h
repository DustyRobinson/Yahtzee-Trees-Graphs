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


class ScoreCard: public Dice, public Player {
    //Protected member variables
protected:
    list <ScoreCard> s;
    
    int score, one, two, three, four, five, six;
    int trip, quad, small, large, chance, fHouse;
    int yazy, bonus, total, upper, lower;
public:
    //Default constructor
    ScoreCard();
    //Mutator member variables
    void setOne(int o) { one = o; }
    void setTwo(int tw) { two = tw; }
    void setThree(int th) { three = th; }
    void setFour(int fr) { four = fr; }
    void setFive(int fi) { five = fi; }
    void setSix(int sx) { six = sx; }
    void setTrip(int tp) { trip = tp; }
    void setQuad(int qd) { quad = qd; }
    void setFull(int fh) { fHouse = fh; }
    void setSmall(int sm) { small = sm; }
    void setLarge(int lg) { large = lg; }
    void setYazy(int yz) { yazy = yz; }
    void setChan(int ch) { chance = ch; }
    void setBonus(int bn) { bonus = bn; }
    void setScore(int sc) { score = sc; }
    void setTotal(int t) { total = t; }
    void setUpper(int up) { upper = up; }
    void setLower(int lw) { lower = lw; }
    //virtual Accessor function
    virtual int getScore()const { return score; }
    //Accessor function
    int getOne() const { return one; }
    int getTwo()const { return two; }
    int getThree()const { return three; }
    int getFour()const { return four; }
    int getFive()const { return five; }
    int getSix()const { return six; }
    int getTrip()const { return trip; }
    int getQuad()const { return quad; }
    int getFull()const { return fHouse; }
    int getSmall()const { return small; }
    int getLarge()const { return large; }
    int getYazy()const { return yazy; }
    int getChan()const { return chance; }
    int getBon()const { return bonus; }
    int getTotal()const { return total; }
    int getUpper() const { return upper; }
    int getLower() const { return lower; }
    //created the scorecard
    void create(int &);
    //get scores from the player based on dice rolled
    void getScores(list<ScoreCard>::iterator, set<Player>::iterator);
    //Functions for calculate scorecard for each category
    void calScore(stack<int>&, stack<string>&);
    //Displays scorecard with real time updated scores 
    void card(list<ScoreCard>::iterator, set<Player>::iterator j);
    //Functions to calculate final score for reach player   
    void finalScore();
    void winner(stack<int>&,stack<string> &);
};


#endif /* SCORECARD_H */

