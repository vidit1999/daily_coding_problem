#include <bits/stdc++.h>
using namespace std;

/*
Given a function that generates perfectly random numbers between
1 and k (inclusive), where k is an input, write a function that
shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations
of the deck is equally likely.
*/

int randK(int k){
    return rand()%k + 1;
}

void shuffleDeck(int arr[], int n){
    for(int i=n-1; i>=0; i--){
        int swap_index = randK(i+1) - 1;
        swap(arr[i], arr[swap_index]);
    }
}

// main function
int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    shuffleDeck(arr, n);

    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";

    return 0;
}
