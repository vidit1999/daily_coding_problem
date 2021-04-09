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
In addition, note that the Roman numeral system uses subtractive notation for numbers such as IV and XL.

For the input XIV, for instance, you should return 14.
*/

int value(char c){
	switch(c){
		case 'M': return 1000;
		case 'D': return 500;
		case 'C': return 100;
		case 'L': return 50;
		case 'X': return 10;
		case 'V': return 5;
		case 'I': return 1;
		default	: return -1;
	}
}

int decimalValue(string roman_numeral){
	int ans = 0;
	
	for(int i=0; i<roman_numeral.length(); i++){
		int val1 = value(roman_numeral[i]);
		if(i+1 < roman_numeral.length()){
			int val2 = value(roman_numeral[i+1]);
			if(val1 >= val2){
				ans += val1;
			}
			else{
				ans += (val2 - val1);
				i++;
			}
		}
		else{
			ans += val1;
		}
	}
	
	return ans;
}

// main function
int main(){
	cout << decimalValue("XIV") << "\n";
	cout << decimalValue("MCMIV") << "\n";
	return 0;
}