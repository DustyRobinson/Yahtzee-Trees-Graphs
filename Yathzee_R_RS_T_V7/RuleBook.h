/* File:   RuleBook.h
 * Author: Steven
 *
 * Created on June, 4 2023, 11:53 AM
 */

#ifndef RULEBOOK_H
#define RULEBOOK_H

#include<iostream>
#include <fstream>  

using namespace std;

class RuleBook {

public:
	string text;
        //Constructor
	RuleBook() { text = " "; }
         //Mutator member functions
	void setString(string word) { text = word; }
         //Accessor member functions
	string getString()const { return text; }
	void prtRules(fstream& );
};

#endif /* RULEBOOK_H */

