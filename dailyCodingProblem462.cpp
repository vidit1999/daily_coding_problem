#include <bits/stdc++.h>
using namespace std;

int nextSparse(int number){
    vector<bool> binNumber;
    while(number){
        binNumber.push_back(number&1);
        number >>= 1;
    }
    binNumber.push_back(0);
    int n = binNumber.size();
    int last_final = 0;
    for(int i=1;i<n;i++){
        if(binNumber[i]==1 && binNumber[i-1]==1 && binNumber[i+1] != 1){
            binNumber[i+1] = 1;
            for(int j=i;j>=last_final;j--)
                binNumber[j] = 0;
            last_final = i+1;
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans += binNumber[i]*(1<<i);
    }
    return ans;
}

// main function
int main(){
    cout << nextSparse(21) << "\n";
    cout << nextSparse(22) << "\n";
    cout << nextSparse(38) << "\n";
    return 0;
}