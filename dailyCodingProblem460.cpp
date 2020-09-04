#include <bits/stdc++.h>
using namespace std;

/*
You are given a string consisting of the letters x and y, such as xyxxxyxyy.
In addition, you have an operation called flip, which changes a single x to y or vice versa.

Determine how many times you would need to apply this operation to ensure that
all x's come before all y's. In the preceding example, it suffices to
flip the second and sixth characters, so you should return 2
*/

/*
Here we need to find a sweet spot where summation of
no. of x in right side and no. of y in left side is minimum. 
*/

int flipCount(string s){
	int n = s.length();
	int leftYCount[n];
	int rightXCount[n];
	
	leftYCount[0] = (s[0] == 'y')? 1 : 0;
	rightXCount[n-1] = (s[n-1] == 'x')? 1 : 0;
	
	for(int i=1;i<n;i++){
		leftYCount[i] = leftYCount[i-1] + ((s[i] == 'y')? 1 : 0);
		rightXCount[n-1-i] = rightXCount[n-i] + ((s[n-1-i] == 'x')? 1 : 0);
	}
	cout << s << "\n";
	cout << s << "\n";
	for(int i=0;i<n;i++)
		cout << leftYCount[i] << " ";
	cout << "\n";
	for(int i=0;i<n;i++)
		cout << rightXCount[i] << " ";
	cout << "\n";
}

// main function
int main(){
	flipCount("xyxxxyxyy");
	return 0;
}