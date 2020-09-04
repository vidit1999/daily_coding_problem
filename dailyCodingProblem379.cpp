#include <bits/stdc++.h>
using namespace std;

/*
Given a string, generate all possible subsequences of the string.

For example, given the string xyz, return an array or set with the following strings:

x
y
z
xy
xz
yz
xyz

Note that zx is not a valid subsequence since it is not in the order of the given string.
*/

unordered_set<string> subsequences(string s){
	int count = pow(2, s.length());
	unordered_set<string> ans;
	
    for(int k=0;k<count;k++){
		string to_include = "";
		int start = 1;
		for(int i=0;i<s.length();i++){
			if(k & start) to_include += s[i];
			start <<= 1;
		}
		ans.insert(to_include);
	}

	ans.erase("");
	return ans;
}

// main function
int main(){
    for(auto it : subsequences("xyz"))
        cout << it << "\n";
	return 0;
}