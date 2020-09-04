#include <bits/stdc++.h>
#define N 10
using namespace std;

/*
Snakes and Ladders is a game played on a 10 x 10 board, the goal of which is get
from square 1 to square 100. On each turn players will roll a six-sided die and
move forward a number of spaces equal to the result. If they land on a square
that represents a snake or ladder, they will be transported ahead or behind,
respectively, to a new square.

Find the smallest number of turns it takes to play snakes and ladders.

For convenience, here are the squares representing snakes and ladders, and their outcomes:

snakes = {16: 6, 48: 26, 49: 11, 56: 53, 62: 19, 64: 60, 87: 24, 93: 73, 95: 75, 98: 78}
ladders = {1: 38, 4: 14, 9: 31, 21: 42, 28: 84, 36: 44, 51: 67, 71: 91, 80: 100}
*/

struct Move{
	int pos, count;
};

int minTurns(unordered_map<int, int> snakes, unordered_map<int, int> ladders){
	bool visited[N*N] = { false };
	
	queue<Move> q;
	visited[0] = true; // starting position mark visited
	q.push({0, 0});
	
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		
		// if we reah the ending position then return t.count-1
		// -1 because turn is one less than the minimum number
		// of throws
		if(t.pos == N*N-1) return t.count-1;
		
		for(int i=t.pos+1; i <= t.pos+6 && i < N*N; i++){
			if(!visited[i]){
				Move m;
				m.count = t.count+1;
				visited[i] = true;
				
				if(snakes.find(i+1) != snakes.end())
					m.pos = snakes[i+1]-1;
				else if(ladders.find(i+1) != ladders.end())
					m.pos = ladders[i+1]-1;
				else
					m.pos = i;
				
				q.push(m);
			}
		}
	}
	
	return INT_MAX;
}

// main function
int main(){
    unordered_map<int, int> ladders, snakes;

    ladders = {
        {1,38},
        {4,14},
        {9,31},
        {21, 42},
        {28, 84},
        {36, 44},
        {51, 67},
        {71, 91},
        {80, 100}
    };

    snakes = {
        {16, 6},
        {48, 26},
        {49, 11},
        {56, 53},
        {62, 19},
        {64, 60},
        {87, 24},
        {93, 73},
        {95, 75},
        {98, 78}
    };

    cout << minTurns(snakes, ladders) << "\n";
	return 0;
}