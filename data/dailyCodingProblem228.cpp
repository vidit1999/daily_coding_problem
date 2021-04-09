#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers, create an algorithm that arranges them in order
to form the largest possible integer. For example, given [10, 7, 76, 415],
you should return 77641510.
*/

struct Compare{
	bool operator () (int s1, int s2){
		return (to_string(s1) + to_string(s2)) > (to_string(s2) + to_string(s1));
	}
};

string largestNumber(vector<int> arr){
	sort(arr.begin(), arr.end(), Compare());
	string ans;
	for(int i : arr) ans += to_string(i);
	
	return ans;
}

// main function
int main(){
	cout << largestNumber({54, 546, 548, 60}) << "\n";
	return 0;
}