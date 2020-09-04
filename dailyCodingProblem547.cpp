#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers, find the maximum XOR of any two elements.
*/

int maxXOR(vector<int> arr){
	int maxXor = 0;

	for(int i=0;i<arr.size();i++){
		for(int j=i+1;j<arr.size();j++){
            maxXor = max(maxXor, arr[i]^arr[j]);
        }
	}

    return maxXor;
}



// main function
int main(){
    cout << maxXOR({25, 10, 2, 8, 5, 3}) << "\n";
    cout << maxXOR({1, 2, 3, 4, 5, 6, 7}) << "\n";
	return 0;
}