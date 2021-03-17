#include <bits/stdc++.h>
using namespace std;

/*
Given a list of numbers, create an algorithm that arranges
them in order to form the largest possible integer.
For example, given [10, 7, 76, 415], you should return 77641510.
*/

string largestPossibleInteger(vector<int> arr){
    sort(
        arr.begin(), arr.end(),
        [](int a, int b){
            return to_string(a) + to_string(b) > to_string(b) + to_string(a);
        }
    );
    
    string ans = "";
    
    for(int i: arr){
        ans += to_string(i);
    }
    
    return ans;
}

// main function
int main(){
    cout << largestPossibleInteger({10, 7, 76, 415}) << "\n";
    return 0;
}