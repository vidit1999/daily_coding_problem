#include <bits/stdc++.h>
using namespace std;

/*
Given a string and a number of lines k, print the string in zigzag form.
In zigzag, characters are printed out diagonally from top left to bottom right
until reaching the kth line, then back up to top right, and so on.

For example, given the sentence "thisisazigzag" and k = 4, you should print:

t     a     g
 h   s z   a
  i i   i z
   s     g
*/

void printLinesZigZag(string s, int k){
	if(k == 1){
		cout << s;
		return;
	}
	int len = s.length();
	string arr[k];
	
	int row = 0;
	bool down = true;
	
	for(int i=0;i<len;i++){
		arr[row].push_back(s[i]);
		if(row == k-1)
			down = false;
		else if(row == 0)
			down = true;
		(down)? (row++) : (row--);
	}
}

// main function
int main(){
	printLinesZigZag("thisisazigzag", 4);
	return 0;
}