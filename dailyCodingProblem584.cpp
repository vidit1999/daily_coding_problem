#include <bits/stdc++.h>
using namespace std;

/*
Given a string with repeated characters,
rearrange the string so that no two adjacent
characters are the same.
If this is not possible, return None.

For example, given "aaabbc",
you could return "ababac".

Given "aaab", return None.
*/

class Compare{
	public:

	bool operator() (pair<char, int> p1, pair<char, int> p2){
		return p2.second > p1.second;
	}
};

string rearrangeNotRepeat(string s){
	unordered_map<char, int> charCount;

	for(char c : s){
		charCount[c]++;
	}

	priority_queue<pair<char, int>, vector<pair<char, int>>, Compare> pq(charCount.begin(), charCount.end());
	string ans = "";
	pair<char, int> prev = {'#', -1};

	while(!pq.empty()){
		auto t = pq.top();
		pq.pop();
		ans += t.first;

		if(prev.second > 0)
			pq.push(prev);

		t.second--;
		prev = t;
	}

	if(ans.length() != s.length())
		return "";
	return ans;
}

// main function
int main(){
	cout << rearrangeNotRepeat("aaabbc") << "\n";
	cout << rearrangeNotRepeat("aaabb") << "\n";
	cout << rearrangeNotRepeat("aaaabc") << "\n";
	cout << rearrangeNotRepeat("aa") << "\n";
	cout << rearrangeNotRepeat("aaabc") << "\n";
	return 0;
}