#include <bits/stdc++.h>
using namespace std;

/*
A teacher must divide a class of students into two teams to play dodgeball.
Unfortunately, not all the kids get along, and several
refuse to be put on the same team as that of their enemies.

Given an adjacency list of students and their enemies,
write an algorithm that finds a satisfactory pair of teams,
or returns False if none exists.

For example, given the following enemy graph
you should return the teams {0, 1, 4, 5} and {2, 3}.

students = {
    0: [3],
    1: [2],
    2: [1, 4],
    3: [0, 4, 5],
    4: [2, 3],
    5: [3]
}

On the other hand, given the input below,
you should return False.

students = {
    0: [3],
    1: [2],
    2: [1, 3, 4],
    3: [0, 2, 4, 5],
    4: [2, 3],
    5: [3]
}
*/

void helper(
	set<int>& team1,
	set<int>& team2,
	vector<vector<int>> students
){
	
}

pair<vector<int>, vector<int>> teamCreate(vector<vector<int>> students){
	vector<int> team1, team2;
	
	for(auto v : students){
		// first option
		// put player in team1 and enemies in team2
		
	}
}

// main function
int main(){
	return 0;
}