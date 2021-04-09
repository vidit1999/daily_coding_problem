#include <bits/stdc++.h>
using namespace std;

/*
Gray code is a binary code where each successive value differ in only one bit,
as well as when wrapping around. Gray code is common in hardware so
that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
*/

vector<string> grayCode(int n){
	if(n == 0) return {};
	
	vector<string> arr = {"0", "1"};
	
	for(int i=1; i<n; i++){
		int n = arr.size();
		
		for(int j=n-1; j>=0; j--){
			arr.push_back(arr[j]);
		}
		
		for(int j=0; j<n; j++){
			arr[j] = "0" + arr[j];
		}
		
		for(int j=n; j<2*n; j++){
			arr[j] = "1" + arr[j];
		}
	}
	
	return arr;
}

// main function
int main(){
	for(int i=0; i<5; i++){
		auto arr = grayCode(i);
		for(auto s : arr){
			cout << s << " ";
		}
		cout << "\n";
	}
	return 0;
}