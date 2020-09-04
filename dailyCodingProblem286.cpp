#include <bits/stdc++.h>
using namespace std;

/*
The skyline of a city is composed of several buildings of various widths and heights,
possibly overlapping one another when viewed from a distance.
We can represent the buildings using an array of (left, right, height) tuples,
which tell us where on an imaginary x-axis a building begins and ends, and how tall it is.
The skyline itself can be described by a list of (x, height) tuples,
giving the locations at which the height visible to a distant observer changes, and each new height.

Given an array of buildings as described above, create a function that returns the skyline.

For example, suppose the input consists of the buildings [(0, 15, 3), (4, 11, 5), (19, 23, 4)].
In aggregate, these buildings would create a skyline that looks like the one below.

     ______  
    |      |        ___
 ___|      |___    |   | 
|   |   B  |   |   | C |
| A |      | A |   |   |
|   |      |   |   |   |
------------------------
As a result, your function should return [(0, 3), (4, 5), (11, 3), (15, 0), (19, 4), (23, 0)].
*/

struct Building{
	int left, right, height;
};

// class Compare{
	// public:
	// bool operator () (Building b1, Building b2){
		// return (b1.right < b2.right);
	// }
// };

vector<pair<int, int>> skylineVector(vector<Building> buildings){
	int max_right_side = 0;
	for(auto building : buildings)
		max_right_side = max(max_right_side, building.right);
	
	vector<int> heights(max_right_side+1, 0);
	
	for(auto building : buildings){
		for(int i=building.left; i < building.right; i++)
			heights[i] = max(heights[i], building.height);
	}
	
	vector<pair<int, int>> ans = {{0, heights[0]}};
	int prev_height = heights[0];
	
	for(int i=1; i<heights.size();i++){
		if(heights[i] != prev_height){
			ans.push_back({i, heights[i]});
			prev_height = heights[i];
		}
	}
	
	return ans;
}

// main function
int main(){
	vector<Building> buildings = {{0, 15, 3}, {4, 11, 5}, {19, 23, 4}};
	
	for(auto sl : skylineVector(buildings))
		cout << sl.first << ", " << sl.second << "\n";
	return 0;
}