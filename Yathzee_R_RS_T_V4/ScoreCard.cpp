#include "Scorecard.h"
#include "Player.h"
#include "Dice.h"
using namespace std;

ScoreCard::ScoreCard(): Dice(),Player() {
    //empty score card, well with -1 value
    score = -1, one = -1, two = -1, three = -1;
    four = -1, five = -1, six = -1, trip = -1;
    quad = -1, small = -1, large = -1, chance = -1;
    fHouse = -1, yazy = -1, bonus = -1;
    total = -1, upper = -1, lower = -1;
}
void ScoreCard::create(int & n){
    for(int i = 0; i < n; i++){
        s.emplace_back();
    }
}
void ScoreCard::card(list<ScoreCard>::iterator i, set<Player>::iterator j)
{
    cout << "Chose any empty category. Values with a -1 have yet to be filled out" << endl << endl;
    cout << " __________________________________________________________________" << endl;
    cout << "|" << "\t \t \t" << "Player: " << setw(10) << j->getName() << " \t \t\t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "|"<< "\tYahtzee"<< "\t\t Score Card"<< "\t\t \t\t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| Upper Section          |\t   Lower Section"<< "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 1 - Aces:    " << setw(2) << i->getOne() << "\t | \t" << "7. 3 of a Kind : " << setw(2) << i->getTrip() << "\t \t    |" << endl;
    cout << "| -----------------------------------------------------------------" << endl;
    cout << "| 2 - Twos:    " << setw(2) << i->getTwo() << "\t | \t""8. 4 of a Kind: " << setw(2) << i->getQuad() << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 3 - Threes:  " << setw(2) << i->getThree() << "\t | \t""9. Full House : " << setw(2) << i->getFull() << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 4 - Fours:   " << setw(2) << i->getFour()<< "\t | \t" "10. Small Straight : "<< setw(2) << i->getSmall() << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 5 - Fives:   " << setw(2) << i->getFive()  << "\t | \t""11. Large Straight : " << setw(2) << i->getLarge() << "\t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 6 - Sixes:   " << setw(2) << i->getSix()<< "\t | \t"<< "12. Yahtzee: " << setw(2) << i->getYazy() << "\t \t \t    |" << endl;
    cout << "|------------------------------------------------------------------" << endl;
    cout << "| 13. Chance:  " << setw(2) << i->getChan() << "\t \t \t\t\t\t    |" << endl;
    cout << "|-----------------------------------------------------------------|" << endl;
    cout << "|-----------------------------------------------------------------|" << endl;
    cout << "Category? ";
}
void ScoreCard::getScores(list<ScoreCard>::iterator i, set<Player>::iterator j) {
    //display scorecard
    card(i, j);
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
                if (i->getOne() < 0) {
                    //call results function and stores value returned
                    i->setOne(result( pos));
                    //outputs value score to verify score was received 
                    cout << "Ones: " << i->getOne() << endl;
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
                if (i->getTwo() < 0) {
                    //call results function and stores value returned
                    i->setTwo(result(pos));
                    //outputs value score to verify score was received 
                    cout << "Twos: " << i->getTwo() << endl;
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
                if (i->getThree() < 0) {
                    //call results function and stores value returned
                    i->setThree(result(pos));
                    //outputs value score to verify score was received 
                    cout << "Threes: " << i->getThree() << endl;
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
                if (i->getFour() < 0) {
                    //call results function and stores value returned
                    i->setFour(result(pos));
                    //outputs value score to verify score was received 
                    cout << "Fours: " << i->getFour() << endl;
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
                if (i->getFive() < 0) {
                    //call results function and stores value returned
                    i->setFive(result(pos));
                    //outputs value score to verify score was received 
                    cout << "Fives: " << i->getFive() << endl;
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
                    if (i->getSix() < 0) {
                        //call results function and stores value returned
                        i->setSix(result(pos));
                        //outputs value score to verify score was received 
                        cout << "Sixes: " << i->getSix() << endl;
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
                if (i->getTrip() < 0) {
                    //call max frequency function and stores value returned
                    max = maxFreq();
                    if (max >= 3)
                    {
                        i->setTrip(product());
                        //outputs value score to verify score was received 
                        cout << "Triple: " << i->getTrip() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 3, 0 points is stored
                    else {

                        i->setTrip(0);
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getTrip() << endl;
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
                if (i->getQuad() < 0) {
                    //call max frequency function and stores value returned
                    max = maxFreq();
                    if (max >= 4)
                    {
                        i->setQuad(product());
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getQuad() << endl;
                        //condition set to false and breaks out of loop and switch case
                        tryAgn = false;
                    }
                    //max frequency is less than 0, 0 points is stored
                    else {
                        i->setQuad(0);
                        //outputs value score to verify score was received 
                        cout << "Quads: " << i->getQuad() << endl;
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
                if (i->getFull() < 0) {
                    //ternary operator for check for full house passed in seFull function
                    i->setFull((full() == 25) ? 25 : 0);
                    //outputs value score to verify score was received 
                    cout << "Full House: " << i->getFull() << endl;
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
                if (i->getSmall() < 0) {
                    //ternary operator for check for small straight passed in set small function
                    i->setSmall((smallStraight() == 25) ? 25 : 0);
                    //outputs value score to verify score was received 
                    cout << "Small Straight: " << i->getSmall() << endl;
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
                if (i->getLarge() < 0) {
                    //ternary operator for check for large straight passed in set large function
                    i->setLarge((largeStraight() == 40)? 40 : 0);
                    //outputs value score to verify score was received 
                    cout << "Large Straight: " << i->getLarge() << endl;
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
                if (i->getYazy() < 0) {
                    //max frequency is greater than 4
                    max = maxFreq();
                    if (max > 4)
                    {
                        //checks to see if the player already has a yazy and will add 100 if so
                        if (i->getYazy() > 0) {
                            //if player gets second Yahtzee gets extra 100 points and bonus turn
                            i->setYazy(i->getYazy() + 100);
                            //outputs value score to verify score was received 
                            cout << "Yahtzee " << i->getYazy() << endl;
                            //condition set to false and breaks out of loop and switch case
                            tryAgn = false;
                        }
                        else {
                            //set 50 if first Yahtzee
                            i->setYazy(50);
                            cout << "Yahtzee " << i->getYazy() << endl;
                            tryAgn = false;
                        }
                    }
                    else {
                        i->setYazy(0);
                        cout << "Yahtzee " << i->getYazy() << endl;
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
                if (i->getChan() < 0) {
                    i->setChan(product());
                    //outputs value score to verify score was received 
                    cout << "Chance " << i->getChan() << endl;
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
//function for added up all the points for each player by passing pointer to array of player and scorecard object and number of players
void ScoreCard::calScore(stack<int>& scores, stack<string>& names)
{
    set<Player>::iterator j = p.begin();
    // Determines the final score with bonus
    for (auto i = s.begin(); i != s.end(); i++, j++)
    {
        if ((i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix()) > 62)
        {
            //populating bonus
            i->setBonus(35);
            //totaling upper before bonus
            i->setTotal(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix());
            //totaling upper with bonus
            i->setUpper(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix() + i->getBon());
            //totaling lower score
            i->setLower(i->getTrip() + i->getQuad() + i->getFull() + i->getSmall() + i->getLarge() + i->getYazy() + i->getChan());
            //total the final score
            i->setScore(i->getUpper() + i->getLower());
            //adding total score to a stack for comparison of highest score
            scores.push(i->getScore());
            names.push(j->getName());
        }
        // Determine the final score without bonus
        else if ((i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix()) <= 62)
        {
            //populating bonus
            i->setBonus(0);
            //totaling upper before bonus
            i->setTotal(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix());
            //totaling upper with bonus
            i->setUpper(i->getOne() + i->getTwo() + i->getThree() + i->getFour() + i->getFive() + i->getSix() + i->getBon());
            //totaling lower score
            i->setLower(i->getTrip() + i->getQuad() + i->getFull() + i->getSmall() + i->getLarge() + i->getYazy() + i->getChan());
            //total the final score
            i->setScore(i->getUpper() + i->getLower());
            //adding total score to a stack for comparison of highest score and storing the players too
            scores.push(i->getScore());
            names.push(j->getName());
        }
    }
}
//outputting final score by passing pointer to array of player and scorecard object and number of players
void ScoreCard::finalScore() {
    
    set<Player>::iterator it = p.begin();
    
    for (auto i = s.begin(); i != s.end(); i++, it++)
    {
        cout << endl;
        cout << " __________________________________________________________________" << endl;
        cout << "|" << "\t \t \t" << "Player: " << setw(10) << it->getName()<< " \t \t\t  |" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|"<< "\tYahtzee"<< "\t\t Score Card"<< "\t\t \t\t  |" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Upper Section" <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Aces:    " << setw(2) << i->getOne()<<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "| -----------------------------------------------------------------" << endl;
        cout << "| Twos:    " << setw(2) <<i->getTwo() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Threes:  " << setw(2) <<i->getThree() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fours:   " << setw(2) <<i->getFour() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Fives:   " << setw(2) << i->getFive() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Sixes:   " << setw(2) << i->getSix() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Chance:  " << setw(2) << i->getChan() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total Score:" << setw(2) <<i->getTotal() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Bonus: " << setw(2) <<i->getBon() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total with bonus:" << setw(2) <<i->getUpper() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 3 of a Kind : " << setw(2) <<i->getTrip() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| 4 of a Kind: " << setw(2) <<i->getQuad() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Full House : " << setw(2) <<i->getFull() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Small Straight : " << setw(2) <<i->getSmall() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Large Straight : " << setw(2) <<i->getLarge() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Yahtzee: " << setw(2) <<i->getYazy() <<"\t\t\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Upper Section: " << setw(2) <<i->getUpper() <<"\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Total of Lower Section: " <<setw(2) << i->getLower()<<"\t\t\t\t\t  |"<< endl;
        cout << "|------------------------------------------------------------------" << endl;
        cout << "| Grand Total: " << setw(3) <<i->getScore() <<"\t\t\t\t\t\t  |"<< endl;
        cout << "|__________________________________________________________________" << endl << endl;
    }
}



