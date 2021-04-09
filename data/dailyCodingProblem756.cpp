#include <bits/stdc++.h>
using namespace std;

/*
You are given a string formed by concatenating several words
corresponding to the integers zero through nine and then anagramming.

For example, the input could be 'niesevehrtfeev',
which is an anagram of 'threefiveseven'.
Note that there can be multiple instances of each integer.

Given this string, return the original integers
in sorted order. In the example above, this would be 357.
*/

bool checkUmapEmpty(unordered_map<char, int>& umap){
	for(auto it : umap){
		if(it.second != 0){
			return false;
		}
	}
	return true;
}

bool checkDigitUsable(
	unordered_map<char, int>& umap,
	unordered_map<char, int>& digit_char
){
	for(auto it : digit_char){
		if(umap[it.first] < it.second){
			return false;
		}
	}
	return true;
}

bool originalIntegerHelper(
	unordered_map<int, unordered_map<char, int>>& digit_char_count,
	unordered_map<char, int>& umap,
	string& ans, string num
){
	if(checkUmapEmpty(umap)){
		ans = num;
		return true;
	}
	
	for(int i=0; i<=9; i++){
		if(checkDigitUsable(umap, digit_char_count[i])){
			
			for(auto it : digit_char_count[i]){
				umap[it.first] -= it.second;
			}
			
			num.push_back(char(i+'0'));
			
			if(originalIntegerHelper(digit_char_count, umap, ans, num)){
				return true;
			}
			
			for(auto it : digit_char_count[i]){
				umap[it.first] += it.second;
			}
			
			num.pop_back();
		}
	}
	
	return false;
}

string originalInteger(string anagram){
	unordered_map<char, int> umap;
	for(char c : anagram){
		umap[c]++;
	}
	
	vector<string> digit_string_vec = {
		"zero",
		"one",
		"two",
		"three",
		"four",
		"five",
		"six",
		"seven",
		"eight",
		"nine",
	};
	
	unordered_map<int, unordered_map<char, int>> digit_char_count;
	
	for(int i=0; i<=9; i++){
		for(char c : digit_string_vec[i]){
			digit_char_count[i][c]++;
		}
	}
	
	string ans = "";
	
	if(!originalIntegerHelper(digit_char_count, umap, ans, "")){
		cout << "No solution.";
	}
	
	return ans;
}

// main function
int main(){
	cout << originalInteger("niesevehrtfeev") << "\n";
	return 0;
}
