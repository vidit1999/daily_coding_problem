#include <bits/stdc++.h>
using namespace std;

/*
Given a string s, rearrange the characters so that any
two adjacent characters are not the same.
If this is not possible, return null.

For example, if s = yyz then return yzy.
If s = yyy then return null.
*/

string noTwoAdjacent(string s){
	unordered_map<char, int> char_count;
	
	for(char c : s){
		char_count[c]++;
	}
	
	priority_queue<pair<int, char>> pq;
	
	for(auto it : char_count){
		pq.push({it.second, it.first});
	}
	
	pair<int, char> prev = {-1, '$'};
	
	string ans = "";
	
	while(!pq.empty()){
		auto t = pq.top(); pq.pop();
		ans += t.second;
		
		if(prev.first > 0){
			pq.push(prev);
		}
		
		t.first--;
		prev = t;
	}
	
	cout << count << "\n";
	
	if(ans.length() != s.length()){
		return "";
	}
	
	return ans;
}

// main function
int main(){
	cout << noTwoAdjacent("bbbaa") << "\n";
	return 0;
}