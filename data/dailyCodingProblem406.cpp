#include <bits/stdc++.h>
using namespace std;

/*
You are presented with an array representing a Boolean expression. The elements are of two kinds:

T and F, representing the values True and False.
&, |, and ^, representing the bitwise operators for AND, OR, and XOR.
Determine the number of ways to group the array elements using parentheses
so that the entire expression evaluates to True.

For example, suppose the input is ['F', '|', 'T', '&', 'T']. In this case,
there are two acceptable groupings: (F | T) & T and F | (T & T).
*/


int countTrueParen(char symbol[], char oper[], int n){
	int T[n][n], F[n][n];
	
	for(int i=0;i<n;i++){
		T[i][i] = (symbol[i] == 'T')? 1 : 0;
		F[i][i] = (symbol[i] == 'F')? 1 : 0;
	}
	
	for(int gap=1; gap<n; gap++){
		for(int i=0, j=gap; j<n; i++, j++){
			T[i][j] = F[i][j] = 0;
			for(int g=0;g<gap;g++){
				int k = i+g;
				int tik = T[i][k] + F[i][k];
				int tkj = T[k+1][j] + F[k+1][j];
				
				if(oper[k] == '&'){
					T[i][j] += T[i][k]*T[k+1][j];
					F[i][j] += (tik*tkj - T[i][k]*T[k+1][j]);
				}
				else if(oper[k] == '|'){
					T[i][j] += (tik*tkj + F[i][k]*F[k+1][j]);
					F[i][j] += F[i][k]*F[k+1][j]; 
				}
				else if(oper[k] == '^'){
					T[i][j] += (T[i][k]*F[k+1][j] + F[i][k]*T[k+1][j]);
					F[i][j] += (T[i][k]*T[k+1][j] + F[i][k]*F[k+1][j]);
				}
			}
		}
	}
	
	return T[0][n-1];
}

// main function
int main(){
	char symbol[] = "TTFT";
	char oper[] = "|&^";
	int n = strlen(symbol);
	
	cout << countTrueParen(symbol, oper, n) << "\n";
	return 0;
}