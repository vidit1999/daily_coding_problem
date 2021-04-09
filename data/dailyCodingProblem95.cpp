#include <bits/stdc++.h>
using namespace std;

/*
Given a number represented by a list of digits, find the next greater
permutation of a number, in terms of lexicographic ordering.
If there is not greater permutation possible, return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2].
The list [1,3,2] should return [2,1,3].
The list [3,2,1] should return [1,2,3].
*/

vector<int> nextPermutation(vector<int> digits){
	int i;
	
	for(i=digits.size()-1; i>0; i--){
		if(digits[i] > digits[i-1])
			break;
	}
	
	if(i == 0){
		reverse(digits.begin(), digits.end());
		return digits;
	}
	
	int min_index = i;
	
	for(int j=i+1; j<digits.size(); j++){
		if(digits[j] > digits[i-1] && digits[j] < digits[min_index]){
			min_index = j;
		}
	}
	
	swap(digits[min_index], digits[i-1]);
	
	reverse(digits.begin()+i, digits.end());
	
	return digits;
}

void testFunc(vector<vector<int>> v){
	for(auto digits : v){
		for(int i : nextPermutation(digits))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		{1,2,3},
		{1,3,2},
		{3,2,1}
	});
	return 0;
}