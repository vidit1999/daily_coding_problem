#include <bits/stdc++.h>
using namespace std;

/*
Given an integer, find the next permutation of it in absolute order.
For example, given 48975, the next permutation would be 49578.
*/

string nextGreater(string num){
	if(num.length() < 2) return num;

	int n = num.length();
	int i;

	for(i=n-1; i>0; i--){
		if(num[i] > num[i-1]){
			break;
		}
	}

    if(i == 0) return num;

	int x = i-1, small = i;

	for(int j=i; j<n; j++){
		if(num[j] > num[x] && num[j] <= num[small]){
			small = j;
		}
	}

	swap(num[small], num[x]);
	reverse(num.begin()+i, num.end());

	return num;
}

void testFunc(vector<string> v){
	for(string s : v){
		cout << s << ", " << nextGreater(s) << "\n";
	}
}

// main function
int main(){
	testFunc({
		"218765",
		"1234",
		"4321",
		"534976",
		"48975",
	});
	return 0;
}