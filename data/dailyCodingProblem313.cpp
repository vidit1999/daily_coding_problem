#include <bits/stdc++.h>
using namespace std;

/*
You are given a circular lock with three wheels, each of which display the
numbers 0 through 9 in order.
Each of these wheels rotate clockwise and counterclockwise.

In addition, the lock has a certain number of "dead ends", meaning that if you turn the
wheels to one of these combinations, the lock becomes stuck in that state and cannot be opened.

Let us consider a "move" to be a rotation of a single wheel by one digit, in either direction.
Given a lock initially set to 000, a target combination, and a list of dead ends,
write a function that returns the minimum number of moves required to reach the target state,
or None if this is impossible.
*/

struct Move{
	string state;
	int move_count;
};


vector<string> newStates(string s){
	vector<string> states;
	
    for(int j=0;j<s.length();j++){
        string first, second;
        for(int i=0;i<s.length();i++){
            if(i == j){
                first +=  ((s[i] == '0')? '9' : (s[i] - 1)); // left rotate, 0 -> 9, 2 -> 1 etc.
                second += ((s[i] == '9')? '0' : (s[i] + 1)); // right rotate, 0 -> 1, 9 -> 0 etc.
            }
            else{
                first += s[i];
                second += s[i];
            }
        }
        states.push_back(first);
        states.push_back(second);
    }
	return states;
}

int minMoves(unordered_set<string> dead_ends, string target){
	queue<Move> q;
	unordered_set<string> seen;
	
	q.push({"0000", 0});
	seen.insert("0000");
	
	while(!q.empty()){
		auto mv = q.front();
		q.pop();

		if(mv.state == target) return mv.move_count;
		
		if(dead_ends.find(mv.state) == dead_ends.end()){
			for(string state : newStates(mv.state)){
				if(seen.find(state) == seen.end()){
					q.push({state, mv.move_count+1});
					seen.insert(state);
				}
			}
		}
	}
	
	return -1;
}

// main function
int main(){
	cout << minMoves({"0201","0101","0102","1212","2002"}, "0202") << "\n";
	cout << minMoves({"8888"}, "0009") << "\n";
	cout << minMoves({"8887","8889","8878","8898","8788","8988","7888","9888"}, "8888") << "\n";
	cout << minMoves({"0000"}, "8888") << "\n";
	return 0;
}