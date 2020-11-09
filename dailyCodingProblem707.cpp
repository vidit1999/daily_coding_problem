#include <bits/stdc++.h>
using namespace std;

/*
You are the technical director of WSPT radio, serving listeners nationwide.
For simplicity's sake we can consider each listener to live along a horizontal
line stretching from 0 (west) to 1000 (east).

Given a list of N listeners, and a list of M radio towers,
each placed at various locations along this line, determine
what the minimum broadcast range would have to be in order
for each listener's home to be covered.

For example, suppose listeners = [1, 5, 11, 20], and
towers = [4, 8, 15]. In this case the minimum range
would be 5, since that would be required for the tower
at position 15 to reach the listener at position 20.
*/

int towerRange(int house[], int m, int tower[], int n){
	int left_tower = INT_MIN;
	int right_tower = tower[0];
	int min_range = 0;
	
	int j = 0, k = 0;
	
	while(j < m){
		if(house[j] < right_tower){
			int left = house[j] - left_tower;
			int right = right_tower - house[j];
			min_range = max(min_range, min(left, right));
			j++;
		}
		else{
			left_tower = tower[k];
			if(k < n-1){
				k++;
				right_tower = tower[k];
			}
			else{
				right_tower = INT_MAX;
			}
		}
	}
	
	return min_range;
}

// main function
int main(){
	int house[] = {12, 13, 11, 80};
	int m = sizeof(house)/sizeof(house[0]);
	
	int tower[] = {4, 6, 15, 60};
	int n = sizeof(tower)/sizeof(tower[0]);
	
	cout << towerRange(house, m, tower, n) << "\n";
	
	return 0;
}