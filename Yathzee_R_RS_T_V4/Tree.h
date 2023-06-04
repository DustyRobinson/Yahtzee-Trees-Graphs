/* 
 * File:   Tree.h
 * Author: Steven
 *
 * Created on May 31, 2023, 9:22 PM
 */

#ifndef TREE_H
#define TREE_H

   struct Tree {
        int data;
        int side;
        struct Tree *left;
        struct Tree* right;
    };

#endif /* TREE_H */

