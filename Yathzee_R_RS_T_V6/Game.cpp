using namespace std;

#include "Game.h"

void Game::menu() {
    //Display menu
    cout << "******************************************" << endl;
    cout << setw(23) << "YAHTZEE" << endl;
    cout << "******************************************" << endl
        << endl;
    cout << "1 .Play Game" << endl;
    cout << "2. Display Rules" << endl
        << endl;
    cout << "Make your selection ";
}
void Game::playGame() {
    // Game variables
    int round = 0;
    int ply = 0;
    int roundCounter = 5;
    stack<int> scores;
    stack <string> names;

    //setting up the number of players and there names
    getPlayers(ply);
    int *hashAry = plyNames(ply);
    
    cout << endl << "This is the order of player turns" << endl << endl;
    print();
    getVal();
    
    // start the the Game of 13 rounds, outputs players turn each time and randomly generates a new between 1-6 for all dice
    start(hashAry,round,roundCounter);
    
    //calculates the scores
//    calScore(scores,names);
    
    //outputs the scorecards
  //  finalScore();

    //compares and displays the user
    winner(scores,names);

    //end of game
}
void Game::start(int *array, int round, int n){
  if (n > 0) {
    int i = 0;
    cout << "Round: " << round + 1 << endl << endl;
    for (auto j = p.begin(); j != p.end(); j++) {
        cout << j->getName() << "'s turn" << endl << endl;

        //Generate random values for the map (dice roll)
        for(int n = 0; n < 5;n++){
           search(n+1);
        }
        //displays dice roll and prompts user for which dice to re-roll
        reRoll();

        //prompts the players to assigns scores to proper category on the scorecard
        getScores(array[i], j);
        i++;
    }
    round++;
    start(array,round, n - 1);
  }
}
void Game::winner(stack<int>& s, stack<string>& p) { 

    //temporary values to store for comparison
    int max = 0;
    int temp = 0;
    string winPly;
    string tempPly;
    
    //comparing values to return winning score
    while (!s.empty() && !p.empty())
    {
        temp = s.top();
        tempPly = p.top();
        if (temp > max)
        {
            max = temp;
            winPly = tempPly;
        }
        s.pop();
        p.pop();
    }
    
    cout << "Congratulations: " << winPly << " you won, Winning score: " << max << endl;
}
