#include <bits/stdc++.h>
using namespace std;

/*
On a mysterious island there are creatures known as Quxes which come in
three colors: red, green, and blue. One power of the Qux is that
if two of them are standing next to each other, they can transform
into a single creature of the third color.

Given N Quxes standing in a line, determine the smallest number of
them remaining after any possible sequence of such transformations.

For example, given the input ['R', 'G', 'B', 'G', 'B'], it is
possible to end up with a single Qux through the following steps:

        Arrangement       |   Change
----------------------------------------
['R', 'G', 'B', 'G', 'B'] | (R, G) -> B
['B', 'B', 'G', 'B']      | (B, G) -> R
['B', 'R', 'B']           | (R, B) -> G
['B', 'G']                | (B, G) -> R
['R']                     |
*/

int minNumQux(vector<char> quxes){
	int red = 0, blue = 0, green = 0;
	
	for(char c : quxes){
		if(c == 'R') red++;
		else if(c == 'G') green++;
		else blue++;
	}
	
	if(red == quxes.size() || green == quxes.size() || blue == quxes.size())
		return quxes.size();
	
	if(red%2 == green%2 && red%2 == blue%2)
		return 2;
	return 1;
}

// main function
int main(){
	cout << minNumQux({'R', 'G', 'B', 'G', 'B'}) << "\n";
	return 0;
}