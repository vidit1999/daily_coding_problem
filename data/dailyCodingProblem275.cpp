#include <bits/stdc++.h>
using namespace std;

/*
The "look and say" sequence is defined as follows: beginning with the term 1,
each subsequent term visually describes the digits appearing in the previous term.
The first few terms are as follows:

1
11
21
1211
111221
As an example, the fourth term is 1211, since the third term consists of one 2 and one 1.

Given an integer N, print the Nth term of this sequence.
*/

string lookAndSay(int n){
	string ans = "1";
	
	while(n > 1){
		string s;
		int count = 1;
		for(int i=1;i<ans.length();i++){
			if(ans[i] != ans[i-1]){
				s += (to_string(count) + ans[i-1]);
				count = 1;
			}
			else{
				count++;
			}
		}
		s += (to_string(count) + ans[ans.length()-1]);
		ans = s;
		n--;
	}

	return ans;
}

// main function
int main(){
	for(int i=1;i<=10;i++)
		cout << lookAndSay(i) << "\n";
	return 0;
}