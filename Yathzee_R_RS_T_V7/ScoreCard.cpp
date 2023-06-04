#include "Scorecard.h"
#include "Player.h"
#include "Dice.h"
using namespace std;

ScoreCard::ScoreCard(): Dice(),Player() {
    //setting the size of the array of linked list and number of vertices
    length = 24, numSect = 18;
    head = new sCard *[length];

    //string array with the name of the sections of the score card
    sectAry[0] = "Ones", sectAry[1] = "Twos", sectAry[2] = "Threes", sectAry[3] = "Fours", sectAry[4] = "Fives", sectAry[5] = "Sixes", sectAry[6] = "3 of Kind",
    sectAry[7] = "4 of Kind", sectAry[8] = "full House", sectAry[9] = "Small Straight", sectAry[10] = "Large Straight", 
    sectAry[11] = "Yahtzee", sectAry[12] = "Chance", sectAry[13] = "Bonus",sectAry[14] = "Upper",sectAry[15] = "Lower",sectAry[16] = "Total",sectAry[17] = "Lower/Bonus";
    //setting the head pointers to null
    for (int i = 0; i < length; i++) {
        head[i] = nullptr;
    }
    setCard();
}
ScoreCard::~ScoreCard() {
    for (int i = 0; i < length; i++) {
        delete[] head[i];
    }
    delete[] head;
    head = nullptr;
}
void ScoreCard::setCard() {
    //setting all the categories to -1 and numbering the vertex (categories)
    int n = -1;
    for (int j = 0; j < length; j++) {
        for (int i = 0; i < numSect; i++) {
            inVertex(j,i+1, n, sectAry[i]);
        }
    }
}
void ScoreCard::inVertex(int i,  int v, int s, string n) {

        //declaring pointer and node 
        sCard* ptr;
        sCard* link = new sCard;
        //setting the vertex number and value to - 1;
        link->vertex = v;
        link->score = s;
        link->section = n;
        //checking if the list is empty
        if (head[i] == nullptr) {
            head[i] = link;
        }
        else {
            ptr = head[i];
            while (ptr->edge != nullptr) {
                ptr = ptr->edge;
            }
            ptr->edge = link;
        }
}
void ScoreCard::card(int index, set<Player>::iterator j)
{
    sCard* ptr = head[index];
    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << "\t \t \t" << "Player: " << setw(10) << j->getName() << " \t \t\t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|"<< "\tYahtzee"<< "\t\t Score Card"<< "\t\t \t\t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Upper Section          |\t   Lower Section"<< "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 1 - Aces:    "; display(index,1); cout << "\t | \t" << "7. 3 of a Kind : ";display(index,7); cout << "\t \t    |" << endl;
    cout << "| -----------------------------------------------------------------" << endl;
    cout << "| 2 - Twos:    "; display(index,2); cout << "\t | \t""8. 4 of a Kind: "; display(index,8); cout << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 3 - Threes:  "; display(index,3); cout << "\t | \t""9. Full House : " ; display(index,9); cout << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 4 - Fours:   "; display(index,4); cout << "\t | \t" "10. Small Straight : "; display(index,10); cout  << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 5 - Fives:   "; display(index,5); cout << "\t | \t""11. Large Straight : "; display(index,11); cout  << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 6 - Sixes:   "; display(index,6); cout << "\t | \t"<< "12. Yahtzee: "; display(index,12); cout << "\t \t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 13. Chance:  "; display(index,13); cout << "\t \t \t\t\t\t    |" << endl;
    cout << "|-----------------------------------------------------------------|" << endl;
    cout << "|-----------------------------------------------------------------|" << endl;
    cout << "Category? ";

}
void ScoreCard::display(int index, int v ){
    sCard *ptr = head[index];
    
    while(ptr->vertex != v) {
        ptr = ptr->edge;
       }
         cout << setw(2) <<  ptr->score;
}
int ScoreCard::traverse(int index, int v){
    sCard *ptr = head[index];
    
       while(ptr->vertex !=v ) {
        ptr = ptr->edge;
       }
        return ptr->score;
}
void ScoreCard::store(int index, int v, int s){
   sCard *ptr = head[index];
       while(ptr->vertex !=v ) {
        ptr = ptr->edge;
       }
       ptr->score = s;
}
void ScoreCard::printScore(int index, int v){
    sCard *ptr = head[index];
    
    while(ptr->vertex !=v ) {
        ptr = ptr->edge;
       }
         cout << ptr->section << ": ";
         cout << setw(2) <<  ptr->score << endl;
}
void ScoreCard::getScores(int index, set<Player>::iterator j) {
    //display scorecard
    card(index, j);
    //int temp value called max and bool variable set to true
    int pos = 0;
    int max = 0;
    bool tryAgn = true;
    //Start of a do while loop to check is category entered in within bounds.
    do
    {
        cin >> pos;         //choice entered by please
        switch (pos) // switch/case statement
        {
            //while statement to check if condition is true and repeats until condition is false
            while (tryAgn) {
        case 1:             //try catch statement repeated for all 13 cases
            try {
                //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (traverse(index,pos) <0) {
                    //call results function and stores value returned
                    store(index,pos,result(pos));
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 2:
            try { //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (traverse(index,pos) <0) {
                    //call results function and stores value returned
                    store(index,pos,result(pos));
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }
                //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 3://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //call results function and stores value returned
                    store(index,pos,result( pos));
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 4: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //call results function and stores value returned
                    store(index,pos,result(pos));
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 5: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //call results function and stores value returned
                    store(index,pos,result(pos));
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 6: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            while (tryAgn) {
                try {
                    if (traverse(index,pos) <0) {
                        //call results function and stores value returned
                        store(index,pos,result(pos));
                        //outputs value score to verify score was received 
                        printScore(index,pos);
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }//if condition is still true exceptions is thrown
                    else {
                        string taken = "You have already entered score for this category. Choose again: ";
                        throw taken;
                    }
                } //exception handler prompts user to enter again, any category
                catch (string taken) {
                    cout << taken;
                    cin >> pos;
                }
            }
            break;
        case 7: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //call max frequency function and stores value returned
                    max = maxFreq();
                    if (max >= 3)
                    {
                        store(index,pos,product());
                        //outputs value score to verify score was received 
                        printScore(index,pos);
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 3, 0 points is stored
                    else {

                        store(index,pos,0);
                        //outputs value score to verify score was received 
                        printScore(index,pos);
                        tryAgn = false;
                    }
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 8: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //call max frequency function and stores value returned
                    max = maxFreq();
                    if (max >= 4)
                    {
                        store(index,pos,product());
                        //outputs value score to verify score was received 
                        printScore(index,pos);
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 0, 0 points is stored
                    else {
                        store(index,pos,0);
                        //outputs value score to verify score was received 
                        cout << "Quads: ";
                        printScore(index,pos);
                        tryAgn = false;
                    }
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 9: //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //ternary operator for check for full house passed in seFull function
                    store(index,pos,full());
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 10:   // checks to make sure the user actually has a small straight
            try { //if value is -1 which indicates category has yet to be filled out, run functions for storing values
                if (traverse(index,pos) <0) {
                    //ternary operator for check for small straight passed in set small function
                    store(index,pos,smallStraight());
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                }//if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 11:  //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    //ternary operator for check for large straight passed in set large function
                    store(index,pos,largeStraight());
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 12:  //if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                    if (traverse(index,pos) <0) {
                    //max frequency is greater than 4
                    max = maxFreq();
                    if (max > 4)
                    {
                        //set 50 if first Yahtzee
                         store(index,pos,50);
                         printScore(index,pos);
                         tryAgn = false;
                    }
                    else {
                        store(index,pos,0);
                        printScore(index,pos);
                        tryAgn = false;
                    }
                }  //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            }//exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        case 13://if value is -1 which indicates category has yet to be filled out, run functions for storing values
            try {
                if (traverse(index,pos) <0) {
                    store(index,pos,product());
                    //outputs value score to verify score was received 
                    printScore(index,pos);
                    //condition set to false and breaks out of loop and switch case
                    tryAgn = false;
                } //if condition is still true exceptions is thrown
                else {
                    string taken = "You have already entered score for this category. Choose again: ";
                    throw taken;
                }
            } //exception handler prompts user to enter again, any category
            catch (string taken) {
                cout << taken;
                cin >> pos;
            }
            break;
        default:
            cout << " Invalid selection: Choose again: ";
            break;
            }
        }
    } while (pos > 13 || pos < 1); // continues if player choice greater than 13/selection options

}
 int ScoreCard::addScores(int index, int v){
        int temp = 0;
       sCard *ptr = head[index];
       
       while(ptr->vertex != v ) {
           temp+= ptr->score;
           ptr = ptr->edge;
       }
        return temp;
 }
//function for added up all the points for each player by passing pointer to array of player and scorecard object and number of players
void ScoreCard::calScore(int *array, int n, int *scores, string *names)
{
    set<Player>::iterator j = p.begin();
    // Determines the final score with bonus
    for (int i = 0; i < n; i++, j++)
    {
        if (addScores(array[i],6) > 62)
        {
            //populating bonus
            store(array[i],14,35);
            //totaling the upper score
            store(array[i],15,addScores(array[i],6));
            //totaling the lower score
            store(array[i],16,addScores(array[i],13)- addScores(array[i],6));
            //upper score with bonus
            store(array[i],18,addScores(array[i],6) + addScores(array[i],14));
            //totaling final score bonus and adding to an array of stored score
            store(array[i],17,addScores(array[i],17));
            scores[i] = addScores(array[i],17);
            names[i] = j->getName();
        }
        // Determine the final score without bonus
        else if (addScores(array[i],6) <= 62)
        {
            //populating  no bonus
            store(array[i],14,0);
            //totaling the upper score
            store(array[i],15,addScores(array[i],6));
            //totaling the lower score
            store(array[i],16,addScores(array[i],13)- addScores(array[i],6));
            //upper score with bonus
            store(array[i],18,addScores(array[i],6) + addScores(array[i],14));
            //totaling final score bonus and adding to an array of stored score
            store(array[i],17,addScores(array[i],17));
            scores[i] = addScores(array[i],17);
            names[i] = j->getName();
        }
    }
}
void ScoreCard::winner(int *scores, string *names, int player) {
    //compares the scores stored in the array
    int number = scores[0]; // sets the elements at index 0 to the largest number
    int index = 0;        // sets index to 0 and it will store the index that corresponds to the largest number  
    for (int i = 0; i < player; i++) {
        if (scores[i] > number) {
            number = scores[i];
            index = i;
        }
    }
    //outputs the winner and their winning score
    cout << endl;
    cout << "Congratulations " << names[index] << " you're the winner!!!" << endl;
    cout << "Winning score: " << scores[index] << endl;
}

//outputting the winners score card
void ScoreCard::finalScore(int *array,int n) {
    
     set<Player>::iterator it = p.begin();
    
    for (int i = 0; i < n; i++, it++)
    {
        cout << endl;
        cout << " __________________________________________________________________" << endl;
        cout << "|" << "\t \t \t" << "Player: " << setw(10) << it->getName()<< " \t \t\t    |" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|"<< "\tYahtzee"<< "\t\t Score Card"<< "\t\t \t\t    |" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Upper Section" <<"\t\t\t\t\t\t\t     |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Aces:    "; display(array[i],1); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "| -----------------------------------------------------------------" << endl;
        cout << "| Twos:    "; display(array[i],2); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Threes:  "; display(array[i],3); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fours:   "; display(array[i],4); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fives:   "; display(array[i],5); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Sixes:   "; display(array[i],6); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total Score:"; display(array[i],15); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Bonus: "; display(array[i],14); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total with bonus:"; display(array[i],18); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 3 of a Kind : "; display(array[i],7); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 4 of a Kind: "; display(array[i],8); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Full House : "; display(array[i],9); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Small Straight : "; display(array[i],10); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Large Straight : "; display(array[i],11); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Yahtzee: "; display(array[i],12); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Chance:  "; display(array[i],13); cout <<"\t\t\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Upper Section: "; display(array[i],18); cout <<"\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Lower Section: "; display(array[i],16); cout <<"\t\t\t\t\t    |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Grand Total: "; display(array[i],17); cout <<"\t\t\t\t\t\t    |"<< endl;
        cout << "|__________________________________________________________________" << endl << endl;
    }
}


