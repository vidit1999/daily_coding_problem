#include <bits/stdc++.h>
using namespace std;

/*
Snakes and Ladders is a game played on a 10 x 10 board, the goal of which is get from square 1 to square 100.
On each turn players will roll a six-sided die and move forward a number of spaces equal to the result.
If they land on a square that represents a snake or ladder, they will be transported ahead or behind,
respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
*/

struct Position{
	int pos, count;
};

int smallestTurn(unordered_map<int, int> snakes, unordered_map<int, int> ladders){
	unordered_map<int, int> snakes_and_ladders;
	
    snakes_and_ladders.insert(snakes.begin(), snakes.end());
	snakes_and_ladders.insert(ladders.begin(), ladders.end());

	
	queue<Position> q;
    q.push({1, 0});
	unordered_set<int> visited = {1};
	
	while(!q.empty()){
		auto f = q.front(); q.pop();
		
		if(f.pos == 100) return f.count;
		
		for(int i=1; i<=6 && f.pos+i <= 100; i++){
			int next_pos = f.pos + i;
			
			if(snakes_and_ladders.find(next_pos) != snakes_and_ladders.end()){
				next_pos = snakes_and_ladders[next_pos];
			}
			
			if(visited.find(next_pos) == visited.end()){
				visited.insert(next_pos);
				q.push({next_pos, f.count+1});
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	unordered_map<int, int> snakes = {
		{16, 6}, {48, 26}, {49, 11}, {56, 53}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78}
	},
	ladders = {
		{1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91}, {80, 100}
	};
	
	cout << smallestTurn(snakes, ladders) << "\n";
	
	return 0;
}