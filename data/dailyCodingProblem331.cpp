#include <bits/stdc++.h>
using namespace std;

/*
You are given a string consisting of the letters x and y, such as xyxxxyxyy.
In addition, you have an operation called flip, which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation to
ensure that all x's come before all y's. In the preceding example,
it suffices to flip the second and sixth characters, so you should return 2.
*/

void flip(string& s, int i){
	if(s[i] == 'x') s[i] = 'y';
	else s[i] = 'x';
}

int countMinFlip(string s){
	int leftY[s.length()], rightX[s.length()];
	leftY[0] = 0, rightX[s.length()-1] = 0;
	
	for(int i=1;i<s.length();i++){
		leftY[i] = leftY[i-1] + (s[i-1] == 'y');
	}
	
	for(int i = s.length()-2;i>=0;i--){
		rightX[i] = rightX[i+1] + (s[i+1] == 'x');
	}
	
	int res = s.length();
	
	for(int i=0;i<s.length();i++)
		res = min(res, leftY[i]+rightX[i]);
	
	return res;
}

// main function
int main(){
	cout << countMinFlip("xyxxxyxyy") << "\n";
	return 0;
}