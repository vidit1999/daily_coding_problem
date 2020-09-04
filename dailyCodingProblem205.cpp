#include <bits/stdc++.h>
using namespace std;

/*
Given an integer, find the next permutation of it in absolute order.
For example, given 48975, the next permutation would be 49578.
*/

string nextPerm(string number){
	int i, j, n = number.length();
	
	for(i=n-1; i>0; i--){
		if(number[i] > number[i-1])
			break;
	}
	
	if(i == 0) return "No next permutation.";
	
	int smallest = i;
	
	for(j=i+1; j<n; j++){
		if(number[j] > number[i] && number[j] > number[smallest])
			smallest = j;
	}
	
	swap(number[smallest], number[i-1]);
	reverse(number.begin()+i, number.end());
	
	return number;
}

// main function
int main(){
	cout << nextPerm("48975") << "\n";
	return 0;
}