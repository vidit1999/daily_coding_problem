#include <bits/stdc++.h>
using namespace std;

/*
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for
its order is an array representing whether each number is larger or smaller
than the last. Given this information, reconstruct an array that is
consistent with it. For example, given [None, +, +, -, +],
you could return [1, 2, 3, 0, 4].
*/

vector<int> originalArray(vector<char> jumbled){
	int min_seen = 0, max_seen = 0;
	
	vector<int> ans;
	ans.push_back(0);
	
	for(int i=1; i<jumbled.size(); i++){
		if(c == '+'){
			ans.push_back(++max_seen);
		}
		else
			ans.push_back(--min_seen);
	}
	
	for(int i=0; i<ans.size(); i++)
		ans[i]+=(0-min_seen);
	
	return ans;
}

// main function
int main(){
	for(int i : originalArray({'0', '+', '+', '-', '+'}))
		cout << i << "\n";
	return 0;
}