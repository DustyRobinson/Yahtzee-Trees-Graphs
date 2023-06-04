/* File:   RuleBook.h
 * Author: Steven
 *
 * Created on May 24, 2023, 10:48 PM
 */

#ifndef RULEBOOK_H
#define RULEBOOK_H

#include<iostream>
#include <fstream>  

using namespace std;

class RuleBook {

public:
	string text;
	RuleBook() { text = " "; }
	void setString(string word) { text = word; }
	string getString()const { return text; }
	void prtRules(fstream& );
};

#endif /* RULEBOOK_H */

