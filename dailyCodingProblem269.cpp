#include <bits/stdc++.h>
using namespace std;

/*
You are given an string representing the initial conditions of some dominoes.

Each element can take one of three values:
L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.

Determine the orientation of each tile when the dominoes stop falling.

Note that if a domino receives a force from the left and right
side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL.

Given the string ..R...L.L, you should return ..RR.LLLL.
*/

string fallenDominos(string init_dominos){
	int len = init_dominos.length();
	vector<int> forces(len, 0);
	
	int force = 0;
	
	for(int i=0;i<len;i++){
		if(init_dominos[i] == 'R') force = len;
		else if(init_dominos[i] == 'L') force = 0;
		else force = max(force-1, 0);
		forces[i] += force;
	}
	
	force = 0;
	
	for(int i=len-1;i>=0;i--){
		if(init_dominos[i] == 'L') force = len;
		else if(init_dominos[i] == 'R') force = 0;
		else force = max(force-1, 0);
		forces[i] -= force;
	}
	
	string ans;
	
	for(int i : forces){
		if(i > 0)
			ans += 'R';
		else if(i < 0)
			ans += 'L';
		else
			ans += '.';
	}
	
	return ans;
}

// main function
int main(){
	cout << fallenDominos(".L.R....L") << "\n";
	cout << fallenDominos("..R...L.L") << "\n";
	return 0;
}