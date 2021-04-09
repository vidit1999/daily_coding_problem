#include <bits/stdc++.h>
using namespace std;

/*
Run-length encoding is a fast and simple method of encoding strings.
The basic idea is to represent repeated successive characters as a single count and character.
For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be
encoded have no digits and consists solely of alphabetic characters.
You can assume the string to be decoded is valid.
*/

string runLengthEncode(string s){
	if(s.empty())
		return "";
	if(s.length() == 1)
		return "1"+string(1,s[0]);
	
	int count = 1;
	string res = "";
	int i=1;
	for(;i<s.length();i++){
		if(s[i] != s[i-1]){
			res += to_string(count)+s[i-1];
			count = 1;
		}
		else
			count++;
	}
	
	return res + to_string(count)+s[i-1];
}

string runLengthDecode(string s){
	string res = "";
	for(int i=0;i<s.length()-1 && !s.empty();i+=2)
		for(int j=1;j<=(s[i]-'0');j++)
			res += s[i+1];
	return res;
}

// main function
int main(){
	cout << runLengthEncode("AAAABBBCCDAA") << "\n";
	cout << runLengthEncode("CCDAA") << "\n";
	cout << runLengthEncode("AAA") << "\n";
	cout << runLengthEncode("") << "\n";
	cout << runLengthEncode("A") << "\n";
	
	cout << runLengthDecode("4A3B2C1D2A") << "\n";
	cout << runLengthDecode("2C1D2A") << "\n";
	cout << runLengthDecode("3A") << "\n";
	cout << runLengthDecode("") << "\n";
	cout << runLengthDecode("1A") << "\n";
	
	return 0;
}