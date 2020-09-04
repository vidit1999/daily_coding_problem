#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a set of delimiters,
reverse the words in the string while
maintaining the relative order of the
delimiters.

For example, given "hello/world:here",
return "here/world:hello"

Follow-up: Does your solution work for
the following cases:
"hello/world:here/", "hello//world:here"
*/

string reverseNotDelim(string s, unordered_set<char> delimiters){
	vector<char> delimiters_occ;
	vector<string> words;
	
	string temp = "";
	
	for(char c : s){
		if(delimiters.find(c) != delimiters.end()){
			if(!temp.empty()){
				words.push_back(temp);
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}
	
	if(!temp.empty()){
		words.push_back(temp);
		temp = "";
	}
	
	reverse(words.begin(), words.end());
	
	string ans = "";
	int i = 0;
	
	for(char c : s){
		if(delimiters.find(c) != delimiters.end()){
			if(!temp.empty()){
				ans += words[i++];
				temp = "";
			}
			ans += c;
		}
		else{
			temp += c;
		}
	}
	
	if(!temp.empty()){
		ans += words[i++];
		temp = "";
	}
	
	return ans;
}

// main function
int main(){
	unordered_set<char> delimiters = {'/', ':'};
	
	cout << reverseNotDelim("hello/world:here", delimiters) << "\n";
	cout << reverseNotDelim("hello/world:here/", delimiters) << "\n";
	cout << reverseNotDelim("hello//world:here", delimiters) << "\n";
	
	return 0;
}