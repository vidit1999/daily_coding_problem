#include <bits/stdc++.h>
using namespace std;

/*
Given the mapping a = 1, b = 2, ... z = 26, and an encoded message,
count the number of ways it can be decoded.

For example, the message '111' would give 3, since it could be
decoded as 'aaa', 'ka', and 'ak'.

You can assume that the messages are decodable.
For example, '001' is not allowed.
*/

// reecursive approach
int countDecode(string digits, int n){
    if(n==0 || n==1)
        return 1;
    if(digits[0] == '0')
        return 0;
    int count = 0;
    if(digits[n-1] > '0')
        count += countDecode(digits,n-1);
    if(digits[n-2] == '1' || (digits[n-2] == '2' && digits[n-1] < '7'))
        count += countDecode(digits,n-2);
    return count;
}

// dp approach
int countDecodeDP(string digits, int n){
    if(digits[0] == '0')
        return 0;
    int count[n+1];
    count[0] = count[1] = 1;
    for(int i=2;i<=n;i++){
        count[i] = 0;
        if(digits[i-1] > '0')
            count[i] += count[i-1];
        if(digits[i-2] == '1' || (digits[i-2] == '2' && digits[i-1] < '7'))
            count[i] += count[i-2];
    }
    return count[n];
}


// main function
int main(){
    cout << countDecodeDP("1234",4);
    return 0;
}