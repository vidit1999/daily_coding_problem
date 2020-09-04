#include <bits/stdc++.h>
using namespace std;

/*
The sequence [0, 1, ..., N] has been jumbled, and the only clue you have for its order
is an array representing whether each number is larger or smaller than the last.
Given this information, reconstruct an array that is consistent with it.
For example, given [None, +, +, -, +], you could return [1, 2, 3, 0, 4]
*/

vector<int> jumbledArray(vector<char> signs){
	int min = 0, max = 0;
	vector<int> ans = {0};
	
	for(int i=1; i<signs.size(); i++){
		if(signs[i] == '+'){
			ans.push_back(++max);
		}
		else{ // signs[i] == '-'
			ans.push_back(--min);
		}
	}
	
	for(int i=0; i<ans.size(); i++){
		ans[i] -= min;
	}
	
	return ans;
}

// main function
int main(){
	vector<char> signs = {'0', '+', '+', '-', '+'};
	for(int i : jumbledArray(signs))
		cout << i << " ";
	cout << "\n";
	return 0;
}