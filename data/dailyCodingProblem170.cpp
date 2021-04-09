#include <bits/stdc++.h>
using namespace std;

/*
Given a start word, an end word, and a dictionary of valid words,
find the shortest transformation sequence from start to end such
that only one letter is changed at each step of the sequence,
and each transformed word exists in the dictionary.
If there is no possible transformation, return null.
Each word in the dictionary have the same length as
start and end and is lowercase.

For example, given start = "dog", end = "cat", and
dictionary = {"dot", "dop", "dat", "cat"}, return
["dog", "dot", "dat", "cat"].

Given start = "dog", end = "cat", and dictionary
= {"dot", "tod", "dat", "dar"}, return null as
there is no possible transformation from dog to cat.
*/

struct WordVec{
	string word;
	vector<string> sequence;
};

bool checkDiffOne(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	int diff_count = 0;
	for(int i=0; i<s1.length(); i++){
		if(s1[i] != s2[i]){
			if(++diff_count > 1)
				return false;
		}
	}
	
	return diff_count == 1;
}

vector<string> minDiffOneLetter(string start, string end, vector<string> words){
	if(start == end) return {};
	
	queue<WordVec> q({{start, {start}}});
	unordered_set<string> visited;
	
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		
		if(t.word == end) return t.sequence;
		
		for(string word : words){
			if(visited.find(word) == visited.end() && checkDiffOne(word, t.word)){
				visited.insert(word);
				vector<string> word_sequence = t.sequence;
				word_sequence.push_back(word);
				q.push({word, word_sequence});
			}
		}
	}
	
	return {};
}

// main function
int main(){
	string start ="dog", end = "cat";
	vector<string> words = {"dot", "dop", "dat", "cat"}; // {"dot", "tod", "dat", "dar"};
	
	for(string s : minDiffOneLetter(start, end, words))
		cout << s << "\n";
	
	return 0;
}