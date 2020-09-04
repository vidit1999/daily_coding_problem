#include <bits/stdc++.h>
using namespace std;

/*
Given a list of integers and a number K,
return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5]
and K is 9, then it should return [2, 3, 4].
*/

vector<int> kSumArray(vector<int> arr, int k){
	unordered_map<int, int> sum_index;
	int curr_sum = 0;
	
	for(int i=0; i<arr.size(); i++){
		curr_sum += arr[i];
		
		if(curr_sum == k){
			return vector<int>(arr.begin(), arr.begin()+i+1);
		}

        if(sum_index.find(curr_sum - k) != sum_index.end()){
            return vector<int>(arr.begin()+sum_index[curr_sum-k]+1, arr.begin()+i+1);
        }

        sum_index[curr_sum] = i;
	}

    return {};
}

// main function
int main(){
    for(int i : kSumArray({1,2,3,4,5}, 10))
        cout << i << "\n";
	return 0;
}