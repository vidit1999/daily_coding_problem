#include <bits/stdc++.h>
using namespace std;

/*
At a popular bar, each customer has a set of favorite drinks,
and will happily accept any drink among this set.
For example, in the following situation, customer 0 will
be satisfied with drinks 0, 1, 3, or 6.

preferences = {
    0: [0, 1, 3, 6],
    1: [1, 4, 7],
    2: [2, 4, 7, 5],
    3: [3, 2, 5],
    4: [5, 8]
}
A lazy bartender working at this bar is trying to reduce his
effort by limiting the drink recipes he must memorize.
Given a dictionary input such as the one above,
return the fewest number of drinks he must learn in order to satisfy all customers.

For the input above, the answer would be 2, as drinks 1 and 5 will satisfy everyone.
*/


void lazyBartenderHelper(
	vector<vector<int>>& preferences,
	unordered_set<int>& drinks,
	int index, int& ans
){
	if(index == preferences.size() || drinks.size() >= ans){
		ans = min(ans, int(drinks.size()));
		return;
	}

	for(auto pref : preferences[index]){
		if(drinks.find(pref) != drinks.end()){
			lazyBartenderHelper(preferences, drinks, index+1, ans);
		}
		else{
			drinks.insert(pref);
			lazyBartenderHelper(preferences, drinks, index+1, ans);
			drinks.erase(pref);
		}
	}
}

int lazyBartender(vector<vector<int>>& preferences){
	int ans = INT_MAX;
	unordered_set<int> drinks;
	
	lazyBartenderHelper(preferences, drinks, 0, ans);
	
	return ans;
}

// main function
int main(){
	vector<vector<int>> preferences = {
		{0, 1, 3, 6},
		{1, 4, 7},
		{2, 4, 7, 5},
		{3, 2, 5},
		{5, 8}
	};

	cout << lazyBartender(preferences) << "\n";

	return 0;
}