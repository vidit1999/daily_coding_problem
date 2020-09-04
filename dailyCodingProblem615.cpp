#include <bits/stdc++.h>
using namespace std;

/*
The stable marriage problem is defined as follows:

Suppose you have N men and N women, and each person has ranked
their prospective opposite-sex partners in order of preference.

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

Write an algorithm that pairs the men and women together in such
a way that no two people of opposite sex would both rather be
with each other than with their current partners.
*/

bool galPrefersMore(
	string gal, // the girl in concern
	string guy1, // her current boyfriend
	string guy2, // wants to get her
	unordered_map<string, vector<string>>& gal_preferences // all girls preferences
){
	// if guy1 is in her preference list before guy2
	// then nothing will happen return false
	// else return true
	for(string guy : gal_preferences[gal]){
		if(guy == guy1) return false;
		if(guy == guy2) return true;
	}
	return false;
}


// function prints the stable pairing
void stableMarriage(
	unordered_map<string, vector<string>> guy_preferences,
	unordered_map<string, vector<string>> gal_preferences
){
	unordered_map<string, string> gal_paired;
	unordered_set<string> guy_hooked;
	int num_guys = guy_preferences.size();
	
	while(guy_hooked.size() < num_guys){
		string guy = ""; // try for this guy
		for(auto it : guy_preferences){
			// take a guy who is not already hooked up
			if(guy_hooked.find(it.first) == guy_hooked.end()){
				guy = it.first;
				break;
			}
		}
		
		for(string gal : guy_preferences[guy]){
			// check all his preferable girls
			// if a girl is not already paired then make them a pair
			// else check the girl's preferences
			// if she prefers this guy more then her previous
			// relation will break and she will pair with this guy
			// the her ex will be free
			if(gal_paired.find(gal) == gal_paired.end()){
				gal_paired[gal] = guy;
				guy_hooked.insert(guy);
				break;
			}
			else{
				if(galPrefersMore(gal, gal_paired[gal], guy, gal_preferences)){
					guy_hooked.erase(gal_paired[gal]);
					gal_paired[gal] = guy;
					guy_hooked.insert(guy);
					break;
				}
			}
		}
	}
	
	for(auto it : gal_paired){
		cout << it.second << " <---> " << it.first << "\n";
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
	
    stableMarriage(guy_preferences, gal_preferences);
	return 0;
}