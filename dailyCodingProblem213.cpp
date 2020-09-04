#include <bits/stdc++.h>
using namespace std;

/*
Given a string of digits, generate all possible valid IP address combinations.

IP addresses must follow the format A.B.C.D, where A, B, C, and D are numbers
between 0 and 255. Zero-prefixed numbers, such as 01 and 065, are not allowed,
except for 0 itself.

For example, given "2542540123",
you should return ['254.25.40.123', '254.254.0.123'].
*/

bool isValid(vector<string> v){
	for(string s : v){
		if(s.length() > 3 || s.length() < 1) return false;
		if(s.length() > 1 && s[0] == '0') return false;
		if(stoi(s) < 0 || stoi(s) > 255) return false;
	}
	
	return true;
}

vector<string> generateAllIp(string number){
	vector<string> res;
	
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			for(int k=1; k<=3; k++){
				for(int l=0; l<=3; l++){
					if(i+j+k+l == number.length()){
						string a = number.substr(0, i);
						string b = number.substr(i, j);
						string c = number.substr(i+j, k);
						string d = number.substr(i+j+k, l);
						if(isValid({a, b, c, d}))
							res.push_back(a+"."+b+"."+c+"."+d);
					}
				}
			}
		}
	}
	
	return res;
}

void testFunc(vector<string> v){
	for(string s : v){
		for(string ip : generateAllIp(s))
			cout << ip << " ";
		cout << "\n";
	}
}

// main function
int main(){
	testFunc({
		"2542540123",
		"25525511135"
	});
	return 0;
}