#include <bits/stdc++.h>
using namespace std;

/*
Write a program that computes the length of the longest common subsequence
of three given strings. For example, given "epidemiologist", "refrigeration",
and "supercalifragilisticexpialodocious", it should return 5,
since the longest common subsequence is "eieio".
*/

int longestCommonSubStr(string s1, string s2, string s3){
	int lcs[s1.length()+1][s2.length()+1][s3.length()+1];
	
	for(int i=0; i<=s1.length(); i++){
		for(int j=0; j<=s2.length(); j++){
			for(int k=0; k<=s3.length(); k++){
				if(i == 0 || j == 0 || k == 0)
					lcs[i][j][k] = 0;
				else if(s1[i-1] == s2[j-1] && s1[i-1] == s3[k-1])
					lcs[i][j][k] = 1 + lcs[i-1][j-1][k-1];
				else{
					lcs[i][j][k] = max(
						max(lcs[i-1][j][k], lcs[i][j-1][k]),
						lcs[i][j][k-1]
					);
				}
			}
		}
	}
	
	return lcs[s1.length()][s2.length()][s3.length()];
}

// main function
int main(){
	string s1 = "epidemiologist", s2 = "refrigeration", s3 = "supercalifragilisticexpialodocious";
	cout << longestCommonSubStr(s1, s2, s3) << "\n";
	return 0;
}