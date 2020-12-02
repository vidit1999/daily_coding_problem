#include <bits/stdc++.h>
using namespace std;

/*
UTF-8 is a character encoding that maps each symbol to one, two, three, or four bytes.

For example, the Euro sign, €, corresponds to
the three bytes 11100010 10000010 10101100.

The rules for mapping characters are as follows:

For a single-byte character, the first bit must be zero.
For an n-byte character, the first byte starts with n ones and a zero.
The other n - 1 bytes all start with 10.

Visually, this can be represented as follows.

 Bytes   |           Byte format
-----------------------------------------------
   1     | 0xxxxxxx
   2     | 110xxxxx 10xxxxxx
   3     | 1110xxxx 10xxxxxx 10xxxxxx
   4     | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

Write a program that takes in an array of integers representing byte values,
and returns whether it is a valid UTF-8 encoding.
*/

bool valididateUTF8(vector<int> numbers){
	int next_nums = 0;
	
	for(int num : numbers){
		if(next_nums == 0){
			int mask = (1 << 7);
			while(mask & num){
				next_nums++;
				mask >>= 1;
			}
			
			if(next_nums == 0)
				continue;
			if(next_nums > 4 || next_nums == 1)
				return false;
		}
		else{
			if(!(num & (1 << 7)) || (num & (1 << 6)))
				return false;
		}
		next_nums--;
	}
	
	return (next_nums == 0);
}

void testFunc(vector<vector<int>> v){
	for(auto numbers : v){
		if(valididateUTF8(numbers))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}

// main function
int main(){
	testFunc({
		{197, 130, 1},
		{235, 140, 4},
		{250,145,145,145,145}
	});
	return 0;
}