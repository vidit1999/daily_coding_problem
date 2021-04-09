#include <bits/stdc++.h>
using namespace std;

/*
Given a string s and an integer k, break up the string into multiple texts
such that each text has a length of k or less. You must break it up so that
words don't break across lines. If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that
there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog"
and k = 10, you should return: ["the quick", "brown fox", "jumps over", "the lazy", "dog"].
No string in the list has a length of more than 10.
*/

vector<string> splitString(string s){
	vector<string> splited;
	string temp = "";
	
	for(char c : s){
		if(c == ' '){
			if(!temp.empty()){
				splited.push_back(temp);
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}
	
	if(!temp.empty()) splited.push_back(temp);
	
	return splited;
}

vector<string> breakString(string s, int k){
	auto splited = splitString(s);
	
	for(string st : splited) if(st.length() > k) return {};
	
	vector<string> ans;
	string temp = "";
	int i = 0;

	while(i<splited.size()){
		if(temp.empty()){
			temp += splited[i++];
		}
		while(i < splited.size() && temp.length() + splited[i].length() + 1 <= k){
			temp += ' ';
            temp += splited[i++];
		}
		ans.push_back(temp);
		temp = "";
	}
	
	return ans;
}

// main function
int main(){
	for(string s : breakString("the quick brown fox jumps over the lazy dog", 10))
		cout << s << "\n";
	return 0;
}