#include <bits/stdc++.h>
using namespace std;

/*
You are given a circular lock with three wheels,
each of which display the numbers 0 through 9 in order.
Each of these wheels rotate clockwise and counterclockwise.

In addition, the lock has a certain number of "dead ends",
meaning that if you turn the wheels to one of these combinations,
the lock becomes stuck in that state and cannot be opened.

Let us consider a "move" to be a rotation of a single wheel by one digit,
in either direction. Given a lock initially set to 000,
a target combination, and a list of dead ends, write a
function that returns the minimum number of moves required
to reach the target state, or None if this is impossible.
*/

struct Move{
	string state;
	int move_count;
};

vector<string> nextMove(string s){
	vector<string> ans;
	
	for(int i=0; i<s.length(); i++){
		string first, second;
		for(int j=0; j<s.length(); j++){
			if(i == j){
				first += ((s[j] == '9')? '0' : (s[j] + 1)); // for clockwise rotation i.e. 0 -> 1, 2 -> 3, ... , 9 -> 0
				second += ((s[j] == '0')? '9' : (s[j] - 1)); // for counterclockwise rotation i.e. 1 -> 0, ... , 0 -> 9
			}
			else{
				first += s[j];
				second += s[j];
			}
		}
		ans.push_back(first);
		ans.push_back(second);
	}
	
	return ans;
}

int minMoveToTargetState(unordered_set<string> dead_ends, string target){
	queue<Move> q({{"0000", 0}});
	unordered_set<string> seen({"0000"});
	
	while(!q.empty()){
		auto front = q.front(); q.pop();
		
		if(front.state == target) return front.move_count;
		
		if(dead_ends.find(front.state) == dead_ends.end()){
			for(string next : nextMove(front.state)){
				if(seen.find(next) == seen.end()){
					seen.insert(next);
					q.push({next, front.move_count+1});
				}
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << minMoveToTargetState({"0201","0101","0102","1212","2002"}, "0202") << "\n";
	cout << minMoveToTargetState({"8888"}, "0009") << "\n";
	cout << minMoveToTargetState({"8887","8889","8878","8898","8788","8988","7888","9888"}, "8888") << "\n";
	cout << minMoveToTargetState({"0000"}, "8888") << "\n";
	return 0;
}