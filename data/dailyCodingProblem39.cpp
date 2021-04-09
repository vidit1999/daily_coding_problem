#include <bits/stdc++.h>
using namespace std;

/*
Conway's Game of Life takes place on an infinite two-dimensional board of square cells.
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting
list of live cell coordinates and the number of steps it should run for.
Once initialized, it should print out the board state at each step.
Since it's an infinite board, print out only the relevant coordinates,
i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
*/


// positions set contains the positions of live cells after the game is finish
// input arguments are initial positions and number of steps game will go on
// position is in the form of <x-coordinate, y-coordinate>
void conwayGame(set<pair<int, int>>& positions, int steps){
	// game iterations
	while(steps--){
		// these sets represent the cells who will be alive after this step
		// and who will be dead after these step
		set<pair<int, int>> newLive, newDead;
		
		// dead neighbours of a living cell and their neighbour count
		// to help make dead cells alive
		// philosophy is, if i am your neighbour, then you are my neighbour also
		map<pair<int, int>, int> deadNeighbourCount;
		
		for(auto pos : positions){
			int liveNeighbourCount = 0;
			// chek all neighbours
			for(int i=-1;i<=1;i++){
				for(int j=-1;j<=1;j++){
					// no need to check for same cell
					if(i == 0 && j == 0)
						continue;
					// if the cell is in positions set that means it is live
					if(positions.find({pos.first+i, pos.second+j}) != positions.end()){
						liveNeighbourCount++;
					}
					else{
						// there is a dead cell in position <pos.first+i, pos.second+j> which have a live cell
						deadNeighbourCount[{pos.first+i, pos.second+j}]++;
					}
				}
			}
			
			// if the cell is to die then include it in newDead
			if(liveNeighbourCount < 2 || liveNeighbourCount > 3)
				newDead.insert(pos);
		}
		
		// after checking all the living cells check which dead cell is to be live
		for(auto it : deadNeighbourCount){
			// dead cell with exactly 3 live neighbours
			if(it.second == 3){
				newLive.insert(it.first);
			}
		}
		
		// now remove all the cells which will die
		// and include all the cells which will be new alive
		for(auto it : newDead) positions.erase(it);
		positions.insert(newLive.begin(), newLive.end());
	}
}

// main function
int main(){
	return 0;
}