#include <bits/stdc++.h>
using namespace std;

/*
Create a basic sentence checker that takes in a stream of characters
and determines whether they form valid sentences. If a sentence is valid, the program should print it out.

We can consider a sentence valid if it conforms to the following rules:

The sentence must start with a capital letter, followed by a lowercase letter or a space.
All other characters must be lowercase letters, separators (,,;,:) or terminal marks (.,?,!,‽).
There must be a single space between each word.
The sentence must end with a terminal mark immediately following a word.
*/

bool sentenceChecker(string sentence){
	// if length of sentence is less than 2 return false
	if(sentence.length() < 2) return false;
	
	// if sentence does not start with capital letter or second character is not lower or space return false
	if(!isupper(sentence[0]) || !(islower(sentence[1]) || sentence[1] == ' ')) return false;
	
	int n = sentence.length(); // length of sentence
	
	unordered_set<char> terminals = {'.', '?', '!'}, separators = {',', ';', ':', ' '};
	
	for(int i=1;i<n;i++){
		if(
			!islower(sentence[i]) && // character is not lower case
			terminals.find(sentence[i]) == terminals.end() && // character is not a terminal character
			separators.find(sentence[i]) == separators.end() // character is not a separator
		)
			return false;
		if(sentence[i] == ' ' && sentence[i-1] == ' ')
			return false; // if a space is followed by a space then return false
	}
	
	if(
		terminals.find(sentence[n-1]) == terminals.end() || // last character is not a terminal character
		!islower(sentence[n-2]) // character just before the last character is not lower case
	)
		return false;
	
	return true;
}

void testFunc(vector<string> v){
	for(string s : v){
		cout << s << " -- ";
		if(sentenceChecker(s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	testFunc({
		"This is a valid sentence.",
		"This is not a valid sentence .",
		"This is not a valid ^ sentence.",
		" This is not a valid sentence.",
		"This is not    a valid sentence."
		
	});
	return 0;
}