#include <bits/stdc++.h>
using namespace std;

/*
The ancient Egyptians used to express fractions as a sum of several terms where each numerator is one.
For example, 4 / 13 can be represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b, into an Egyptian fraction.
*/

void egyptianFractionHelper(int numr, int denr, vector<int>& denums){
	if(numr == 1 || numr == denr){
        denums.push_back(denr);
		return;
    }
    if(denr%numr == 0){
        denums.push_back(denr/numr);
        return;
    }
	int d = ceil(float(denr)/float(numr));
	denums.push_back(d);
	egyptianFractionHelper(d*numr - denr, d*denr, denums);
}

vector<int> egyptianFraction(int numr, int denr){
	vector<int> denums = {};
	egyptianFractionHelper(numr, denr, denums);
    return denums;
}

// main function
int main(){
	for(int i : egyptianFraction(12,13))
		cout << i << "\n";
	return 0;
}