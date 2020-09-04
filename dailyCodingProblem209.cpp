#include <bits/stdc++.h>
using namespace std;

/*
Write a program that computes the length of the longest common subsequence of three given strings.
For example, given "epidemiologist", "refrigeration", and "supercalifragilisticexpialodocious",
it should return 5, since the longest common subsequence is "eieio".
*/

int longestCommonSubsequence(string s1, string s2, string s3){
	int n1 = s1.length(), n2 = s2.length(), n3 = s3.length();
	
	int lcs[n1+1][n2+1][n3+1];
	
	for(int i=0; i<=n1; i++){
		for(int j=0; j<=n2; j++){
			for(int k=0; k<=n3; k++){
				if(i == 0 || j == 0 || k == 0)
					lcs[i][j][k] = 0;
				else if(s1[i-1] == s2[j-1] && s2[j-1] == s3[k-1])
					lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
				else
					lcs[i][j][k] = max({
						lcs[i-1][j][k],
						lcs[i][j-1][k],
						lcs[i][j][k-1]
					});
			}
		}
	}
	
	return lcs[n1][n2][n3];
}

// main function
int main(){
	cout << longestCommonSubsequence("epidemiologist", "refrigeration", "supercalifragilisticexpialodocious") << "\n";
	return 0;
}