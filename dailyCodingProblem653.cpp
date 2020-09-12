#include <bits/stdc++.h>
using namespace std;

/*
You are given given a list of rectangles represented by min and max x- and y-coordinates.
Compute whether or not a pair of rectangles overlap each other.
If one rectangle completely covers another, it is considered overlapping.

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

struct Rectangle{
	int x, y, width, height;
};

bool isInRange(int val, int min_val, int max_val){
	return (val >= min_val) && (val <= max_val);
}

bool isOverlapping(Rectangle r1, Rectangle r2){
	bool x_overlap = isInRange(r1.x, r2.x, r2.x + r2.height) || isInRange(r2.x, r1.x, r1.x + r1.height);
	bool y_overlap = isInRange(r1.y, r2.y, r2.y + r2.width) || isInRange(r2.y, r1.y, r1.y + r1.width);
	
	return x_overlap && y_overlap;
}

bool isOverlappingRects(vector<Rectangle> rects){
	for(int i=0; i<rects.size(); i++){
		for(int j=i+1; j<rects.size(); j++){
			if(isOverlapping(rects[i], rects[j])){
				return true;
			}
		}
	}
	return false;
}

// main function
int main(){
	vector<Rectangle> rects = {
		{1, 4, 3, 3},
		{-1, 3, 2, 1},
		{0, 5, 4, 3}
	};
	cout << isOverlappingRects(rects) << "\n";
	return 0;
}