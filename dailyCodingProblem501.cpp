#include <bits/stdc++.h>
using namespace std;

/*
Given a function that generates perfectly random numbers between 1 and k (inclusive),
where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
*/

// get a random number between 1 and k (inclusive)
int get_random_int(int k){
	return rand()%k + 1;
}

void shuffleCards(int arr[], int n){
	srand(time(0));
	for(int i=0;i<n;i++){
		swap(arr[i], arr[n-get_random_int(n-i)]);
	}
}

// main function
int main(){
	int arr[52];
	for(int i=1;i<=52;i++){
		arr[i-1] = i;
	}
	
	for(int i=0;i<52;i+=13){
		for(int j=i;j<13+i;j++){
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
	cout << "\n-----------------\n";
	shuffleCards(arr, 52);
	for(int i=0;i<52;i+=13){
		for(int j=i;j<13+i;j++){
			cout << arr[j] << " ";
		}
		cout << "\n";
	}
	return 0;
}