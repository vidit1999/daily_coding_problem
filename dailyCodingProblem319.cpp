#include <bits/stdc++.h>
using namespace std;

#define N 2
#define SHUFFLE_COUNT 10

/*
An 8-puzzle is a game played on a 3 x 3 board of tiles,
with the ninth tile missing. The remaining tiles are
labeled 1 through 8 but shuffled randomly. Tiles may
slide horizontally or vertically into an empty space,
but may not be removed from the board.

Design a class to represent the board, and find a series
of steps to bring the board to the state
[[1, 2, 3], [4, 5, 6], [7, 8, None]].
*/

bool isValid(int x, int y){
	return (
		x >= 0 && x < N &&
		y >= 0 && y < N
	);
}

bool isSolution(vector<vector<int>>& board){
	int num = 1;

	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			if(j == N-1 && i == N-1) break;
			if(board[i][j] != num++){
				return false;
			}
		}
	}

	return board[N-1][N-1] == -1;
}

void printBoard(vector<vector<int>>& board){
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "-------------\n";
}

pair<int, int> shuffleBoard(vector<vector<int>>& board, int dx[], int dy[]){
	int x = N-1, y = N-1;
	int count = SHUFFLE_COUNT;
	int index;

	while(count--){
		do{
			index = rand()%4;
		}while(!isValid(x+dx[index], y+dy[index]));

		swap(board[x][y], board[x+dx[index]][y+dy[index]]);
		x = x + dx[index];
		y = y + dy[index];
	}

	return {x, y};
}

void eightPuzzle(){
	vector<vector<int>> board(N, vector<int>(N));
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};

	// board initialization
	int num = 1;
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			board[i][j] = num++;
		}
	}
	board[N-1][N-1] = -1;

	// shuffling
	auto indices = shuffleBoard(board, dx, dy);
	int x = indices.first, y = indices.second;
    
    set<vector<vector<int>>> board_set = {board};
	vector<vector<vector<int>>> states = {board};

	while(!isSolution(board)){
		int i;

		do{
			i = rand()%4;
		}while(!isValid(x+dx[i], y+dy[i]));


		swap(board[x][y], board[x+dx[i]][y+dy[i]]);
		
		if(board_set.find(board) != board_set.end()){
		    swap(board[x][y], board[x+dx[i]][y+dy[i]]);
		}
		else{
		    x = x + dx[i];
		    y = y + dy[i];
		    board_set.insert(board);
    		states.push_back(board);
		}
	}

	for(auto& b : states){
		printBoard(b);
	}
}

// main function
int main(){
	eightPuzzle();
	return 0;
}