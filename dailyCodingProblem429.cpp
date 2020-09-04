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

vector<int> pascalRow(int k){
	vector<int> row(k+1);
	row[0] = 1;
	row[k] = 1;
	
	for(int i=1;i<k/2+1;i++){
		row[i] = row[i-1]*(k-i+1)/i;
		row[k-i] = row[i];
	}
	return row;
}

// main function
int main(){
	for(int k=0;k<=5;k++){
		for(int i : pascalRow(k))
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}