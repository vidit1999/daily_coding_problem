#include <bits/stdc++.h>
using namespace std;

/*
Write a function, throw_dice(N, faces, total), that determines how many ways
it is possible to throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
*/

unordered_map<string, int> seen;

int throw_dice(int N, int faces, int total){
	if(total == 0 && N == 0)
		return 1;
	if(total != 0 && N == 0)
		return 0;
	
	string seen_string = to_string(N) + ", " + to_string(total);
	if(seen.find(seen_string) != seen.end())
		return seen[seen_string];
	
	int res = 0;
	for(int i=1;i<=faces;i++)
		res += throw_dice(N-1, faces, total-i);
	
	seen[seen_string] = res;
	return res;
}

// main function
int main(){
	cout << throw_dice(3, 6, 7) << "\n";
	return 0;
}