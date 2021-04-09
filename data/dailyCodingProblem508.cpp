#include <bits/stdc++.h>
using namespace std;

/*
Create an algorithm to efficiently compute the approximate median of a list of numbers.
More precisely, given an unordered list of N numbers, find an element whose rank is between N / 4 and 3 * N / 4,
with a high level of certainty, in less than O(N) time.
*/


int countMedian(int arr[], int n){
	srand(time(0));
	set<int> s;
	int k = 10*log2(n);
	
	for(int i=0;i<k;i++){
		s.insert(arr[rand()%n]);
	}
	
	set<int>::iterator it = s.begin();
	advance(it,(s.size()/2)-1);
	return *it;
}

// main function
int main(){
	int arr[] = {1, 3, 2, 4, 5, 6, 8, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << countMedian(arr, n) << "\n";
	return 0;
}