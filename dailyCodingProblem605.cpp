#include <bits/stdc++.h>
using namespace std;

/*
In academia, the h-index is a metric used to calculate the impact of a researcher's papers.
It is calculated as follows:

A researcher has index h if at least h of her N papers have h citations each.
If there are multiple h satisfying this formula, the maximum is chosen.

For example, suppose N = 5, and the respective citations of each paper
are [4, 3, 0, 1, 5]. Then the h-index would be 3, since the researcher
has 3 papers with at least 3 citations.

Given a list of paper citations of a researcher, calculate their h-index.
*/

int hIndex(vector<int> citations){
	sort(citations.begin(), citations.end(), greater<int>());
	int h_index = 0;
	
	for(int citation : citations){
		if(citation >= h_index+1){
			h_index++;
		}
		else{
			break;
		}
	}
	
	return h_index;
}

// main function
int main(){
	cout << hIndex({4, 3, 0, 1, 5}) << "\n";
	return 0;
}