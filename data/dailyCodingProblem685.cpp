#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a set of delimiters, reverse the words in the string while
maintaining the relative order of the delimiters.
For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases:
"hello/world:here/",
"hello//world:here"
*/

string reverseMaintainDelim(string s, unordered_set<char> delimiters){
	string temp = "";
	vector<string> splited;

	for(char c : s){
		if(delimiters.find(c) != delimiters.end()){
			if(!temp.empty()){
				splited.push_back(temp);
			}
			temp = "";
		}
		else{
			temp += c;
		}
	}

	if(!temp.empty()){
		splited.push_back(temp);
	}

	int i=0, n = s.length();
	string ans = "";

	while(i < n){
		if(delimiters.find(s[i]) != delimiters.end()){
			while(i < n && delimiters.find(s[i]) != delimiters.end()){
				ans += s[i];
				i++;
			}
		}
		else{
			ans += splited.back();
			splited.pop_back();
			while(i < n && delimiters.find(s[i]) == delimiters.end()){
				i++;
			}
		}
	}

	return ans;
}

void testFunc(vector<string> v){
	unordered_set<char> delimiters = {'/', ':'};
	for(auto s : v){
		auto rev = reverseMaintainDelim(s, delimiters);
		cout << s << " ---> " << rev << " ---> " << reverseMaintainDelim(rev, delimiters) << "\n"; 
	}
}

// main function
int main(){
	vector<string> v = {
		"hello/world:here",
		"hello/world:here/",
		"hello//world:here"
	};
	testFunc(v);
	return 0;
}