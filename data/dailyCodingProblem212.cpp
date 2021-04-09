#include <bits/stdc++.h>
using namespace std;

/*
Spreadsheets often use this alphabetical encoding for its columns:
"A", "B", "C", ..., "AA", "AB", ..., "ZZ", "AAA", "AAB", ....

Given a column number, return its alphabetical column id. For example,
given 1, return "A". Given 27, return "AA".
*/

string alphabeticalColumn(int num){
	string ans = "";
	while(num){
		ans += ((num-1)%26 + 'A');
		num = (num-1)/26;
	}
	return ans;
}

// main function
int main(){
	srand(time(0));
	for(int i=0; i<10; i++){
		int num = rand()%1000 + 1;
		cout << num << " ---> " << alphabeticalColumn(num) << "\n";
	}
	return 0;
}