#include <bits/stdc++.h>
using namespace std;

/*
You are given given a list of rectangles represented by min and max x- and y-coordinates.
Compute whether or not a pair of rectangles overlap each other. If one rectangle
completely covers another, it is considered overlapping.

For example, given the following rectangles:

{
    "top_left": (1, 4),
    "dimensions": (3, 3) # width, height
},
{
    "top_left": (-1, 3),
    "dimensions": (2, 1)
},
{
    "top_left": (0, 5),
    "dimensions": (4, 3)
}
return true as the first and third rectangle overlap each other.
*/

struct Rect{
	pair<int, int> top_left;
	pair<int, int> dimensions;
};

bool doesOverlap(
	pair<int, int> pl1, pair<int, int> pr1,
	pair<int, int> pl2, pair<int, int> pr2
){
	if(pl1.first >= pr2.first || pl2.first >= pr1.first) return false;
	if(pl1.second <= pr2.second || pl2.second <= pr1.second) return false;
	return true;
}

bool anyOverlap(vector<Rect> rectangles){
	for(int i=0; i<rectangles.size(); i++){
		for(int j=i+1; j<rectangles.size(); j++){
			pair<int, int> pl1 = rectangles[i].top_left,
			pr1 = {
				rectangles[i].top_left.first + rectangles[i].dimensions.second,
				rectangles[i].top_left.second - rectangles[i].dimensions.first
			},
			pl2 = rectangles[j].top_left,
			pr2 = {
				rectangles[j].top_left.first + rectangles[j].dimensions.second,
				rectangles[j].top_left.second - rectangles[j].dimensions.first
			};
			
			if(doesOverlap(pl1, pr1, pl2, pr2)) return true;
		}
	}
	
	return false;
}

// main function
int main(){
	vector<Rect> rectangles = {
		{
			{1, 4},
			{3, 3},
		},
		{
			{-1, 3},
			{2, 1},
		},
		{
			{0, 5},
			{4, 3},
		}
	};
	
	if(anyOverlap(rectangles))
		cout << "Yes\n";
	else
		cout << "No\n";
	return 0;
}