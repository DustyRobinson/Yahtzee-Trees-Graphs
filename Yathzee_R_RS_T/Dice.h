/* 
 * File:   Dice.h
 * Author: Steven
 *
 * Created on May 23, 2023, 10:30 PM
 */

#ifndef DICE_H
#define DICE_H

#include <map>
#include <list>

using namespace std;

class Dice{

protected:
    int side;
    int size;
    map<int, Dice> d;
    int *array;

public:

    Dice() { side = 0; size = 6; array = new int[size]; }
    ~Dice(){delete array;}
    void setSide(int s) { side = s; }
    int getSide()const { return side; }
    void getVal();
    //function for displaying dice roll  
    void roll();
    //Function for re-rolling dice  
    void reRoll();
    //function for total dice values  
    int result(int);
    //function for a full house 
    int full();
    //function for a small straight 
    int smallStraight();
    //function for a large straight
    int largeStraight();
    //function for a getting max frequency if dice values selected defined 
    int maxFreq();
    //function for a total all dice values selected 
    int product();
};

#endif /* DICE_H */

