#include <bits/stdc++.h>
using namespace std;

/*
We have some historical clickstream data gathered from our site anonymously using cookies.
The histories contain URLs that users have visited in chronological order.

Write a function that takes two users' browsing histories as input and returns
the longest contiguous sequence of URLs that appear in both.

For example, given the following two users' histories:

user1 = ['/home', '/register', '/login', '/user', '/one', '/two']
user2 = ['/home', '/red', '/login', '/user', '/one', '/pink']

You should return the following:

['/login', '/user', '/one']
*/

vector<string> longestContiguousSequence(vector<string> v1, vector<string> v2){
	int m = v1.size(), n = v2.size();
	int lcs[m+1][n+1];
	int len = 0;
	int row, col;
	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i == 0 || j == 0){
				lcs[i][j] = 0;
			}
			else if(v1[i-1] == v2[j-1]){
				lcs[i][j] = lcs[i-1][j-1]+1;
				if(lcs[i][j] > len){
					len = lcs[i][j];
					row = i;
					col = j;
				}
			}
			else{
				lcs[i][j] = 0;
			}
		}
	}
	
	if(len == 0){
		return {};
	}
	
	vector<string> ans;
	
	while(lcs[row][col]){
		ans.push_back(v1[row-1]);
		row--;
		col--;
	}
	
	reverse(ans.begin(), ans.end());
	
	return ans;
}

// main function
int main(){
	vector<string> v1 = {"/home", "/register", "/login", "/user", "/one", "/two"};
	vector<string> v2 = {"/home", "/red", "/login", "/user", "/one", "/pink"};
	
	for(string s : longestContiguousSequence(v1, v2)){
		cout << s << "\n";
	}
	
	return 0;
}