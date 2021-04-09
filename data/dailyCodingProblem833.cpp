#include <bits/stdc++.h>
using namespace std;

/*
At a party, there is a single person who everyone knows,
but who does not know anyone in return (the "celebrity").
To help figure out who this is, you have access to an O(1)
method called knows(a, b), which returns True if person a
knows person b, else False.

Given a list of N people and the above operation,
find a way to identify the celebrity in O(N) time.
*/

vector<vector<int>> matrix = {
    {0, 0, 1, 0},
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0}
};

bool knows(int i, int j){
    return matrix[i][j];
}

int celebrityIdentification(int n){
    int a = 0, b = n-1;

    while(a < b){
        if(knows(a, b)){
            a++;
        }
        else{
            b--;
        }
    }

    for(int i=0; i<n; i++){
        if(i != a && (knows(a, i) || !knows(i, a))){
            return -1;
        }
    }

    return a;
}

// main function
int main(){
    cout << celebrityIdentification(4) << "\n";
    return 0;
}