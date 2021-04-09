#include <bits/stdc++.h>
using namespace std;

/*
Given a string with repeated characters, rearrange the string so that no two adjacent
characters are the same. If this is not possible, return None.

For example, given "aaabbc", you could return "ababac". Given "aaab", return None.
*/


string rearrangeNoTwoAdj(string s){
	unordered_map<char, int> char_count;
	for(char c : s) char_count[c]++;
	
	priority_queue<pair<int, char>> pq;
	
	for(auto it : char_count) pq.push({it.second, it.first});
	
	pair<int, char> prev = {-1, '$'};
	string ans;
	
	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		ans += t.second;
		
		if(prev.first > 0) pq.push(prev);
		
		(t.first)--;
		prev = t;
	}
	
	if(ans.length() != s.length())
		return "$$";
	
	return ans;
}

// main function
int main(){
	cout << rearrangeNoTwoAdj("aaabbc") << "\n";
	cout << rearrangeNoTwoAdj("aaab") << "\n";
	return 0;
}