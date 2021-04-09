#include <bits/stdc++.h>
using namespace std;

/*
Write a function, throw_dice(N, faces, total), that determines how many ways it is possible
to throw N dice with some number of faces each to get a specific total.

For example, throw_dice(3, 6, 7) should equal 15.
*/

int throw_dice(int n, int faces, int total){
	if(n == 0 && total == 0)
		return 1;
	if((n == 0 && total != 0) || (n != 0 && total == 0))
		return 0;
	
	int ans = 0;
	for(int i=1;i<=faces;i++){
		if(total >= i)
			ans += throw_dice(n-1, faces, total - i);
	}
	
	return ans;
}

// main function
int main(){
	cout << throw_dice(3, 6, 12) << "\n";
	return 0;
}