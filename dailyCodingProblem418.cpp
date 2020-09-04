#include <bits/stdc++.h>
using namespace std;

/*
MegaCorp wants to give bonuses to its employees based on how many lines of codes they have written.
They would like to give the smallest positive amount to each worker consistent with the constraint
that if a developer has written more lines of code than their neighbor, they should receive more money.

Given an array representing a line of seats of employees at MegaCorp, determine how much each one should get paid.

For example, given [10, 40, 200, 1000, 60, 30], you should return [1, 2, 3, 4, 2, 1].
*/

vector<int> bonus(vector<int> codes){
	vector<int> ans(codes.size(), 1);
	
	bool anyChange = true;
	while(anyChange){
		anyChange = false;
		for(int i=0;i<ans.size();i++){
            if(
                (i > 0 && codes[i] > codes[i-1] && ans[i] <= ans[i-1]) ||
                (i < ans.size()-1 && codes[i] > codes[i+1] && ans[i] <= ans[i+1])
            ){
                ans[i] += 1;
                anyChange = true;
            }
		}
	}
	
	return ans;
}

void testFunc(vector<vector<int>> v){
    for(auto codes : v){
        for(int i : bonus(codes))
            cout << i << " ";
        cout << "\n";
    }
}

// main function
int main(){
    testFunc({
        {10, 40, 200, 1000, 60, 30},
        {10, 40, 200, 1000, 900, 800, 30}
    });
	return 0;
}