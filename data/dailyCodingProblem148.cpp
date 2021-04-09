#include <bits/stdc++.h>
using namespace std;

/*
Gray code is a binary code where each successive value differ in only one bit,
as well as when wrapping around. Gray code is common in hardware so
that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].
*/

vector<string> grayCode(int n){
	vector<string> ans;
	if(n <= 0) return ans;
	
	ans.push_back("0");
	ans.push_back("1");
	
	for(int i=2; i<(1<<n); i<<=1){
		for(int j=i-1; j>=0; j--)
			ans.push_back(ans[j]);
		for(int j=0; j<i; j++)
			ans[j] = "0" + ans[j];
		for(int j=i; j<2*i; j++)
			ans[j] = "1" + ans[j];
	}
	
	return ans;
}

// main function
int main(){
	for(string s : grayCode(4))
		cout << s << "\n";
	return 0;
}