#include <bits/stdc++.h>
using namespace std;

#define DECAY_FACTOR 0.01

/*
In chess, the Elo rating system is used to calculate player strengths based on game results.

A simplified description of the Elo system is as follows.
Every player begins at the same score. For each subsequent game,
the loser transfers some points to the winner, where the amount
of points transferred depends on how unlikely the win is.
For example, a 1200-ranked player should gain much more
points for beating a 2000-ranked player than for beating a 1300-ranked player.

Implement this system.
*/

class EloGame{
	// initial point of every player
	// new player starts with this point
	int initial_point;

	// stores the points of each player
	// player id as key, point as value
	unordered_map<int, int> player_point;

public:

	// initializer
	EloGame(int initial_point);

	// add palyers
	// returns the player id
	int addPlayer();

	// game play
	void gamePlay(int player_id1, int player_id2);

	// print points table
	void pointsTable();
};

EloGame::EloGame(int initial_point){
	this->initial_point = initial_point;
}

int EloGame::addPlayer(){
	int player_id = rand();

	while(player_point.find(player_id) != player_point.end()){ player_id = rand(); }

	player_point[player_id] = initial_point;

	return player_id;
}


void EloGame::gamePlay(int player_id1, int player_id2){
	int point1 = player_point[player_id1], point2 = player_point[player_id2];
	
	cout << "Player 1 : " << player_id1 << ", Point : " << point1 << "\n";
	cout << "Player 2 : " << player_id2 << ", Point : " << point2 << "\n";

	int max_player, min_player, winner, looser;

	if(point1 > point2){
		max_player = player_id1, min_player = player_id2;
	}
	else{
		max_player = player_id2, min_player = player_id1;
	}

	double win_factor = double(player_point[max_player]) / double(point1 + point2);
	double num = double(rand())/double(RAND_MAX);

	if(num <= win_factor){
		winner = max_player, looser = min_player;
	}
	else{
		winner = min_player, looser	= max_player;
	}

	cout << "Winner : " << winner << "\n";
	cout << "Looser : " << looser << "\n";

	int gain = player_point[looser]*DECAY_FACTOR;

	player_point[winner] += gain;
	player_point[looser] -= gain;
	player_point[looser] = max(0, player_point[looser]);

	cout << "Final Points => " << "Winner : " << player_point[winner];
	cout << ", Looser : " << player_point[looser] << "\n\n";
}

void EloGame::pointsTable(){
    cout << "Player_id\tPoints\n\n";
    for(auto it : player_point){
        cout << it.first << "\t" << it.second << "\n";
    }
    cout << "\n";
}

// main function
int main(){
    EloGame eg(500);

    int p1 = eg.addPlayer(), p2 = eg.addPlayer();

    for(int i=0; i<5; i++){
        eg.gamePlay(p1, p2);
    }

    eg.pointsTable();
	return 0;
}