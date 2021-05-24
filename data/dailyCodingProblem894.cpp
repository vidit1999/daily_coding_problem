#include <bits/stdc++.h>
using namespace std;

/*
Design and implement a HitCounter class that keeps track of requests (or hits).
It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps
lower and upper (inclusive)

Follow-up: What if our system has limited memory?
*/

class HitCounter{
    map<int, int> m;
    int tot = 0;

    public:
    void show_map();
    void record(int timestamp);
    int total();
    int range(int lower, int upper);
};

void HitCounter::show_map(){
    for(auto it : m){
        cout << it.first << ", " << it.second << "\n";
    }
}

void HitCounter::record(int timestamp){
    m[timestamp]++;
    tot++;
}

int HitCounter::total(){
    return tot;
}

int HitCounter::range(int lower, int upper){
    int sum = 0;

    for(int i=lower; i<=upper; i++){
        sum += m[i];
    }

    return sum;
}

// main function
int main(){
    srand(time(0));
    HitCounter hc;

    for(int i=0; i<10; i++){
        hc.record(rand()%5);
    }

    cout << hc.total() << "\n";

    hc.show_map();

    for(int i=0; i<10; i++){
        int a = rand()%5, b = rand()%5;
        cout << a << ", " << b << ", " << hc.range(min(a, b), max(a, b)) << "\n";
    }

    return 0;
}