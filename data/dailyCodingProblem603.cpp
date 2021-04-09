#include <bits/stdc++.h>
using namespace std;

/*
You are given an string representing the initial conditions of some dominoes.
Each element can take one of three values:

L, meaning the domino has just been pushed to the left,
R, meaning the domino has just been pushed to the right, or
., meaning the domino is standing still.

Determine the orientation of each tile when the dominoes stop falling.
Note that if a domino receives a force from the left and right side simultaneously, it will remain upright.

For example, given the string .L.R....L, you should return LL.RRRLLL.

Given the string ..R...L.L, you should return ..RR.LLLL
*/

string fallingDominos(string dominoes){
	vector<int> forces(dominoes.length());
	int force = 0;
	
	for(int i=0; i<dominoes.length(); i++){
		if(dominoes[i] == 'R') force = dominoes.length();
		else if(dominoes[i] == 'L') force = 0;
		else force = max(force-1, 0);
		forces[i] += force;
	}
	
	for(int i=dominoes.length()-1; i>=0; i--){
		if(dominoes[i] == 'L') force = dominoes.length();
		else if(dominoes[i] == 'R') force = 0;
		else force = max(force-1, 0);
		forces[i] -= force;
	}
	
	string s;
	for(int f : forces)
		s += (f > 0)? 'R' : (f < 0)? 'L' : '.';
	
	return s;
}

// main function
int main(){
	cout << fallingDominos(".L.R....L") << "\n";
	cout << fallingDominos("..R...L.L") << "\n";
	return 0;
}