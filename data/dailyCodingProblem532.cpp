#include <bits/stdc++.h>
using namespace std;

/*
On our special chessboard, two bishops attack each other if they share the same diagonal.
This includes bishops that have another bishop located between them, i.e. bishops can attack through pieces.

You are given N bishops, represented as (row, column) tuples on a M by M chessboard.
Write a function to count the number of pairs of bishops that attack each other.
The ordering of the pair doesn't matter: (1, 2) is considered the same as (2, 1).

For example, given M = 5 and the list of bishops:

(0, 0)
(1, 2)
(2, 2)
(4, 0)
The board would look like this:

[b 0 0 0 0]
[0 0 b 0 0]
[0 0 b 0 0]
[0 0 0 0 0]
[b 0 0 0 0]
You should return 2, since bishops 1 and 3 attack each other, as well as bishops 3 and 4.
*/

bool isAttacking(pair<int, int> pos1, pair<int, int> pos2){
	return abs(pos1.first - pos2.first) == abs(pos1.second - pos2.second);
}

bool isAlreadyConsidered(set<pair<pair<int, int>, pair<int, int>>> attacks, pair<int, int> pos1, pair<int, int> pos2){
	return (attacks.find({pos1, pos2}) != attacks.end()) || (attacks.find({pos2, pos1}) != attacks.end()); 
}

int countAttackingBishops(int m, vector<pair<int, int>> bishops){
	int attackCount = 0;
	set<pair<pair<int, int>, pair<int, int>>> attacks;
	
	for(int i=0;i<bishops.size();i++){
		for(int j=i+1;j<bishops.size();j++){
			if(isAttacking(bishops[i], bishops[j]) && !isAlreadyConsidered(attacks, bishops[i], bishops[j])){
				attackCount++;
				attacks.insert({bishops[i], bishops[j]});
			}
		}
	}
	
	return attackCount;
}

// main function
int main(){
	int m = 5;
	vector<pair<int, int>> bishops = {
		{0, 0},
		{1, 2},
		{2, 2},
		{4, 0}
	};
	
	cout << countAttackingBishops(m, bishops) << "\n";
	return 0;
}