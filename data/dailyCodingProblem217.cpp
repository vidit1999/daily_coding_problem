#include <bits/stdc++.h>
using namespace std;

/*
We say a number is sparse if there are no adjacent ones in its binary representation.
For example, 21 (10101) is sparse, but 22 (10110) is not. For a given input N,
find the smallest sparse number greater than or equal to N.

Do this in faster than O(N log N) time.
*/

int nextSparse(int num){
	vector<bool> binary;
	while(num){
		binary.push_back(num&1);
		num >>= 1;
	}
	
	binary.push_back(0);
	int n = binary.size();
	int last_final = 0;
	
	for(int i=1; i<n-1; i++){
		if(binary[i] && binary[i-1] && !binary[i+1]){
			binary[i+1] = 1;
			
			for(int j=i; j>=last_final; j--) binary[j] = 0;
			
			last_final = i+1;
		}
	}
	
	int ans = 0;
	for(int i=0; i<n; i++)
		ans += binary[i] * (1<<i);
	
	return ans;
}

// main function
int main(){
	cout << nextSparse(21) << "\n";
	cout << nextSparse(38) << "\n";
	return 0;
}