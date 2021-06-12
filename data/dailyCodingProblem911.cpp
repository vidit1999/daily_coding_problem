#include <bits/stdc++.h>
using namespace std;

/*
Given a stream of elements too large to store in memory,
pick a random element from the stream with uniform probability.
*/

int randomUniformLarge(int n){
    static int res, count = 0;

    count++;

    if(count == 1){
        res = n;
    } else {
        if(rand()%count == count-1)
            res = n;
    }

    return res;
}

// main function
int main(){
    srand(time(0));
    
    for(int i : {1, 2, 3, 4, 5, 6, 7, 8, 9}){
        cout << randomUniformLarge(i) << "\n";
    }
    return 0;
}