#include <bits/stdc++.h>
using namespace std;

/*
You are given a string of length N and a parameter k. The string can be manipulated by
taking one of the first k letters and moving it to the end.

Write a program to determine the lexicographically smallest string that can be created
after an unlimited number of moves.

For example, suppose we are given the string daily and k = 1.
The best we can create in this case is ailyd.
*/

string lexSmallest(string s, int k){
	if(k >= s.length()){
		sort(s.begin(), s.end());
		return s;
	}
	
	string temp = "";

	while(1){
        string prev = s;
        auto maxPos = max_element(s.begin(), s.begin()+k);
        char c = *maxPos;
        s.erase(maxPos);
        temp = s + c;
        if(temp < prev)
            s = temp;
        else{
            s = prev;
            break;
        }
	}

    return s;
}

// main function
int main(){
    cout << lexSmallest("daily", 1) << "\n";
	return 0;
}