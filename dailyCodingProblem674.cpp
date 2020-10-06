#include <bits/stdc++.h>
using namespace std;

/*
A girl is walking along an apple orchard with a bag in each hand.
She likes to pick apples from each tree as she goes along,
but is meticulous about not putting different kinds of apples in the same bag.

Given an input describing the types of apples she will pass on her path,
in order, determine the length of the longest portion of
her path that consists of just two types of apple trees.

For example, given the input [2, 1, 2, 3, 3, 1, 3, 5],
the longest portion will involve types 1 and 3, with a length of four.
*/

int longestPortion(vector<int> arr){
    // check if array has only one or two kind of object
    int type_number = unordered_set<int>(arr.begin(), arr.end()).size();
    if(type_number <= 2)
        return arr.size();

	unordered_map<int, int> path_map;
	int start = 0, max_path_size = INT_MIN;
	
	for(int i=0;i<arr.size();i++){
		path_map[arr[i]]++;
		if(path_map.size() > 2){
			int path_size = i - start;
			max_path_size = max(max_path_size, path_size);
            
            while(path_map.size() > 2){
                if((--path_map[arr[start]]) == 0){
                    path_map.erase(arr[start]);
                }
                start++;
            }
        }
	}
	
	return max_path_size;
}

// main function
int main(){
	cout << longestPortion({2, 1, 2, 3, 3, 1, 3, 5}) << "\n";
	return 0;
}