#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/*
Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element

That is, implement a function that takes in a string and a valid regular
expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray",
your function should return true. The same regular expression on the
string "raymond" should return false.

Given the regular expression ".*at" and the string "chat",
your function should return true. The same regular expression
on the string "chats" should return false.
*/

bool regMatcher(char text[], char pattern[], int m, int n){
	if(m == 0) return (n == 0);
	
	bool lookup[m+1][n+1];
	memset(lookup, false, sizeof(lookup));
	
	lookup[0][0] = true;
	
	for(int i=1; i<=n; i++){
		if(pattern[i-1] == '*')
			lookup[0][i] = lookup[0][i-1];
	}
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			if(pattern[j-1] == '*')
				lookup[i][j] = lookup[i][j-1] || lookup[i-1][j];
			else if(pattern[j-1] == '.' || text[i-1] == pattern[j-1])
				lookup[i][j] = lookup[i-1][j-1];
			else lookup[i][j] = false;
		}
	}
	
	return lookup[m][n];
}


// main function
int main(){
	char str[] = "baaabab";
    char pattern[] = "*****ba*****ab";
	char pattern1[] = "ba*****ab"; 
    char pattern2[] = "ba*ab"; 
    char pattern3[] = "a*ab"; 
    char pattern4[] = "a*****ab"; 
    char pattern5[] = "*a*****ab"; 
    char pattern6[] = "ba*ab****"; 
    char pattern7[] = "****"; 
    char pattern8[] = "*"; 
    char pattern9[] = "aa?ab"; 
    char pattern10[] = "b*b"; 
    char pattern11[] = "a*a"; 
    char pattern12[] = "baaabab"; 
    char pattern13[] = "?baaabab"; 
    char pattern14[] = "*baaaba*"; 

	if(regMatcher(str, pattern, strlen(str), strlen(pattern)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern2, strlen(str), strlen(pattern2)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern3, strlen(str), strlen(pattern3)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern4, strlen(str), strlen(pattern4)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern5, strlen(str), strlen(pattern5)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern6, strlen(str), strlen(pattern6)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern7, strlen(str), strlen(pattern7)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern8, strlen(str), strlen(pattern8)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern9, strlen(str), strlen(pattern9)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern10, strlen(str), strlen(pattern10)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern11, strlen(str), strlen(pattern11)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern12, strlen(str), strlen(pattern12)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern13, strlen(str), strlen(pattern13)))
		printf("Yes\n");
	else
		printf("No\n");
	
    if(regMatcher(str, pattern14, strlen(str), strlen(pattern14)))
		printf("Yes\n");
	else
		printf("No\n");
	
	return 0;
}