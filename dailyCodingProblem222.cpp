#include <bits/stdc++.h>
using namespace std;

/*
Given an absolute pathname that may
have . or .. as part of it,
return the shortest standardized path.

For example,
given "/usr/bin/../bin/./scripts/../",
return "/usr/bin/".
*/

vector<string> splitPath(string path){
	vector<string> ans;
	
	string s;
	for(char c : path){
		if(c == '/' && !s.empty()){
			ans.push_back(s);
			s = "";
		}
		else if(c != '/')
			s += c;
	}
	
	return ans;
}

string absolutePath(string path){	
	stack<string> st;
	
	for(string s : splitPath(path)){
		if(s == ".."){
			if(st.empty())
				return "Error";
			st.pop();
		}
		else if(s == ".") continue;
		else
			st.push(s);
	}
	
	string ans = "/";
	while(!st.empty()){
		ans = "/" + st.top() + ans;
		st.pop();
	}
	
	return ans;
}

// main function
int main(){
	cout << absolutePath("/usr/bin/../bin/./scripts/../") << "\n";
	return 0;
}