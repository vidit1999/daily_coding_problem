#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a number of lines k, print the string in zigzag form.
In zigzag, characters are printed out diagonally from top left to bottom
right until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
*/

void printZigZag(string s, int k){
	if(k == 1){
		cout << k << "\n";
		return;
	}
	
	for(int i=0; i<s.length(); i += 2*(k-1))
		cout << s[i];
	
	for(int j=1; j<k-1; j++){
		bool down = true;
		for(int i=j; i<s.length();){
			cout<< s[i]; 
			if(down) i += 2*(k-j-1);
			else i += 2*j;
			down = !down;
		}
	}
	
	for(int i=k-1; i<s.length(); i += 2*(k-1))
		cout << s[i];
}

// main function
int main(){
	printZigZag("thisisazigzag", 4);
	return 0;
}