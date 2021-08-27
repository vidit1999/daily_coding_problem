#include <bits/stdc++.h>
using namespace std;

/*
Given a string, return whether it represents a number.
Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation
And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"
*/

bool isStringNumber(string s){
	int n = s.length();
	int digit_count = 0, neg_count = 0, point_count = 0, e_count = 0;

	for(int i=0; i<n; i++){
		if(s[i] >= '0' && s[i] <= '9'){
			digit_count++;
		}
		else if(s[i] == '.'){ 
			if(++point_count > 1 && (i == 0 || i == n-1)){
				return false;
			}
		}
		else if(s[i] == '-'){
			if(++neg_count > 1 && i != 0){
				return false;
			}
		}
		else if(s[i] == 'e'){
			if(++e_count > 1 && (i == 0 || i == n-1)){
				return false;
			}
		}
		else{
			return false;
		}
	}

	return digit_count != 0;
}

void testFunc(vector<string> v){
	for(string s : v){
		cout << s << " --> " << isStringNumber(s) << "\n";
	}
}

// main function
int main(){
	testFunc({
		"10",
		"-10",
		"10.1",
		"-10.1",
		"1e5",
		"a",
		"x 1",
		"a -2",
		"-",
	});
	return 0;
}