#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

/*
Implement a job scheduler which takes in a function f and an integer n,
and calls f after n milliseconds.
*/

void jobScheduler(void f(), int t){
    sleep(t);
    f();
}

void printNum(){
    cout << rand() << "\n";
}

// main function
int main(){
    srand(time(0));

    for(int i=0; i<10; i++){
        jobScheduler(printNum, 2);
    }
    return 0;
}