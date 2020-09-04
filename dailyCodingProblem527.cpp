#include <bits/stdc++.h>
#define MAXN 100
using namespace std;

/*
Write a program to determine how many distinct ways there are to create a
max heap from a list of N given integers.

For example, if N = 3, and our integers are [1, 2, 3], there are two ways, shown below.

  3      3
 / \    / \
1   2  2   1
*/

int dp[MAXN], nck[MAXN][MAXN], logBase2[MAXN];

int choose(int n, int k){
    if(k > n)
        return 0;
    if(n <= 1 || k == 0)
        return 1;
    
    if(nck[n][k] != -1) return nck[n][k];

    int ans = choose(n-1, k-1) + choose(n-1, k);
    nck[n][k] = ans;
    return ans;
}


int getLeft(int n){
    if(n == 1)
        return 0;
    
    int h = logBase2[n];
    int numh = (1 << h);
    int last = n - (numh - 1);

    if(last >= numh/2)
        return numh - 1;
    else
        return numh - 1 - (numh/2 - last);

}

int numOfHeaps(int n){
    if(n <= 1)
        return 1;
    
    if(dp[n] != -1)
        return dp[n];
    
    int left = getLeft(n);
    int ans = choose(n-1, left) * numOfHeaps(left) * numOfHeaps(n-left-1);
    dp[n] = ans;
    return ans;
}

int solve(int n){
    for(int i=0;i<=n;i++){
        dp[i] = -1;
        for(int j=0;j<=n;j++)
            nck[i][j] = -1;
    }

    int currPower2 = 1, currLog = -1;
    for(int i=1;i<=n;i++){
        if(currPower2 == i){
            currLog++;
            currPower2 *= 2;
        }
        logBase2[i] = currLog;
    }

    return numOfHeaps(n);
}

// main function
int main(){
    int n = 3;
    cout << solve(n) << "\n";
	return 0;
}