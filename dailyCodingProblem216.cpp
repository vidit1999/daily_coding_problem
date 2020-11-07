#include <bits/stdc++.h>
using namespace std;

/*
Given a number in Roman numeral format, convert it to decimal.

The values of Roman numerals are as follows:

{
    'M': 1000,
    'D': 500,
    'C': 100,
    'L': 50,
    'X': 10,
    'V': 5,
    'I': 1
}
In addition, note that the Roman numeral system
uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.
*/

int romanToDecimal(string num, unordered_map<char, int>& value){
	int ans = 0;
	
	for(int i=0; i<num.length(); i++){
		if(i+1 < num.length() && value[num[i+1]] > value[num[i]]){
			ans += (value[num[i+1]] - value[num[i]]);
			i++;
		}
		else{
			ans += value[num[i]];
		}
	}
	
	return ans;
}

// main function
int main(){
	unordered_map<char, int> value = {
		{'M', 1000},
		{'D', 500},
		{'C', 100},
		{'L', 50},
		{'X', 10},
		{'V', 5},
		{'I', 1}
	};
	
	cout << romanToDecimal("XIV", value) << "\n";
	return 0;
}