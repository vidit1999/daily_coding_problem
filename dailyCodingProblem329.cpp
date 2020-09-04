#include <bits/stdc++.h>
using namespace std;

/*
Suppose you have N men and N women, and each person has ranked their prospective
opposite-sex partners in order of preference.

For example, if N = 3, the input could be something like this:

guy_preferences = {
    'andrew': ['caroline', 'abigail', 'betty'],
    'bill': ['caroline', 'betty', 'abigail'],
    'chester': ['betty', 'caroline', 'abigail'],
}

gal_preferences = {
    'abigail': ['andrew', 'bill', 'chester'],
    'betty': ['bill', 'andrew', 'chester'],
    'caroline': ['bill', 'chester', 'andrew']
}

Write an algorithm that pairs the men and women together in such a
way that no two people of opposite sex would both rather be with each
other than with their current partners.
*/

// gal => women behind this mess
// guy1 => already hooked with her, guy2 => trying hard to get her
bool galPreferMore(
	unordered_map<string, vector<string>> gal_preferences,
	string gal, string guy1, string guy2
){
	for(string guy : gal_preferences[gal]){
		if(guy == guy1)
			return false;
		if(guy == guy2)
			return true;
	}
	return false;
}

void preferences(
	unordered_map<string, vector<string>> guy_preferences,
	unordered_map<string, vector<string>> gal_preferences
){
	unordered_map<string, string> gal_paired;
	unordered_set<string> guys_hooked;
	int num_guys = guy_preferences.size();
	
	while(guys_hooked.size() < num_guys){
		string guy = "";
		for(auto it : guy_preferences){
			if(guys_hooked.find(it.first) == guys_hooked.end()){
				guy = it.first;
				break;
			}
		}
		
		for(string gal : guy_preferences[guy]){
			if(gal_paired.find(gal) == gal_paired.end()){
				gal_paired[gal] = guy;
				guys_hooked.insert(guy);
				break;
			}
			else{
				if(galPreferMore(gal_preferences, gal, gal_paired[gal], guy)){
					guys_hooked.erase(gal_paired[gal]);
					gal_paired[gal] = guy;
					guys_hooked.insert(guy);
					break;
				}
			}
		}
		
	}
	
	for(auto it : gal_paired){
		cout << it.second << " <--> " << it.first << "\n";
	}
}

// main function
int main(){
	unordered_map<string, vector<string>> guy_preferences = {
		{"andrew", {"caroline", "abigail", "betty"}},
		{"bill", {"caroline", "betty", "abigail"}},
		{"chester", {"betty", "caroline", "abigail"}}
	};
	unordered_map<string, vector<string>> gal_preferences = {
		{"abigail", {"andrew", "bill", "chester"}},
		{"betty", {"bill", "andrew", "chester"}},
		{"caroline", {"bill", "chester", "andrew"}}
	};
	
    preferences(guy_preferences, gal_preferences);
	return 0;
}