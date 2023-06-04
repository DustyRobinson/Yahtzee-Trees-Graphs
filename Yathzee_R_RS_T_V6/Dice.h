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
#include "Tree.h"

class Dice{

protected:
    Tree* root;
    int *array;
    int size;
public:

    Dice() { size = 5; array = new int[size]; root = NULL; }
    ~Dice(){delete array; destroy(root);}
    void insertNode(int,int);
    void insert(Tree*&, Tree*&);
    void deleteNode(int, Tree *&);
    void PreOrder(Tree*)const;
    bool search(int);
    void destroy(Tree*);
    int transfer(int);
    void getVal();
    void roll();
    void reRoll();
    int result(int);
    int full();
    int smallStraight();
    int largeStraight();
    int maxFreq();
    int product();
    int partition(int, int);
    void quickSort(int, int);
    void PreOrder()const {
        PreOrder(root);
    }
};

#endif /* DICE_H */

