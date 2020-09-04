#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

/*
Implement a job scheduler which takes in a function
f and an integer n, and calls f after n milliseconds.
*/

void callFuncDelay(void f(int), int n){
    sleep(n);
    f(n);
}

void print(int n){
    cout << rand() << "\n";
}

// main function
int main(){
    srand(time(0));
    for(int i=0; i<10; i++)
        callFuncDelay(print, 5);
	return 0;
}