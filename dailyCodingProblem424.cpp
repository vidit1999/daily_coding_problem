#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice,
find the two elements that appear only once.
*/

pair<int, int> twoAppear(vector<int> arr){
	int xor_num = 0, a = 0, b = 0;
	
	for(int i : arr)
		xor_num ^= i;
	
	int set_bit_num = xor_num & ~(xor_num - 1);
	
	for(int i : arr){
		if(i & set_bit_num)
			a ^= i;
		else
			b ^= i;
	}
	
	return {a, b};
}

// main function
int main(){
	auto ans = twoAppear({2, 3, 7, 9, 11, 2, 3, 11});
	cout << ans.first << " -- " << ans.second << "\n";
	return 0;
}