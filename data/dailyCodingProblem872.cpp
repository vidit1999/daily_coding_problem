#include <bits/stdc++.h>
using namespace std;

/*
Create an algorithm to efficiently compute
the approximate median of a list of numbers.

More precisely, given an unordered list of N numbers,
find an element whose rank is between N / 4 and 3 * N / 4,
with a high level of certainty, in less than O(N) time.
*/

int medianApprox(int arr[], int n){
    if(n == 0) return 0;

    set<int> s;

    for(int i=0; i<10*log2(n); i++){
        int index = rand()%n;
        s.insert(arr[index]);
    }

    auto itr = s.begin();

    advance(itr, s.size()/2 - 1);

    return *itr;
}

// main function
int main(){
    int arr[] = {1, 3, 2, 4, 5, 6, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << medianApprox(arr, n) << "\n";
    
    return 0;
}