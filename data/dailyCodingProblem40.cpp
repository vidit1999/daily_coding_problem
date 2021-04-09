#include <bits/stdc++.h>
using namespace std;

/*
Given an array of integers where every integer occurs three
times except for one integer, which only occurs once,
find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1.
Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
*/

int uniqueElement(int arr[], int n){
    int ones = 0, twos = 0;

    for(int i=0; i<n; i++){
        twos |= (ones & arr[i]);
        ones ^= arr[i];
        int common_bit_mask = ~(ones & twos);
        ones &= common_bit_mask;
        twos &= common_bit_mask;
    }

    return ones;
}

// main function
int main(){
    int arr[] ={13, 19, 13, 13}; // {6, 1, 3, 3, 3, 6, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << uniqueElement(arr, n) << "\n";
	return 0;
}