#include <bits/stdc++.h>
using namespace std;

/*
A Collatz sequence in mathematics can be defined as follows. Starting with any positive integer:

if n is even, the next number in the sequence is n / 2
if n is odd, the next number in the sequence is 3n + 1
It is conjectured that every such sequence eventually reaches the number 1. Test this conjecture.

Bonus: What input n <= 1000000 gives the longest sequence?
*/

bool testCollatzSeq(int n){
	if(n == 1)
		return true;
	if(n%2 == 0)
		return testCollatzSeq(n/2);
	return testCollatzSeq(3*n+1);
}

int getSeqCount(int n, unordered_map<int, int>& seqCount){
	if(seqCount.find(n) != seqCount.end())
		return seqCount[n];
	
	if(n%2 == 0)
		seqCount[n] = 1 + getSeqCount(n/2, seqCount);
	else
		seqCount[n] = 1 + getSeqCount(3*n+1, seqCount);
	
	return seqCount[n];
}

pair<int, int> checkMaxSeq(int n){
	unordered_map<int, int> seqCount = {{1, 0}};
	int maxCount = 0, number = 1;
	for(int i=1;i<=n;i++){
        int count = getSeqCount(i, seqCount);
        if(maxCount <= count){
            maxCount = count;
            number = i;
        }
    }
	
	return {number, maxCount};
}

// main function
int main(){
	auto ans = checkMaxSeq(10000);
    cout << ans.first << " --> " << ans.second << "\n";
	return 0;
}