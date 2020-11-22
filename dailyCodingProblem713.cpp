#include <bits/stdc++.h>
using namespace std;

/*
Given an absolute pathname that may have . or .. as part of it,
return the shortest standardized path.

For example, given "/usr/bin/../bin/./scripts/../", return "/usr/bin/".
*/

vector<string> splitPath(string& path){
	vector<string> ans;
	string temp = "";
	
	for(char c : path){
		if(c == '/'){
			if(!temp.empty()){
				ans.push_back(temp);
				temp = "";
			}
		}
		else{
			temp += c;
		}
	}
	
	if(!temp.empty()){
		ans.push_back(temp);
	}
	
	return ans;
}

string standardizedPath(string path){
	auto splited = splitPath(path);
	stack<string> s;
	
	for(auto fol : splited){
		if(fol == "."){
			continue;
		}
		else if(fol == ".."){
			if(!s.empty()){
				s.pop();
			}
		}
		else{
			s.push(fol);
		}
	}
	
	string ans = "";
	
	while(!s.empty()){
		ans = "/" + s.top() + ans;
		s.pop();
	}
	
	ans += "/";
	
	return ans;
}

// main function
int main(){
	cout << standardizedPath("/usr/bin/../bin/./scripts/../") << "\n";
	return 0;
}