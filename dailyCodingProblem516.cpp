#include <bits/stdc++.h>
using namespace std;

/*
Let's define a "sevenish" number to be one which is either a power of 7,
or the sum of unique powers of 7. The first few sevenish numbers are 1, 7, 8, 49, and so on.
Create an algorithm to find the nth sevenish number.
*/

int power(int number, int n){
	int p = 1;
	for(int i=1;i<=n;i++)
		p *= number;
	return p;
}

int sevenishNumber(int n){
	vector<int> sevenish = {};
	int i = 0;
	
	while(sevenish.size() < n){
		sevenish.push_back(power(7, i));
		int last_index = sevenish.size()-1;
		
		for(int i=0;i<last_index;i++){
			sevenish.push_back(sevenish[last_index]+sevenish[i]);
			if(sevenish.size() == n)
				break;
		}
		i++;
	}
	
	return sevenish[n-1];
}

// main function
int main(){
	for(int i=1;i<=10;i++)
		cout << sevenishNumber(i) << "\n";
	return 0;
}