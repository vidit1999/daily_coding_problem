#include <bits/stdc++.h>
using namespace std;

/*
Given a dictionary of words and a string made up of those words (no spaces),
return the original sentence in a list. If there is more than one possible reconstruction, return any of them.
If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and
the string "thequickbrownfox", you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and
the string "bedbathandbeyond", return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].
*/

vector<string> originalSentence(string s, unordered_set<string> dict){
	int start = 0;
	vector<string> original;
	for(int i=0;i<s.length();i++){
		string sub = s.substr(start,i-start+1);
		if(dict.find(sub) != dict.end()){
			original.push_back(sub);
			start = i+1;
		}
	}
	return original;
}

// main function
int main(){
	// vector<string> ans = originalSentence("thequickbrownfox",{"quick", "brown", "the", "fox"});
	vector<string> ans = originalSentence("bedbathandbeyond",{"bed", "bath", "bedbath", "and", "beyond"});
	for(string s : ans)
		cout << s << "\n";
	return 0;
}