#include <bits/stdc++.h>
using namespace std;

/*
Pascal's triangle is a triangular array of integers constructed with the following formula:

The first row consists of the number 1.
For each subsequent row, each element is the sum of the numbers directly above it, on either side.
For example, here are the first few rows:

    1
   1 1
  1 2 1
 1 3 3 1
1 4 6 4 1
Given an input k, return the kth row of Pascal's triangle.

Bonus: Can you do this using only O(k) space?
*/

vector<int> pascalRow(int n){
	vector<int> row(n);
	row[0] = 1;
	
	for(int i=1;i<(n+1)/2;i++)
		row[i] = row[i-1]*(n-i)/i;
	
	for(int i=(n+1)/2;i<n;i++)
		row[i] = row[n-1-i];
	
	return row;
}

void testFunc(vector<int> v){
	for(int num : v){
		for(int i : pascalRow(num))
			cout << i << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({1,2,3,4,5,6});
	return 0;
}