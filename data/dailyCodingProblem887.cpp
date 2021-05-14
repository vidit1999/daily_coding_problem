#include <bits/stdc++.h>
using namespace std;

/*
The ancient Egyptians used to express fractions as a sum of several
terms where each numerator is one. For example, 4 / 13 can be
represented as 1 / 4 + 1 / 18 + 1 / 468.

Create an algorithm to turn an ordinary fraction a / b, where a < b,
into an Egyptian fraction.
*/

void egyptiansFractionsHelper(int num, int denum, vector<int>& exps){
    if(num == 1){
        exps.push_back(denum);
        return;
    }

    if(denum % num == 0){
        exps.push_back(denum/num);
        return;
    }

    int z = denum/num + 1;

    exps.push_back(z);

    egyptiansFractionsHelper(num*z - denum, denum*z, exps);
}

vector<int> egyptiansFractions(int num, int denum){
    vector<int> exps;
    egyptiansFractionsHelper(num, denum, exps);
    return exps;
}

// main function
int main(){
    for(int i : egyptiansFractions(4,13)){
        cout << i << "\n";
    }
    return 0;
}
