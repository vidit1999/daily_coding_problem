#include <bits/stdc++.h>
using namespace std;

/*
Determine whether there exists a one-to-one character mapping from one string s1 to another s2.

For example, given s1 = abc and s2 = bcd, return true since we can map a to b, b to c, and c to d.

Given s1 = foo and s2 = bar, return false since the o cannot map to two characters.
*/

bool charMapping(string s1, string s2){
	if(s1.length() != s2.length()) return false;
	
	int n = s1.length();
	unordered_map<char, char> char_map1, char_map2;
	
	for(int i=0; i<n; i++){
		if(char_map1.find(s1[i]) == char_map1.end()){
			if(char_map2.find(s2[i]) != char_map2.end()) return false;
			char_map1[s1[i]] = s2[i];
			char_map2[s2[i]] = s1[i];
		}
		else{
			if(
				(char_map1[s1[i]] != s2[i]) ||
				(char_map2[s2[i]] != s1[i])
			)
				return false;
		}
	}
	
	return true;
}

// main function
int main(){
	cout << boolalpha << charMapping("abc", "bcd") << "\n";
	cout << charMapping("foo", "bar") << "\n";
	return 0;
}