#include <bits/stdc++.h>
using namespace std;

/*
Given a set of characters C and an integer k, a De Bruijn sequence is a cyclic
sequence in which every possible k-length string of characters in C occurs exactly once.

For example, suppose C = {0, 1} and k = 3. Then our sequence should contain
the substrings {'000', '001', '010', '011', '100', '101', '110', '111'},
and one possible solution would be 00010111.

Create an algorithm that finds a De Bruijn sequence.
*/

unordered_set<string> seen;
vector<int> edges;

void dfs(string node, int& k, string& s){
	for(int i=0;i<k;i++){
		string str =node + s[i];
		if(seen.find(str) == seen.end()){
			seen.insert(str);
			dfs(str.substr(1), k, s);
			edges.push_back(i);
		}
	}
}

string deBrujin(int n, int k, string s){
	string startingNode(n-1,s[0]);
	dfs(startingNode, k, s);
	
	string ans = "";
	int l = pow(k, n);
	for(int i=0;i<l;i++)
		ans += s[edges[i]];
	ans += startingNode;
	
	return ans;
}


// main function
int main(){
	int n=3, k=2;
	string s = "01";
	cout << deBrujin(n, k, s) << "\n";
	return 0;
}