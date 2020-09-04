#include <bits/stdc++.h>
using namespace std;

/*
Create an algorithm to efficiently compute the approximate median of a list of numbers.

More precisely, given an unordered list of N numbers, find an element whose rank
is between N / 4 and 3 * N / 4, with a high level of certainty, in less than O(N) time.
*/

int median(int arr[], int n){
	if(n == 0) return 0;
	
	int k = 10*log2(n);
	
	set<int> s;
	for(int i=0;i<k;i++)
		s.insert(arr[rand()%n]);
	
	auto it = s.begin();
	advance(it, (s.size()/2) - 1);
	
	return *it;
}

// main function
int main(){
	srand(time(0));
	int arr[] = {1, 3, 2, 4, 5, 6, 8, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	cout << median(arr, n) << "\n";
	return 0;
}