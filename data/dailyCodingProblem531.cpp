#include <bits/stdc++.h>
using namespace std;

/*
Using a read7() method that returns 7 characters from a file,
implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”,
three read7() returns “Hello w”, “orld” and then “”.
*/

int index;

string read7(string& s){
	string ans = "";
	int count = 7;

	while(index < s.length() && count--){
		ans.push_back(s[index++]);
	}

	return ans;
}

string readN(string s, int n){
	string ans = "";
	int count = 0;

	while(count < n){
		string r = read7(s);
		if(r.empty())
			break;
		for(int i=0; i<r.length() && count<n; i++, count++){
			ans.push_back(r[i]);
		}
	}

	return ans;
}

// main function
int main(){
	index = 0;
	string s = "Hello world";
	
	cout << readN(s, 17) << "\n";

	return 0;
}