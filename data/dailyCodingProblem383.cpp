#include <bits/stdc++.h>
using namespace std;

/*
Implement the function embolden(s, lst) which takes in a string s and list of substrings lst,
and wraps all substrings in s with an HTML bold tag <b> and </b>.

If two bold tags overlap or are contiguous, they should be merged.

For example, given s = abcdefg and lst = ["bc", "ef"], return the string a<b>bc</b>d<b>ef</b>g.

Given s = abcdefg and lst = ["bcd", "def"], return the string a<b>bcdef</b>g, since they overlap.
*/

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>> intervals){
	sort(intervals.begin(), intervals.end());
	
	stack<pair<int, int>> s;
	
	s.push(intervals[0]);
	
	for(int i=1;i<intervals.size();i++){
		auto top = s.top();
		if(top.second+1 < intervals[i].first){
			s.push(intervals[i]);
		}
		else{
			top.second = max(top.second, intervals[i].second);
			s.pop();
			s.push(top);
		}
	}
	
	vector<pair<int, int>> merged;
	
	while(!s.empty()){
		merged.push_back(s.top());
		s.pop();
	}
	
	reverse(merged.begin(), merged.end());
	return merged;
}


string boldify(string s, vector<pair<int, int>> intervals){
	if(intervals.empty()) return s;
	
	string ans = "", opening = "<b>", closing = "</b>";
	
	int intervalCount = 0;
	
	for(int i=0;i<s.length();i++){
		pair<int, int> currInterval = {-1, -1};
		if(intervalCount < intervals.size())
			currInterval = intervals[intervalCount];

		if(currInterval.first == i)
			ans += opening;
		
		ans += s[i];
		
		if(currInterval.second == i){
			ans += closing;
			intervalCount++;
		}
	}
	
	return ans;
}

string embolden(string s, vector<string> lst){
	vector<pair<int, int>> startEndIndices;
	
	for(string sub : unordered_set<string>(lst.begin(), lst.end())){
		for(int i=0;i<=s.length()-sub.length();i++){
			if(s.substr(i,sub.length()) == sub)
				startEndIndices.push_back({i, i+sub.length()-1});
		}
	}
	
	return boldify(s, mergeIntervals(startEndIndices));
}

// main function
int main(){
	cout << embolden("abcdefg", {"bc", "ef"}) << "\n";
	return 0;
}