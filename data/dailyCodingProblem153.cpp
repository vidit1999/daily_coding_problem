#include <bits/stdc++.h>
using namespace std;

/*
Find an efficient algorithm to find the smallest distance
(measured in number of words) between any two given words in a string.

For example, given words "hello", and "world" and a text
content of "dog cat hello cat dog dog hello cat world",
return 1 because there's only one word "cat" in between the two words.
*/

vector<string> splitWords(string s){
	string st = "";
	vector<string> ans;
	
	for(char c : s){
		if(c == ' '){
			if(!st.empty())
				ans.push_back(st);
			st = "";
		}
		else{
			st += c;
		}
	}
	
	if(!st.empty()){
		ans.push_back(st);
	}
	
	return ans;
}

int smallestDistance(string s, string word1, string word2){
	int word1_index = INT_MAX, word2_index = INT_MAX;
	int min_distance = INT_MAX;
	
	vector<string> splited = splitWords(s);
	
	for(int i=0; i<splited.size(); i++){
		if(splited[i] == word1){
			min_distance = min(
				min_distance,
				(word2_index != INT_MAX)? i - word2_index - 1: INT_MAX
			);
			word1_index = i;
		}
		else if(splited[i] == word2){
			min_distance = min(
				min_distance,
				(word1_index != INT_MAX)? i - word1_index - 1 : INT_MAX
			);
			word2_index = i;
		}
	}
	
	return min_distance;
}

// main function
int main(){
	cout << smallestDistance("dog cat hello cat dog dog hello cat world", "hello", "world") << "\n";
	return 0;
}