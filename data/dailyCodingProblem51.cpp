#include <bits/stdc++.h>
using namespace std;

#define DECK_SIZE 52

/*
Given a function that generates perfectly random numbers between 1 and k (inclusive),
where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/

int randK(int k){
	return rand()%k + 1;
}

void shuffleDeck(int arr[], int n){
	for(int i=n-1; i>=0; i--){
		int index = randK(i+1) - 1;
		swap(arr[i], arr[index]);
	}
}

// main function
int main(){
	srand(time(0));
	
	int arr[DECK_SIZE];
	for(int i=0; i<DECK_SIZE; i++){
		arr[i] = i+1;
	}
	
	shuffleDeck(arr, DECK_SIZE);
	
	for(int i=0; i<DECK_SIZE; i++){
		cout << arr[i] << " ";
		if((i+1)%13 == 0) cout << "\n";
	}
	
	return 0;
}