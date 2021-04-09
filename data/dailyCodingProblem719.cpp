#include <bits/stdc++.h>
using namespace std;

/*
Spreadsheets often use this alphabetical encoding for its columns:
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id.
For example, given 1, return "A". Given 27, return "AA".
*/

string columnEncoding(int number){
	string ans = "";
	
	while(number){
		int rem = number%26;
		
		if(rem == 0){
			ans += 'Z';
			number /= 26;
			number--;
		}
		else{
			ans += ('A' + rem - 1);
			number /= 26;
		}
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

void testFunc(vector<int> v){
	for(auto i : v){
		cout << i << " --> " << columnEncoding(i) << "\n";
	}
}

// main function
int main(){
	testFunc({26, 51, 52, 80, 676, 702, 705});
	return 0;
}