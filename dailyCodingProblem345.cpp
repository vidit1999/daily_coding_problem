#include <bits/stdc++.h>
using namespace std;

/*
You are given a set of synonyms, such as (big, large) and (eat, consume).
Using this set, determine if two sentences with the same number of words are equivalent.

For example, the following two sentences are equivalent:

"He wants to eat food."
"He wants to consume food."
Note that the synonyms (a, b) and (a, c) do not necessarily imply (b, c):
consider the case of (coach, bus) and (coach, teacher).

Follow-up: what if we can assume that (a, b) and (a, c) do in fact imply (b, c)?
*/

unordered_multimap<string, string> synonyms1(vector<pair<string, string>> words){
	unordered_multimap<string, string> um(words.begin(), words.end());
	return um;
}

// main function
int main(){
	for(auto it : synonyms({{"big", "large"} , {"eat", "consume"}, {"big", "huge"}}))
		cout << it.first << " -- " << it.second << "\n";
	return 0;
}