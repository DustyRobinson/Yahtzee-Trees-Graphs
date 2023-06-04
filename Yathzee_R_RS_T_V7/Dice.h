/* 
 * File:   Dice.h
 * Author: Steven
 *
 * Created on June, 4 2023, 11:53 AM
 */

#ifndef DICE_H
#define DICE_H

using namespace std;
#include "Tree.h"

class Dice{

protected:
    Tree* root;
    int *array;
    int size;
public:
    //Constructor
    Dice() { size = 5; array = new int[size]; root = NULL; }
    ~Dice(){delete array; destroy(root);}
    //Accessor member functions
    void insertNode(int,int);
    void insert(Tree*&, Tree*&);
    void deleteNode(int, Tree *&);
    void PreOrder(Tree*)const;
    void search(int);
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

