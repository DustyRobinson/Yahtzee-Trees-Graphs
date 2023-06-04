/* 
 * File:   Tree.h
 * Author: Steven
 *
 * Created on June, 4 2023, 11:53 AM
 */

#ifndef TREE_H
#define TREE_H

   struct Tree {
        int data;
        int die;
        struct Tree *left;
        struct Tree* right;
    };

#endif /* TREE_H */

