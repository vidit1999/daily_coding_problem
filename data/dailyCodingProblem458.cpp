#include <bits/stdc++.h>
using namespace std;

/*
A rule looks like this:

A NE B

This means this means point A is located northeast of point B.

A SW C

means that point A is southwest of C.

Given a list of rules, check if the sum of the rules validate. For example:

A N B
B NE C
C N A
does not validate, since A cannot be both north and south of C.

A NW B
A N B
is considered valid.
*/

// generate position of a point from a given point and the direction
// Example : given point == {0,0} and direction == "NE"
// returns {1,1}
pair<int, int> generatePosition(pair<int, int> point, string direction){
	int x_add = 0, y_add = 0;
	x_add = (direction == "N")? 1 : (direction == "S")? -1 : 0;
	y_add = (direction == "E")? 1 : (direction == "W")? -1 : 0;

	if(direction == "NE")
		x_add = 1, y_add = 1;
	if(direction == "NW")
		x_add = 1, y_add = -1;
	if(direction == "SE")
		x_add = -1, y_add = 1;
	if(direction == "SW")
		x_add = -1, y_add = -1;
	return make_pair(point.first+x_add, point.second+y_add);
}

// given two points coordinate and the given direction returns whether
// this set up is valid or not
// Example : Starting point == {0,0} , Ending point == {1,2}, given direction = "N"
// returns True as a pair as the ending point is in North and also in East
// but it will return false if given direction is "SE"
bool directionVerify(pair<int, int> stpos, pair<int, int> endpos, string givenDirection){
	// if endpos is in north then n_dist will be > 0 ,endpos is in south if n_dist < 0
	// if in east then e_dist > 0, in west then e_dist < 0
	int n_dist = endpos.first - stpos.first;
	int e_dist = endpos.second - stpos.second;

	string nDirection = "";
	string eDirection = "";

	nDirection += (n_dist > 0)? "N" : (n_dist < 0)? "S" : "";
	eDirection += (e_dist > 0)? "E" : (e_dist < 0)? "W" : "";

	unordered_set<string> allowedDirections;
	if(nDirection != "")
		allowedDirections.insert(nDirection);
	if(eDirection != "")
		allowedDirections.insert(eDirection);
	allowedDirections.insert(nDirection+eDirection);

    for(auto it : allowedDirections)
        cout << it << "\n";
	return allowedDirections.find(givenDirection) != allowedDirections.end();
}

// check if the given rules are valid or not
// input argument is vector<pair<pair<stpos, endpos>, direction>
bool validRules(vector<pair<pair<string, string> , string>> points){
    unordered_map<string, pair<int, int>> positions; // map<pos, pair<x-cord, y-cord>>
    for(auto pt : points){
		// if the starting position is not in positions
		// then insert starting position in positions
		// and make its corresponding position {0,0}
		// And calculate the position of the second point
		// using generatePosition and insert it in positions
		if(positions.find(pt.first.first) == positions.end()){
			positions[pt.first.first] = make_pair(0,0);
			positions[pt.first.second] = generatePosition({0,0},pt.second);
		}
		else{
			// if second position is not in positions
			// then calculate position using generatePosition
			// and insert it into positions
			if(positions.find(pt.first.second) == positions.end())
				positions[pt.first.second] = generatePosition(positions[pt.first.first],pt.second);
			else{
				if(!directionVerify(positions[pt.first.second],positions[pt.first.first],pt.second))
					return false;
			}
		}
	}
    for(auto it : positions){
        cout << it.first << " --- " << "(" << it.second.first << ", " << it.second.second << ")\n";
    }
	return true;
}


// A N B
// B NE C
// C N A

// A NW B
// A N B
// main function
int main(){
	vector<pair<pair<string, string> , string>> points;
    points.push_back(make_pair(make_pair("B","A"),"N"));
    points.push_back(make_pair(make_pair("B","C"),"SW"));
    points.push_back(make_pair(make_pair("C","A"),"N"));
    if(validRules(points))
        cout << "Yes\n";
    else
        cout << "No\n";
	return 0;
}