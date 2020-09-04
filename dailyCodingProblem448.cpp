#include <bits/stdc++.h>
using namespace std;

/*
Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of
the array so that all the Rs come first, the Gs come second, and the Bs come last.
You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become
['R', 'R', 'R', 'G', 'G', 'B', 'B'].
*/

void segregateRGB(vector<char>& v){
	int countR = 0, countG = 0, countB = 0;
	
	for(char c : v){
		if(c == 'R')
			countR++;
		else if(c == 'G')
			countG++;
		else
			countB++;
	}
	
	for(int i=0;i<countR;i++)
		v[i] = 'R';
	for(int i=countR;i<countR+countG;i++)
		v[i] = 'G';
	for(int i=countR+countG;i<v.size();i++)
		v[i] = 'B';
}

// main function
int main(){
	vector<char> v = {'G', 'B', 'R', 'R', 'B', 'R', 'G'};
	
	for(char c : v)
		cout << c << " ";
	cout << "\n";
	
	segregateRGB(v);
	
	for(char c : v)
		cout << c << " ";
	cout << "\n";
	
	return 0;
}