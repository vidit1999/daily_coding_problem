#include <bits/stdc++.h>
using namespace std;

/*
Assume you have access to a function toss_biased() which
returns 0 or 1 with a probability that's not 50-50
(but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.
*/

// true => head (70%)
// false => tail (30%)
bool biasedCoin(){
    return float(rand())/float(RAND_MAX) >= 0.3;
}

// true => head (50%)
// false => tail (50%)
bool unbiasedCoin(){
    bool toss1, toss2;
    
    do{
        toss1 = biasedCoin();
        toss2 = biasedCoin();
    }while(!(toss1 ^ toss2));

    return toss1;
}

pair<int, int> testFunc(){
    int true_count = 0, false_count = 0;
    
    for(int i=0; i<1000; i++){
        if(unbiasedCoin()) true_count++;
        else false_count++;
    }
    
    return {true_count, false_count};
}

// main function
int main(){
    srand(time(0));
    
    for(int i=0; i<5; i++){
        auto ans = testFunc();
        cout << ans.first << ", " << ans.second << "\n";
    }
    
    return 0;
}