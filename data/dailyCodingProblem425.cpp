#include <bits/stdc++.h>
using namespace std;

/*
You are presented with an 8 by 8 matrix representing the positions of pieces on a chess board.
The only pieces on the board are the black king and various white pieces. Given this matrix,
determine whether the king is in check.

For example, given the following matrix:

...K....
........
.B......
......P.
.......R
..N.....
........
.....Q..

You should return True, since the bishop is attacking the king diagonally.
*/

// get the position of pieces in the board
unordered_map<char, vector<pair<int, int>>> positionMap(vector<vector<char>> board){
	unordered_map<char, vector<pair<int, int>>> positions;
	
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			if(board[i][j] != '.'){
				positions[board[i][j]].push_back({i, j});
			}
		}
	}
	
	return positions;
}

bool isValidPosition(int x, int y){
	return x >= 0 && x < 8 && y >= 0 && y < 8;
}

bool isBishopChecking(pair<int, int> bPos, pair<int, int> kPos){
	return abs(bPos.first - kPos.first) == abs(bPos.second - kPos.second);
}

bool isRookChecking(pair<int, int> rPos, pair<int, int> kPos){
	return (rPos.first == kPos.first) || (rPos.second == kPos.second);
}

bool isKnightChecking(pair<int, int> nPos, pair<int, int> kPos){
	vector<pair<int, int>> knightMoves = {
		{-2, 1},
		{-2, 1},
		{2, -1},
		{2, 1}
	};
	
	for(auto move : knightMoves){
		if(
			((nPos.first + move.first == kPos.first) && (nPos.second + move.second == kPos.second)) ||
			((nPos.first + move.second == kPos.first) && (nPos.second + move.first == kPos.second))
		)
			return true;
	}
	
	return false;
}

bool isPawnChecking(pair<int, int> pPos, pair<int, int> kPos){
	return (
		(pPos.first == kPos.first + 1) &&
		(pPos.second == kPos.second - 1)
	);
}

bool isQueenChecking(pair<int, int> qPos, pair<int, int> kPos){
	return isBishopChecking(qPos, kPos) || isRookChecking(qPos, kPos);
}

bool isCheckingKingCases(unordered_map<char, vector<pair<int, int>>> positions, pair<int, int> kPos, char piece){
	
	if(positions.find(piece) != positions.end()){
		if(piece == 'Q'){
			for(auto pos : positions[piece])
				if(isQueenChecking(pos, kPos))
					return true;
		}
		if(piece == 'B'){
			for(auto pos : positions[piece])
				if(isBishopChecking(pos, kPos))
					return true;
		}
		if(piece == 'R'){
			for(auto pos : positions[piece])
				if(isRookChecking(pos, kPos))
					return true;
		}
		if(piece == 'P'){
			for(auto pos : positions[piece])
				if(isPawnChecking(pos, kPos))
					return true;
		}
	}
	
	return false;
}

bool isKingChecked(vector<vector<char>> board){
	auto positions = positionMap(board);
	auto kPos = positions['K'][0];
	
	for(char c : {'B', 'P', 'R', 'Q'}){
		if(isCheckingKingCases(positions, kPos, c))
			return true;
	}
	
	return false;
}

// main function
int main(){
	vector<vector<char>> board = {
		{'.','.','.','K','.','.','.','.'},
		{'.','.','.','.','.','.','.','.'},
		{'B','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','.','P','.'},
		{'.','.','.','.','.','.','.','R'},
		{'.','.','N','.','.','.','.','.'},
		{'.','.','.','.','.','.','.','.'},
		{'.','.','.','.','.','Q','.','.'}
	};
	
	if(isKingChecked(board))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}