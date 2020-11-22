#include <bits/stdc++.h>
using namespace std;

/*
You are given a string of length N and a parameter k.
The string can be manipulated by taking one of the
first k letters and moving it to the end.

Write a program to determine the lexicographically
smallest string that can be created after an unlimited number of moves.

For example, suppose we are given the string daily and k = 1.
The best we can create in this case is ailyd
*/

string kMoveLast(string s, int k){
	if(k >= 2){
		sort(s.begin(), s.end());
		return s;
	}
	
	int min_char_index = 0;
	
	for(int i=1; i<s.length(); i++){
		if(s[min_char_index] > s[i]){
			min_char_index = i;
		}
	}
	
	string ans = "";
	
	for(int i=min_char_index; i<s.length(); i++){
		ans += s[i];
	}
	
	for(int i=0; i<min_char_index; i++){
		ans += s[i];
	}
	
	return ans;
}

// main function
int main(){
	cout << kMoveLast("daily", 1) << "\n";
	cout << kMoveLast("daily", 2) << "\n";
	return 0;
}