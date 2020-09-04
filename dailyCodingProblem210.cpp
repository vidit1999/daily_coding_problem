#include <bits/stdc++.h>
using namespace std;

/*
A Collatz sequence in mathematics can be defined as follows.
Starting with any positive integer:

if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1

It is conjectured that every such sequence eventually
reaches the number 1. Test this conjecture.

Bonus: What input n <= 1000000 gives the longest sequence?
*/

bool conjectureTest(int n){
	while(n > 0){
		if(n == 1) return true;
		if(n%2 == 0) n /= 2;
		else n = 3*n+1;
	}
	return false;
}

long countSteps(long n, unordered_map<long, long>& seen){
    if(seen.find(n) != seen.end()){
        return seen[n];
    }

    if(n == 1) return 0;
    
    seen[n] = 1 + ((n % 2 == 0)? countSteps(n/2, seen) : countSteps(3*n+1, seen));
    
    return seen[n];
}

// main function
int main(){
	srand(time(0));
	for(int i=0; i<10; i++){
		int num = rand() + 1;
		cout << num << " : ";
		if(conjectureTest(num))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	
	long num = 1;
    long max_count = INT_MIN;
    unordered_map<long, long> seen;
    
    for(long i=1; i<=1e6; i++){
        long count = countSteps(i, seen);
        if(count > max_count){
            max_count = count;
            num = i;
        }
	}
    cout << num << " : " << max_count << "\n";
	
	
	return 0;
}