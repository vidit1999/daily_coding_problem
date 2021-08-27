#include <bits/stdc++.h>
using namespace std;

/*
A cryptarithmetic puzzle is a mathematical game where the digits of some numbers
are represented by letters. Each letter represents a unique digit.

For example, a puzzle of the form:

  SEND
+ MORE
--------
 MONEY

may have the solution:
{'S': 9, 'E': 5, 'N': 6, 'D': 7, 'M': 1, 'O', 0, 'R': 8, 'Y': 2}

Given a three-word puzzle like the one above,
create an algorithm that finds a solution.
*/

// helper function for cryptarithmeticPuzzle
// checks if a map satisfies the conditions
bool checkSum(unordered_map<char, int> char_map, string s1, string s2, string s3){
	vector<int> digit_strings;
	
	for(string s : {s1, s2, s3}){
		string digit_string;
		for(char c : s)
			digit_string += char_map[c]+'0';
		
		digit_strings.push_back(stoi(digit_string));
	}

	return digit_strings[0] + digit_strings[1] == digit_strings[2];
}

// generate all permutations of length k (k <= 10)
void enumerate(int digits[], int n, int k, int& size, vector<vector<int>>& all_perms){
	if(k == 0){
		// we have got one permutations
		all_perms.push_back(vector<int>(digits+n, digits+size));
		return;
	}
	
	for(int i=0; i<n; i++){
		swap(digits[i], digits[n-1]);
		enumerate(digits, n-1, k-1, size, all_perms);
		swap(digits[i], digits[n-1]);
	}
}

// takes a set and a vector
// maps each element of set with element of vector
unordered_map<char, int> generate_map(unordered_set<char> s, vector<int> v){
	unordered_map<char, int> char_map;
	int i = 0;
	for(char c : s){
		char_map[c] = v[i++];
	}
	return char_map;
}

// returns a map of char to int(digit)
unordered_map<char, int> cryptarithmeticPuzzle(string s1, string s2, string s3){
	unordered_set<char> s;
	// get all unique characters
	for(string str : {s1, s2, s3})
        for(char c : str)
            s.insert(c);

	// more than 10 unique letters is not possible
	// as each letter represents a unique digit
	if(s.size() > 10) return {};
	
	vector<vector<int>> all_perms;
	int digits[] = {0,1,2,3,4,5,6,7,8,9};
	int n = 10;
	int k = s.size();
    int size = 10;
	

	enumerate(digits, n, k, size, all_perms);

	for(auto v : all_perms){
		auto char_map = generate_map(s, v);
		if(checkSum(char_map, s1, s2, s3))
			return char_map;
	}
	
	return {}; // if no config is possible
}

// main function
int main(){
	for(auto it : cryptarithmeticPuzzle("SEND", "MORE", "MONEY"))
		cout << it.first << " --> " << it.second << "\n";
    
	return 0;
}