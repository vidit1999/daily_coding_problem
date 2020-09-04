#include <bits/stdc++.h>
using namespace std;

/*
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
*/

bool isMappingPossible(string s1, string s2){
	if(s1.length() != s2.length()) return false;

	unordered_map<char, char> s1_map;
	unordered_set<char> s2_check;

	for(int i=0;i<s1.length();i++){
		if(s1_map.find(s1[i]) == s1_map.end()){

			if(s2_check.find(s2[i]) != s2_check.end())
				return false;

			s2_check.insert(s2[i]);
			s1_map[s1[i]] = s2[i];
		}
		else{
			if(s1_map[s1[i]] != s2[i])
				return false;
		}
	}

	return true;
}

// main function
int main(){
	string s1 = "abb", s2 = "bcc";

	if(isMappingPossible(s1, s2))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}