#include <bits/stdc++.h>
using namespace std;

/*
Given a real number n, find the square root of n.
For example, given n = 9, return 3.
*/

int squareRoot(int n){
	if(n <= 1) return n;
	
	int low = 1, high = n, ans;
	
	while(low <= high){
		int mid = low + (high - low)/2;
		
		if(mid*mid == n){
			return mid;
		}
		else if(mid*mid < n){
			low = mid+1;
			ans = mid;
		}
		else{
			high = mid - 1;
		}
	}
	
	return ans;
}

// main function
int main(){
	for(int i=0; i<11; i++)
		cout << squareRoot(i) << "\n";
	return 0;
}