#include <bits/stdc++.h>
using namespace std;

/*
Given a positive integer N, find the smallest number of steps it will take to reach 1.

There are two kinds of permitted steps:

You may decrement N to N - 1.

If a * b = N, you may decrement N to the larger of a and b.

For example, given 100, you can reach 1 in five steps with
the following route: 100 -> 10 -> 9 -> 3 -> 2 -> 1.
*/

struct node{
    int data, count;
};

int smallestToOne(int n){
    queue<node> q;
    unordered_set<int> uset;

    q.push({n, 0});
    uset.insert(n);

    while(!q.empty()){
        auto f = q.front(); q.pop();

        if(f.data == 1){
            return f.count;
        }

        if(uset.find(f.data - 1) == uset.end()){
            uset.insert(f.data - 1);
            q.push({f.data - 1, f.count + 1});
        }

        for(int i=2; i*i<=f.data; i++){
            if(f.data % i == 0 && uset.find(f.data / i) == uset.end()){
                uset.insert(f.data / i);
                q.push({f.data / i, f.count + 1});
            }
        }
    }

    return -1;
}

// main function
int main(){
    cout << smallestToOne(100) << "\n";
    cout << smallestToOne(17) << "\n";
    cout << smallestToOne(50) << "\n";
    return 0;
}
