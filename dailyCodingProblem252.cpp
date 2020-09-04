#include <bits/stdc++.h>
using namespace std;

/*
The ancient Egyptians used to express fractions as a sum of several
terms where each numerator is one. For example, 4 / 13 can be
represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary
fraction a / b, where a < b,
into an Egyptian fraction.
*/

vector<pair<int, int>> egyptianFraction(pair<int, int> fraction){
	if(fraction.second % fraction.first == 0){
		return {{1, fraction.second/fraction.first}};
	}
	
	int d = ceil(float(fraction.second)/float(fraction.first));
	
	vector<pair<int, int>> ans = {{1, d}};
	
	for(auto it : egyptianFraction({fraction.first*d - fraction.second, fraction.second*d}))
		ans.push_back(it);
	
	return ans;
}

// main function
int main(){
	for(auto it : egyptianFraction({4, 13}))
		cout << it.first << "/" << it.second << "\n";
	return 0;
}