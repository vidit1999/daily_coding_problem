#include <bits/stdc++.h>
using namespace std;

#define FACTOR 0.1

/*
In chess, the Elo rating system is used to calculate player strengths based on game results.

A simplified description of the Elo system is as follows.
Every player begins at the same score. For each subsequent game,
the loser transfers some points to the winner, where the amount
of points transferred depends on how unlikely the win is.
For example, a 1200-ranked player should gain much more points
for beating a 2000-ranked player than for beating a 1300-ranked player.

Implement this system.
*/

// return true if first player wins
bool chooseWinner(){
    return rand()%2;
}

// changes the points of the players and returns the points
void gamePlay(int& player1, int& player2){
    int point_change = abs(player1 - player2) * FACTOR;
    
    if(chooseWinner()){
        // player1 wins
        player1 += point_change;
        player2 = max(0, player2 - point_change);
        cout << "First player is winner\n";
    }
    else{
        // player2 wins
        player1 = max(0, player1 - point_change);
        player2 += point_change;
        cout << "Second player is winner\n";
    }
}

// game rounds simulator
void eloRating(int rounds, int player_count){
    if(player_count < 2){
        cout << "Atleast two players are needed\n";
        return;
    }
    
    vector<int> players(player_count);
    
    cout << "All players' score:\n";
    for(int i=0; i<players.size(); i++){
        players[i] = rand()%1001 + 500;
        cout << "Player " << i+1 << " -> " << players[i] << "\n";
    }
    
    for(int r=1; r<=rounds; r++){
        int i, j;
        
        do{
            i = rand()%players.size();
            j = rand()%players.size();
        }while(i == j);
        
        cout << "\nRound : " << r << "\n";
        cout << "Between players " << i+1 << " and " << j+1 << "\n";
        cout << "Scores before game:\n";
        cout << "Player " << i+1 << " -> " << players[i] << ", " << "Player " << j+1 << " -> " << players[j] << "\n";
        
        gamePlay(players[i], players[j]);
        
        cout << "Scores after game:\n";
        cout << "Player " << i+1 << " -> " << players[i] << ", " << "Player " << j+1 << " -> " << players[j] << "\n";
    }
    
    cout << "\nAll players' score:\n";
    for(int i=0; i<players.size(); i++){
        cout << "Player " << i+1 << " -> " << players[i] << "\n";
    }
}

// main function
int main(){
    srand(time(0));
    eloRating(10, 10);
    return 0;
}